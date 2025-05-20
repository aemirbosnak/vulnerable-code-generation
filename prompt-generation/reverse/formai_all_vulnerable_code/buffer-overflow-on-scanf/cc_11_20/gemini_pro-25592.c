//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, j, k, l;
    double a[100][100], b[100][100], c[100][100], d[100][100];

    printf("Enter the order of the matrices:\n");
    scanf("%d", &n);

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    // Multiply the two matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Find the determinant of the resulting matrix
    double det = 0;
    for (i = 0; i < n; i++) {
        det += c[i][i];
    }

    // Find the inverse of the resulting matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            d[i][j] = 0;
            for (k = 0; k < n; k++) {
                d[i][j] += c[i][k] * c[k][j];
            }
            d[i][j] /= det;
        }
    }

    // Print the resulting matrix
    printf("The resulting matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", c[i][j]);
        }
        printf("\n");
    }

    // Print the determinant of the resulting matrix
    printf("The determinant of the resulting matrix is: %lf\n", det);

    // Print the inverse of the resulting matrix
    printf("The inverse of the resulting matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", d[i][j]);
        }
        printf("\n");
    }

    return 0;
}