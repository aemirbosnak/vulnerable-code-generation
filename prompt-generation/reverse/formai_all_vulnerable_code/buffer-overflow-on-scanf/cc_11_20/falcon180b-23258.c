//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {
    int board[ROWS][COLS] = {0};
    int x, y;
    int player = 1;
    char move;
    int flag = 0;

    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }

    while (!flag) {
        system("clear");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 1) {
                    printf("X");
                } else {
                    printf("O");
                }
            }
            printf("\n");
        }
        printf("Player %d's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d%c", &x, &move);
        y = move - '0';

        if (board[x][y]!= 0) {
            printf("Invalid move. Try again.\n");
        } else {
            board[x][y] = player;
            flag = check_winner(board, player);
            player = (player == 1)? 2 : 1;
        }
    }

    return 0;
}

int check_winner(int board[ROWS][COLS], int player) {
    int win = 0;

    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            win = 1;
            break;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            win = 1;
            break;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        win = 1;
    } else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        win = 1;
    }

    return win;
}