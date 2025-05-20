//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int maze[SIZE][SIZE];
int startX, startY, endX, endY;

void createMaze() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            maze[i][j] = 0;
        }
    }
    startX = rand() % SIZE;
    startY = rand() % SIZE;
    endX = rand() % SIZE;
    endY = rand() % SIZE;
    maze[startX][startY] = 1;
    maze[endX][endY] = 2;
}

void printMaze() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (maze[i][j] == 1) {
                printf("S");
            } else if (maze[i][j] == 2) {
                printf("E");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int checkWin() {
    if (maze[endX][endY] == 1) {
        printf("You won!\n");
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    createMaze();
    printMaze();
    int playerX = startX, playerY = startY;
    while (1) {
        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf("%c", &move);
        if (move == 'w' && playerY > 0 && maze[playerX][playerY - 1]!= 1) {
            playerY--;
        } else if (move == 'a' && playerX > 0 && maze[playerX - 1][playerY]!= 1) {
            playerX--;
        } else if (move =='s' && playerY < SIZE - 1 && maze[playerX][playerY + 1]!= 1) {
            playerY++;
        } else if (move == 'd' && playerX < SIZE - 1 && maze[playerX + 1][playerY]!= 1) {
            playerX++;
        }
        if (checkWin()) {
            break;
        }
    }
    return 0;
}