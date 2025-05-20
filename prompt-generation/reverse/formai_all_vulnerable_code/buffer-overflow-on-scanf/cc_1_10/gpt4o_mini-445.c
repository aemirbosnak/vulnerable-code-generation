//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define MAX_MONSTERS 3
#define TREASURE 'T'
#define MONSTER 'M'
#define EMPTY ' '
#define PLAYER 'P'

// Structure to keep track of player position
typedef struct {
    int x;
    int y;
} Player;

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], Player *player);
void displayGrid(char grid[GRID_SIZE][GRID_SIZE], Player player);
void movePlayer(char grid[GRID_SIZE][GRID_SIZE], Player *player, char direction);
int checkMonsterEncounter(char grid[GRID_SIZE][GRID_SIZE], Player player);
void placeTreasure(char grid[GRID_SIZE][GRID_SIZE]);
void placeMonsters(char grid[GRID_SIZE][GRID_SIZE]);
int isGameOver(char grid[GRID_SIZE][GRID_SIZE], Player player);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    Player player = {0, 0};
    char move;
    int gameOver = 0;

    srand(time(NULL));  // Seed for random number generation
    initializeGrid(grid, &player);
    
    while (!gameOver) {
        displayGrid(grid, player);
        printf("Move (W/A/S/D to move, Q to quit): ");
        scanf(" %c", &move);
        
        if (move == 'Q' || move == 'q') {
            printf("Thanks for playing!\n");
            break;
        }
        
        movePlayer(grid, &player, move);
        gameOver = isGameOver(grid, player);
    }
    
    if (gameOver) {
        printf("Game Over! You encountered a monster!\n");
    }

    return 0;
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], Player *player) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
    grid[player->x][player->y] = PLAYER;
    placeTreasure(grid);
    placeMonsters(grid);
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE], Player player) {
    printf("\nGame Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == player.x && j == player.y) {
                printf("%c ", PLAYER);
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

void movePlayer(char grid[GRID_SIZE][GRID_SIZE], Player *player, char direction) {
    grid[player->x][player->y] = EMPTY; // Clear current position
    if (direction == 'W' || direction == 'w') {
        if (player->x > 0) player->x--;
    } else if (direction == 'S' || direction == 's') {
        if (player->x < GRID_SIZE - 1) player->x++;
    } else if (direction == 'A' || direction == 'a') {
        if (player->y > 0) player->y--;
    } else if (direction == 'D' || direction == 'd') {
        if (player->y < GRID_SIZE - 1) player->y++;
    }
    if (grid[player->x][player->y] == TREASURE) {
        printf("Congratulations! You found the treasure!\n");
        exit(0);
    }
    grid[player->x][player->y] = PLAYER; // Update position
}

int checkMonsterEncounter(char grid[GRID_SIZE][GRID_SIZE], Player player) {
    return (grid[player.x][player.y] == MONSTER);
}

void placeTreasure(char grid[GRID_SIZE][GRID_SIZE]) {
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;
    while (grid[x][y] != EMPTY) {
        x = rand() % GRID_SIZE;
        y = rand() % GRID_SIZE;
    }
    grid[x][y] = TREASURE;
}

void placeMonsters(char grid[GRID_SIZE][GRID_SIZE]) {
    int count = 0;
    while (count < MAX_MONSTERS) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == EMPTY) {
            grid[x][y] = MONSTER;
            count++;
        }
    }
}

int isGameOver(char grid[GRID_SIZE][GRID_SIZE], Player player) {
    return checkMonsterEncounter(grid, player);
}