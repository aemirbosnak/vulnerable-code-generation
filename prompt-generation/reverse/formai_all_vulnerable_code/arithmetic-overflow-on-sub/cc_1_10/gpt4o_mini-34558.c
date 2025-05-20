//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 8

// Piece representation
#define EMPTY ' '
#define PAWN 'P'
#define ROOK 'R'
#define KNIGHT 'N'
#define BISHOP 'B'
#define QUEEN 'Q'
#define KING 'K'

// Enums for colors
typedef enum { WHITE, BLACK } Color;

// Struct to represent the chessboard
typedef struct {
    char squares[BOARD_SIZE][BOARD_SIZE];
    Color turn;
} Board;

// Functions to initialize the board and display it
void initializeBoard(Board* board) {
    char initialLayout[BOARD_SIZE][BOARD_SIZE] = {
        { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK },
        { PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN },
        { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK }
    };

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board->squares[i][j] = initialLayout[i][j];
        }
    }
    board->turn = WHITE;
}

void displayBoard(const Board* board) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%c ", board->squares[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isMoveValid(const Board* board, int startX, int startY, int endX, int endY) {
    char piece = board->squares[startX][startY];
    char target = board->squares[endX][endY];

    if (piece == EMPTY || (target != EMPTY && target < 'A' && piece < 'A')) {
        return false; // Invalid move
    }

    // Add basic validation logic for pieces (a simplified version)
    switch (piece) {
        case PAWN:
            return (endX == startX + 1 && endY == startY); // just move forward for now
        case ROOK:
            return (endX == startX || endY == startY); // straight movement
        case KNIGHT:
            return (abs(endX - startX) == 2 && abs(endY - startY) == 1) || 
                   (abs(endX - startX) == 1 && abs(endY - startY) == 2); // L-shape
        case BISHOP:
            return abs(endX - startX) == abs(endY - startY); // diagonal movement
        case QUEEN:
            return (endX == startX || endY == startY || abs(endX - startX) == abs(endY - startY)); // straight or diagonal
        case KING:
            return abs(endX - startX) <= 1 && abs(endY - startY) <= 1; // one square in any direction
        default:
            return false;
    }
}

void makeMove(Board* board, int startX, int startY, int endX, int endY) {
    board->squares[endX][endY] = board->squares[startX][startY];
    board->squares[startX][startY] = EMPTY;
    board->turn = (board->turn == WHITE) ? BLACK : WHITE;
}

int main() {
    Board board;
    initializeBoard(&board);
    displayBoard(&board);

    while (true) {
        int startX, startY, endX, endY;
        printf("Enter your move (startX startY endX endY) or -1 to exit: ");
        scanf("%d", &startX);
        if (startX == -1) break; // Exit condition
        scanf("%d %d %d", &startY, &endX, &endY);
        
        if (isMoveValid(&board, startX, startY, endX, endY)) {
            makeMove(&board, startX, startY, endX, endY);
            displayBoard(&board);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    printf("Game over!\n");
    return 0;
}