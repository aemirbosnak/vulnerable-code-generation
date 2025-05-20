//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, num_perc;
    int **grid, i, j, count = 0;
    int top, bottom, left, right;

    srand(time(NULL));
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of perc: ");
    scanf("%d", &num_perc);

    grid = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }

    for (i = 0; i < num_perc; i++) {
        top = rand() % rows;
        left = rand() % cols;
        if (grid[top][left] == 0) {
            grid[top][left] = 1;
            count++;
        }
    }

    printf("Total number of percolating sites: %d\n", count);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}