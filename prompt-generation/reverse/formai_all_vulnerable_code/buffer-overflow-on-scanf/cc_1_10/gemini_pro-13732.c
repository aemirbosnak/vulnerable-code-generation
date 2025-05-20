//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

// Create a new grid of size rows x cols
int** create_grid(int rows, int cols) {
    int **grid = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(sizeof(int) * cols);
    }
    return grid;
}

// Free the grid
void free_grid(int **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Initialize the grid with random values
void init_grid(int **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Print the grid
void print_grid(int **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Count the number of live neighbors of a cell
int count_neighbors(int **grid, int x, int y, int rows, int cols) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                count += grid[i][j];
            }
        }
    }
    return count - grid[x][y];  // Subtract the cell itself
}

// Update the grid to the next generation
void update_grid(int **grid, int rows, int cols) {
    int **new_grid = create_grid(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = count_neighbors(grid, i, j, rows, cols);
            if (neighbors == 3 || (grid[i][j] && neighbors == 2)) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }

    free_grid(grid, rows);
    grid = new_grid;
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **grid = create_grid(rows, cols);
    init_grid(grid, rows, cols);

    printf("Initial grid:\n");
    print_grid(grid, rows, cols);

    printf("Press any key to update the grid...\n");
    getchar();

    for (int i = 0; i < 10; i++) {
        update_grid(grid, rows, cols);
    }

    printf("Grid after 10 generations:\n");
    print_grid(grid, rows, cols);

    free_grid(grid, rows);

    return 0;
}