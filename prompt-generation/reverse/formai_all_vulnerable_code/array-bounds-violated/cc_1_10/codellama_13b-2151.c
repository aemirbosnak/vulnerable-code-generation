//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
/*
 * Tic Tac Toe AI in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2
#define EMPTY 0
#define DRAW 3
#define AI_MOVE 4
#define HUMAN_MOVE 5

// Global variables
int board[BOARD_SIZE][BOARD_SIZE];
int turn = 0; // 0: human, 1: AI

// Function prototypes
void print_board();
int check_win();
void make_move(int player, int row, int col);
void random_move();

int main() {
    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Game loop
    while (1) {
        // Print the board
        print_board();

        // Check if the game is over
        int result = check_win();
        if (result != 0) {
            printf("Game over! Player %d wins!\n", result);
            break;
        }

        // Human's turn
        if (turn == 0) {
            // Ask the human for their move
            int row, col;
            printf("Enter row and column (e.g. 0 0): ");
            scanf("%d %d", &row, &col);

            // Make the human's move
            make_move(PLAYER_X, row, col);
            turn = 1;
        }

        // AI's turn
        else {
            // Make a random move
            random_move();
            turn = 0;
        }
    }

    return 0;
}

void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case PLAYER_X:
                    printf("X");
                    break;
                case PLAYER_O:
                    printf("O");
                    break;
                case EMPTY:
                    printf("_");
                    break;
            }
        }
        printf("\n");
    }
}

int check_win() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // Check if the board is full
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }

    // The game is a draw
    return DRAW;
}

void make_move(int player, int row, int col) {
    if (board[row][col] != EMPTY) {
        printf("Invalid move!\n");
        return;
    }

    board[row][col] = player;
}

void random_move() {
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != EMPTY);

    make_move(PLAYER_O, row, col);
}