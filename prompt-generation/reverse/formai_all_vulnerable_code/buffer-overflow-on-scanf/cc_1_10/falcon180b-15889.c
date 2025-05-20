//Falcon-180B DATASET v1.0 Category: Table Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS] = {{2, 1, 0}, {1, 2, 0}, {0, 0, 2}};
    int player = 1;
    int move;
    int win = 0;

    while (!win) {
        print_board(board);
        printf("Player %d's turn.\n", player);
        scanf("%d", &move);
        if (move < 1 || move > 9) {
            printf("Invalid move.\n");
            continue;
        }
        if (board[move / 3][move % 3]!= 0) {
            printf("Invalid move.\n");
            continue;
        }
        board[move / 3][move % 3] = player;
        win = check_win(board);
        if (!win) {
            player =!player;
        }
    }

    if (player == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}

int check_win(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
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