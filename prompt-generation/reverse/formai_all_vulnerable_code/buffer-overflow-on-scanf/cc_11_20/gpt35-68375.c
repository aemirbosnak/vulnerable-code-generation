//FormAI DATASET v1.0 Category: Fractal Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// function to generate fractal pattern
void fractal(int rows, int columns)
{
    int size = 1;
    int i, j, k, l, m;

    while (size <= rows) {
        for (i = 0; i < columns; i += size * 2) {
            for (j = 0; j < rows; j += size * 2) {
                //creating an empty matrix
                int **matrix = (int **)malloc(size * sizeof(int *));
                for (k = 0; k < size; k++) {
                    matrix[k] = (int *)malloc(size * sizeof(int));
                }

                //filling the matrix with 1's
                for (k = 0; k < size; k++) {
                    for (l = 0; l < size; l++) {
                        matrix[k][l] = 1;
                    }
                }

                //printing the matrix in the predefined pattern
                for (k = 0; k < size; k++) {
                    for (l = 0; l < size; l++) {
                        if ((k == 0 && l == 0) || (k == size - 1 && l == size - 1)) {
                            printf("+");
                        } else if ((k == 0 && l == size - 1) || (k == size - 1 && l == 0)) {
                            printf("+");
                        } else if (k == l) {
                            printf("\\");
                        } else if (k + l == size - 1) {
                            printf("/");
                        } else {
                            printf("%c", matrix[k][l] ? ' ' : 'X');
                        }
                    }
                    printf("\n");
                }

                //freeing memory allocated to matrix
                for (m = 0; m < size; m++) {
                    free(matrix[m]);
                }
                free(matrix);
            }
        }
        size *= 2;
    }
}

// driver function
int main(void)
{
    int rows, columns;
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    fractal(rows, columns);

    return 0;
}