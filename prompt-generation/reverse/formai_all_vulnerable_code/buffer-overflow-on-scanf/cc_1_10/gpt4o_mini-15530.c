//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1 && i < 3) {
                board[i][j] = PLAYER1;
            } else if ((i + j) % 2 == 1 && i > 4) {
                board[i][j] = PLAYER2;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol, char player) {
    // Conditions for a valid move
    if (endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        return 0; // Move out of bounds
    }
    if (board[endRow][endCol] != EMPTY) {
        return 0; // End position not empty
    }
    
    // Check direction and distance of the move
    int rowDiff = endRow - startRow;
    int colDiff = endCol - startCol;
    
    // Check for normal moves
    if (player == PLAYER1 && rowDiff == 1 && (colDiff == 1 || colDiff == -1)) {
        return 1;
    } else if (player == PLAYER2 && rowDiff == -1 && (colDiff == 1 || colDiff == -1)) {
        return 1;
    }
    
    // Check for capturing moves (jumping over opponent's piece)
    if (player == PLAYER1 && rowDiff == 2 && (colDiff == 2 || colDiff == -2)) {
        if (board[startRow + 1][startCol + (colDiff > 0 ? 1 : -1)] == PLAYER2) {
            return 1; // Valid capture move
        }
    } else if (player == PLAYER2 && rowDiff == -2 && (colDiff == 2 || colDiff == -2)) {
        if (board[startRow - 1][startCol + (colDiff > 0 ? 1 : -1)] == PLAYER1) {
            return 1; // Valid capture move
        }
    }
    
    return 0; // Invalid move
}

void movePiece(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol) {
    board[endRow][endCol] = board[startRow][startCol]; // Move the piece
    board[startRow][startCol] = EMPTY; // Empty the original position
}

void playGame() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    char currentPlayer = PLAYER1;
    int startRow, startCol, endRow, endCol;

    while (1) {
        printBoard(board);
        printf("Player %c's turn. Enter move (e.g., 2a 3b): ", currentPlayer);
        
        char start[3], end[3];
        scanf("%s %s", start, end);
        
        startRow = start[0] - '1';
        startCol = start[1] - 'a';
        endRow = end[0] - '1';
        endCol = end[1] - 'a';

        if (isValidMove(board, startRow, startCol, endRow, endCol, currentPlayer)) {
            movePiece(board, startRow, startCol, endRow, endCol);
        } else {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Switch players
        currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
    }
}

int main() {
    playGame();
    return 0;
}