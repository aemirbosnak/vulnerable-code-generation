//FormAI DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
/*
 * Ada Lovelace Style Memory Game
 * Author : AI Bot
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int score;
char board[ROWS][COLS];
char userBoard[ROWS][COLS];

void printBoard() {
    printf("\n-------------------------------\n");
    printf("             Memory Game\n");
    printf("            Score : %d\n", score);
    printf("-------------------------------\n\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("  %c  ", userBoard[i][j]);
        }
        printf("\n\n");
    }
}

void fillBoard() {
    char characters[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int count = 0;
    srand(time(NULL));
    while(count < 8) {
        int i = rand() % ROWS, j = rand() % COLS;
        if(board[i][j] == ' ') {
            board[i][j] = characters[count];
            count++;
        }
    }
}

void resetBoard() {
    score = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
            userBoard[i][j] = ' ';
        }
    }
    fillBoard();
}

void checkCards(int x1, int y1, int x2, int y2) {
    if(board[x1][y1] == board[x2][y2]) {
        userBoard[x1][y1] = board[x1][y1];
        userBoard[x2][y2] = board[x2][y2];
        score++;
    }
    else {
        userBoard[x1][y1] = '?';
        userBoard[x2][y2] = '?';
    }
    printBoard();
}

int main() {
    printf("Welcome to Ada Lovelace Style Memory Game!\n");
    resetBoard();
    printBoard();
    int x1, y1, x2, y2;
    while(1) {
        printf("Enter x1 and y1 co-ordinates: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter x2 and y2 co-ordinates: ");
        scanf("%d %d", &x2, &y2);
        if(x1 > ROWS || y1 > COLS || x2 > ROWS || y2 > COLS) {
            printf("Invalid co-ordinates!\n");
            continue;
        }
        else if(x1 == x2 && y1 == y2) {
            printf("Both co-ordinates are the same!\n");
            continue;
        }
        if(userBoard[x1][y1] != '?' && userBoard[x2][y2] != '?') {
            printf("Both cards are already flipped!\n");
            continue;
        }
        checkCards(x1, y1, x2, y2);
        if(score == 8) {
            printf("Congratulations! You have won the game!\n");
            resetBoard();
        }
    }
    return 0;
}