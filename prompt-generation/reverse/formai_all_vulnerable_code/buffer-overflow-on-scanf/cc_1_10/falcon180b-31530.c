//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRows, numCols, numPercolations;
    int **grid;
    int i, j, count = 0;
    int topRow, leftCol;

    srand(time(NULL));
    printf("Enter number of rows: ");
    scanf("%d", &numRows);
    printf("Enter number of columns: ");
    scanf("%d", &numCols);

    grid = (int **) malloc(numRows * sizeof(int *));
    for (i = 0; i < numRows; i++) {
        grid[i] = (int *) malloc(numCols * sizeof(int));
    }

    printf("Enter number of percolations: ");
    scanf("%d", &numPercolations);

    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < numPercolations; i++) {
        topRow = rand() % numRows;
        leftCol = rand() % numCols;

        if (grid[topRow][leftCol] == 1) {
            grid[topRow][leftCol] = -1;
            count++;
        }
    }

    printf("Total percolations: %d\n", count);

    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < numRows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}