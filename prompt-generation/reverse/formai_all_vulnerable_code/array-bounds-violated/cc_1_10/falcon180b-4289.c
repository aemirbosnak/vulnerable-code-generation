//Falcon-180B DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void print_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    int i;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for (i = 0; i < COLS; i++) {
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

int main() {
    int player = 1;
    int choice;
    int i, j;

    srand(time(NULL));

    while (1) {
        print_board();
        printf("Player %d's turn.\n", player);

        choice = rand() % 9;
        i = (choice / 3) * 3;
        j = (choice % 3) * 3;

        if (board[i][j]!= 'X' && board[i][j]!= 'O') {
            board[i][j] = (player == 1)? 'X' : 'O';
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move. Try again.\n");
        }

        if (check_win()) {
            printf("Player %d wins!\n", player);
            break;
        }

        if (player == 2) {
            player = 1;
        }
    }

    return 0;
}