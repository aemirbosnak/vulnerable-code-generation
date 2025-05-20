//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 8
#define WHITE 'W'
#define BLACK 'B'
#define EMPTY ' '

char board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            board[i][j] = EMPTY;

    // Place pawns
    for (int j = 0; j < SIZE; j++) {
        board[1][j] = WHITE;  // White pawns
        board[6][j] = BLACK;  // Black pawns
    }

    // Place other pieces
    char pieces[] = { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };
    for (int j = 0; j < SIZE; j++) {
        board[0][j] = pieces[j]; // White pieces
        board[7][j] = pieces[j] + 32; // Black pieces (lowercase)
    }
}

void printBoard() {
    printf("  a b c d e f g h\n");
    printf(" +----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("+----------------\n");
}

bool isValidMove(int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE || 
        endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE)
        return false;

    char piece = board[startX][startY];
    if (piece == EMPTY || (piece >= 'a' && piece <= 'z' && piece != BLACK) ||
        (piece >= 'A' && piece <= 'Z' && piece != WHITE))
        return false;

    // Basic pawn movement logic for demonstration
    if (piece == WHITE) {
        if (startX == 1 && startY == endY && (endX == startX + 1 || endX == startX + 2) && 
            board[endX][endY] == EMPTY)  // Pawn initial double move
            return true;
        if (startX + 1 == endX && startY == endY && board[endX][endY] == EMPTY) // Pawn single move
            return true;
        if (startX + 1 == endX && (startY - 1 == endY || startY + 1 == endY) &&
            board[endX][endY] >= 'a' && board[endX][endY] <= 'z') // Capturing a piece
            return true;
    } else if (piece == BLACK) {
        if (startX == 6 && startY == endY && (endX == startX - 1 || endX == startX - 2) && 
            board[endX][endY] == EMPTY)  // Pawn initial double move
            return true;
        if (startX - 1 == endX && startY == endY && board[endX][endY] == EMPTY) // Pawn single move
            return true;
        if (startX - 1 == endX && (startY - 1 == endY || startY + 1 == endY) &&
            board[endX][endY] >= 'A' && board[endX][endY] <= 'Z') // Capturing a piece
            return true;
    }
    return false;
}

void makeMove(int startX, int startY, int endX, int endY) {
    if (isValidMove(startX, startY, endX, endY)) {
        board[endX][endY] = board[startX][startY];
        board[startX][startY] = EMPTY;
    } else {
        printf("Invalid Move!\n");
    }
}

void getMove(int *startX, int *startY, int *endX, int *endY) {
    char from[3], to[3];
    printf("Enter move (e.g., e2 e4): ");
    scanf("%s %s", from, to);

    *startX = SIZE - (from[1] - '0'); // Convert to array index
    *startY = from[0] - 'a';          // Convert to array index
    *endX = SIZE - (to[1] - '0');     // Convert to array index
    *endY = to[0] - 'a';               // Convert to array index
}

int main() {
    initializeBoard();
    while (true) {
        printBoard();
        int startX, startY, endX, endY;
        getMove(&startX, &startY, &endX, &endY);
        makeMove(startX, startY, endX, endY);
    }
    return 0;
}