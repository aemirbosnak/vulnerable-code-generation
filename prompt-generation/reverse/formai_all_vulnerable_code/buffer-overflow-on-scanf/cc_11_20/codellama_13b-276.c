//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: all-encompassing
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

    #define BOARD_SIZE 3
    #define EMPTY_CELL ' '
    #define PLAYER_1 'X'
    #define PLAYER_2 'O'

    int main() {
        char board[BOARD_SIZE][BOARD_SIZE] = {
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
            {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
        };

        int player = 1;
        int row, col;

        while (1) {
            printf("Player %d, enter row and column: ", player);
            scanf("%d %d", &row, &col);

            if (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE) {
                printf("Invalid input. Try again.\n");
                continue;
            }

            if (board[row - 1][col - 1] != EMPTY_CELL) {
                printf("Cell already occupied. Try again.\n");
                continue;
            }

            board[row - 1][col - 1] = (player == 1 ? PLAYER_1 : PLAYER_2);

            printf("Board after move:\n");
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    printf("%c ", board[i][j]);
                }
                printf("\n");
            }

            if (check_win(board, player)) {
                printf("Player %d wins!\n", player);
                break;
            }

            player = 3 - player;
        }

        return 0;
    }

    int check_win(char board[BOARD_SIZE][BOARD_SIZE], int player) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == player) {
                return 1;
            }
        }

        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == player) {
                return 1;
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == player) {
            return 1;
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == player) {
            return 1;
        }

        return 0;
    }