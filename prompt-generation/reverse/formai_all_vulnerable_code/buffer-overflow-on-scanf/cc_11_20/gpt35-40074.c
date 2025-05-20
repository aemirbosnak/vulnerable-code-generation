//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>

int main() {
    int m, n, i, j, k;
    float matrix1[10][10], matrix2[10][10], result[10][10];

    printf("Enter the number of rows (m) and columns (n) of the matrices:\n");
    scanf("%d %d", &m, &n);

    /* Input for Matrix 1 */
    printf("\nEnter the elements of Matrix 1:\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%f", &matrix1[i][j]);
        }
    }

    /* Input for Matrix 2 */
    printf("\nEnter the elements of Matrix 2:\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%f", &matrix2[i][j]);
        }
    }

    /* Matrix addition */
    printf("\nAddition of the two matrices:\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    /* Matrix subtraction */
    printf("\nSubtraction of the two matrices:\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    /* Matrix multiplication */
    printf("\nMultiplication of the two matrices:\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            result[i][j] = 0;
            for(k=0; k<n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    /* Matrix division */
    printf("\nDivision of the two matrices:\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            result[i][j] = matrix1[i][j] / matrix2[i][j];
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}