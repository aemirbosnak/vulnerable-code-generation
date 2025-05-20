//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 3
#define MAX_COLS 3

int board[MAX_ROWS][MAX_COLS];

void print_board() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    // Check rows
    for (int i = 0; i < MAX_ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check cols
    for (int j = 0; j < MAX_COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void make_move(int player) {
    int row, col;

    do {
        printf("Enter row and column (e.g. 0,0): ");
        scanf("%d, %d", &row, &col);
    } while (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS || board[row][col] != 0);

    board[row][col] = player;
}

void play_game() {
    int player = 1;
    int winner = 0;

    while (!winner) {
        make_move(player);
        print_board();
        winner = check_win();
        player = player == 1 ? 2 : 1;
    }

    printf("Player %d wins!\n", winner);
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}