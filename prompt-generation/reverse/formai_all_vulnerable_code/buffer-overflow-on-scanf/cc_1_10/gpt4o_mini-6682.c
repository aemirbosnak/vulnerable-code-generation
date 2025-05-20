//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define NUM_TREASURES 3
#define NUM_TRAPS 3

typedef struct {
    int x;
    int y;
} Player;

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void placeTreasuresAndTraps(char grid[GRID_SIZE][GRID_SIZE]);
void printGrid(char grid[GRID_SIZE][GRID_SIZE], Player players[], int playerTurn);
int isPositionOccupied(char grid[GRID_SIZE][GRID_SIZE], int x, int y);
int isTreasure(char grid[GRID_SIZE][GRID_SIZE], int x, int y);
void movePlayer(Player *player, char grid[GRID_SIZE][GRID_SIZE]);
int checkGameEnd(Player players[], int treasuresFound);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    Player players[2] = {{0, 0}, {0, 0}};
    int playerTurn = 0, treasuresFound = 0;

    srand(time(NULL));
    initializeGrid(grid);
    placeTreasuresAndTraps(grid);
    
    while (1) {
        printGrid(grid, players, playerTurn);

        printf("Player %d, enter your move (W/A/S/D): ", playerTurn + 1);
        movePlayer(&players[playerTurn], grid);

        if (isTreasure(grid, players[playerTurn].x, players[playerTurn].y)) {
            treasuresFound++;
            printf("Player %d found a treasure! Total treasures found: %d\n", playerTurn + 1, treasuresFound);
            if (checkGameEnd(players, treasuresFound)) {
                printf("Player %d wins the game!\n", playerTurn + 1);
                break;
            }
        }

        playerTurn = (playerTurn + 1) % 2; // Switch turn
    }
    
    return 0;
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void placeTreasuresAndTraps(char grid[GRID_SIZE][GRID_SIZE]) {
    int count = 0;

    while (count < NUM_TREASURES) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == '.') {
            grid[x][y] = 'T'; // 'T' for Treasure
            count++;
        }
    }

    count = 0;
    while (count < NUM_TRAPS) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == '.') {
            grid[x][y] = 'X'; // 'X' for Trap
            count++;
        }
    }
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE], Player players[], int playerTurn) {
    printf("\nGame Board:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int isPlayer1 = (i == players[0].x && j == players[0].y);
            int isPlayer2 = (i == players[1].x && j == players[1].y);
            if (isPlayer1)
                printf("P1 ");
            else if (isPlayer2)
                printf("P2 ");
            else
                printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int isPositionOccupied(char grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    return (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE || grid[x][y] == 'X');
}

int isTreasure(char grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    return grid[x][y] == 'T';
}

void movePlayer(Player *player, char grid[GRID_SIZE][GRID_SIZE]) {
    char move;
    while (1) {
        scanf(" %c", &move);
        int nextX = player->x, nextY = player->y;

        if (move == 'W') {
            nextX--;
        } else if (move == 'S') {
            nextX++;
        } else if (move == 'A') {
            nextY--;
        } else if (move == 'D') {
            nextY++;
        } else {
            printf("Invalid move! Use W/A/S/D to move.\n");
            continue;
        }

        if (!isPositionOccupied(grid, nextX, nextY)) {
            player->x = nextX;
            player->y = nextY;
            break;
        } else {
            printf("You can't move there! Try again.\n");
        }
    }
}

int checkGameEnd(Player players[], int treasuresFound) {
    return treasuresFound >= NUM_TREASURES;
}