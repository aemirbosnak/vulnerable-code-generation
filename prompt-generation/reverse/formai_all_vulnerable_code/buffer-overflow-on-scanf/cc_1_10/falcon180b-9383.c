//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define EMPTY '.'
#define PLAYER '@'
#define EXIT 'X'
#define WALL '#'

char maze[ROWS][COLS];
int playerRow, playerCol;
int exitRow, exitCol;
int score;

void initMaze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
    exitRow = rand() % ROWS;
    exitCol = rand() % COLS;
    maze[exitRow][exitCol] = EXIT;
    playerRow = 0;
    playerCol = 0;
    score = 0;
}

void drawMaze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(int rowDiff, int colDiff) {
    int newRow = playerRow + rowDiff;
    int newCol = playerCol + colDiff;

    if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol]!= WALL) {
        playerRow = newRow;
        playerCol = newCol;
        if (maze[newRow][newCol] == EXIT) {
            printf("You won!\n");
            exit(0);
        }
    }
}

int main() {
    srand(time(0));
    initMaze();

    while (1) {
        drawMaze();
        printf("Score: %d\n", score);
        printf("Move (w/a/s/d): ");
        char move;
        scanf("%c", &move);
        switch (move) {
            case 'w':
                movePlayer(0, -1);
                break;
            case 'a':
                movePlayer(-1, 0);
                break;
            case's':
                movePlayer(0, 1);
                break;
            case 'd':
                movePlayer(1, 0);
                break;
            default:
                printf("Invalid move.\n");
        }
        if (maze[playerRow][playerCol] == EXIT) {
            printf("You won!\n");
            exit(0);
        }
    }

    return 0;
}