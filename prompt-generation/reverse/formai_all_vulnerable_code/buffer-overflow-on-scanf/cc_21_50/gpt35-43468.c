//FormAI DATASET v1.0 Category: Matrix operations ; Style: relaxed
/*
 * This program demonstrates some matrix operations in C language.
 * It allows the user to define two matrices and performs addition, subtraction,
 * multiplication, and transpose operations on them. 
 * The program also displays the result of each operation.
 * Enjoy!
 */

#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10

int main()
{
    int a[MAX_ROWS][MAX_COLS], b[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rows, cols, i, j, choice;

    // User enters size of matrices
    printf("Enter size of matrices (rows columns): ");
    scanf("%d %d", &rows, &cols);

    // User enters values for matrix A
    printf("\nEnter matrix A:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // User enters values for matrix B
    printf("\nEnter matrix B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Display menu
    printf("\n Menu");
    printf("\n 1. Add matrices");
    printf("\n 2. Subtract matrices");
    printf("\n 3. Multiply matrices");
    printf("\n 4. Transpose of matrix A");
    printf("\n 5. Transpose of matrix B");
    printf("\n Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Add matrices A and B
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    result[i][j] = a[i][j] + b[i][j];
                }
            }
            // Display result
            printf("\nResult of addition:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            // Subtract matrix B from A
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    result[i][j] = a[i][j] - b[i][j];
                }
            }
            // Display result
            printf("\nResult of subtraction:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;
        case 3:
            // Multiply matrices A and B
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    result[i][j] = 0;
                    for(int k=0;k<cols;k++){
                        result[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            // Display result
            printf("\nResult of multiplication:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;
        case 4:
            // Transpose of matrix A
            printf("\nTranspose of matrix A:\n");
            for (i = 0; i < cols; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%d ", a[j][i]);
                }
                printf("\n");
            }
            break;
        case 5:
            // Transpose of matrix B
            printf("\nTranspose of matrix B:\n");
            for (i = 0; i < cols; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%d ", b[j][i]);
                }
                printf("\n");
            }
            break;
        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}