//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MINES 10
#define ROOM '.'
#define MINE '*'
#define EMPTY''
#define DEATH 'X'

int board[ROWS][COLS] = {ROOM};
int mines[ROWS][COLS] = {0};
int flag[ROWS][COLS] = {0};
int playerRow = 0, playerCol = 0;
int lives = 1;
int minesLeft = MINES;

void generateMines() {
    int count = 0;
    while (count < MINES) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (mines[row][col] == 0) {
            mines[row][col] = 1;
            count++;
        }
    }
}

void generateBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (mines[i][j] == 1) {
                board[i][j] = MINE;
            } else {
                board[i][j] = ROOM;
            }
        }
    }
}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (board[row][col] == ROOM) {
            playerRow = row;
            playerCol = col;
        } else if (board[row][col] == MINE) {
            board[row][col] = DEATH;
            lives--;
        }
    }
}

int main() {
    srand(time(NULL));
    generateMines();
    generateBoard();
    printBoard();

    while (lives > 0) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &playerRow, &playerCol);
        movePlayer(playerRow, playerCol);
        printBoard();
        if (lives == 0) {
            printf("You lose!\n");
            break;
        } else if (minesLeft == 0) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}