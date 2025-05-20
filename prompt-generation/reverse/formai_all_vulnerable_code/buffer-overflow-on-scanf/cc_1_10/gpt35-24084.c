//FormAI DATASET v1.0 Category: Digital signal processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 1024

void fir_filter(double *input, double *output, int length, double *coefficients, int filterLength);

int main()
{
    int i, filterLength, numberOfSamples;
    double *input, *output, *coefficients;

    printf("Enter the number of samples: ");
    scanf("%d", &numberOfSamples);

    printf("Enter the filter length: ");
    scanf("%d", &filterLength);

    input = (double*) malloc(sizeof(double) * numberOfSamples);
    output = (double*) malloc(sizeof(double) * numberOfSamples);
    coefficients = (double*) malloc(sizeof(double) * filterLength);

    printf("Enter the input signal values: ");
    for(i = 0;  i < numberOfSamples; i++)
    {
        scanf("%lf", &input[i]);
    }

    printf("Enter the filter coefficient values: ");
    for(i = 0; i < filterLength; i++)
    {
        scanf("%lf", &coefficients[i]);
    }

    fir_filter(input, output, numberOfSamples, coefficients, filterLength);

    printf("The output signal values are: ");
    for(i = 0; i < numberOfSamples; i++)
    {
        printf("%lf ", output[i]);
    }

    free(input);
    free(output);
    free(coefficients);

    return 0;
}

void fir_filter(double *input, double *output, int length, double *coefficients, int filterLength) 
{
    int i, j, k;
    double sum;

    for(i = 0; i < length; i++)
    {
        sum = 0.0;
        k = 0;
        for(j = i; j >= 0 && k < filterLength; j--, k++)
        {
            sum += input[j] * coefficients[k];
        }
        output[i] = sum;
    }
}