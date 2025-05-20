//FormAI DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, op;
    printf("Enter the number of rows in matrix: ");
    scanf("%d", &m);
    printf("Enter the number of columns in matrix: ");
    scanf("%d", &n);

    // Allocate memory for matrix
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    // Input matrix elements
    printf("Enter matrix elements:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the matrix
    printf("The matrix you have entered is:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Perform matrix operations
    printf("\nEnter matrix operation to perform:\n");
    printf("1. Transpose\n2. Find maximum element\n3. Find minimum element\n");
    scanf("%d", &op);

    switch(op) {
        case 1:
            printf("\nThe transpose of matrix is:\n");
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    printf("%d ", matrix[j][i]);
                }
                printf("\n");
            }
            break;
        case 2:
            {
                int max = matrix[0][0];
                for(int i=0; i<m; i++) {
                    for(int j=0; j<n; j++) {
                        if(matrix[i][j] > max) {
                            max = matrix[i][j];
                        }
                    }
                }
                printf("\nThe maximum element of matrix is: %d\n", max);
            }
            break;
        case 3:
            {
                int min = matrix[0][0];
                for(int i=0; i<m; i++) {
                    for(int j=0; j<n; j++) {
                        if(matrix[i][j] < min) {
                            min = matrix[i][j];
                        }
                    }
                }
                printf("\nThe minimum element of matrix is: %d\n", min);
            }
            break;
        default:
            printf("\nInvalid operation entered!\n");
            break;
    }

    // Free memory allocated for matrix
    for (int i = 0; i < m; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}