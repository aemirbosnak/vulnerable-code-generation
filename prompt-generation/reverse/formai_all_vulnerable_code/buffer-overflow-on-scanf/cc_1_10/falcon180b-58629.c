//Falcon-180B DATASET v1.0 Category: Game ; Style: recursive
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

int check_win(char board[ROWS][COLS]) {
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void play_game(char board[ROWS][COLS]) {
    int player = 1;
    int choice;
    int valid_move = 1;

    while (valid_move) {
        printf("Player %d's turn\n", player);
        printf("Enter your move (row col): ");
        scanf("%d %d", &choice, &choice);
        if (choice >= 0 && choice < ROWS * COLS) {
            if (board[choice / COLS][choice % COLS] == '\0') {
                board[choice / COLS][choice % COLS] = (player == 1)? 'X' : 'O';
                valid_move = 0;
            }
        } else {
            printf("Invalid move\n");
        }
        player = (player == 1)? 2 : 1;
    }

    if (check_win(board)) {
        printf("Player %d wins!\n", player);
    } else {
        printf("It's a draw.\n");
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS] = { { '\0', '\0', '\0' }, { '\0', '\0', '\0' }, { '\0', '\0', '\0' } };

    play_game(board);

    return 0;
}