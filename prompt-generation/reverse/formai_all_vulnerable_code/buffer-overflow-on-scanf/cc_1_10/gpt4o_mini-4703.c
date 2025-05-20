//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 10
#define TRAPS 10
#define EMPTY ' '
#define WALL '#'
#define PLAYER '@'
#define EXIT 'E'
#define TRAP 'X'

char maze[SIZE][SIZE];
int playerX, playerY;

void initializeMaze() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == 0 || i == SIZE-1 || j == 0 || j == SIZE-1) {
                maze[i][j] = WALL;
            } else {
                maze[i][j] = EMPTY;
            }
        }
    }
    // Place exit
    maze[SIZE - 2][SIZE - 2] = EXIT;

    // Place traps
    for (int i = 0; i < TRAPS; ) {
        int x = rand() % (SIZE - 2) + 1;
        int y = rand() % (SIZE - 2) + 1;
        if (maze[x][y] == EMPTY) {
            maze[x][y] = TRAP;
            i++;
        }
    }
}

void placePlayer() {
    playerX = 1;
    playerY = 1;
    maze[playerX][playerY] = PLAYER;
}

void printMaze() {
    system("clear");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char direction) {
    maze[playerX][playerY] = EMPTY; // Remove player from current position

    switch (direction) {
        case 'W': case 'w': if (maze[playerX - 1][playerY] != WALL) playerX--; break;
        case 'S': case 's': if (maze[playerX + 1][playerY] != WALL) playerX++; break;
        case 'A': case 'a': if (maze[playerX][playerY - 1] != WALL) playerY--; break;
        case 'D': case 'd': if (maze[playerX][playerY + 1] != WALL) playerY++; break;
        default: printf("Invalid move! Use W/A/S/D to move.\n"); break;
    }

    // Check for traps or exit
    if (maze[playerX][playerY] == TRAP) {
        printf("You stepped on a trap! Game Over!\n");
        exit(0);
    } else if (maze[playerX][playerY] == EXIT) {
        printf("Congratulations! You've found the exit!\n");
        exit(0);
    }

    maze[playerX][playerY] = PLAYER; // Place player in new position
}

int main() {
    srand(time(NULL));
    initializeMaze();
    placePlayer();

    char input;
    while (1) {
        printMaze();
        printf("Use W (up), A (left), S (down), D (right) to move!\n");
        printf("Enter your move: ");
        scanf(" %c", &input);
        movePlayer(input);
    }
    return 0;
}