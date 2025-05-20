//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define MAX_MOVES 100

typedef enum { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } PieceType;
typedef enum { WHITE, BLACK } Color;

typedef struct {
    PieceType type;
    Color color;
} Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

typedef struct {
    int startX, startY, endX, endY;
} Move;

void initializeBoard(ChessBoard* chessBoard) {
    // Initialize empty board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            chessBoard->board[i][j].type = EMPTY;
        }
    }

    // Setup pieces
    for (int j = 0; j < BOARD_SIZE; j++) {
        chessBoard->board[1][j] = (Piece) { PAWN, WHITE };
        chessBoard->board[6][j] = (Piece) { PAWN, BLACK };
    }

    chessBoard->board[0][0] = (Piece) { ROOK, WHITE };
    chessBoard->board[0][1] = (Piece) { KNIGHT, WHITE };
    chessBoard->board[0][2] = (Piece) { BISHOP, WHITE };
    chessBoard->board[0][3] = (Piece) { QUEEN, WHITE };
    chessBoard->board[0][4] = (Piece) { KING, WHITE };
    chessBoard->board[0][5] = (Piece) { BISHOP, WHITE };
    chessBoard->board[0][6] = (Piece) { KNIGHT, WHITE };
    chessBoard->board[0][7] = (Piece) { ROOK, WHITE };

    chessBoard->board[7][0] = (Piece) { ROOK, BLACK };
    chessBoard->board[7][1] = (Piece) { KNIGHT, BLACK };
    chessBoard->board[7][2] = (Piece) { BISHOP, BLACK };
    chessBoard->board[7][3] = (Piece) { QUEEN, BLACK };
    chessBoard->board[7][4] = (Piece) { KING, BLACK };
    chessBoard->board[7][5] = (Piece) { BISHOP, BLACK };
    chessBoard->board[7][6] = (Piece) { KNIGHT, BLACK };
    chessBoard->board[7][7] = (Piece) { ROOK, BLACK };
}

void printBoard(const ChessBoard* chessBoard) {
    const char* pieceSymbols[2][7] = {
        {".", "P", "N", "B", "R", "Q", "K"},
        {".", "p", "n", "b", "r", "q", "k"}
    };

    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece = chessBoard->board[i][j];
            printf("%s ", pieceSymbols[piece.color][piece.type]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

bool moveIsValid(const ChessBoard* chessBoard, Move move) {
    // Simplified movement check (not complete)
    Piece piece = chessBoard->board[move.startY][move.startX];
    if (piece.type == EMPTY || (move.endX < 0 || move.endX >= BOARD_SIZE || 
        move.endY < 0 || move.endY >= BOARD_SIZE)) {
        return false;
    }
    // Additional logic for piece movements and checking for own pieces...
    return true;
}

void makeMove(ChessBoard* chessBoard, Move move) {
    if (moveIsValid(chessBoard, move)) {
        chessBoard->board[move.endY][move.endX] = chessBoard->board[move.startY][move.startX];
        chessBoard->board[move.startY][move.startX] = (Piece) { EMPTY, WHITE }; // clear old position
    }
}

int main() {
    ChessBoard chessBoard;
    initializeBoard(&chessBoard);
    
    Move moves[MAX_MOVES];
    int moveCount = 0;

    while (moveCount < MAX_MOVES) {
        printBoard(&chessBoard);
        
        // Assume input in format: "startX startY endX endY"
        char input[100];
        printf("Enter your move: ");
        fgets(input, sizeof(input), stdin);
        
        Move move;
        sscanf(input, "%d %d %d %d", &move.startX, &move.startY, &move.endX, &move.endY);
        
        makeMove(&chessBoard, move);
        moveCount++;
    }

    return 0;
}