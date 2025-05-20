//Code Llama-13B DATASET v1.0 Category: Checkers Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Global variables
int board[8][8];
int player1, player2;
int turn;

// Function to initialize the board
void init_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = 0;
        }
    }

    // Place the pieces on the board
    for (int i = 0; i < 8; i++) {
        board[1][i] = 1;
        board[6][i] = 2;
    }

    player1 = 1;
    player2 = 2;
    turn = 1;
}

// Function to print the board
void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 1) {
                printf("1 ");
            } else if (board[i][j] == 2) {
                printf("2 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to make a move
void make_move(int row, int col) {
    if (turn == 1) {
        if (board[row][col] == 1) {
            board[row][col] = 0;
            turn = 2;
        }
    } else {
        if (board[row][col] == 2) {
            board[row][col] = 0;
            turn = 1;
        }
    }
}

// Function to check if a move is valid
int is_valid_move(int row, int col) {
    if (board[row][col] == 1 || board[row][col] == 2) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a player has won
int has_won(int player) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == player) {
                return 1;
            }
        }
    }
    return 0;
}

// Main function
int main() {
    init_board();

    // Game loop
    while (1) {
        print_board();

        int row, col;
        scanf("%d %d", &row, &col);

        if (is_valid_move(row, col)) {
            make_move(row, col);
        } else {
            printf("Invalid move!\n");
            continue;
        }

        if (has_won(player1)) {
            printf("Player 1 has won!\n");
            break;
        } else if (has_won(player2)) {
            printf("Player 2 has won!\n");
            break;
        }
    }

    return 0;
}