//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define SYMBOLS 3

char board[ROWS][COLS];
char symbols[SYMBOLS] = {'X', 'O', '*'};

void initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    initBoard();

    int player = 1;
    int choice;
    char symbol;

    do {
        printBoard();
        printf("Player %d's turn.\n", player);
        printf("Enter your symbol (X or O): ");
        scanf(" %c", &symbol);

        int validInput = 0;
        while (!validInput) {
            printf("Enter your move (row and column): ");
            scanf(" %d %d", &choice, &choice);

            if (choice >= 0 && choice < ROWS && choice >= 0 && choice < COLS) {
                if (board[choice][choice] == '-') {
                    board[choice][choice] = symbol;
                    validInput = 1;
                } else {
                    printf("Invalid move. Try again.\n");
                }
            } else {
                printf("Invalid move. Try again.\n");
            }
        }

        if (checkWin()) {
            printf("Player %d wins!\n", player);
            break;
        }

        player = (player % 2)? 1 : 2;
    } while (1);

    return 0;
}