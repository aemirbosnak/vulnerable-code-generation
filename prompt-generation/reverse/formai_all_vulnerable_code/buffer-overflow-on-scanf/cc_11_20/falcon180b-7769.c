//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int n, i, j, k;
    double a[10][10], b[10][10], c[10][10], det;

    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix A:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (i == k) {
                    det += pow(-1, i + j) * a[i][k] * c[k][j];
                } else {
                    det += a[i][k] * c[k][j];
                }
            }
        }
    }

    printf("The determinant of the sum of matrices is: %lf\n", det);

    return 0;
}