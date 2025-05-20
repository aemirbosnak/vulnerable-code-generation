//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: creative
/*
* Tic Tac Toe AI
* Created by [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 3
#define MAX_COLS 3

int board[MAX_ROWS][MAX_COLS] = {0};

void display_board(int board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == -1) {
                printf("O ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int check_win(int board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    for (int i = 0; i < MAX_COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return 0;
}

void make_move(int board[MAX_ROWS][MAX_COLS], int row, int col, int player) {
    board[row][col] = player;
}

int make_random_move(int board[MAX_ROWS][MAX_COLS]) {
    int row, col;
    do {
        row = rand() % MAX_ROWS;
        col = rand() % MAX_COLS;
    } while (board[row][col] != 0);
    make_move(board, row, col, 1);
}

void make_human_move(int board[MAX_ROWS][MAX_COLS]) {
    int row, col;
    printf("Enter row and column (0-2): ");
    scanf("%d %d", &row, &col);
    make_move(board, row, col, -1);
}

int main() {
    int board[MAX_ROWS][MAX_COLS] = {0};
    srand(time(NULL));
    int player = 1;
    int winner;

    while (1) {
        display_board(board);
        if (player == 1) {
            make_human_move(board);
        } else {
            make_random_move(board);
        }
        player *= -1;
        winner = check_win(board);
        if (winner) {
            display_board(board);
            printf("Player %d wins!\n", winner);
            break;
        }
    }
    return 0;
}