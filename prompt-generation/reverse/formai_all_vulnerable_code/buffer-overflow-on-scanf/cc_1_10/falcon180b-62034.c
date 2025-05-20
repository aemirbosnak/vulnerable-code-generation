//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

int main()
{
    int i, j, n, m;
    double a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];

    // Prompt user to input the size of the matrices
    printf("Enter the size of the matrices (maximum %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Prompt user to input the matrices
    printf("Enter the first matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &a[i * n + j]);
        }
    }

    printf("Enter the second matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &b[i * n + j]);
        }
    }

    // Perform matrix addition
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i * n + j] = a[i * n + j] + b[i * n + j];
        }
    }

    // Print the result
    printf("The sum of the matrices is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%lf ", c[i * n + j]);
        }
        printf("\n");
    }

    return 0;
}