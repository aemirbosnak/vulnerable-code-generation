//GPT-4o-mini DATASET v1.0 Category: Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 5
#define TREASURE 'T'
#define TRAP 'X'
#define EMPTY ' '

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void placeItems(char grid[GRID_SIZE][GRID_SIZE], int count, char item);
void printGrid(char grid[GRID_SIZE][GRID_SIZE], bool reveal);
bool makeMove(char grid[GRID_SIZE][GRID_SIZE], int *x, int *y);
bool checkGameOver(char grid[GRID_SIZE][GRID_SIZE], int x, int y, int treasuresFound);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    int x = 0, y = 0;  // Starting position
    bool gameOver = false;
    int treasuresFound = 0;

    srand(time(NULL));
    initializeGrid(grid);
    placeItems(grid, 3, TREASURE); // 3 treasures
    placeItems(grid, 3, TRAP);      // 3 traps

    printf("Welcome to Treasure Hunt Adventure!\n");
    printGrid(grid, false);

    while (!gameOver) {
        if (makeMove(grid, &x, &y)) {
            if (grid[x][y] == TREASURE) {
                treasuresFound++;
                printf("You found a treasure! Total treasures found: %d\n", treasuresFound);
                grid[x][y] = EMPTY; // Remove treasure from the grid
            } else if (grid[x][y] == TRAP) {
                printf("Oh no! You fell into a trap! Game Over.\n");
                gameOver = true;
            } else {
                printf("You moved to an empty space.\n");
            }
            gameOver = checkGameOver(grid, x, y, treasuresFound);
            if (!gameOver) {
                printGrid(grid, false);
            }
        }
    }

    printf("Game Over! You found %d treasures. Thanks for playing!\n", treasuresFound);
    return 0;
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
}

void placeItems(char grid[GRID_SIZE][GRID_SIZE], int count, char item) {
    while (count > 0) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;

        if (grid[x][y] == EMPTY) {
            grid[x][y] = item;
            count--;
        }
    }
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE], bool reveal) {
    printf("\nGrid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (reveal || grid[i][j] == EMPTY) {
                printf("[%c] ", grid[i][j]);
            } else {
                printf("[ ] "); // Show empty spaces only if not revealing
            }
        }
        printf("\n");
    }
}

bool makeMove(char grid[GRID_SIZE][GRID_SIZE], int *x, int *y) {
    char direction;
    printf("Choose your move (W/A/S/D for up/left/down/right): ");
    scanf(" %c", &direction);

    switch (direction) {
        case 'W':
        case 'w':
            if (*x > 0) (*x)--;
            else printf("You can't move up!\n");
            break;
        case 'A':
        case 'a':
            if (*y > 0) (*y)--;
            else printf("You can't move left!\n");
            break;
        case 'S':
        case 's':
            if (*x < GRID_SIZE - 1) (*x)++;
            else printf("You can't move down!\n");
            break;
        case 'D':
        case 'd':
            if (*y < GRID_SIZE - 1) (*y)++;
            else printf("You can't move right!\n");
            break;
        default:
            printf("Invalid move! Please use W/A/S/D.\n");
            return false;
    }
    return true;
}

bool checkGameOver(char grid[GRID_SIZE][GRID_SIZE], int x, int y, int treasuresFound) {
    if (treasuresFound >= 3) {
        printf("Congratulations! You found all the treasures! You Win!\n");
        return true;
    }
    return false;
}