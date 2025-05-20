//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ALIVE 1
#define DEAD 0

typedef struct {
    int width;
    int height;
    int **grid;
} GameOfLife;

void initializeGrid(GameOfLife *game);
void printGrid(GameOfLife *game);
void updateGrid(GameOfLife *game);
int countNeighbors(GameOfLife *game, int x, int y);
void freeGrid(GameOfLife *game);

int main() {
    GameOfLife game;
    printf("Enter the width of the grid: ");
    scanf("%d", &game.width);
    printf("Enter the height of the grid: ");
    scanf("%d", &game.height);
    
    // Validate dimensions
    if (game.width <= 0 || game.height <= 0) {
        fprintf(stderr, "Invalid grid dimensions.\n");
        return 1;
    }

    // Allocate memory for grid
    game.grid = (int **)malloc(game.height * sizeof(int *));
    for (int i = 0; i < game.height; i++) {
        game.grid[i] = (int *)malloc(game.width * sizeof(int));
    }

    initializeGrid(&game);
    
    // Main loop
    char command;
    while (1) {
        printGrid(&game);
        printf("Press 'n' for next generation, 'q' to quit: ");
        scanf(" %c", &command);

        if (command == 'n') {
            updateGrid(&game);
        } else if (command == 'q') {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }

        usleep(200000); // Sleep for 200 ms for better visualization
    }

    freeGrid(&game);
    return 0;
}

void initializeGrid(GameOfLife *game) {
    memset(game->grid[0], 0, game->width * game->height * sizeof(int)); // clear the grid
    // Example initial configuration (Glider)
    game->grid[1][2] = ALIVE;
    game->grid[2][3] = ALIVE;
    game->grid[3][1] = ALIVE;
    game->grid[3][2] = ALIVE;
    game->grid[3][3] = ALIVE;
}

void printGrid(GameOfLife *game) {
    system("clear"); // Clear console for better visualization
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width; j++) {
            if (game->grid[i][j] == ALIVE) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void updateGrid(GameOfLife *game) {
    int **newGrid = (int **)malloc(game->height * sizeof(int *));
    for (int i = 0; i < game->height; i++) {
        newGrid[i] = (int *)malloc(game->width * sizeof(int));
        memset(newGrid[i], 0, game->width * sizeof(int)); // clear the new grid
    }

    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width; j++) {
            int neighbors = countNeighbors(game, i, j);
            if (game->grid[i][j] == ALIVE) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = DEAD; // Cell dies
                } else {
                    newGrid[i][j] = ALIVE; // Cell lives
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = ALIVE; // Cell becomes alive
                }
            }
        }
    }

    // Swap grids
    for (int i = 0; i < game->height; i++) {
        free(game->grid[i]);
        game->grid[i] = newGrid[i];
    }
    free(newGrid);
}

int countNeighbors(GameOfLife *game, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int neighborX = x + i;
            int neighborY = y + j;

            if (neighborX >= 0 && neighborX < game->height && neighborY >= 0 && neighborY < game->width) {
                count += game->grid[neighborX][neighborY];
            }
        }
    }
    return count;
}

void freeGrid(GameOfLife *game) {
    for (int i = 0; i < game->height; i++) {
        free(game->grid[i]);
    }
    free(game->grid);
}