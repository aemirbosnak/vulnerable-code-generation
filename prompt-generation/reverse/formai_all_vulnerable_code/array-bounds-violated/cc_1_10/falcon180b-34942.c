//Falcon-180B DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void init_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void draw_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[ROWS][COLS]) {
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

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    int player = 1;
    int choice;
    int i, j;

    init_board(board);

    while (1) {
        draw_board(board);
        printf("Player %d's turn.\n", player);
        printf("Enter row and column: ");
        scanf("%d %d", &i, &j);

        if (board[i - 1][j - 1]!= '-') {
            printf("Invalid move.\n");
            continue;
        }

        board[i - 1][j - 1] = (player == 1)? 'X' : 'O';

        if (check_winner(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}