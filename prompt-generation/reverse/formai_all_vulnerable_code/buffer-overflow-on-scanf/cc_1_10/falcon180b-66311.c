//Falcon-180B DATASET v1.0 Category: Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define EMPTY '.'
#define PLAYER1 'X'
#define PLAYER2 'O'
#define PLAYER '*'

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(char board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == EMPTY) {
        return 1;
    }
    return 0;
}

int check_winner(char board[ROWS][COLS]) {
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
    char board[ROWS][COLS];
    int row, col, player = 1;
    srand(time(NULL));
    memset(board, EMPTY, sizeof(board));
    while (1) {
        system("clear");
        print_board(board);
        printf("Player %d's turn\n", player);
        if (player == 1) {
            printf("Enter row and column: ");
            scanf("%d %d", &row, &col);
            if (is_valid_move(board, row, col)) {
                board[row][col] = PLAYER1;
                player = 2;
            }
        } else if (player == 2) {
            printf("Enter row and column: ");
            scanf("%d %d", &row, &col);
            if (is_valid_move(board, row, col)) {
                board[row][col] = PLAYER2;
                player = 1;
            }
        }
        if (check_winner(board)) {
            printf("Player %d wins!\n", player);
            break;
        } else if (memset(board, EMPTY, sizeof(board)) == NULL) {
            printf("Draw!\n");
            break;
        }
    }
    return 0;
}