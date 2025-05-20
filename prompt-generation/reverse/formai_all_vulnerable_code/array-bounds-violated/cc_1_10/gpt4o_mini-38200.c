//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE 'O'
#define BLACK 'X'
#define EMPTY ' '

char board[BOARD_SIZE][BOARD_SIZE];

void initBoard() {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if((r + c) % 2 == 1) {
                if(r < 3) board[r][c] = WHITE;
                else if(r > 4) board[r][c] = BLACK;
                else board[r][c] = EMPTY;
            } else {
                board[r][c] = EMPTY;
            }
        }
    }
}

void printBoard() {
    printf("\n  a b c d e f g h\n");
    for (int r = 0; r < BOARD_SIZE; r++) {
        printf("%d ", r + 1);
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int isMoveValid(int startRow, int startCol, int endRow, int endCol, char player) {
    if (endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE)
        return 0;
    
    if (board[endRow][endCol] != EMPTY)
        return 0;

    if (player == WHITE) {
        if (endRow - startRow == 1 && abs(endCol - startCol) == 1)
            return 1; // regular move for white
        if (endRow - startRow == 2 && abs(endCol - startCol) == 2) {
            int midRow = (startRow + endRow) / 2;
            int midCol = (startCol + endCol) / 2;
            if (board[midRow][midCol] == BLACK)
                return 1; // capture move for white
        }
    } else {
        if (startRow - endRow == 1 && abs(startCol - endCol) == 1)
            return 1; // regular move for black
        if (startRow - endRow == 2 && abs(startCol - endCol) == 2) {
            int midRow = (startRow + endRow) / 2;
            int midCol = (startCol + endCol) / 2;
            if (board[midRow][midCol] == WHITE)
                return 1; // capture move for black
        }
    }
    return 0;
}

void movePiece(int startRow, int startCol, int endRow, int endCol) {
    char player = board[startRow][startCol];
    board[endRow][endCol] = player;
    board[startRow][startCol] = EMPTY;

    // Check for captures
    if (abs(endRow - startRow) == 2) {
        int midRow = (startRow + endRow) / 2;
        int midCol = (startCol + endCol) / 2;
        board[midRow][midCol] = EMPTY; // Remove captured piece
    }
}

int main() {
    initBoard();
    printBoard();
    char currentPlayer = WHITE;
    while (1) {
        char input[100];
        printf("\nPlayer %c's turn (e.g., 'a1 b2'): ", currentPlayer);
        fgets(input, sizeof(input), stdin);
        char startColChar, endColChar;
        int startRow, endRow;
        sscanf(input, "%c%d %c%d", &startColChar, &startRow, &endColChar, &endRow);
        int startCol = startColChar - 'a';
        int endCol = endColChar - 'a';
        startRow--; endRow--; // Convert to zero index

        if (isMoveValid(startRow, startCol, endRow, endCol, currentPlayer)) {
            movePiece(startRow, startCol, endRow, endCol);
            printBoard();
            currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE; // Switch player
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    return 0;
}