//Falcon-180B DATASET v1.0 Category: Table Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define BOARD_FULL 9

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_board_full(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int is_winner(int board[BOARD_SIZE][BOARD_SIZE], int player) {
    int i, j;
    
    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    
    // Check columns
    for (j = 0; j < BOARD_SIZE; j++) {
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

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int i, j;
    
    srand(time(NULL));
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
    
    while (!is_board_full(board)) {
        printf("Player %d's turn\n", player);
        printf("Current board:\n");
        print_board(board);
        int row, col;
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0) {
            board[row][col] = player;
            if (is_winner(board, player)) {
                printf("Player %d wins!\n", player);
                break;
            }
        } else {
            printf("Invalid move\n");
        }
        player =!player;
    }
    
    return 0;
}