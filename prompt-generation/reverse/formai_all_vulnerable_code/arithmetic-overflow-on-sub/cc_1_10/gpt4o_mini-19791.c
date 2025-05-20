//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE] = {
    {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
    {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
    {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
    {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
    {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '}
};

void printBoard() {
    printf("\n  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(int startRow, int startCol, int endRow, int endCol, char player) {
    // Basic bounds check
    if (endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        return 0;
    }

    // Check if the destination square is empty
    if (board[endRow][endCol] != ' ') {
        return 0;
    }

    // Determine direction of move
    int direction = (player == 'X') ? 1 : -1;
    if ((endRow - startRow) == direction && abs(endCol - startCol) == 1) {
        return 1; // Normal move
    }
    if ((endRow - startRow) == 2 * direction && abs(endCol - startCol) == 2) {
        return (board[startRow + direction][(startCol + endCol) / 2] == (player == 'X' ? 'O' : 'X')); // Capture
    }
    return 0;
}

void makeMove(int startRow, int startCol, int endRow, int endCol, char player) {
    board[endRow][endCol] = player; // Place the player piece
    board[startRow][startCol] = ' '; // Empty the original square

    // Check if it's a capture move
    if (abs(endRow - startRow) == 2) {
        int midRow = (startRow + endRow) / 2;
        int midCol = (startCol + endCol) / 2;
        board[midRow][midCol] = ' '; // Remove captured piece
    }
}

int main() {
    int startRow, startCol, endRow, endCol;
    char currentPlayer = 'X';
    int moves = 0;

    printf("Welcome to the Happy Checkers Game!\n");
    printf("Player X starts the game!\n");

    while (moves < 100) {
        printBoard();

        printf("Player %c's turn! Enter your move (e.g., A1 B2): ", currentPlayer);
        char startColChar, endColChar;
        int startRowInput, endRowInput;
        scanf(" %c%d %c%d", &startColChar, &startRowInput, &endColChar, &endRowInput);

        startCol = startColChar - 'A';
        startRow = startRowInput - 1;
        endCol = endColChar - 'A';
        endRow = endRowInput - 1;

        if (isValidMove(startRow, startCol, endRow, endCol, currentPlayer)) {
            makeMove(startRow, startCol, endRow, endCol, currentPlayer);
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
            moves++;
        } else {
            printf("Oops! That's an invalid move. Try again!\n");
        }
    }

    printf("Game over! Thanks for playing the Happy Checkers Game!\n");
    return 0;
}