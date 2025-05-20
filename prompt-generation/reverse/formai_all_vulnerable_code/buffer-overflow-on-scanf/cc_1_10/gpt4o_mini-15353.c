//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define EMPTY ' '
#define WHITE_PAWN 'W'
#define BLACK_PAWN 'B'
#define WHITE_KING 'WK'
#define BLACK_KING 'BK'

void initializeBoard(char board[SIZE][SIZE]) {
    // Initialize empty board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Place the white pawns
    for (int j = 0; j < SIZE; j += 2) {
        board[0][j] = WHITE_PAWN;
        board[1][j + 1] = WHITE_PAWN;
        board[2][j] = WHITE_PAWN;
    }

    // Place the black pawns
    for (int j = 0; j < SIZE; j += 2) {
        board[5][j + 1] = BLACK_PAWN;
        board[6][j] = BLACK_PAWN;
        board[7][j + 1] = BLACK_PAWN;
    }
}

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(char board[SIZE][SIZE], int fromX, int fromY, int toX, int toY, char player) {
    if (toX < 0 || toX >= SIZE || toY < 0 || toY >= SIZE) return 0;
    if (board[toX][toY] != EMPTY) return 0; // target must be empty
    if (abs(fromX - toX) == 1 && abs(fromY - toY) == 1) return 1; // normal move
    if (abs(fromX - toX) == 2 && abs(fromY - toY) == 2 && 
        board[(fromX + toX) / 2][(fromY + toY) / 2] != EMPTY && 
        board[(fromX + toX) / 2][(fromY + toY) / 2] != player) {
        return 1; // capture
    }
    return 0;
}

void makeMove(char board[SIZE][SIZE], int fromX, int fromY, int toX, int toY) {
    board[toX][toY] = board[fromX][fromY];
    board[fromX][fromY] = EMPTY;

    // Capture logic
    if (abs(fromX - toX) == 2) {
        int capturedX = (fromX + toX) / 2;
        int capturedY = (fromY + toY) / 2;
        board[capturedX][capturedY] = EMPTY;
    }
}

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    char player = WHITE_PAWN;
    int fromX, fromY, toX, toY;

    while (1) {
        system("clear");
        printBoard(board);
        printf("Enter move (fromX fromY toX toY) for %c: ", player);
        scanf("%d %d %d %d", &fromX, &fromY, &toX, &toY);

        if (isValidMove(board, fromX, fromY, toX, toY, player)) {
            makeMove(board, fromX, fromY, toX, toY);
            player = (player == WHITE_PAWN) ? BLACK_PAWN : WHITE_PAWN; // switch player
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}