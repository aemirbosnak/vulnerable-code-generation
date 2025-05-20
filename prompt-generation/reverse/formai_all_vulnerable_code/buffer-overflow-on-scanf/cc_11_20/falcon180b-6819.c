//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k;
    double a[100][100], b[100][100], c[100][100], sum = 0;
    clock_t start, end;
    double cpu_time_used;
    srand(time(0));

    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            a[i][j] = rand() % 100;
            b[i][j] = rand() % 100;
            c[i][j] = 0;
        }
    }

    start = clock();
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nMatrix A:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    printf("\nMultiplication of matrices:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    printf("\nTime taken by CPU: %lf seconds\n", cpu_time_used);

    return 0;
}