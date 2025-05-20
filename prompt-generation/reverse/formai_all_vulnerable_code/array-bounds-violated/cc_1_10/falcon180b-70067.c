//Falcon-180B DATASET v1.0 Category: Table Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void createBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS]);
int checkWin(char board[ROWS][COLS]);

int main() {
    char board[ROWS][COLS];
    int player = 1;
    int choice;
    int i, j;

    srand(time(NULL));

    createBoard(board);

    do {
        system("clear");
        printBoard(board);
        printf("\nPlayer %d's turn. Enter your move (row and column): ", player);
        scanf("%d %d", &i, &j);
        if (board[i-1][j-1]!= 'X' && board[i-1][j-1]!= 'O') {
            board[i-1][j-1] = (player % 2 == 0)? 'X' : 'O';
            player++;
        } else {
            printf("Invalid move. Try again.\n");
        }
    } while (checkWin(board) == 0);

    printf("\nGame over! Player %d wins!\n", (player % 2) + 1);

    return 0;
}

void createBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0]!= '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i]!= '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0]!= '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2]!= '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}