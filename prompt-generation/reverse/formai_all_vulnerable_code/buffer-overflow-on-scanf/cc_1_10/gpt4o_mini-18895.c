//GPT-4o-mini DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAZE_SIZE 5
#define TREASURES 3
#define TRAPS 2

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position player;
    char maze[MAZE_SIZE][MAZE_SIZE];
    int treasures;
    int traps;
} GameState;

void initializeMaze(GameState *game) {
    // Fill the maze with blanks
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            game->maze[i][j] = '.';
        }
    }

    // Place treasures
    for (int i = 0; i < TREASURES; i++) {
        int x, y;
        do {
            x = rand() % MAZE_SIZE;
            y = rand() % MAZE_SIZE;
        } while (game->maze[x][y] != '.');
        game->maze[x][y] = 'T';
    }

    // Place traps
    for (int i = 0; i < TRAPS; i++) {
        int x, y;
        do {
            x = rand() % MAZE_SIZE;
            y = rand() % MAZE_SIZE;
        } while (game->maze[x][y] != '.');
        game->maze[x][y] = 'X';
    }

    // Initialize player position
    game->player.x = 0;
    game->player.y = 0;
    game->maze[0][0] = 'P'; // P for Player
    game->treasures = 0;
    game->traps = 0;
}

void printMaze(GameState *game) {
    printf("Maze:\n");
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c ", game->maze[i][j]);
        }
        printf("\n");
    }
    printf("Treasures collected: %d\n", game->treasures);
    printf("Traps encountered: %d\n", game->traps);
}

int movePlayer(GameState *game, char direction) {
    int newX = game->player.x;
    int newY = game->player.y;

    switch (direction) {
        case 'w': newX--; break; // Move up
        case 's': newX++; break; // Move down
        case 'a': newY--; break; // Move left
        case 'd': newY++; break; // Move right
        default: return 0; // Invalid move
    }

    // Check bounds
    if (newX < 0 || newX >= MAZE_SIZE || newY < 0 || newY >= MAZE_SIZE) {
        printf("You can't move outside the maze!\n");
        return 0; // Invalid move
    }

    // Update player's position and check the cell
    if (game->maze[newX][newY] == 'T') {
        game->treasures++;
        printf("You found a treasure! Total: %d\n", game->treasures);
    } else if (game->maze[newX][newY] == 'X') {
        game->traps++;
        printf("You stepped on a trap! Total traps: %d\n", game->traps);
    }

    // Update maze and player position
    game->maze[game->player.x][game->player.y] = '.';
    game->player.x = newX;
    game->player.y = newY;
    game->maze[newX][newY] = 'P';

    return 1; // Successful move
}

int main() {
    srand(time(NULL)); // Seed random number generator
    GameState game;
    initializeMaze(&game);

    char command;
    while (1) {
        printMaze(&game);
        printf("Enter command (w/a/s/d to move, q to quit): ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Thanks for playing!\n");
            break;
        }

        if (!movePlayer(&game, command)) {
            printf("Invalid move!\n");
        }

        // You can add conditions to win or lose based on treasures and traps encountered
        if (game.treasures == TREASURES) {
            printf("Congratulations! You've collected all the treasures!\n");
            break;
        } else if (game.traps >= 3) {
            printf("Oh no! You've hit too many traps!\n");
            break;
        }
    }

    return 0;
}