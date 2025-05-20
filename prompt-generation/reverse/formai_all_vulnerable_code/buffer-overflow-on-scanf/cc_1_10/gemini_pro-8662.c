//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Represents a piece on the board
typedef enum {
    EMPTY,
    RED,
    BLACK
} Piece;

// Represents the current state of the board
Piece board[BOARD_SIZE][BOARD_SIZE];

// Function to print the board
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case RED:
                    printf("R");
                    break;
                case BLACK:
                    printf("B");
                    break;
            }
        }
        printf("\n");
    }
}

// Function to initialize the board
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Place the red pieces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = RED;
            }
        }
    }

    // Place the black pieces
    for (int i = BOARD_SIZE - 3; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = BLACK;
            }
        }
    }
}

// Function to get the piece at a given position
Piece get_piece(int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return EMPTY;
    }

    return board[x][y];
}

// Function to check if a move is valid
int is_valid_move(Piece player, int from_x, int from_y, int to_x, int to_y) {
    // Check if the player is trying to move their own piece
    if (get_piece(from_x, from_y) != player) {
        return 0;
    }

    // Check if the destination square is empty
    if (get_piece(to_x, to_y) != EMPTY) {
        return 0;
    }

    // Check if the move is a single diagonal move
    if (abs(to_x - from_x) != 1 || abs(to_y - from_y) != 1) {
        return 0;
    }

    // Check if there is an opponent's piece to jump over
    if (player == RED) {
        if (get_piece(to_x - 1, to_y - 1) == BLACK) {
            return 1;
        }
    } else {
        if (get_piece(to_x + 1, to_y + 1) == RED) {
            return 1;
        }
    }

    return 0;
}

// Function to make a move
void make_move(Piece player, int from_x, int from_y, int to_x, int to_y) {
    // Check if the move is valid
    if (!is_valid_move(player, from_x, from_y, to_x, to_y)) {
        return;
    }

    // Move the piece
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = EMPTY;

    // Check if the piece has reached the other side of the board
    if (player == RED && to_x == 7) {
        board[to_x][to_y] = BLACK;
    } else if (player == BLACK && to_x == 0) {
        board[to_x][to_y] = RED;
    }
}

// Function to check if a player has won
int has_won(Piece player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    // Initialize the board
    initialize_board();

    // Print the board
    print_board();

    // Get the player's move
    int from_x, from_y, to_x, to_y;
    printf("Enter your move (from x, y to x, y): ");
    scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);

    // Make the move
    make_move(RED, from_x, from_y, to_x, to_y);

    // Print the board
    print_board();

    // Check if the player has won
    if (has_won(RED)) {
        printf("Red wins!\n");
    } else if (has_won(BLACK)) {
        printf("Black wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}