//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) { // set dark squares
                if (i < 3) {
                    board[i][j] = 'B'; // Black pieces
                } else if (i > 4) {
                    board[i][j] = 'R'; // Red pieces
                } else {
                    board[i][j] = '.'; // Empty square
                }
            } else {
                board[i][j] = ' '; // Light squares
            }
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int fromRow, int fromCol, int toRow, int toCol, char board[SIZE][SIZE], char player) {
    // check if the destination is empty
    if (board[toRow][toCol] != '.') {
        return 0;
    }
    
    // validation based on direction of movement
    if (player == 'R' && toRow < fromRow) {
        return 0; // Red can only move down
    } else if (player == 'B' && toRow > fromRow) {
        return 0; // Black can only move up
    }

    // check if the move is diagonal and distance is 1
    if (abs(fromRow - toRow) != 1 || abs(fromCol - toCol) != 1) {
        return 0;
    }
    
    return 1; // valid move
}

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'R'; // Start with Red
    int fromRow, fromCol, toRow, toCol;
    char fromColChar, toColChar;

    initializeBoard(board);

    while (1) {
        printBoard(board);
        printf("Player %c's turn. Enter your move (e.g., 'e4 d5'): ", currentPlayer);
        scanf(" %c%d %c%d", &fromColChar, &fromRow, &toColChar, &toRow);
        
        fromCol = fromColChar - 'a';
        fromRow = SIZE - fromRow; // Adjust to board index
        toCol = toColChar - 'a';
        toRow = SIZE - toRow; // Adjust to board index

        if (fromRow < 0 || fromRow >= SIZE || fromCol < 0 || fromCol >= SIZE || 
            toRow < 0 || toRow >= SIZE || toCol < 0 || toCol >= SIZE) {
            printf("Invalid coordinates! Please try again.\n");
            continue;
        }

        if (board[fromRow][fromCol] != currentPlayer) {
            printf("It's not your piece! Choose a valid piece.\n");
            continue;
        }

        if (!isValidMove(fromRow, fromCol, toRow, toCol, board, currentPlayer)) {
            printf("Invalid move! Please try again.\n");
            continue;
        }

        // Move the piece on the board
        board[toRow][toCol] = currentPlayer; // Place piece in new position
        board[fromRow][fromCol] = '.'; // Clear old position

        // Switch players
        currentPlayer = (currentPlayer == 'R') ? 'B' : 'R';
    }

    return 0;
}