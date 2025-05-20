//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define PLAYERS 4

// Structure to represent a player's turn
typedef struct {
    int row;
    int col;
} turn_t;

// Global variable to store the game board
char board[ROWS][COLS];

// Function to initialize the game board with random values
void init_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 'O' + (rand() % 2);
        }
    }
}

// Function to print the game board
void print_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get a player's move
turn_t get_move(int player_num) {
    int row, col;
    printf("Player %d, enter row and column (1-%d, 1-%d): ", player_num, ROWS, COLS);
    scanf("%d%d", &row, &col);
    return (turn_t) {row, col};
}

// Function to update the game board based on a player's move
void update_board(turn_t move) {
    board[move.row][move.col] = 'X';
}

// Function to check if a player has won
int check_win(int player_num) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == player_num + '1') {
                return 1; // Return 1 if the player has won
            }
        }
    }
    return 0; // Return 0 if no player has won
}

// Main game loop
int main() {
    srand(time(NULL)); // Seed the random number generator
    init_board();
    print_board();

    for (int i = 0; i < PLAYERS; i++) {
        turn_t move = get_move(i);
        update_board(move);
        print_board();

        if (check_win(i)) {
            printf("Player %d has won!", i + 1);
            return 0;
        }
    }

    return 1; // Return 1 if no player has won
}