//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

// Define piece characters
#define EMPTY ' '
#define PAWN 'P'
#define ROOK 'R'
#define KNIGHT 'N'
#define BISHOP 'B'
#define QUEEN 'Q'
#define KING 'K'

char board[SIZE][SIZE];

// Function to initialize the chess board
void init_board() {
    const char *row1 = "RNBQKBNR";
    const char *row2 = "PPPPPPPP";
    const char *empty_row = "        ";
    
    // Setting up the pieces
    for (int i = 0; i < SIZE; i++) {
        board[0][i] = row1[i];   // Place pieces in the first row
        board[1][i] = row2[i];   // Place pawns in the second row
        board[2][i] = empty_row[i]; // Empty rows
        board[3][i] = empty_row[i];
        board[4][i] = empty_row[i];
        board[5][i] = empty_row[i];
        board[6][i] = row2[i];   // Place pawns in the seventh row
        board[7][i] = row1[i];   // Place pieces in the last row
    }
}

// Function to display the chess board
void display_board() {
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d|", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n +----------------+\n");
    }
}

// Function to move a piece on the board
int move_piece(char *move) {
    int start_col = move[0] - 'a';
    int start_row = move[1] - '1';
    int end_col = move[2] - 'a';
    int end_row = move[3] - '1';

    // Check for out of bounds
    if (start_col < 0 || start_col >= SIZE || start_row < 0 || start_row >= SIZE ||
        end_col < 0 || end_col >= SIZE || end_row < 0 || end_row >= SIZE) {
        printf("Invalid move: Out of bounds\n");
        return 0;
    }

    // Check if there is a piece to move
    if (board[start_row][start_col] == EMPTY) {
        printf("Invalid move: No piece at source\n");
        return 0;
    }

    // Move the piece
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = EMPTY;

    return 1;
}

int main() {
    char move[5];
    init_board(); // Initialize the board
    display_board(); // Show the initial board

    while (1) {
        printf("Enter your move (e.g. e2e4) or 'exit' to quit: ");
        scanf("%s", move);

        if (strcmp(move, "exit") == 0) {
            break; // Exit the game
        }

        if (strlen(move) != 4) {
            printf("Invalid input. Move must be in the format 'e2e4'.\n");
            continue;
        }

        if (move_piece(move)) {
            display_board(); // Display the board after a valid move
        }
    }

    printf("Thanks for playing the whimsical chess game!\n");
    return 0;
}