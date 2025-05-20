//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, k;
    int **matrix1, **matrix2, **result;
    char choice;
    int sum = 0;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    matrix1 = (int **) malloc(rows * sizeof(int *));
    matrix2 = (int **) malloc(rows * sizeof(int *));
    result = (int **) malloc(rows * sizeof(int *));

    for (i = 0; i < rows; i++) {
        matrix1[i] = (int *) malloc(cols * sizeof(int));
        matrix2[i] = (int *) malloc(cols * sizeof(int));
        result[i] = (int *) malloc(cols * sizeof(int));
    }

    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Choose an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n");
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    sum = matrix1[i][j] + matrix2[i][j];
                    result[i][j] = sum;
                }
            }
            break;
        case '2':
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    sum = matrix1[i][j] - matrix2[i][j];
                    result[i][j] = sum;
                }
            }
            break;
        case '3':
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    sum = matrix1[i][j] * matrix2[i][j];
                    result[i][j] = sum;
                }
            }
            break;
        default:
            printf("Invalid choice!");
            break;
    }

    printf("Result:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}