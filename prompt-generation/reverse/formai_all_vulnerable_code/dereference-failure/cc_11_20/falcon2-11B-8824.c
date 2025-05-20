//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define N 10

int main()
{
    int n, i, j, k;
    int *A, *B, *C;
    int *X, *Y, *Z;
    int *F;
    float sum, sum1, sum2, sum3, sum4;
    clock_t start, end;

    start = clock();

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    A = (int*)malloc(n * sizeof(int));
    B = (int*)malloc(n * sizeof(int));
    C = (int*)malloc(n * sizeof(int));
    X = (int*)malloc(n * sizeof(int));
    Y = (int*)malloc(n * sizeof(int));
    Z = (int*)malloc(n * sizeof(int));
    F = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
    {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
        C[i] = rand() % 100;
        X[i] = 0;
        Y[i] = 0;
        Z[i] = 0;
        F[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(A[i] == A[j] || B[i] == B[j] || C[i] == C[j])
            {
                X[i] += 1;
                X[j] += 1;
                Y[i] += 1;
                Y[j] += 1;
                Z[i] += 1;
                Z[j] += 1;
                F[i] += 1;
                F[j] += 1;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        sum = 0;
        sum1 = 0;
        sum2 = 0;
        sum3 = 0;
        sum4 = 0;
        for(j = 0; j < n; j++)
        {
            if(X[i] == X[j])
            {
                sum += A[i] * A[j];
                sum1 += B[i] * B[j];
                sum2 += C[i] * C[j];
                sum3 += X[i] * X[j];
                sum4 += Y[i] * Y[j];
            }
        }
        F[i] = (sum * sum) - (sum1 * sum1) - (sum2 * sum2) - (sum3 * sum3) + (sum4 * sum4);
    }

    for(i = 0; i < n; i++)
    {
        if(F[i] < 0)
        {
            printf("The cluster with the index %d is the center of the cluster.\n", i);
        }
    }

    end = clock();
    printf("Time taken by the program: %.2f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(A);
    free(B);
    free(C);
    free(X);
    free(Y);
    free(Z);
    free(F);

    return 0;
}