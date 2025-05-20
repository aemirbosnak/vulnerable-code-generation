//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 6

char board[ROWS][COLS]; // game board
int matches = 0; // number of matches found
int moves = 0; // number of moves made

void initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '*';
        }
    }
}

void drawBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void placeCard(int row, int col) {
    int card = rand() % 2 + 1; // 1 or 2
    if (board[row][col] == '*') {
        if (card == 1) {
            board[row][col] = 'R';
        } else {
            board[row][col] = 'J';
        }
        matches = 0;
        moves = 0;
    } else {
        if (card == 1 && board[row][col] == 'R') {
            matches++;
        } else if (card == 2 && board[row][col] == 'J') {
            matches++;
        } else {
            board[row][col] = '*';
        }
        moves++;
    }
}

int main() {
    srand(time(NULL));
    initBoard();
    int player = 1; // Romeo starts
    while (matches < 10) {
        drawBoard();
        int row, col;
        printf("Player %d, enter your move (row, col): ", player);
        scanf("%d %d", &row, &col);
        placeCard(row, col);
        if (matches == 10) {
            printf("Romeo and Juliet win!\n");
        } else if (moves == 20) {
            printf("Tie game.\n");
        }
        player = (player % 2)? 1 : 2; // switch players
    }
    return 0;
}