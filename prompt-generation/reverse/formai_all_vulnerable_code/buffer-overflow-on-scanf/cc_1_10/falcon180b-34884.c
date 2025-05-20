//Falcon-180B DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void generate_board(int board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[MAX_ROWS][MAX_COLS]) {
    int i, j;

    // Check rows
    for (i = 0; i < MAX_ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < MAX_COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    int board[MAX_ROWS][MAX_COLS];
    generate_board(board);
    print_board(board);

    int player = 1;
    int row, col;
    while (1) {
        printf("Player %d's turn. Enter row and column: ", player);
        scanf("%d %d", &row, &col);
        row--; col--;

        if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS && board[row][col] == 0) {
            board[row][col] = player;
            if (check_win(board)) {
                printf("Player %d wins!\n", player);
                break;
            }
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}