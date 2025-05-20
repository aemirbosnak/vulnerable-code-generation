//Falcon-180B DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[ROWS][COLS], int player) {
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < COLS; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;
    int valid_choice = 0;

    while (1) {
        system("clear");
        printf("Player 1: X, Player 2: O\n");
        print_board(board);

        valid_choice = 0;
        while (!valid_choice) {
            printf("\nPlayer %d, enter your move: ", player);
            scanf("%d", &choice);
            if (choice >= 1 && choice <= 9 && board[choice / 3][choice % 3] == 0) {
                board[choice / 3][choice % 3] = player;
                valid_choice = 1;
            } else {
                printf("Invalid move, please try again.\n");
            }
        }

        if (check_win(board, player)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player =!player;
    }

    return 0;
}