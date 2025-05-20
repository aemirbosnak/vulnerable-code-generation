//Gemma-7B DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

int main() {
    // Initialize the game board
    int board[MAX_NUM][MAX_NUM] = {{0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};

    // Place the initial pieces
    board[1][1] = 1;
    board[2][2] = 2;

    // Game loop
    int game_on = 1;
    while (game_on) {
        // Get the player's move
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Check if the move is valid
        if (board[move_x][move_y] != 0) {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece
        board[move_x][move_y] = 3;

        // Check if the player has won
        int winner = check_winner(board);

        // If the player has won, end the game
        if (winner) {
            game_on = 0;
            printf("Congratulations! You have won!\n");
        }

        // If the board is full, end the game
        else if (board[MAX_NUM - 1][MAX_NUM - 1] == 3) {
            game_on = 0;
            printf("It's a draw!\n");
        }
    }

    return 0;
}

int check_winner(int **board) {
    // Check rows
    for (int r = 0; r < MAX_NUM; r++) {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == board[r][3] && board[r][0] == board[r][4]) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < MAX_NUM; c++) {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == board[3][c] && board[0][c] == board[4][c]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] == board[4][4]) {
        return 1;
    }

    // Check if the board is full
    for (int r = 0; r < MAX_NUM; r++) {
        for (int c = 0; c < MAX_NUM; c++) {
            if (board[r][c] == 0) {
                return 0;
            }
        }
    }

    // If all conditions are met, return 1
    return 0;
}