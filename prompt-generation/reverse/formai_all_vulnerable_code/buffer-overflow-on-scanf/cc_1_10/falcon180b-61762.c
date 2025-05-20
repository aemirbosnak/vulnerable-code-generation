//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void generateMaze(char maze[10][10]);
void printMaze(char maze[10][10]);
int checkWin(int playerX, int playerY);
void movePlayer(char maze[10][10], int *playerX, int *playerY, char direction);

int main() {
    srand(time(0)); // Seed the random number generator

    char maze[10][10];
    generateMaze(maze);

    int playerX = 0, playerY = 0;
    while (!checkWin(playerX, playerY)) {
        system("clear"); // clear the terminal
        printMaze(maze);
        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);
        movePlayer(maze, &playerX, &playerY, move);
    }

    printf("Congratulations! You won!");
    return 0;
}

void generateMaze(char maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }

    // Set start and end points
    maze[0][0] = '.';
    maze[9][9] = 'E';
}

void printMaze(char maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int playerX, int playerY) {
    return (playerX == 9 && playerY == 9)? 1 : 0;
}

void movePlayer(char maze[10][10], int *playerX, int *playerY, char direction) {
    int newX = *playerX, newY = *playerY;

    switch (direction) {
        case 'w': --newY; break;
        case 'a': --newX; break;
        case's': ++newY; break;
        case 'd': ++newX; break;
    }

    if (maze[newX][newY] == '.') {
        *playerX = newX;
        *playerY = newY;
    }
}