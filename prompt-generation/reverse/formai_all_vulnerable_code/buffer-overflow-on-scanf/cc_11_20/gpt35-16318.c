//FormAI DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // We will start with painting a canvas first.
    // This canvas will have a shape of matrix.
    int n, m;
    printf("Enter the number of rows and columns for the canvas: ");
    scanf("%d %d", &n, &m);

    // Initializing the random seed for generating random colors
    srand(time(NULL));

    // Creating the canvas
    int **canvas = (int **) calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        canvas[i] = (int *) calloc(m, sizeof(int));
    }

    // Let's fill the canvas with some random colors now
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            canvas[i][j] = rand() % 256;
        }
    }

    printf("\nMatrix canvas, created with surrealistic colors:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", canvas[i][j]);
        }
        printf("\n");
    }

    // Now, we will perform some matrix operations on this canvas
    printf("\nPerforming surrealistic matrix operations on the canvas...\n");
    printf("Please close your eyes and imagine the effects!\n");

    // Operation 1: Multiply each element of the matrix by its row number
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            canvas[i][j] *= i;
        }
    }

    // Operation 2: Add random values to the diagonal elements
    for (int i = 0; i < n && i < m; i++) {
        canvas[i][i] += rand() % 101;
    }

    // Operation 3: Transpose the matrix
    int **transposed = (int **) calloc(m, sizeof(int *));
    for (int i = 0; i < m; i++) {
        transposed[i] = (int *) calloc(n, sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transposed[j][i] = canvas[i][j];
        }
    }

    // Let's see the effects of these operations on the canvas
    printf("\nSurrealistic masterpiece after matrix operations:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }

    // Freeing up the memory allocated for the matrices
    for (int i = 0; i < n; i++) {
        free(canvas[i]);
    }
    free(canvas);

    for (int i = 0; i < m; i++) {
        free(transposed[i]);
    }
    free(transposed);

    return 0;
}