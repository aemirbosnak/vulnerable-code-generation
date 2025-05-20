//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 5
#define NUM_TREASURES 3
#define NUM_TRAPS 2

// Function prototypes
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void placeItems(char grid[GRID_SIZE][GRID_SIZE], char symbol, int count);
void displayGrid(char grid[GRID_SIZE][GRID_SIZE], bool reveal);
bool makeMove(char grid[GRID_SIZE][GRID_SIZE], int *playerRow, int *playerCol);
bool checkGameStatus(char grid[GRID_SIZE][GRID_SIZE]);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    int playerRow = 0, playerCol = 0;
    char command;
    bool gameWon = false;

    initializeGrid(grid);
    printf("Welcome to Treasure Hunt!\n");
    printf("You have %d treasures to find and avoid %d traps!\n", NUM_TREASURES, NUM_TRAPS);

    while (!gameWon) {
        displayGrid(grid, false);
        printf("Your move (W/A/S/D to move): ");
        scanf(" %c", &command);

        bool validMove = makeMove(grid, &playerRow, &playerCol);

        if (!validMove) {
            printf("Invalid move! Out of bounds.\n");
            continue;
        }

        if (grid[playerRow][playerCol] == 'T') {
            printf("Congratulations! You've found a treasure!\n");
            grid[playerRow][playerCol] = '.';
        } else if (grid[playerRow][playerCol] == 'X') {
            printf("Oh no! You've fallen into a trap!\n");
            displayGrid(grid, true);
            break;
        }

        gameWon = checkGameStatus(grid);
    }

    if (gameWon) {
        printf("You found all treasures! You win!\n");
    } else {
        printf("Game Over! Better luck next time!\n");
    }

    return 0;
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
    placeItems(grid, 'T', NUM_TREASURES);
    placeItems(grid, 'X', NUM_TRAPS);
}

void placeItems(char grid[GRID_SIZE][GRID_SIZE], char symbol, int count) {
    srand(time(NULL));
    for (int i = 0; i < count; ) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        if (grid[row][col] == '.') {
            grid[row][col] = symbol;
            i++;
        }
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE], bool reveal) {
    printf("Current Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (reveal || (grid[i][j] == '.' && !(i == 0 && j == 0))) {
                printf("%c ", grid[i][j]);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

bool makeMove(char grid[GRID_SIZE][GRID_SIZE], int *playerRow, int *playerCol) {
    char direction;
    int newRow = *playerRow, newCol = *playerCol;

    switch (direction) {
        case 'W':
        case 'w':
            newRow--;
            break;
        case 'A':
        case 'a':
            newCol--;
            break;
        case 'S':
        case 's':
            newRow++;
            break;
        case 'D':
        case 'd':
            newCol++;
            break;
        default:
            return false;
    }

    if (newRow < 0 || newRow >= GRID_SIZE || newCol < 0 || newCol >= GRID_SIZE) {
        return false;
    }

    *playerRow = newRow;
    *playerCol = newCol;
    return true;
}

bool checkGameStatus(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'T') {
                return false;
            }
        }
    }
    return true;
}