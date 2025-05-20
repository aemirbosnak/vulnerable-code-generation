//FormAI DATASET v1.0 Category: Chess engine ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the move is valid
int isValidMove(char board[8][8], int startRow, int startCol, int endRow, int endCol, char player) {    
    // Check player
    if (player == 'W') {
        // Check if in bounds and if trying to move backwards
        if (startRow > endRow || endRow - startRow > 1 || abs(endCol - startCol) > 1) {
            return 0;
        }
        // Check if move is diagonal or capturing move
        if ((startRow - endRow == 1 && abs(endCol - startCol) == 1) || (startRow - endRow == 1 && board[endRow][endCol] != ' ' && abs(endCol - startCol) == 1)) {
            return 1;
        }
    }
    else if (player == 'B') {
        // Check if in bounds and if trying to move backwards
        if (endRow > startRow || startRow - endRow > 1 || abs(endCol - startCol) > 1) {
            return 0;
        }
        // Check if move is diagonal or capturing move
        if ((endRow - startRow == 1 && abs(endCol - startCol) == 1) || (endRow - startRow == 1 && board[endRow][endCol] != ' ' && abs(endCol - startCol) == 1)) {
            return 1;
        }
    }
    return 0;
}

// Function to move a piece
void makeMove(char board[8][8], int startRow, int startCol, int endRow, int endCol, char player) {
    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = ' ';
}

// Function to print the board
void printBoard(char board[8][8]) {
    int i, j;
    printf("  1 2 3 4 5 6 7 8\n");
    for (i = 0; i < 8; i++) {
        printf("%c ", i + 'A');
        for (j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to swap players
char nextPlayer(char player) {
    if (player == 'W') {
        return 'B';
    }
    else {
        return 'W';
    }
}

// Function to get user's input for move
void getUserInput(int* startRow, int* startCol, int* endRow, int* endCol) {
    char start[3], end[3];
    printf("Enter start position (eg. A1): ");
    scanf("%s", start);
    printf("Enter end position (eg. A2): ");
    scanf("%s", end);
    *startRow = start[0] - 'A';
    *startCol = start[1] - '1';
    *endRow = end[0] - 'A';
    *endCol = end[1] - '1';
}

int main() {
    char board[8][8] = {
        {'R','N','B','Q','K','B','N','R'},
        {'P','P','P','P','P','P','P','P'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'p','p','p','p','p','p','p','p'},
        {'r','n','b','q','k','b','n','r'}
    };

    char player = 'W';
    int startRow, startCol, endRow, endCol;
    while (1) {
        printBoard(board);
        getUserInput(&startRow, &startCol, &endRow, &endCol);
        if (isValidMove(board, startRow, startCol, endRow, endCol, player)) {
            makeMove(board, startRow, startCol, endRow, endCol, player);
            player = nextPlayer(player);
        }
        else {
            printf("Invalid move, try again!\n");
        }
    }
    return 0;
}