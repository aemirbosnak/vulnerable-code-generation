//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 30

int main() {
    int rows, cols;
    int **matrix;
    int i, j;

    //Initialize random seed
    srand(time(NULL));

    //Get user input for number of rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    //Create matrix with random integers
    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    //Print matrix in a surprised style
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 == 0) {
                printf(" %d ", matrix[i][j]);
            } else {
                printf(" %d!! ", matrix[i][j]);
            }
        }
        printf("\n");
    }

    //Free memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}