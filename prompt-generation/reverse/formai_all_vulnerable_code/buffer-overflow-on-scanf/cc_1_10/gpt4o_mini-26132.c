//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define WHITE 'W'
#define BLACK 'B'
#define EMPTY '.'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int white_king_x, white_king_y;
    int black_king_x, black_king_y;
} ChessBoard;

void initializeBoard(ChessBoard *chess) {
    const char *initialSetup[BOARD_SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBQR"
    };
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        strcpy(chess->board[i], initialSetup[i]);
    }

    chess->white_king_x = 7;
    chess->white_king_y = 4;
    chess->black_king_x = 0;
    chess->black_king_y = 4;
}

void printBoard(const ChessBoard *chess) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", chess->board[i][j]);
        }
        printf("\n");
    }
}

bool isValidMove(const ChessBoard *chess, int from_x, int from_y, int to_x, int to_y) {
    char piece = chess->board[from_x][from_y];
    
    if (piece == EMPTY || (from_x < 0 || from_x >= BOARD_SIZE || from_y < 0 || from_y >= BOARD_SIZE
        || to_x < 0 || to_x >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE)) {
        return false;
    }
    
    if (piece >= 'A' && piece <= 'Z' && chess->board[to_x][to_y] >= 'A' && chess->board[to_x][to_y] <= 'Z') {
        return false; // Can't capture your own piece
    }
    
    // Simplified movement rules (not complete):
    if (piece == 'P') {  // Pawn
        return (to_x == from_x - 1 && to_y == from_y) || (to_x == from_x - 1 && abs(to_y - from_y) == 1);
    }
    
    if (piece == 'R' || piece == 'r') { // Rook
        return (to_x == from_x || to_y == from_y);
    }
    
    return true; // For other pieces, add logic
}

void movePiece(ChessBoard *chess, int from_x, int from_y, int to_x, int to_y) {
    chess->board[to_x][to_y] = chess->board[from_x][from_y];
    chess->board[from_x][from_y] = EMPTY;
    
    // Update kings' positions if necessary
    if (chess->board[to_x][to_y] == 'K') {
        chess->white_king_x = to_x;
        chess->white_king_y = to_y;
    }
    if (chess->board[to_x][to_y] == 'k') {
        chess->black_king_x = to_x;
        chess->black_king_y = to_y;
    }
}

bool isCheck(const ChessBoard *chess, char color) {
    int king_x = (color == WHITE) ? chess->white_king_x : chess->black_king_x;
    int king_y = (color == WHITE) ? chess->white_king_y : chess->black_king_y;

    // Check for simple attacks (need detailed logic per piece)
    return false; // This function needs complete checks
}

void playGame() {
    ChessBoard chess;
    initializeBoard(&chess);
    char turn = WHITE;
    int from_x, from_y, to_x, to_y;

    while (true) {
        printBoard(&chess);
        
        printf("Current turn: %s\n", (turn == WHITE) ? "White" : "Black");
        printf("Enter move (from_x from_y to_x to_y): ");
        scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);
        
        if (isValidMove(&chess, from_x, from_y, to_x, to_y)) {
            movePiece(&chess, from_x, from_y, to_x, to_y);
            if (isCheck(&chess, (turn == WHITE) ? BLACK : WHITE)) {
                printf("Check!\n");
            }
            turn = (turn == WHITE) ? BLACK : WHITE;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}