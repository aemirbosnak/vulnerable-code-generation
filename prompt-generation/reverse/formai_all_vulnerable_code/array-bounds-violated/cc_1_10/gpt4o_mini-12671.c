//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define RED 'R'
#define WHITE 'W'
#define EMPTY ' '

char board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) board[i][j] = RED;
                else if (i > 4) board[i][j] = WHITE;
                else board[i][j] = EMPTY;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int fromRow, int fromCol, int toRow, int toCol, char player) {
    if (toRow < 0 || toRow >= SIZE || toCol < 0 || toCol >= SIZE) return 0;
    if (board[toRow][toCol] != EMPTY) return 0; // Target cell must be empty

    if (player == RED) {
        if (toRow - fromRow == 1 && abs(toCol - fromCol) == 1) return 1; // Simple move
        if (toRow - fromRow == 2 && abs(toCol - fromCol) == 2 && board[(fromRow + toRow) / 2][(fromCol + toCol) / 2] == WHITE) return 1; // Capture
    } else {
        if (fromRow - toRow == 1 && abs(toCol - fromCol) == 1) return 1; // Simple move
        if (fromRow - toRow == 2 && abs(toCol - fromCol) == 2 && board[(fromRow + toRow) / 2][(fromCol + toCol) / 2] == RED) return 1; // Capture
    }

    return 0; // Not a valid move
}

void movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    char player = board[fromRow][fromCol];
    board[toRow][toCol] = player; // Move the piece
    board[fromRow][fromCol] = EMPTY; // Empty the original space

    // Check for capture
    if (abs(toRow - fromRow) == 2) {
        int capturedRow = (fromRow + toRow) / 2;
        int capturedCol = (fromCol + toCol) / 2;
        board[capturedRow][capturedCol] = EMPTY; // Remove the captured piece
    }
}

int main() {
    initializeBoard();
    printBoard();
    
    int fromRow, fromCol, toRow, toCol;
    char player = RED;
    
    while (1) {
        printf("%c player's turn. Enter move (e.g. A3 B4): ", player);
        char fromColChar, toColChar;
        scanf(" %c%d %c%d", &fromColChar, &fromRow, &toColChar, &toRow);
        
        fromCol = fromColChar - 'A';
        toCol = toColChar - 'A';
        fromRow -= 1;
        toRow -= 1;

        if (isValidMove(fromRow, fromCol, toRow, toCol, player)) {
            movePiece(fromRow, fromCol, toRow, toCol);
            printBoard();
            player = (player == RED) ? WHITE : RED; // Switch players
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    
    return 0;
}