//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS];
int playerRow, playerCol;
int score;
int gameOver;

void generateMaze();
void drawMaze();
void movePlayer(int dir);
void checkGameOver();

int main() {
    srand(time(NULL));
    generateMaze();

    while (!gameOver) {
        drawMaze();
        int key = getchar();
        movePlayer(key);
        checkGameOver();
    }

    printf("Game Over! Your score is: %d\n", score);
    return 0;
}

void generateMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }

    playerRow = 0;
    playerCol = 0;
    score = 0;
}

void drawMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(int dir) {
    int newRow, newCol;

    switch (dir) {
        case 'w':
            newRow = playerRow - 1;
            break;
        case's':
            newRow = playerRow + 1;
            break;
        case 'a':
            newCol = playerCol - 1;
            break;
        case 'd':
            newCol = playerCol + 1;
            break;
    }

    if (maze[newRow][newCol] == '.') {
        playerRow = newRow;
        playerCol = newCol;
        score++;
    }
}

void checkGameOver() {
    if (playerRow == ROWS - 1 && playerCol == COLS - 1) {
        gameOver = 1;
        printf("Congratulations! You won!\n");
    } else if (maze[playerRow][playerCol]!= '.') {
        gameOver = 1;
        printf("Game Over! You hit a wall.\n");
    }
}