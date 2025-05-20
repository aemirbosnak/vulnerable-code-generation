//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, PLAYER1, PLAYER2 } Piece;

Piece board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0 && i < 3) {
                board[i][j] = PLAYER1;
            } else if ((i + j) % 2 != 0 && i > 4) {
                board[i][j] = PLAYER2;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard() {
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf(" .");
            } else if (board[i][j] == PLAYER1) {
                printf(" X");
            } else {
                printf(" O");
            }
        }
        printf("|\n");
    }
    printf(" +----------------+\n");
}

int isMoveValid(int fromRow, int fromCol, int toRow, int toCol, int player) {
    if (toRow < 0 || toRow >= BOARD_SIZE || toCol < 0 || toCol >= BOARD_SIZE || board[toRow][toCol] != EMPTY) {
        return 0;
    }
    int direction = (player == 1) ? 1 : -1;
    if (fromRow + direction == toRow && (fromCol + 1 == toCol || fromCol - 1 == toCol)) {
        return 1;
    }
    int jumpRow = fromRow + 2 * direction;
    int jumpCol = (fromCol + 1 == toCol) ? fromCol - 1 : fromCol + 1;
    if (jumpRow >= 0 && jumpRow < BOARD_SIZE && board[jumpRow][jumpCol] != EMPTY && board[jumpRow][jumpCol] != player) {
        return 2; // Indicates jump
    }
    return 0;
}

void makeMove(int fromRow, int fromCol, int toRow, int toCol, int player) {
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = EMPTY;
    // Check for jump
    if (abs(toRow - fromRow) == 2) {
        int jumpedRow = (fromRow + toRow) / 2;
        int jumpedCol = (fromCol + toCol) / 2;
        board[jumpedRow][jumpedCol] = EMPTY; // Remove the jumped piece
    }
}

int main() {
    initializeBoard();
    int player = 1;
    char fromCol, toCol;
    int fromRow, toRow;

    while (1) {
        printBoard();
        printf("Player %d's turn. Enter move (e.g., 'a3 b4'): ", player);
        char input[6];
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%c%d %c%d", &fromCol, &fromRow, &toCol, &toRow);
        
        int fromRowIndex = fromRow - 1;
        int fromColIndex = fromCol - 'a';
        int toRowIndex = toRow - 1;
        int toColIndex = toCol - 'a';

        if (board[fromRowIndex][fromColIndex] == (player == 1 ? PLAYER1 : PLAYER2) && 
            isMoveValid(fromRowIndex, fromColIndex, toRowIndex, toColIndex, player)) {
            makeMove(fromRowIndex, fromColIndex, toRowIndex, toColIndex, player);
            player = (player == 1) ? 2 : 1; // Switch player
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    
    return 0;
}