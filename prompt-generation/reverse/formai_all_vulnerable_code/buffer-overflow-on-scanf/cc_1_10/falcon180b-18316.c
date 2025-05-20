//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 10

int main() {
    int i, j, k;
    double matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], result[SIZE][SIZE];
    clock_t start, end;
    double cpu_time_used;

    printf("Enter elements for first matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Enter elements for second matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    start = clock();
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Result of matrix multiplication:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    printf("CPU time used: %lf seconds\n", cpu_time_used);

    return 0;
}