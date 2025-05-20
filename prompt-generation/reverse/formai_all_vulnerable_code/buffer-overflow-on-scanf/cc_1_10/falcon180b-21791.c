//Falcon-180B DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define BOARD_SIZE (ROWS * COLS)
#define PLAYER_ONE 1
#define PLAYER_TWO 2
#define EMPTY 0

void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
}

int check_winner(int board[ROWS][COLS]) {
    // Check horizontal lines
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0]!= EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check vertical lines
    for (int j = 0; j < COLS; j++) {
        if (board[0][j]!= EMPTY && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonal lines
    if (board[0][0]!= EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2]!= EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return 0;
}

int main() {
    int board[ROWS][COLS];
    initialize_board(board);

    int current_player = PLAYER_ONE;
    int winner = 0;

    while (winner == 0) {
        printf("Player %d's turn\n", current_player + 1);
        printf("Enter row and column: ");
        scanf("%d %d", &(board[current_player][0]), &(board[current_player][1]));

        if (board[current_player][0] < 1 || board[current_player][0] > ROWS || board[current_player][1] < 1 || board[current_player][1] > COLS) {
            printf("Invalid move\n");
            current_player =!current_player;
            continue;
        }

        if (board[current_player][0] == ROWS - 1) {
            winner = current_player;
        } else {
            current_player =!current_player;
        }

        print_board(board);
    }

    printf("Player %d wins!\n", winner + 1);

    return 0;
}