//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void drawMaze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
}

void printRobotPosition(int x, int y) {
    printf("Robot is at (%d, %d)\n", x, y);
}

int main() {
    srand(time(NULL));

    char maze[ROWS][COLS];
    generateMaze(maze);
    drawMaze(maze);

    int robotX = 0, robotY = 0;
    while (1) {
        system("clear");
        drawMaze(maze);
        printRobotPosition(robotX, robotY);

        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);

        int newX = robotX, newY = robotY;

        switch (move) {
            case 'w':
                newY--;
                break;
            case 'a':
                newX--;
                break;
            case's':
                newY++;
                break;
            case 'd':
                newX++;
                break;
            default:
                continue;
        }

        if (maze[newY][newX] == '.') {
            robotX = newX;
            robotY = newY;
        }
    }

    return 0;
}