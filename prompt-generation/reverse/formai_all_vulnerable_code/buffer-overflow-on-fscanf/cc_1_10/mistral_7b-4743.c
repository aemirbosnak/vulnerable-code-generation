//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_GRID_SIZE 100

typedef struct {
    int x, y;
} point;

bool is_valid_move(int grid[MAX_GRID_SIZE][MAX_GRID_SIZE], int curr_x, int curr_y, int grid_size) {
    if (curr_x < 0 || curr_x >= grid_size || curr_y < 0 || curr_y >= grid_size)
        return false;
    if (grid[curr_x][curr_y] == -1)
        return false;
    return true;
}

void dfs(int grid[MAX_GRID_SIZE][MAX_GRID_SIZE], int curr_x, int curr_y, int grid_size) {
    grid[curr_x][curr_y] = -1;

    int dx[4] = {-1, 1, 1, -1};
    int dy[4] = {-1, -1, 1, 1};

    for (int i = 0; i < 4; ++i) {
        int new_x = curr_x + dx[i];
        int new_y = curr_y + dy[i];

        if (is_valid_move(grid, new_x, new_y, grid_size)) {
            dfs(grid, new_x, new_y, grid_size);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int grid_size;
    fscanf(file, "%d", &grid_size);

    int grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
    for (int i = 0; i < grid_size; ++i)
        for (int j = 0; j < grid_size; ++j)
            grid[i][j] = 0;

    int x, y;
    while (fscanf(file, "%d%d", &x, &y) == 2) {
        if (!is_valid_move(grid, x, y, grid_size)) {
            fprintf(stderr, "Invalid move: %d, %d\n", x, y);
            fclose(file);
            return 1;
        }
        grid[x][y] = 1;
    }

    fclose(file);

    bool percolated = false;
    for (int i = 0; i < grid_size; ++i) {
        if (grid[i][0] == 1) {
            dfs(grid, i, 0, grid_size);
            percolated = true;
            break;
        }
    }

    printf(percolated ? "Percolation occurs.\n" : "Percolation does not occur.\n");

    return 0;
}