//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10

void generateMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);
int isValid(int x, int y);

int main() {
    srand(time(0));
    char maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}

void generateMaze(char maze[ROWS][COLS]) {
    int startX = rand() % ROWS;
    int startY = rand() % COLS;
    maze[startX][startY] = 'S';
    int directions[4] = {0, 1, 0, -1};
    int currentX = startX;
    int currentY = startY;
    while(1) {
        int direction = rand() % 4;
        int newX = currentX + directions[direction];
        int newY = currentY + directions[direction + 1];
        if(isValid(newX, newY)) {
            maze[newX][newY] = '.';
            currentX = newX;
            currentY = newY;
        }
    }
}

void printMaze(char maze[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int isValid(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}