/*

Modern Portfolio Theory
Mean-Variance Calculation (Version 01)
Author: Sujoy Das
Organization: HNKC Systems
mail: sujoy.xyz@gmail.com

*/


#include<stdio.h>
#include<math.h>

void portfolio_return(float return1, float return2)
{
    float total_return=0.0;

    for(float i = 0.1; i<=0.9; i=i+0.1)
    {
        total_return = total_return + i*return1 + ((1-i)*return2);
        printf("\n Return: %f for weight: %f", total_return, i);

        total_return = 0.0;
    }

}

void portfolio_risk(float stddev1, float stddev2, float return_cor_coeff)
{
    double variance, risk;

    for(float i = 0.1; i<=0.9; i=i+0.1)
    {
        variance =i*i*stddev1 + ((1-i)*(1-i)*stddev2)+ (i*(1-i)*stddev1*stddev2*return_cor_coeff);
        risk = sqrt(variance);
        printf("\n Risk: %lf for weight: %f", risk, i);


        variance = 0.0;
    }
}

int main()
{
    float asset1, asset2;
    float return1, return2;
    float stddev1, stddev2;

    float weight;
    float return_cor_coeff;

    printf("\n Return of Asset1:");
    scanf("%f", &return1);
    printf("\n Deviation of Asset1:");
    scanf("%f", &stddev1);

    printf("\n Return of Asset2:");
    scanf("%f", &return2);
    printf("\n Deviation of Asset2:");
    scanf("%f", &stddev2);

    printf("\n Return Correlation: ");
    scanf("%f", &return_cor_coeff);

    portfolio_return(return1, return2);
    portfolio_risk(stddev1, stddev2, return_cor_coeff);

    return 0;

}
