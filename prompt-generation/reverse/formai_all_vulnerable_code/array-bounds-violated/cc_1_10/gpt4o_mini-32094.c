//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    board[i][j] = 'B';  // Black pieces
                } else if (i > 4) {
                    board[i][j] = 'R';  // Red pieces
                } else {
                    board[i][j] = '.';  // Empty space
                }
            } else {
                board[i][j] = ' ';  // No piece on the white squares
            }
        }
    }
}

// Function to print the board
void print_board() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
bool is_valid_move(int srcRow, int srcCol, int destRow, int destCol, char player) {
    if (destRow < 0 || destRow >= BOARD_SIZE || destCol < 0 || destCol >= BOARD_SIZE) return false;
    if (board[destRow][destCol] != '.') return false;
    if (player == 'B' && destRow - srcRow == 1 && abs(destCol - srcCol) == 1) return true;  // Regular move downwards
    if (player == 'R' && srcRow - destRow == 1 && abs(destCol - srcCol) == 1) return true;  // Regular move upwards
    return false;
}

// Function to move a piece
void move_piece(int srcRow, int srcCol, int destRow, int destCol) {
    board[destRow][destCol] = board[srcRow][srcCol];
    board[srcRow][srcCol] = '.';
}

// Function to run the game
void play_checkers() {
    char current_player = 'R';  // Start with Red
    int srcRow, srcCol, destRow, destCol;
    while (true) {
        print_board();
        printf("Player %c's turn. Enter move (e.g., A3 B4): ", current_player);
        char srcColLetter, destColLetter;
        scanf(" %c%d %c%d", &srcColLetter, &srcRow, &destColLetter, &destRow);

        srcCol = srcColLetter - 'A';
        destCol = destColLetter - 'A';
        srcRow--; // Adjusting for internal array index (0-7)
        destRow--;

        if (is_valid_move(srcRow, srcCol, destRow, destCol, current_player)) {
            move_piece(srcRow, srcCol, destRow, destCol);
            current_player = (current_player == 'R') ? 'B' : 'R';  // Switch players
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}

int main() {
    initialize_board();
    play_checkers();
    return 0;
}