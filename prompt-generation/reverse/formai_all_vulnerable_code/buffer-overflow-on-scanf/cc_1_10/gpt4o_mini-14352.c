//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *chessBoard) {
    const char *initialConfiguration[BOARD_SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            chessBoard->board[i][j] = initialConfiguration[i][j];
        }
    }
}

void printBoard(const ChessBoard *chessBoard) {
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", chessBoard->board[i][j]);
        }
        printf("|\n");
    }
    printf(" +----------------+\n");
}

int isMoveValid(const ChessBoard *chessBoard, int startX, int startY, int endX, int endY) {
    char piece = chessBoard->board[startX][startY];

    if (piece == '.') return 0; // No piece at start position
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) return 0; // Out of bounds
    if (chessBoard->board[endX][endY] != '.' && 
        ((piece >= 'A' && piece <= 'Z' && chessBoard->board[endX][endY] >= 'A' && chessBoard->board[endX][endY] <= 'Z') || // Can't capture own piece
         (piece >= 'a' && piece <= 'z' && chessBoard->board[endX][endY] >= 'a' && chessBoard->board[endX][endY] <= 'z'))) {
        return 0; 
    }

    // Simplified movement rules (just as a place holder)
    if (piece == 'P') return (endX == startX - 1 && startY == endY); // Move forward
    if (piece == 'r' || piece == 'R') return (startX == endX || startY == endY); // Move like Rook
    if (piece == 'n' || piece == 'N') return (abs(endX - startX) == 2 && abs(endY - startY) == 1) || (abs(endY - startY) == 2 && abs(endX - startX) == 1); // Move like Knight

    return 0; // Not valid by default
}

void movePiece(ChessBoard *chessBoard, int startX, int startY, int endX, int endY) {
    chessBoard->board[endX][endY] = chessBoard->board[startX][startY];
    chessBoard->board[startX][startY] = '.';
}

void playGame() {
    ChessBoard chessBoard;
    initializeBoard(&chessBoard);
    printBoard(&chessBoard);

    int startX, startY, endX, endY;
    while (1) {
        printf("Enter your move (e.g., e2 e4): ");
        char move[10];
        scanf("%s", move);
        
        startX = 8 - (move[1] - '0');
        startY = move[0] - 'a';
        
        scanf("%s", move);
        
        endX = 8 - (move[1] - '0');
        endY = move[0] - 'a';

        if (isMoveValid(&chessBoard, startX, startY, endX, endY)) {
            movePiece(&chessBoard, startX, startY, endX, endY);
            printBoard(&chessBoard);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}