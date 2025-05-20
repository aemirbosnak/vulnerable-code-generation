//FormAI DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>

int main() {

    int row, col, i, j; // declare variables

    printf("Enter number of rows: ");
    scanf("%d", &row); // get matrix dimensions

    printf("Enter number of columns: ");
    scanf("%d", &col);

    float matrix1[row][col], matrix2[row][col], result[row][col]; // create arrays

    printf("Enter elements of 1st matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%f", &matrix1[i][j]); // read in 1st matrix elements
        }
    }

    printf("Enter elements of 2nd matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%f", &matrix2[i][j]); // read in 2nd matrix elements
        }
    }

    char operation;
    printf("Enter the arithmetic operation (+, -, *, /): ");
    scanf(" %c", &operation); // get operation to be performed

    switch (operation) {
        case '+': // addition
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j]; // add elements at a given position in each array
                }
            }
            break;
        case '-': // subtraction
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    result[i][j] = matrix1[i][j] - matrix2[i][j]; // subtract elements at a given position in each array
                }
            }
            break;
        case '*': // multiplication
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    result[i][j] = matrix1[i][j] * matrix2[i][j]; // multiply elements at a given position in each array
                }
            }
            break;
        case '/': // division
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    result[i][j] = matrix1[i][j] / matrix2[i][j]; // divide elements at a given position in each array
                }
            }
            break;
        default:
            printf("Invalid operation."); // handle invalid input
            return 0;
    }

    printf("Resultant matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%.2f ", result[i][j]); // print elements of resulting array
        }
        printf("\n");
    }

    return 0; // end program
}