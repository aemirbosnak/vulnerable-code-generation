//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define WINNING_CONDITION ((board[0][0] == board[0][1] && board[0][1] == board[0][2]) || \
                            (board[1][0] == board[1][1] && board[1][1] == board[1][2]) || \
                            (board[2][0] == board[2][1] && board[2][1] == board[2][2]) || \
                            (board[0][0] == board[1][0] && board[1][0] == board[2][0]) || \
                            (board[0][1] == board[1][1] && board[1][1] == board[2][1]) || \
                            (board[0][2] == board[1][2] && board[1][2] == board[2][2]) || \
                            (board[2][0] == board[1][1] && board[1][1] == board[0][0]) || \
                            (board[2][1] == board[1][0] && board[1][0] == board[0][1]) || \
                            (board[2][2] == board[1][2] && board[1][2] == board[0][2]))

void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

int check_position(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == '-') {
        return 1;
    }
    return 0;
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE]) {
    return WINNING_CONDITION;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int player = 1;
    int row, col;

    srand(time(NULL));
    init_board(board);

    while (1) {
        system("clear");
        printf("Player %d's turn\n", player);
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        if (player == 1) {
            printf("Enter row and column: ");
            scanf("%d%d", &row, &col);
            row--; col--;
            if (check_position(board, row, col)) {
                board[row][col] = 'X';
                player++;
            } else {
                printf("Invalid move\n");
            }
        } else {
            int move_row, move_col;
            if (check_win(board)) {
                printf("Player %d wins!\n", player);
                break;
            }
            do {
                move_row = rand() % BOARD_SIZE;
                move_col = rand() % BOARD_SIZE;
            } while (!check_position(board, move_row, move_col));
            board[move_row][move_col] = 'O';
            player--;
        }
    }

    return 0;
}