//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the pieces and their corresponding symbols
#define EMPTY ' '
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

// Define the board size
#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
} ChessBoard;

// Function prototypes
void initializeBoard(ChessBoard* cb);
void printBoard(const ChessBoard* cb);
int isMoveValid(const ChessBoard* cb, int srcRow, int srcCol, int destRow, int destCol);
void makeMove(ChessBoard* cb, int srcRow, int srcCol, int destRow, int destCol);

int main() {
    ChessBoard game;
    initializeBoard(&game);
    printBoard(&game);

    while (1) {
        int srcRow, srcCol, destRow, destCol;
        printf("Enter your move (srcRow srcCol destRow destCol): ");
        scanf("%d %d %d %d", &srcRow, &srcCol, &destRow, &destCol);

        if (isMoveValid(&game, srcRow, srcCol, destRow, destCol)) {
            makeMove(&game, srcRow, srcCol, destRow, destCol);
            printBoard(&game);
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    return 0;
}

void initializeBoard(ChessBoard* cb) {
    // Initialize empty squares
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cb->board[i][j] = EMPTY;
        }
    }

    // Setup pawns
    for (int j = 0; j < SIZE; ++j) {
        cb->board[6][j] = PAWN; // Black Pawns
        cb->board[1][j] = PAWN; // White Pawns
    }

    // Setup rooks
    cb->board[0][0] = cb->board[0][7] = ROOK; // Black Rooks
    cb->board[7][0] = cb->board[7][7] = ROOK; // White Rooks

    // Setup knights
    cb->board[0][1] = cb->board[0][6] = KNIGHT; // Black Knights
    cb->board[7][1] = cb->board[7][6] = KNIGHT; // White Knights

    // Setup bishops
    cb->board[0][2] = cb->board[0][5] = BISHOP; // Black Bishops
    cb->board[7][2] = cb->board[7][5] = BISHOP; // White Bishops

    // Setup queens and kings
    cb->board[0][3] = QUEEN; // Black Queen
    cb->board[0][4] = KING;  // Black King
    cb->board[7][3] = QUEEN; // White Queen
    cb->board[7][4] = KING;  // White King
}

void printBoard(const ChessBoard* cb) {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", cb->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isMoveValid(const ChessBoard* cb, int srcRow, int srcCol, int destRow, int destCol) {
    // Ensure the coordinates are within bounds
    if (srcRow < 0 || srcRow >= SIZE || srcCol < 0 || srcCol >= SIZE ||
        destRow < 0 || destRow >= SIZE || destCol < 0 || destCol >= SIZE) {
        return 0;
    }

    char piece = cb->board[srcRow][srcCol];
    // Check if there's a piece to move
    if (piece == EMPTY) return 0;

    // Just a basic validation: Check for moving to an empty square or capturing opponent piece
    char destinationPiece = cb->board[destRow][destCol];
    if (destinationPiece != EMPTY && (destinationPiece < 'A' && piece < 'A')) {
        return 0; // Cannot capture your own piece
    }

    // Allow moving only forward for pawns (example, can expand later)
    if (piece == PAWN) {
        if (srcRow == 1 && destRow == 3 && srcCol == destCol && destinationPiece == EMPTY) {
            return 1; // Initial double jump
        }
        if (destRow == srcRow + 1 && srcCol == destCol && destinationPiece == EMPTY) {
            return 1; // Normal move
        }
        if (destRow == srcRow + 1 && abs(srcCol - destCol) == 1 && destinationPiece < 'A') {
            return 1; // Capture
        }
    }

    // Add more detailed movement rules here...

    return 0; // Default invalid move
}

void makeMove(ChessBoard* cb, int srcRow, int srcCol, int destRow, int destCol) {
    cb->board[destRow][destCol] = cb->board[srcRow][srcCol];
    cb->board[srcRow][srcCol] = EMPTY;
}