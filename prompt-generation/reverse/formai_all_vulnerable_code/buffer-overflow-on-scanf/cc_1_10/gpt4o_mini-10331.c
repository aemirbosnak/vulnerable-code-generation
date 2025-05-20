//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define TREASURE 'T'
#define TRAP 'X'
#define EMPTY ' '
#define PLAYER 'P'

typedef struct {
    int x;
    int y;
} Player;

void initializeGrid(char grid[MAX_SIZE][MAX_SIZE], int size, int numTreasures, int numTraps);
void printGrid(char grid[MAX_SIZE][MAX_SIZE], int size, Player player);
void movePlayer(Player *player, char direction, int size);

int main() {
    int size, numTreasures, numTraps;
    char grid[MAX_SIZE][MAX_SIZE];
    Player player = {0, 0};

    srand(time(0));

    printf("Welcome to Treasure Hunt!\n");
    printf("Enter grid size (1-20): ");
    scanf("%d", &size);
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Setting size to 5.\n");
        size = 5;
    }

    printf("Enter number of treasures: ");
    scanf("%d", &numTreasures);
    printf("Enter number of traps: ");
    scanf("%d", &numTraps);

    initializeGrid(grid, size, numTreasures, numTraps);
    grid[player.x][player.y] = PLAYER;

    char command;
    while (1) {
        printGrid(grid, size, player);
        printf("Move (WASD) or Q to quit: ");
        scanf(" %c", &command);
        
        if (command == 'Q' || command == 'q') {
            printf("Thanks for playing!\n");
            break;
        }

        movePlayer(&player, command, size);

        if (grid[player.x][player.y] == TREASURE) {
            printf("You found a treasure!\n");
            grid[player.x][player.y] = PLAYER; // replace treasure with player
        } else if (grid[player.x][player.y] == TRAP) {
            printf("You fell into a trap! Game Over.\n");
            break;
        }

        grid[player.x][player.y] = PLAYER; // update player's position
    }

    return 0;
}

void initializeGrid(char grid[MAX_SIZE][MAX_SIZE], int size, int numTreasures, int numTraps) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = EMPTY;
        }
    }

    for (int i = 0; i < numTreasures; i++) {
        int x, y;
        do {
            x = rand() % size;
            y = rand() % size;
        } while (grid[x][y] != EMPTY);
        grid[x][y] = TREASURE;
    }

    for (int i = 0; i < numTraps; i++) {
        int x, y;
        do {
            x = rand() % size;
            y = rand() % size;
        } while (grid[x][y] != EMPTY);
        grid[x][y] = TRAP;
    }
}

void printGrid(char grid[MAX_SIZE][MAX_SIZE], int size, Player player) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == player.x && j == player.y) {
                printf("%c ", PLAYER);
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void movePlayer(Player *player, char direction, int size) {
    int newX = player->x;
    int newY = player->y;

    switch (direction) {
        case 'W':
        case 'w':
            if (newX > 0) newX--;
            break;
        case 'A':
        case 'a':
            if (newY > 0) newY--;
            break;
        case 'S':
        case 's':
            if (newX < size - 1) newX++;
            break;
        case 'D':
        case 'd':
            if (newY < size - 1) newY++;
            break;
        default:
            printf("Invalid move!\n");
            return;
    }

    player->x = newX;
    player->y = newY;
}