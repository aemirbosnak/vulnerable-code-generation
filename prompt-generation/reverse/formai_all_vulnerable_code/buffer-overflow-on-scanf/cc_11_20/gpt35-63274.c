//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, choice, i, j;
    printf("Welcome to the Matrix Operations program!\n");
    printf("Enter number of rows for your matrix: ");
    scanf("%d", &rows);
    printf("Enter number of columns for your matrix: ");
    scanf("%d", &cols);
    int matrix[rows][cols], temp[rows][cols], scalar;
    printf("Enter elements of your matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Your Matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
            if (j == cols - 1)
                printf("\n");
        }
    }
    printf("\nWhat operation do you want to perform on your Matrix? (Enter number)\n");
    printf("1. Matrix Transpose\n");
    printf("2. Scalar Multiplication\n");
    printf("3. Gaussian Elimination (Too fancy? Try row reduction)\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Transpose of your matrix will be:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    temp[j][i] = matrix[i][j];
                }
            }
            for (i = 0; i < cols; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%d ", temp[i][j]);
                    if (j == rows - 1)
                        printf("\n");
                }
            }
            break;
        case 2:
            printf("Enter scalar value for multiplication: ");
            scanf("%d", &scalar);
            printf("After scalar multiplication, your matrix will be:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%d ", matrix[i][j] * scalar);
                    if (j == cols - 1)
                        printf("\n");
                }
            }
            break;
        case 3:
            printf("Sorry buddy, this operation is only available in the deluxe version of our program!\n");
            printf("Try row reduction instead.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
    return 0;
}