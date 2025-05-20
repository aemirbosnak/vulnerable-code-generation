//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE 'W'
#define BLACK 'B'
#define EMPTY '.'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *chessBoard) {
    const char *initialRow[8] = {
        "rnbqkbnr", // Black pieces
        "pppppppp", // Black pawns
        "........", // Empty
        "........", // Empty
        "........", // Empty
        "........", // Empty
        "PPPPPPPP", // White pawns
        "RNBQKBNR"  // White pieces
    };
    for (int i = 0; i < BOARD_SIZE; i++) {
        strncpy(chessBoard->board[i], initialRow[i], BOARD_SIZE);
    }
}

void printBoard(const ChessBoard *chessBoard) {
    printf("  a b c d e f g h\n");
    printf(" +----------------\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d|", 8 - row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", chessBoard->board[row][col]);
        }
        printf("|\n");
    }
    printf(" +----------------\n");
}

int isValidMove(ChessBoard *chessBoard, int fromRank, int fromFile, int toRank, int toFile) {
    // Add basic move validation logic
    // We can improve this later with more rules
    char piece = chessBoard->board[fromRank][fromFile];
    if (piece == EMPTY) return 0;  // No piece at 'from'
    if (toRank < 0 || toRank >= BOARD_SIZE || toFile < 0 || toFile >= BOARD_SIZE) return 0; // Out of bounds
    char targetPiece = chessBoard->board[toRank][toFile];
    if (targetPiece != EMPTY && ((piece >= 'a' && piece <= 'z' && targetPiece >= 'a' && targetPiece <= 'z') || (piece >= 'A' && piece <= 'Z' && targetPiece >= 'A' && targetPiece <= 'Z'))) return 0; // Can't capture own piece
    return 1; // Valid move for now
}

void makeMove(ChessBoard *chessBoard, int fromRank, int fromFile, int toRank, int toFile) {
    chessBoard->board[toRank][toFile] = chessBoard->board[fromRank][fromFile];
    chessBoard->board[fromRank][fromFile] = EMPTY;
}

void parseMove(const char *move, int *fromRank, int *fromFile, int *toRank, int *toFile) {
    // Convert chess notation e.g., e2 to e4
    *fromFile = move[0] - 'a';
    *fromRank = 8 - (move[1] - '0'); // Invert rank
    *toFile = move[2] - 'a';
    *toRank = 8 - (move[3] - '0');
}

int main() {
    ChessBoard chessBoard;
    initializeBoard(&chessBoard);
    char move[5];
    
    while (1) {
        printBoard(&chessBoard);
        printf("Enter your move (e.g., e2e4): ");
        
        if (scanf("%s", move) != 1) break; // Handle input
        if (strlen(move) != 4) {
            printf("Invalid move format. Use e2e4 notation.\n");
            continue;
        }

        int fromRank, fromFile, toRank, toFile;
        parseMove(move, &fromRank, &fromFile, &toRank, &toFile);

        if (isValidMove(&chessBoard, fromRank, fromFile, toRank, toFile)) {
            makeMove(&chessBoard, fromRank, fromFile, toRank, toFile);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}