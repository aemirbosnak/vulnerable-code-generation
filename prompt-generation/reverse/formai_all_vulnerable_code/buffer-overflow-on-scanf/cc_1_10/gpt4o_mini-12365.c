//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *cb) {
    const char *initial[BOARD_SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cb->board[i][j] = initial[i][j];
        }
    }
}

void printBoard(const ChessBoard *cb) {
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            char piece = cb->board[i][j];
            printf("%c ", piece == ' ' ? '.' : piece);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int isValidMove(const ChessBoard *cb, int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE ||
        endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0; // Invalid position
    }
    
    char piece = cb->board[startX][startY];
    
    // Simplified moving logic: only allow moves to empty squares or capturing opposite pieces
    if (cb->board[endX][endY] == ' ' || (cb->board[endX][endY] >= 'a' && cb->board[endX][endY] <= 'z' && piece >= 'A' && piece <= 'Z') ||
        (cb->board[endX][endY] <= 'Z' && cb->board[endX][endY] >= 'A' && piece >= 'a' && piece <= 'z')) {
        return 1; // Valid move
    }
    return 0; // Invalid move 
}

void makeMove(ChessBoard *cb, int startX, int startY, int endX, int endY) {
    cb->board[endX][endY] = cb->board[startX][startY];
    cb->board[startX][startY] = ' ';
}

void playGame() {
    ChessBoard cb;
    initializeBoard(&cb);
    
    while (1) {
        printBoard(&cb);
        
        int startX, startY, endX, endY;
        char startCol, endCol;
        
        printf("Enter move (ex: e2 e4): ");
        scanf(" %c%d %c%d", &startCol, &startX, &endCol, &endX);
        
        // Convert input to array indices
        startY = startCol - 'a';
        endY = endCol - 'a';
        startX -= 1;  // Adjust for 0-indexed array
        endX -= 1;    // Adjust for 0-indexed array
        
        if (isValidMove(&cb, startX, startY, endX, endY)) {
            makeMove(&cb, startX, startY, endX, endY);
        } else {
            printf("Invalid move\n");
        }

        // Check for game over conditions would go here
    }
}

int main() {
    playGame();
    return 0;
}