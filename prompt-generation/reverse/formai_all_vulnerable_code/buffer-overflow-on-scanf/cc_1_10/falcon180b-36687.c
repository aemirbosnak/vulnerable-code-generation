//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void init_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 'X';
        }
    }
}

int is_valid_move(int row, int col, char board[ROWS][COLS]) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == 'X') {
        return 1;
    }
    return 0;
}

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    init_board(board);

    int player = 1;
    while (1) {
        int row, col;
        printf("Player %d's turn:\n", player);
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);

        if (!is_valid_move(row, col, board)) {
            printf("Invalid move.\n");
            continue;
        }

        if (board[row][col] == 'X') {
            board[row][col] = 'O';
            if (player == 2) {
                printf("Player 2 wins!\n");
                break;
            }
            player++;
        } else {
            printf("Missed.\n");
        }

        print_board(board);

        if (player == 3) {
            printf("Tie game.\n");
            break;
        }
    }

    return 0;
}