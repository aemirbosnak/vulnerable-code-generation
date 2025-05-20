//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

char board[SIZE][SIZE];

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3)
                    board[i][j] = 'b'; // Black pieces
                else if (i > 4)
                    board[i][j] = 'r'; // Red pieces
                else
                    board[i][j] = '.'; // Empty
            } else {
                board[i][j] = '.';
            }
        }
    }
}

void printBoard() {
    printf("  A B C D E F G H\n");
    printf(" +----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int startRow, int startCol, int endRow, int endCol, char player) {
    int direction = player == 'r' ? 1 : -1; // Direction of movement for each player
    if (endRow < 0 || endRow >= SIZE || endCol < 0 || endCol >= SIZE)
        return 0; // Out of bounds
    if (board[endRow][endCol] != '.')
        return 0; // Not an empty space
    if ((endRow - startRow) != direction)
        return 0; // Can only move forward
    if (abs(endCol - startCol) != 1) {
        // To jump over another piece
        int jumpRow = (startRow + endRow) / 2;
        int jumpCol = (startCol + endCol) / 2;
        if (board[jumpRow][jumpCol] == '.' || board[jumpRow][jumpCol] == player)
            return 0; // Must jump over an opponent piece
    }
    return 1;
}

void makeMove(int startRow, int startCol, int endRow, int endCol) {
    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = '.';
}

void playGame() {
    int turn = 1; // 1 - red's turn, 2 - black's turn
    while (1) {
        printBoard();
        printf("Player %d's turn (%c):\n", turn, turn == 1 ? 'r' : 'b');
        
        char startColChar, endColChar;
        int startRow, endRow;
        printf("Enter move (e.g., A3 B4): ");
        scanf(" %c%d %c%d", &startColChar, &startRow, &endColChar, &endRow);
        
        int startCol = startColChar - 'A';
        startRow -= 1;
        int endCol = endColChar - 'A';
        endRow -= 1;

        char player = turn == 1 ? 'r' : 'b';
        if (isValidMove(startRow, startCol, endRow, endCol, player)) {
            makeMove(startRow, startCol, endRow, endCol);
            turn = (turn == 1) ? 2 : 1; // Switch turn
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

int main() {
    initBoard();
    playGame();
    return 0;
}