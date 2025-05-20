//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define EMPTY ' '
#define WALL '#'
#define PLAYER 'P'
#define TREASURE 'T'
#define EXIT 'E'

char grid[GRID_SIZE][GRID_SIZE];
int playerPosX, playerPosY;

void initializeGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == 0 || i == GRID_SIZE - 1 || j == 0 || j == GRID_SIZE - 1) {
                grid[i][j] = WALL;
            } else {
                grid[i][j] = EMPTY;
            }
        }
    }
    grid[1][1] = TREASURE;
    grid[3][3] = EXIT;
    playerPosX = 1;
    playerPosY = 2;
    grid[playerPosX][playerPosY] = PLAYER;
}

void printGrid() {
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(int newX, int newY) {
    if (newX < 0 || newX >= GRID_SIZE || newY < 0 || newY >= GRID_SIZE) {
        printf("You can't move outside of the grid!\n");
        return;
    }
    if (grid[newX][newY] == WALL) {
        printf("You hit a wall! Try a different direction.\n");
        return;
    }
    if (grid[newX][newY] == TREASURE) {
        printf("Congratulations! You found the treasure!\n");
        grid[newX][newY] = EMPTY; // Clear the treasure
    }
    if (grid[newX][newY] == EXIT) {
        printf("You've reached the exit! You escaped successfully!\n");
        exit(0);
    }
    // Move player
    grid[playerPosX][playerPosY] = EMPTY;
    playerPosX = newX;
    playerPosY = newY;
    grid[playerPosX][playerPosY] = PLAYER;
}

int main() {
    char command;
    srand(time(0));
    initializeGrid();
    printf("Welcome to the Maze Adventure Game!\n");
    printGrid();

    while (1) {
        printf("Enter command (WASD to move, Q to quit): ");
        scanf(" %c", &command);
        switch (command) {
            case 'W':
            case 'w':
                movePlayer(playerPosX - 1, playerPosY);
                break;
            case 'A':
            case 'a':
                movePlayer(playerPosX, playerPosY - 1);
                break;
            case 'S':
            case 's':
                movePlayer(playerPosX + 1, playerPosY);
                break;
            case 'D':
            case 'd':
                movePlayer(playerPosX, playerPosY + 1);
                break;
            case 'Q':
            case 'q':
                printf("Thanks for playing! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid command! Use W, A, S, D to move or Q to quit.\n");
        }
        printGrid();
    }
    return 0;
}