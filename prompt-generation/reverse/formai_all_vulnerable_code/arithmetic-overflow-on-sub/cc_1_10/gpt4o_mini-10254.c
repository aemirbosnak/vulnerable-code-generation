//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 8

typedef enum { EMPTY, WHITE, BLACK } Piece;
typedef enum { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } PieceType;

typedef struct {
    Piece piece;
    PieceType type;
} Square;

typedef struct {
    Square board[SIZE][SIZE];
} ChessBoard;

void initBoard(ChessBoard *chessBoard) {
    // Initialize empty board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            chessBoard->board[i][j].piece = EMPTY;
            chessBoard->board[i][j].type = 0;
        }
    }

    // Place black pieces
    chessBoard->board[0][0] = (Square){ BLACK, ROOK };
    chessBoard->board[0][1] = (Square){ BLACK, KNIGHT };
    chessBoard->board[0][2] = (Square){ BLACK, BISHOP };
    chessBoard->board[0][3] = (Square){ BLACK, QUEEN };
    chessBoard->board[0][4] = (Square){ BLACK, KING };
    chessBoard->board[0][5] = (Square){ BLACK, BISHOP };
    chessBoard->board[0][6] = (Square){ BLACK, KNIGHT };
    chessBoard->board[0][7] = (Square){ BLACK, ROOK };
    for (int j = 0; j < SIZE; j++)
        chessBoard->board[1][j] = (Square){ BLACK, PAWN };

    // Place white pieces
    chessBoard->board[7][0] = (Square){ WHITE, ROOK };
    chessBoard->board[7][1] = (Square){ WHITE, KNIGHT };
    chessBoard->board[7][2] = (Square){ WHITE, BISHOP };
    chessBoard->board[7][3] = (Square){ WHITE, QUEEN };
    chessBoard->board[7][4] = (Square){ WHITE, KING };
    chessBoard->board[7][5] = (Square){ WHITE, BISHOP };
    chessBoard->board[7][6] = (Square){ WHITE, KNIGHT };
    chessBoard->board[7][7] = (Square){ WHITE, ROOK };
    for (int j = 0; j < SIZE; j++)
        chessBoard->board[6][j] = (Square){ WHITE, PAWN };
}

void printBoard(ChessBoard *chessBoard) {
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            if (chessBoard->board[i][j].piece == EMPTY) {
                printf(". ");
            } else if (chessBoard->board[i][j].piece == WHITE) {
                printf("W ");
            } else {
                printf("B ");
            }
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

bool isMoveValid(ChessBoard *chessBoard, int startX, int startY, int endX, int endY) {
    // Basic move validation: Check if the target square is empty or contains opponent's piece
    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE)
        return false;
    if (chessBoard->board[endX][endY].piece == chessBoard->board[startX][startY].piece)
        return false;
    return true;
}

bool makeMove(ChessBoard *chessBoard, int startX, int startY, int endX, int endY) {
    if (isMoveValid(chessBoard, startX, startY, endX, endY)) {
        chessBoard->board[endX][endY] = chessBoard->board[startX][startY];
        chessBoard->board[startX][startY] = (Square){ EMPTY, 0 };
        return true;
    }
    return false;
}

void playGame() {
    ChessBoard chessBoard;
    initBoard(&chessBoard);
    printBoard(&chessBoard);
    
    int startX, startY, endX, endY;
    char startCol, endCol;
    while (true) {
        printf("Enter your move (e.g., e2 e4): ");
        scanf(" %c%d %c%d", &startCol, &startX, &endCol, &endX);
        startX = 8 - startX; // Convert rank to array index
        endX = 8 - endX;     // Convert rank to array index
        startY = startCol - 'a';
        endY = endCol - 'a';

        if (!makeMove(&chessBoard, startX, startY, endX, endY)) {
            printf("Invalid move, try again.\n");
        } else {
            printBoard(&chessBoard);
        }
    }
}

int main() {
    playGame();
    return 0;
}