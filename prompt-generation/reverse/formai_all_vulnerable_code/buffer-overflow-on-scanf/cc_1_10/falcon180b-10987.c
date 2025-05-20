//Falcon-180B DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define WINNING_NUMBER 15

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
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
    int board[BOARD_SIZE][BOARD_SIZE];
    int player = 1;

    // Initialize board with random numbers
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 10;
        }
    }

    // Print initial board
    printf("Initial board:\n");
    print_board(board);

    while (1) {
        // Print current board
        printf("\nCurrent board:\n");
        print_board(board);

        // Check for win
        if (check_win(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        // Switch player
        player =!player;

        // Get player's move
        int row, col;
        printf("\nPlayer %d, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);

        // Check if move is valid
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col]!= 0) {
            printf("\nInvalid move, try again.\n");
            continue;
        }

        // Update board
        board[row][col] = player;
    }

    return 0;
}