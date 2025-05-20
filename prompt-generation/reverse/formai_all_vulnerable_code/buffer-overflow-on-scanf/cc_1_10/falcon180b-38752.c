//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void init_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
            return 1;
        }
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        return 1;
    }

    if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    init_board(board);

    int player = 0;
    int choice;
    int flag = 0;

    while (flag == 0) {
        printf("Player %d's turn\n", player + 1);
        printf("Enter your choice (1-%d): ", ROWS * COLS - 1);
        scanf("%d", &choice);

        if (choice < 1 || choice > ROWS * COLS - 1) {
            printf("Invalid choice. Skipping turn.\n");
            continue;
        }

        if (board[choice / COLS][choice % COLS]!= '-') {
            printf("Invalid choice. Skipping turn.\n");
            continue;
        }

        board[choice / COLS][choice % COLS] = (player == 0)? 'X' : 'O';

        flag = check_win(board);

        if (flag == 1) {
            printf("Player %d wins!\n", player + 1);
            break;
        }

        player = (player == 0)? 1 : 0;
    }

    return 0;
}