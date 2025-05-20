//FormAI DATASET v1.0 Category: Chess engine ; Style: single-threaded
#include <stdio.h>

// Constants for the board
#define BOARD_SIZE 8
#define WHITE 'W'
#define BLACK 'B'

// Constants for pieces
#define EMPTY '.'
#define KING 'K'
#define QUEEN 'Q'
#define ROOK 'R'
#define BISHOP 'B'
#define KNIGHT 'N'
#define PAWN 'P'

// Create a 2-dimensional array to represent the board
char board[BOARD_SIZE][BOARD_SIZE];

// Create a function to initialize the board with starting positions
void initialize_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row == 0 || row == 7) {
                // Place the back row pieces in their starting positions
                if (col == 0 || col == 7) {
                    board[row][col] = ROOK;
                } else if (col == 1 || col == 6) {
                    board[row][col] = KNIGHT;
                } else if (col == 2 || col == 5) {
                    board[row][col] = BISHOP;
                } else if (col == 3) {
                    board[row][col] = QUEEN;
                } else {
                    board[row][col] = KING;
                }
                
                // Set the color to white for the back row pieces
                board[row][col+1] = WHITE;
            } else if (row == 1 || row == 6) {
                // Place the pawns in their starting positions
                board[row][col] = PAWN;
                
                // Set the color to white for the second row pieces
                board[row][col+1] = WHITE;
            } else {
                // Empty squares
                board[row][col] = EMPTY;
            }
        }
    }
}

// Create a function to print the board in its current state
void print_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col += 2) {
            // Print the cells in a checkerboard pattern
            printf("%c%c ", board[row][col], board[row][col+1]);
        }
        printf("\n");
    }
}

// Main function to run the program
int main() {
    initialize_board();
    print_board();
    return 0;
}