//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define NUM_PLAYERS 2

typedef struct {
    int x;
    int y;
} Location;

typedef struct {
    char name[20];
    Location location;
} Player;

typedef struct {
    Player players[NUM_PLAYERS];
    int target_x;
    int target_y;
} GameState;

void printGrid(int grid[GRID_SIZE][GRID_SIZE], Player players[NUM_PLAYERS]) {
    printf("   ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%2d ", i);
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == players[0].location.y && j == players[0].location.x) {
                printf(" P1");
            } else if (i == players[1].location.y && j == players[1].location.x) {
                printf(" P2");
            } else if (j == GRID_SIZE-1 && i == GRID_SIZE-1) {
                printf(" EE");
            } else {
                printf("%3d", grid[i][j]);
            }
        }
        printf("\n");
    }
}

void initializeGame(GameState* gameState) {
    Player player1 = {"Player 1", {0, 0}};
    Player player2 = {"Player 2", {0, 0}};
    gameState->players[0] = player1;
    gameState->players[1] = player2;
    srand(time(NULL));
    gameState->target_x = rand() % GRID_SIZE;
    gameState->target_y = rand() % GRID_SIZE;
}

int main(void) {
    int grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 10;
        }
    }
    GameState gameState;
    initializeGame(&gameState);
    int currentPlayer = 0;
    printf("Player 1, you can start the game. Your target is at (%d,%d).\n", gameState.target_x, gameState.target_y);
    while (gameState.players[currentPlayer].location.x != gameState.target_x || gameState.players[currentPlayer].location.y != gameState.target_y) {
        printGrid(grid, gameState.players);
        printf("%s, it's your turn. Enter your move (x,y): ", gameState.players[currentPlayer].name);
        int x, y;
        scanf("%d,%d", &x, &y);
        if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
            gameState.players[currentPlayer].location.x = x;
            gameState.players[currentPlayer].location.y = y;
            currentPlayer = (currentPlayer + 1) % NUM_PLAYERS;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
    printf("%s wins!\n", gameState.players[currentPlayer].name);
    return 0;
}