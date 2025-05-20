//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// Chess pieces
#define EMPTY ' '
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

// Function prototypes
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
int isMoveValid(char board[BOARD_SIZE][BOARD_SIZE], int srcX, int srcY, int destX, int destY);
void movePiece(char board[BOARD_SIZE][BOARD_SIZE], int srcX, int srcY, int destX, int destY);
int isGameOver(char board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    int srcX, srcY, destX, destY;
    while (!isGameOver(board)) {
        printBoard(board);
        printf("Enter your move (srcX srcY destX destY): ");
        scanf("%d %d %d %d", &srcX, &srcY, &destX, &destY);

        if (isMoveValid(board, srcX, srcY, destX, destY)) {
            movePiece(board, srcX, srcY, destX, destY);
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    printf("Game Over!\n");
    printBoard(board);
    return 0;
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    const char* initialRow[] = {
        "RNBQKBNR",
        "PPPPPPPP",
        "        ",
        "        ",
        "        ",
        "        ",
        "pppppppp",
        "rnbqkbnr"
    };

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = initialRow[i][j];
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n  A B C D E F G H\n");
    printf(" +----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n +----------------\n");
    }
}

int isMoveValid(char board[BOARD_SIZE][BOARD_SIZE], int srcX, int srcY, int destX, int destY) {
    if (srcX < 0 || srcX >= BOARD_SIZE || srcY < 0 || srcY >= BOARD_SIZE ||
        destX < 0 || destX >= BOARD_SIZE || destY < 0 || destY >= BOARD_SIZE) {
        return 0; // Out of bounds
    }

    char piece = board[srcX][srcY];
    if (piece == EMPTY) {
        return 0; // No piece to move
    }

    // For this example, we just allow any movement - no real chess logic.
    return 1;
}

void movePiece(char board[BOARD_SIZE][BOARD_SIZE], int srcX, int srcY, int destX, int destY) {
    board[destX][destY] = board[srcX][srcY];
    board[srcX][srcY] = EMPTY; // Empty the original cell
}

int isGameOver(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Simplified check for game over, if one side has no kings
    int whiteKing = 0, blackKing = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == KING) whiteKing = 1;
            if (board[i][j] == 'k') blackKing = 1;
        }
    }
    return !(whiteKing && blackKing);
}