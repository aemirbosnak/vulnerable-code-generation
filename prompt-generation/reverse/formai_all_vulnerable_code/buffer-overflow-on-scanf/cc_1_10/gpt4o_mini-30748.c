//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAZE_SIZE 5
#define MAX_STEPS 12
#define EMPTY ' '
#define WALL '#'
#define PLAYER 'P'
#define TREASURE 'T'
#define EXIT 'E'

void initializeMaze(char maze[MAZE_SIZE][MAZE_SIZE]) {
    char tempMaze[MAZE_SIZE][MAZE_SIZE] = {
        {'#', '#', '#', '#', '#'},
        {'#', ' ', ' ', '#', '#'},
        {'#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', 'E', '#'}
    };

    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = tempMaze[i][j];
        }
    }

    maze[1][1] = PLAYER;
}

void printMaze(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\nMaze Layout:\n");
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char maze[MAZE_SIZE][MAZE_SIZE], char direction, int *playerX, int *playerY) {
    int newX = *playerX;
    int newY = *playerY;

    switch (direction) {
        case 'w': newX--; break; // Move up
        case 's': newX++; break; // Move down
        case 'a': newY--; break; // Move left
        case 'd': newY++; break; // Move right
        default: printf("Invalid direction! Use W/A/S/D to move.\n"); return;
    }

    if (newX >= 0 && newX < MAZE_SIZE && newY >= 0 && newY < MAZE_SIZE) {
        if (maze[newX][newY] != WALL) {
            maze[*playerX][*playerY] = EMPTY; // Clear old position
            *playerX = newX; // Update player position
            *playerY = newY;
            maze[newX][newY] = PLAYER; // Set new position
        } else {
            printf("You hit a wall! Ouch!\n");
        }
    } else {
        printf("You can't move outside the maze boundaries!\n");
    }
}

int main() {
    char maze[MAZE_SIZE][MAZE_SIZE];
    int playerX = 1, playerY = 1; // Starting position of the player
    char command;
    int steps = 0;
    int treasureFound = 0; // Treasure flag

    initializeMaze(maze);
    printMaze(maze);

    printf("Welcome to the Maze Adventure Game!\n");
    printf("You can move using W (up), A (left), S (down), and D (right).\n");
    printf("Your goal is to reach the Exit (E) and find the Treasure (T)!\n\n");

    while (steps < MAX_STEPS) {
        printf("Enter your move (W/A/S/D): ");
        scanf(" %c", &command);
        
        movePlayer(maze, command, &playerX, &playerY);
        steps++;

        if (maze[playerX][playerY] == TREASURE) {
            treasureFound = 1;
            printf("Congratulations! You've found the Treasure!\n");
        }

        if (maze[playerX][playerY] == EXIT) {
            printf("You've reached the Exit! You've escaped the maze!\n");
            break;
        }

        printMaze(maze);
    }

    if (steps >= MAX_STEPS) {
        printf("You've run out of steps! Game Over!\n");
    }

    return 0;
}