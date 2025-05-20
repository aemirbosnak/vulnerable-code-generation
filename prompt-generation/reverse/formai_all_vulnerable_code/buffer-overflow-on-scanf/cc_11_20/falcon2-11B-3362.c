//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 3
#define EMPTY '-'

int main() {
    int board[ROWS][COLS] = {
        {'X', 'X', 'O'},
        {'O', 'O', 'X'},
        {'O', 'X', 'X'}
    };
    int player = 1;
    int winner = 0;

    while (1) {
        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your move (row, column):\n");
        int r, c;
        scanf("%d%d", &r, &c);

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS) {
            printf("Invalid move, try again.\n");
        } else if (board[r][c]!= EMPTY) {
            printf("This cell is already occupied, try again.\n");
        } else {
            board[r][c] = player;
            if (winner == 0) {
                winner = check_winner(board, r, c);
            }
            if (winner == 1) {
                printf("Player %d wins!\n", player);
                break;
            }
            if (winner == 2) {
                printf("It's a tie!\n");
                break;
            }

            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        }
    }

    return 0;
}

int check_winner(int board[ROWS][COLS], int r, int c) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == board[r][c]) {
                return 1;
            }
        }
    }
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[r][c] && board[i][1] == board[r][c] && board[i][2] == board[r][c]) {
            return 1;
        }
    }
    for (i = 0; i < COLS; i++) {
        if (board[0][i] == board[r][c] && board[1][i] == board[r][c] && board[2][i] == board[r][c]) {
            return 1;
        }
    }
    return 0;
}