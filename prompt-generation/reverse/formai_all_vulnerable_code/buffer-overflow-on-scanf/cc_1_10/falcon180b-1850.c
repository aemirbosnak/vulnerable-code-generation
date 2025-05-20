//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define ROWS 10
#define COLS 10

bool visited[ROWS][COLS] = {false};

void printPattern(int x, int y, int move) {
    int i, j;
    if (move > 0) {
        printf(" ");
        for (i = 0; i < move; i++) {
            printf(" ");
        }
    }
    for (i = 0; i < move; i++) {
        printf("*");
    }
    printf("\n");
}

void printMaze(int x, int y) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == x && j == y) {
                printf("X");
            } else if (i == x || j == y) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void solveMaze(int x, int y) {
    int i, j, k, l;
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return;
    }
    if (x == 0 || x == ROWS - 1 || y == 0 || y == COLS - 1) {
        return;
    }
    if (visited[x][y]) {
        return;
    }
    visited[x][y] = true;
    printMaze(x, y);
    if (x > 0 &&!visited[x - 1][y]) {
        solveMaze(x - 1, y);
    }
    if (x < ROWS - 1 &&!visited[x + 1][y]) {
        solveMaze(x + 1, y);
    }
    if (y > 0 &&!visited[x][y - 1]) {
        solveMaze(x, y - 1);
    }
    if (y < COLS - 1 &&!visited[x][y + 1]) {
        solveMaze(x, y + 1);
    }
}

int main() {
    int x, y;
    printf("Enter the starting point (x,y): ");
    scanf("%d %d", &x, &y);
    solveMaze(x, y);
    return 0;
}