//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }
}

void drawBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    int x, y;
    int playerX = rand() % ROWS;
    int playerY = rand() % COLS;
    board[playerX][playerY] = 'X';

    while (1) {
        drawBoard(board);

        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);

        switch (move) {
            case 'w':
                if (playerY > 0 && board[playerX][playerY - 1] == '.') {
                    playerY--;
                    board[playerX][playerY] = 'X';
                }
                break;
            case 'a':
                if (playerX > 0 && board[playerX - 1][playerY] == '.') {
                    playerX--;
                    board[playerX][playerY] = 'X';
                }
                break;
            case's':
                if (playerY < COLS - 1 && board[playerX][playerY + 1] == '.') {
                    playerY++;
                    board[playerX][playerY] = 'X';
                }
                break;
            case 'd':
                if (playerX < ROWS - 1 && board[playerX + 1][playerY] == '.') {
                    playerX++;
                    board[playerX][playerY] = 'X';
                }
                break;
            default:
                printf("Invalid move\n");
        }

        if (board[playerX][playerY] == 'X') {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}