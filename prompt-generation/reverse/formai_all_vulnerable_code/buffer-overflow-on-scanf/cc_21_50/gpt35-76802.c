//FormAI DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, columns, i, j, choice;

    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &columns);

    int matrix[rows][columns];

    printf("Enter the elements of the matrix:\n");

    // Inputting the matrix elements
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nSelect the operation to be performed:\n");
    printf("1. Transpose of the matrix\n");
    printf("2. Summation of the matrix\n");
    printf("3. Product of the matrix\n");
    printf("4. Exit\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: {
                int transpose[columns][rows];

                // Transposing the matrix
                for(i = 0; i < rows; ++i) {
                    for(j = 0; j < columns; ++j) {
                        transpose[j][i] = matrix[i][j];
                    }
                }

                printf("\nTranspose of matrix:\n");

                // Displaying the transposed matrix
                for(i = 0; i < columns; ++i) {
                    for(j = 0; j < rows; ++j)
                        printf("%d ",transpose[i][j]);

                    printf("\n");
                }

                break;
            }

            case 2: {
                int sum = 0;

                // Calculating the sum of the elements of the matrix
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < columns; j++) {
                        sum += matrix[i][j];
                    }
                }

                printf("\nSum of the matrix elements is: %d\n", sum);
                break;
            }

            case 3: {
                int second_rows, second_columns;

                printf("\nEnter the number of rows and columns for the second matrix: ");
                scanf("%d %d", &second_rows, &second_columns);

                if (columns != second_rows) {
                    printf("\nMatrix multiplication is not possible!\n");
                    break;
                }

                int second_matrix[second_rows][second_columns], product_matrix[rows][second_columns];

                printf("\nEnter the elements of the second matrix:\n");

                // Inputting the elements of the second matrix
                for (i = 0; i < second_rows; i++) {
                    for (j = 0; j < second_columns; j++) {
                        scanf("%d", &second_matrix[i][j]);
                    }
                }

                // Creating the product matrix
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < second_columns; j++) {
                        product_matrix[i][j] = 0;

                        for (int k = 0; k < columns; k++) {
                            product_matrix[i][j] += matrix[i][k] * second_matrix[k][j];
                        }
                    }
                }

                printf("\nProduct of matrices:\n");

                // Displaying the product matrix
                for (i = 0; i < rows; ++i) {
                    for (j = 0; j < second_columns; ++j) {
                        printf("%d ", product_matrix[i][j]);
                    }

                    printf("\n");
                }

                break;
            }

            case 4:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}