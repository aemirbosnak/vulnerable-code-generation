//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Cell;

void init(Cell **grid, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            grid[i][j].x = 0;
            grid[i][j].y = 0;
        }
    }
}

void print_grid(Cell **grid, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            printf("%d ", grid[i][j].x);
        }
        printf("\n");
    }
}

void percolate(Cell **grid, int rows, int cols) {
    int i, j, k, count = 0;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            if (grid[i][j].x == 1) {
                count = 0;
                for (k = -1; k <= 1; ++k) {
                    if (i + k >= 0 && i + k < rows && grid[i + k][j].x == 1) {
                        grid[i + k][j].y = 1;
                        ++count;
                    }
                }
                for (k = -1; k <= 1; ++k) {
                    if (j + k >= 0 && j + k < cols && grid[i][j + k].x == 1) {
                        grid[i][j + k].y = 1;
                        ++count;
                    }
                }
                if (count == 0) {
                    grid[i][j].y = 1;
                }
            }
        }
    }
}

void fill_random(Cell **grid, int rows, int cols) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            grid[i][j].x = rand() % 2;
        }
    }
}

int main() {
    int rows, cols, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    Cell **grid = (Cell **)malloc(rows * sizeof(Cell *));
    for (i = 0; i < rows; ++i) {
        grid[i] = (Cell *)malloc(cols * sizeof(Cell));
    }

    init(grid, rows, cols);
    fill_random(grid, rows, cols);

    for (i = 0; i < 10; ++i) {
        percolate(grid, rows, cols);
        print_grid(grid, rows, cols);
        printf("\n");
    }

    for (i = 0; i < rows; ++i) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}