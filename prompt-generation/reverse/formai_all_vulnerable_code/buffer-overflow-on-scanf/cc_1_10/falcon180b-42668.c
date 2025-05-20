//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, c = 0;
    float a[100][100], b[100][100], sum[100][100];
    clock_t start, end;

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix A:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%f", &b[i][j]);
        }
    }

    start = clock();

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            sum[i][j] = 0;
            for(c=0; c<n; c++) {
                sum[i][j] += a[i][c] * b[c][j];
            }
        }
    }

    end = clock();
    double time_spent = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sum of the matrices is:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%f ", sum[i][j]);
        }
        printf("\n");
    }

    printf("Time taken: %lf seconds\n", time_spent);

    return 0;
}