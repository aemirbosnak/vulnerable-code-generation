//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE 'W'
#define BLACK 'B'

char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    // Place pieces
    for (int j = 0; j < BOARD_SIZE; j++) {
        board[1][j] = WHITE; // White pawns
        board[6][j] = BLACK; // Black pawns
    }
    board[0][0] = board[0][7] = WHITE; // White rooks
    board[0][1] = board[0][6] = WHITE; // White knights
    board[0][2] = board[0][5] = WHITE; // White bishops
    board[0][3] = WHITE; // White queen
    board[0][4] = WHITE; // White king

    board[7][0] = board[7][7] = BLACK; // Black rooks
    board[7][1] = board[7][6] = BLACK; // Black knights
    board[7][2] = board[7][5] = BLACK; // Black bishops
    board[7][3] = BLACK; // Black queen
    board[7][4] = BLACK; // Black king
}

void printBoard() {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, char piece) {
    // Shocked! Just checking basic movement for Pawns
    if (piece == WHITE) {
        if (fromRow == 1 && fromRow + 2 == toRow && fromCol == toCol && board[toRow][toCol] == EMPTY) {
            return true; // Two steps forward for white pawns
        }
        if (fromRow + 1 == toRow && fromCol == toCol && board[toRow][toCol] == EMPTY) {
            return true; // One step forward for white pawns
        }
    } else if (piece == BLACK) {
        if (fromRow == 6 && fromRow - 2 == toRow && fromCol == toCol && board[toRow][toCol] == EMPTY) {
            return true; // Two steps forward for black pawns
        }
        if (fromRow - 1 == toRow && fromCol == toCol && board[toRow][toCol] == EMPTY) {
            return true; // One step forward for black pawns
        }
    }
    return false;
}

void movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    char piece = board[fromRow][fromCol];
    if (isValidMove(fromRow, fromCol, toRow, toCol, piece)) {
        board[toRow][toCol] = piece;
        board[fromRow][fromCol] = EMPTY;
    } else {
        printf("Invalid move!\n");
    }
}

int main() {
    char input[10];
    int fromRow, fromCol, toRow, toCol;
    initializeBoard();
    printBoard();
    
    while (true) {
        printf("Enter your move (e.g., e2 e4): ");
        fgets(input, sizeof(input), stdin);
        
        sscanf(input, "%c%d %c%d", &input[0], &fromRow, &input[3], &toRow);
        fromCol = input[0] - 'a';
        toCol = input[3] - 'a';
        fromRow = 8 - fromRow; // Converting chess notation to array index
        toRow = 8 - toRow;

        if (fromRow < 0 || fromRow >= BOARD_SIZE || toRow < 0 || toRow >= BOARD_SIZE ||
            fromCol < 0 || fromCol >= BOARD_SIZE || toCol < 0 || toCol >= BOARD_SIZE) {
            printf("Out of bounds! Try again.\n");
            continue;
        }

        movePiece(fromRow, fromCol, toRow, toCol);
        printBoard();
    }

    return 0;
}