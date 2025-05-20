//GPT-4o-mini DATASET v1.0 Category: Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define NUM_OBSTACLES 3

enum Cell {EMPTY, PLAYER, TARGET, OBSTACLE};

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position playerPos;
    Position targetPos;
    Position obstacles[NUM_OBSTACLES];
    enum Cell grid[GRID_SIZE][GRID_SIZE];
} Game;

void initializeGame(Game *game) {
    srand(time(NULL));

    // Initialize player position
    game->playerPos.x = 0;
    game->playerPos.y = 0;

    // Initialize target position
    game->targetPos.x = GRID_SIZE - 1;
    game->targetPos.y = GRID_SIZE - 1;

    // Initialize obstacles
    for(int i = 0; i < NUM_OBSTACLES; i++) {
        do {
            game->obstacles[i].x = rand() % GRID_SIZE;
            game->obstacles[i].y = rand() % GRID_SIZE;
        } while((game->obstacles[i].x == game->playerPos.x && game->obstacles[i].y == game->playerPos.y) ||
                (game->obstacles[i].x == game->targetPos.x && game->obstacles[i].y == game->targetPos.y));

        // Mark obstacle in grid
        game->grid[game->obstacles[i].x][game->obstacles[i].y] = OBSTACLE;
    }

    // Mark player and target in grid
    game->grid[game->playerPos.x][game->playerPos.y] = PLAYER;
    game->grid[game->targetPos.x][game->targetPos.y] = TARGET;

    // Mark empty cells in grid
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if(game->grid[i][j] != PLAYER && game->grid[i][j] != TARGET) {
                game->grid[i][j] = EMPTY;
            }
        }
    }
}

void printGrid(Game *game) {
    printf("\nCurrent Game Grid:\n");
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if(game->grid[i][j] == PLAYER) {
                printf(" P ");
            } else if(game->grid[i][j] == TARGET) {
                printf(" T ");
            } else if(game->grid[i][j] == OBSTACLE) {
                printf(" X ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int movePlayer(Game *game, char direction) {
    int newX = game->playerPos.x;
    int newY = game->playerPos.y;

    switch(direction) {
        case 'w': newX--; break; // Up
        case 's': newX++; break; // Down
        case 'a': newY--; break; // Left
        case 'd': newY++; break; // Right
        default: return -1; // Invalid direction
    }

    // Validate new position
    if(newX < 0 || newX >= GRID_SIZE || newY < 0 || newY >= GRID_SIZE) {
        return -1; // Out of bounds
    }

    if(game->grid[newX][newY] == OBSTACLE) {
        return -1; // Hit an obstacle
    }

    // Update player position
    game->grid[game->playerPos.x][game->playerPos.y] = EMPTY;
    game->playerPos.x = newX;
    game->playerPos.y = newY;
    game->grid[newX][newY] = PLAYER;

    return 0; // Success
}

int main() {
    Game game;
    initializeGame(&game);
    
    char command;
    while(1) {
        printGrid(&game);
        printf("\nMove (w/a/s/d to move up/left/down/right, q to quit): ");
        scanf(" %c", &command);

        if(command == 'q') {
            printf("Exiting the game. Thank you for playing!\n");
            break;
        }

        if(movePlayer(&game, command) == 0) {
            if(game.playerPos.x == game.targetPos.x && game.playerPos.y == game.targetPos.y) {
                printf("Congratulations! You've reached the target!\n");
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}