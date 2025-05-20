//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[i][0] == board[i][2] && board[i][2] == board[i][1])) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
            (board[0][i] == board[2][i] && board[2][i] == board[1][i])) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

void make_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    int i, j;
    char mark;

    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
        if (board[row][col] == '\0') {
            mark = (char) (rand() % 2 + '1');
            board[row][col] = mark;

            if (check_winner(board)) {
                printf("Player %c wins!\n", mark);
                exit(0);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    char board[BOARD_SIZE][BOARD_SIZE];
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '\0';
        }
    }

    int moves = 0;

    while (1) {
        system("clear");
        print_board(board);

        int x, y;
        scanf("%d %d", &x, &y);

        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
            make_move(board, x, y);
            moves++;

            if (moves == BOARD_SIZE * BOARD_SIZE) {
                printf("Tie game.\n");
                exit(0);
            }
        } else {
            printf("Invalid move.\n");
        }
    }

    return 0;
}