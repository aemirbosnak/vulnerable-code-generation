//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY '-'
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
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

int check_draw(char board[BOARD_SIZE][BOARD_SIZE]) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                count++;
            }
        }
    }
    return count == 0;
}

void make_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == EMPTY) {
        board[row][col] = player;
    } else {
        printf("Invalid move!\n");
    }
}

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    char current_player = PLAYER_ONE;

    while (1) {
        system("clear");
        printf("Player %c's turn\n", current_player);
        print_board(board);

        int row, col;
        scanf("%d %d", &row, &col);
        make_move(board, row, col, current_player);

        if (check_win(board, current_player)) {
            printf("Player %c wins!\n", current_player);
            break;
        } else if (check_draw(board)) {
            printf("It's a draw.\n");
            break;
        }

        current_player = (current_player == PLAYER_ONE)? PLAYER_TWO : PLAYER_ONE;
    }

    return 0;
}