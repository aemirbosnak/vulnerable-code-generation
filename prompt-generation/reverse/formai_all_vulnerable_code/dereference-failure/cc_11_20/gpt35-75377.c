//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n, i, j, k, m;
    float sum, variance, stddev;
    float mean, cov, corr;
    float *x, *y;
    float **matrix;
    
    printf("Enter the number of variables:\n");
    scanf("%d", &n);
    
    x = (float *)malloc(n * sizeof(float));
    y = (float *)malloc(n * sizeof(float));
    matrix = (float **)malloc(n * sizeof(float *));
    for(i = 0; i < n; i++)
        matrix[i] = (float *)malloc(n * sizeof(float));
    
    printf("Enter the values of the first variable:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &x[i]);
    
    printf("Enter the values of the second variable:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &y[i]);
    
    printf("Enter the correlation matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%f", &matrix[i][j]);
    
    sum = 0;
    for(i = 0; i < n; i++)
        sum += x[i];
    mean = sum / n;
    
    variance = 0;
    for(i = 0; i < n; i++)
        variance += (x[i] - mean) * (x[i] - mean);
    variance = variance / (n - 1);
    
    stddev = sqrt(variance);
    
    printf("Mean of the first variable: %.2f\n", mean);
    printf("Standard deviation of the first variable: %.2f\n", stddev);
    
    sum = 0;
    for(i = 0; i < n; i++)
        sum += y[i];
    mean = sum / n;
    
    variance = 0;
    for(i = 0; i < n; i++)
        variance += (y[i] - mean) * (y[i] - mean);
    variance = variance / (n - 1);
    
    stddev = sqrt(variance);
    
    printf("Mean of the second variable: %.2f\n", mean);
    printf("Standard deviation of the second variable: %.2f\n", stddev);
    
    cov = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cov += matrix[i][j] * (x[i] - mean) * (y[j] - mean);
    
    cov = cov / (n - 1);
    
    printf("Covariance: %.2f\n", cov);
    
    corr = cov / (stddev * stddev);
    
    printf("Correlation: %.2f", corr);
    
    for(i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
    free(x);
    free(y);
    
    return 0;
}