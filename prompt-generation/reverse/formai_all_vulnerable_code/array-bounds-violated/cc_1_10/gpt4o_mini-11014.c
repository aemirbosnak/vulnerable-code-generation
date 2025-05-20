//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum {
    EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
} Piece;

typedef struct {
    Piece piece;
    int color; // 0 for white, 1 for black
} Square;

typedef struct {
    Square board[SIZE][SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *chessBoard) {
    // Set up the initial chess board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            chessBoard->board[i][j].piece = EMPTY;
            chessBoard->board[i][j].color = -1; // Indicates empty
        }
    }
    
    // Set up pawns
    for (int i = 0; i < SIZE; i++) {
        chessBoard->board[1][i] = (Square){PAWN, 0}; // White Pawns
        chessBoard->board[6][i] = (Square){PAWN, 1}; // Black Pawns
    }

    // Set up other pieces
    chessBoard->board[0][0] = (Square){ROOK, 0}; chessBoard->board[0][7] = (Square){ROOK, 0};
    chessBoard->board[0][1] = (Square){KNIGHT, 0}; chessBoard->board[0][6] = (Square){KNIGHT, 0};
    chessBoard->board[0][2] = (Square){BISHOP, 0}; chessBoard->board[0][5] = (Square){BISHOP, 0};
    chessBoard->board[0][3] = (Square){QUEEN, 0};
    chessBoard->board[0][4] = (Square){KING, 0};

    chessBoard->board[7][0] = (Square){ROOK, 1}; chessBoard->board[7][7] = (Square){ROOK, 1};
    chessBoard->board[7][1] = (Square){KNIGHT, 1}; chessBoard->board[7][6] = (Square){KNIGHT, 1};
    chessBoard->board[7][2] = (Square){BISHOP, 1}; chessBoard->board[7][5] = (Square){BISHOP, 1};
    chessBoard->board[7][3] = (Square){QUEEN, 1};
    chessBoard->board[7][4] = (Square){KING, 1};
}

void displayBoard(ChessBoard *chessBoard) {
    const char *pieceSymbols[] = {".", "P", "N", "B", "R", "Q", "K"};
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            if (chessBoard->board[i][j].piece == EMPTY) {
                printf("%s ", pieceSymbols[0]);
            } else {
                printf("%s ", pieceSymbols[chessBoard->board[i][j].piece + 1]);
            }
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int isMoveValid(ChessBoard *chessBoard, int startX, int startY, int targetX, int targetY) {
    // Placeholder for move validation logic
    // A real implementation would check for piece rules and game rules
    return (targetX >= 0 && targetX < SIZE && targetY >= 0 && targetY < SIZE);
}

void movePiece(ChessBoard *chessBoard, int startX, int startY, int targetX, int targetY) {
    if (isMoveValid(chessBoard, startX, startY, targetX, targetY)) {
        chessBoard->board[targetX][targetY] = chessBoard->board[startX][startY];
        chessBoard->board[startX][startY] = (Square){EMPTY, -1}; // Empty the start square
    } else {
        printf("Invalid move!\n");
    }
}

int main() {
    ChessBoard chessBoard;
    initializeBoard(&chessBoard);
    displayBoard(&chessBoard);

    // Sample move: Move a white pawn from (1, 0) to (3, 0)
    movePiece(&chessBoard, 1, 0, 3, 0);
    displayBoard(&chessBoard);

    return 0;
}