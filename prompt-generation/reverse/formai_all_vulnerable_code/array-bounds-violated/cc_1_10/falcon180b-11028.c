//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 40
#define DROP_RATE 0.5

int rows, cols, num_dropped, num_percolated;
int grid[MAX_ROWS][MAX_COLS];
int num_neighbors(int row, int col);

void init_grid() {
    srand(time(NULL));
    rows = rand() % MAX_ROWS + 2;
    cols = rand() % MAX_COLS + 2;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

int num_neighbors(int row, int col) {
    int count = 0;
    if (row > 0 && grid[row-1][col]) count++;
    if (col > 0 && grid[row][col-1]) count++;
    if (row < rows-1 && grid[row+1][col]) count++;
    if (col < cols-1 && grid[row][col+1]) count++;
    return count;
}

void drop() {
    int row, col;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                row = i;
                col = j;
                break;
            }
        }
    }
    grid[row][col] = 0;
    num_dropped++;
}

void percolate() {
    int row, col;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                row = i;
                col = j;
                break;
            }
        }
    }
    grid[row][col] = 0;
    num_percolated++;
}

int main() {
    init_grid();
    int drops = 0;
    while (num_percolated == 0) {
        print_grid();
        drop();
        drops++;
        if (drops == 100) break;
    }
    printf("Dropped %d drops\n", drops);
    printf("Percolated %d times\n", num_percolated);
    return 0;
}