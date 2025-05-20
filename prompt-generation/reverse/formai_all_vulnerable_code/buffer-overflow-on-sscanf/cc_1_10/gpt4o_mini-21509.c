//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE_PAWN 'P'
#define BLACK_PAWN 'p'
#define WHITE_ROOK 'R'
#define BLACK_ROOK 'r'

char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the chess board
void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 1) {
                board[i][j] = WHITE_PAWN;
            } else if (i == 6) {
                board[i][j] = BLACK_PAWN;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
    board[0][0] = WHITE_ROOK;     board[0][7] = WHITE_ROOK;
    board[7][0] = BLACK_ROOK;     board[7][7] = BLACK_ROOK;
}

// Function to print the chess board
void printBoard() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("-------------------------\n");
    }
}

// Function to move a piece on the board
int movePiece(int startRow, int startCol, int endRow, int endCol) {
    if (startRow < 0 || startRow >= BOARD_SIZE || startCol < 0 || startCol >= BOARD_SIZE ||
        endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        printf("Invalid move: out of bounds.\n");
        return 0;
    }
    
    if (board[startRow][startCol] == EMPTY) {
        printf("Invalid move: no piece at starting position.\n");
        return 0;
    }

    // Basic move legality check (not comprehensive)
    if (board[endRow][endCol] != EMPTY) {
        printf("Invalid move: target position occupied.\n");
        return 0;
    }

    // Move the piece
    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = EMPTY;
    return 1;
}

// Function to play a game of chess against a simple console interface
void playGame() {
    char command[100];
    int startRow, startCol, endRow, endCol;

    while (1) {
        printBoard();
        printf("Enter your move (e.g., 1 0 3 0 for moving from (1,0) to (3,0)) or 'quit' to exit: ");
        
        fgets(command, sizeof(command), stdin);
        if (strcmp(command, "quit\n") == 0) {
            break;
        }

        if (sscanf(command, "%d %d %d %d", &startRow, &startCol, &endRow, &endCol) == 4) {
            movePiece(startRow, startCol, endRow, endCol);
        } else {
            printf("Invalid input. Please enter four integers (startRow startCol endRow endCol).\n");
        }
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}