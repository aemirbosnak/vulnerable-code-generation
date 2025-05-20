//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void print_grid(int grid[][4], int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void update_grid(int grid[][4], int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k >= 0 && i + k < rows && j + l >= 0 && j + l < cols) {
                        neighbors++;
                    }
                }
            }
            if (grid[i][j] == 0) {
                if (neighbors == 3) {
                    grid[i][j] = 1;
                }
            } else if (neighbors < 2 || neighbors > 3) {
                grid[i][j] = 0;
            }
        }
    }
}

int main()
{
    int rows, cols, cell;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int grid[rows][cols];
    printf("Enter the grid:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &cell);
            grid[i][j] = cell;
        }
    }
    printf("Initial grid:\n");
    print_grid(grid, rows, cols);
    while (1) {
        printf("Press 1 to update the grid\n");
        scanf("%d", &cell);
        if (cell == 1) {
            update_grid(grid, rows, cols);
            printf("Updated grid:\n");
            print_grid(grid, rows, cols);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}