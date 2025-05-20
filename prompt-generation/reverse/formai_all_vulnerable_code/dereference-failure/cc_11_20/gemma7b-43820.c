//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 5
#define SYMBOLS_PER_ROW 5

int main() {
    // Memory Game Grid
    int **grid = (int**)malloc(GRID_SIZE * sizeof(int*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (int*)malloc(SYMBOLS_PER_ROW * sizeof(int));
    }

    // Initialize the Grid
    for (int r = 0; r < GRID_SIZE; r++) {
        for (int c = 0; c < SYMBOLS_PER_ROW; c++) {
            grid[r][c] = 0;
        }
    }

    // Place Symbols
    grid[2][2] = 1;
    grid[3][3] = 2;
    grid[0][0] = 3;

    // Game Loop
    int game_state = 0;
    while (!game_state) {
        // Get User Input
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);

        // Validate Input
        if (row < 0 || row >= GRID_SIZE) {
            printf("Invalid row.\n");
        } else if (column < 0 || column >= SYMBOLS_PER_ROW) {
            printf("Invalid column.\n");
        } else if (grid[row][column] != 0) {
            printf("Position already occupied.\n");
        } else {
            // Place Symbol
            grid[row][column] = 4;

            // Check Game State
            game_state = check_game_state(grid);
        }
    }

    // Game Over
    printf("Game Over!\n");

    // Free Memory
    for (int i = 0; i < GRID_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

int check_game_state(int **grid) {
    // Check Rows
    for (int r = 0; r < GRID_SIZE; r++) {
        if (grid[r][0] == grid[r][1] && grid[r][0] == grid[r][2] && grid[r][0] == grid[r][3] && grid[r][0] == grid[r][4]) {
            return 1;
        }
    }

    // Check Columns
    for (int c = 0; c < SYMBOLS_PER_ROW; c++) {
        if (grid[0][c] == grid[1][c] && grid[0][c] == grid[2][c] && grid[0][c] == grid[3][c] && grid[0][c] == grid[4][c]) {
            return 1;
        }
    }

    // Check Diagonals
    if (grid[0][0] == grid[2][2] && grid[0][0] == grid[4][4]) {
        return 1;
    } else if (grid[0][4] == grid[2][2] && grid[0][4] == grid[4][0]) {
        return 1;
    }

    // No winner
    return 0;
}