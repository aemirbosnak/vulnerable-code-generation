//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

char board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    board[i][j] = 'b';  // Black pieces
                } else if (i > 4) {
                    board[i][j] = 'r';  // Red pieces
                } else {
                    board[i][j] = '.';  // Empty square
                }
            } else {
                board[i][j] = ' ';  // Not playable square
            }
        }
    }
}

void printBoard() {
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n +----------------+\n");
    }
}

int isValidMove(char player, int fromRow, int fromCol, int toRow, int toCol) {
    if (toRow < 0 || toRow >= SIZE || toCol < 0 || toCol >= SIZE) return 0;
    if (board[toRow][toCol] != '.') return 0; // Target square must be empty

    int direction = (player == 'r') ? 1 : -1;
    if (fromRow + direction == toRow && (fromCol - 1 == toCol || fromCol + 1 == toCol)) {
        return 1; // Valid move for normal piece
    }

    if (fromRow + 2 * direction == toRow && (fromCol - 2 == toCol || fromCol + 2 == toCol)) {
        int midRow = fromRow + direction;
        int midCol = (fromCol + toCol) / 2;
        if(board[midRow][midCol] != '.' && board[midRow][midCol] != player) {
            return 1; // Valid jump
        }
    }
    
    return 0; // Invalid move
}

void makeMove(int fromRow, int fromCol, int toRow, int toCol) {
    char player = board[fromRow][fromCol];
    board[toRow][toCol] = player;
    board[fromRow][fromCol] = '.';

    int direction = (player == 'r') ? 1 : -1;
    if(abs(toRow - fromRow) == 2) {
        int midRow = (fromRow + toRow) / 2;
        int midCol = (fromCol + toCol) / 2;
        board[midRow][midCol] = '.'; // Remove the jumped piece
    }
}

int main() {
    initializeBoard();
    printBoard();
    
    int fromRow, fromCol, toRow, toCol;
    char player = 'r';
    
    while (1) {
        printf("Player %c's turn. Enter move (e.g., 'a3 b4'): ", player);
        char from[3], to[3];
        scanf("%s %s", from, to);

        fromRow = from[1] - '1'; 
        fromCol = from[0] - 'a';
        toRow = to[1] - '1'; 
        toCol = to[0] - 'a';

        if (isValidMove(player, fromRow, fromCol, toRow, toCol)) {
            makeMove(fromRow, fromCol, toRow, toCol);
            printBoard();

            // Check for winner condition
            // (leaving this simple; in real case, check if one player has no pieces)
            if (player == 'r') {
                player = 'b';
            } else {
                player = 'r';
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }
    
    return 0;
}