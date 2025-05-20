//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

// Game board representation
char board[BOARD_SIZE][BOARD_SIZE];

// Player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// AI symbols
#define AI_X 'x'
#define AI_O 'o'

// Function to print the game board
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
int check_win(char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        int row_win = 1;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != player) {
                row_win = 0;
                break;
            }
        }
        if (row_win) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        int col_win = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j] != player) {
                col_win = 0;
                break;
            }
        }
        if (col_win) {
            return 1;
        }
    }

    // Check diagonals
    int diag_win = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] != player) {
            diag_win = 0;
            break;
        }
    }
    if (diag_win) {
        return 1;
    }

    diag_win = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE - i - 1] != player) {
            diag_win = 0;
            break;
        }
    }
    if (diag_win) {
        return 1;
    }

    return 0;
}

// Function to check if the game is over
int check_game_over() {
    if (check_win(PLAYER_X) || check_win(PLAYER_O)) {
        return 1;
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to make a move for the AI
void make_ai_move() {
    int i, j;
    do {
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
    } while (board[i][j] != 0);
    board[i][j] = AI_X;
}

// Function to make a move for the player
void make_player_move() {
    int i, j;
    do {
        printf("Enter row and column (0-based): ");
        scanf("%d %d", &i, &j);
    } while (board[i][j] != 0);
    board[i][j] = PLAYER_X;
}

// Main function
int main() {
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Game loop
    while (1) {
        // Print the game board
        print_board();

        // Make a move for the player
        make_player_move();

        // Check if the game is over
        if (check_game_over()) {
            break;
        }

        // Make a move for the AI
        make_ai_move();

        // Check if the game is over
        if (check_game_over()) {
            break;
        }
    }

    // Print the final game board
    print_board();

    return 0;
}