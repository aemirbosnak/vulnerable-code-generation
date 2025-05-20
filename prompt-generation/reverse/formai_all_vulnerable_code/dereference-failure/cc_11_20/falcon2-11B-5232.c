//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 20
#define COLS 20
#define BLOCK_SIZE 10

int main() {
    srand(time(NULL));
    
    int **grid = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        grid[i] = (int *)malloc(COLS * sizeof(int));
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    
    int total_open_cells = 0;
    int open_cells_in_row[ROWS];
    int open_cells_in_col[COLS];
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                total_open_cells++;
                open_cells_in_row[i]++;
                open_cells_in_col[j]++;
            }
        }
    }
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                int open_neighbors = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y] == 1) {
                            open_neighbors++;
                        }
                    }
                }
                if (open_neighbors == 1 || open_neighbors == 2) {
                    grid[i][j] = 1;
                    total_open_cells++;
                    open_cells_in_row[i]++;
                    open_cells_in_col[j]++;
                }
            }
        }
    }
    
    printf("Total open cells: %d\n", total_open_cells);
    printf("Open cells in row 0: %d\n", open_cells_in_row[0]);
    printf("Open cells in col 0: %d\n", open_cells_in_col[0]);
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    free(grid);
    
    return 0;
}