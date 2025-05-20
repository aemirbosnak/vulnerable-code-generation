//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define NUM_PLAYERS 2

enum Player {
    PLAYER_X,
    PLAYER_O
};

typedef struct {
    int player;
    int x;
    int y;
} Move;

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], enum Player player) {
    int win_count = 0;

    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            win_count++;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            win_count++;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        win_count++;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        win_count++;
    }

    return win_count == 3;
}

int main() {
    srand(time(NULL));

    char board[BOARD_SIZE][BOARD_SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int current_player = PLAYER_X;

    while (!check_win(board, current_player)) {
        printf("Current board:\n");
        print_board(board);

        int x, y;
        printf("Player %d, enter your move (row and column): ", current_player + 1);
        scanf("%d%d", &x, &y);

        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == (char)('0' + current_player)) {
            board[x][y] = (char)('0' + (current_player == PLAYER_X? PLAYER_O : PLAYER_X));
            current_player = (current_player == PLAYER_X? PLAYER_O : PLAYER_X);
        } else {
            printf("Invalid move.\n");
        }
    }

    printf("Game over! Player %d wins!\n", current_player + 1);

    return 0;
}