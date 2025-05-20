//Falcon-180B DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

int main() {
    int board[ROWS][COLS] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;
    int flag = 0;

    srand(time(NULL));

    while (!flag) {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        printf("Please enter your move: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move, please try again.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col]!= 0) {
            printf("Invalid move, please try again.\n");
            continue;
        }

        board[row][col] = player;
        player = (player == 1)? 2 : 1;

        flag = check_win(board);
    }

    printf("\nGame Over!\n");
    printf("Player %d wins!\n", player);

    return 0;
}

int check_win(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}