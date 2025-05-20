//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define MAX_TREASURES 3
#define MAX_TRAPS 2

typedef struct {
    int x;
    int y;
} Position;

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], Position treasures[], Position traps[], int *treasure_count, int *trap_count) {
    // Initialize the grid with empty spaces
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // Place treasures
    *treasure_count = 0;
    while (*treasure_count < MAX_TREASURES) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == '.') {
            grid[x][y] = 'T'; // T for Treasure
            treasures[*treasure_count].x = x;
            treasures[*treasure_count].y = y;
            (*treasure_count)++;
        }
    }

    // Place traps
    *trap_count = 0;
    while (*trap_count < MAX_TRAPS) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == '.') {
            grid[x][y] = 'X'; // X for Trap
            traps[*trap_count].x = x;
            traps[*trap_count].y = y;
            (*trap_count)++;
        }
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    printf("Current Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

Position getPlayerMove() {
    Position move;
    printf("Enter your move (row and column): ");
    scanf("%d %d", &move.x, &move.y);
    move.x--; // Convert to 0-based index
    move.y--; // Convert to 0-based index
    return move;
}

int isValidMove(Position move) {
    return move.x >= 0 && move.x < GRID_SIZE && move.y >= 0 && move.y < GRID_SIZE;
}

void playGame() {
    char grid[GRID_SIZE][GRID_SIZE];
    Position treasures[MAX_TREASURES];
    Position traps[MAX_TRAPS];
    int treasure_count, trap_count;
    int collected_treasures = 0;

    srand(time(NULL));
    initializeGrid(grid, treasures, traps, &treasure_count, &trap_count);

    while (1) {
        displayGrid(grid);
        Position move = getPlayerMove();

        if (!isValidMove(move)) {
            printf("Invalid move! Please try again.\n");
            continue;
        }

        if (grid[move.x][move.y] == 'T') {
            collected_treasures++;
            grid[move.x][move.y] = 'C'; // C for Collected
            printf("You found a treasure! Total treasures collected: %d\n", collected_treasures);
        } else if (grid[move.x][move.y] == 'X') {
            printf("You fell into a trap! Game over.\n");
            break;
        } else if (grid[move.x][move.y] == 'C') {
            printf("You've already collected this treasure!\n");
        } else {
            printf("Nothing here. Try again.\n");
        }

        if (collected_treasures == MAX_TREASURES) {
            printf("You've collected all treasures! You win!\n");
            break;
        }
    }
}

int main() {
    printf("Welcome to Treasure Hunt!\n");
    playGame();
    return 0;
}