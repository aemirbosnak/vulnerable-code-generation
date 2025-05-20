//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define NUM_PLAYERS 2

void draw_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(int board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return -1; // No winner
}

void play_game(int board[BOARD_SIZE][BOARD_SIZE]) {
    int current_player = 0;
    int winner = -1;

    while (winner == -1) {
        draw_board(board);
        printf("Player %d's turn.\n", current_player + 1);
        int row, col;
        if (scanf("%d%d", &row, &col)!= 2) {
            printf("Invalid input.\n");
            continue;
        }
        row--;
        col--;
        if (board[row][col]!= 0) {
            printf("Spot already taken.\n");
            continue;
        }
        board[row][col] = current_player + 1;
        winner = check_winner(board);
        if (winner == -1) {
            current_player =!current_player;
        }
    }

    draw_board(board);
    printf("Player %d wins!\n", winner);
}

int main() {
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE] = {{0}};
    play_game(board);
    return 0;
}