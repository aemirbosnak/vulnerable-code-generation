//Falcon-180B DATASET v1.0 Category: Educational ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //seed rand() with current time
    int maze[10][10]; //initialize maze with walls
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze[i][j] = 1; //1 represents a wall
        }
    }
    int x = rand() % 10; //random starting point
    int y = rand() % 10;
    int steps = 0; //number of steps taken
    while (steps < 100) { //maximum 100 steps
        int dir = rand() % 4; //random direction (0=up, 1=right, 2=down, 3=left)
        int newX = x;
        int newY = y;
        switch (dir) {
            case 0:
                newY--;
                break;
            case 1:
                newX++;
                break;
            case 2:
                newY++;
                break;
            case 3:
                newX--;
                break;
        }
        if (maze[newX][newY] == 1) { //if there's a wall in the new direction
            steps++; //increment steps taken
        } else {
            x = newX;
            y = newY;
            maze[x][y] = 0; //mark new position as visited
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (maze[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
    return 0;
}