//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[ROWS][COLS]) {
    int i, j;
    // check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // check columns
    for (j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    char board[ROWS][COLS] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int player = 1;
    int row, col, choice;
    char mark;

    do {
        print_board(board);
        player = (player % 2) ? 1 : 2;
        printf("Player %d, enter a number (1-9) to place your mark: ", player);
        scanf("%d", &choice);

        row = --choice / 3;
        col = choice % 3;

        mark = (player == 1) ? 'X' : 'O';

        if (board[row][col] == choice + '1') {
            board[row][col] = mark;
        }
        else {
            printf("Invalid move. Try again.\n");
            player--;
        }
    } while (!check_winner(board));

    print_board(board);
    if (player == 1) {
        printf("Player 2 wins!\n");
    }
    else {
        printf("Player 1 wins!\n");
    }

    return 0;
}