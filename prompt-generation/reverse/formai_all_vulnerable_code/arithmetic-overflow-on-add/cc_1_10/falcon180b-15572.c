//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void generateMaze(char maze[10][10], int startX, int startY) {
    int x, y;
    srand(time(NULL));
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            maze[x][y] = rand() % 2;
        }
    }
    maze[startX][startY] = 0;
}

void printMaze(char maze[10][10]) {
    int x, y;
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            if (maze[x][y] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int isValidMove(int x, int y, char maze[10][10]) {
    if (x < 0 || x >= 10 || y < 0 || y >= 10 || maze[x][y] == 1) {
        return 0;
    }
    return 1;
}

void movePlayer(int *x, int *y, char maze[10][10]) {
    char key;
    printf("Enter your move (w/a/s/d): ");
    scanf("%c", &key);
    switch (key) {
        case 'w':
            *y -= 1;
            break;
        case 'a':
            *x -= 1;
            break;
        case's':
            *y += 1;
            break;
        case 'd':
            *x += 1;
            break;
        default:
            printf("Invalid move.\n");
            return;
    }
    if (!isValidMove(*x, *y, maze)) {
        printf("Invalid move.\n");
        return;
    }
    *x = *x / 2;
    *y = *y / 2;
}

int main() {
    int x, y;
    char maze[10][10];
    generateMaze(maze, 0, 0);
    printMaze(maze);
    while (1) {
        movePlayer(&x, &y, maze);
        if (maze[x][y] == 2) {
            printf("Congratulations! You have reached the end of the maze.\n");
            break;
        }
        printMaze(maze);
    }
    return 0;
}