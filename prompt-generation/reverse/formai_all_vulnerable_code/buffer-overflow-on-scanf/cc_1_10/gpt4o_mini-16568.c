//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int movePiece(char board[SIZE][SIZE], int startRow, int startCol, int endRow, int endCol);
int isValidMove(char board[SIZE][SIZE], int startRow, int startCol, int endRow, int endCol);
int isEmpty(char board[SIZE][SIZE], int row, int col);
void swap(char *a, char *b);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    
    int turn = 1; // 1 for Player 1, 2 for Player 2
    int startRow, startCol, endRow, endCol;
    while (1) {
        printBoard(board);
        printf("Player %d's turn:\n", turn);
        
        printf("Enter the row and column of the piece to move (e.g. 2 3): ");
        scanf("%d %d", &startRow, &startCol);
        
        printf("Enter the row and column to move to (e.g. 3 4): ");
        scanf("%d %d", &endRow, &endCol);
        
        if (movePiece(board, startRow, startCol, endRow, endCol)) {
            // Switch turns
            turn = (turn == 1) ? 2 : 1;
        } else {
            printf("Invalid move, try again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 1 && i < 3) {
                board[i][j] = 'P'; // Player 1's pieces
            } else if ((i + j) % 2 == 1 && i > 4) {
                board[i][j] = 'p'; // Player 2's pieces
            } else {
                board[i][j] = '.';
            }
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int movePiece(char board[SIZE][SIZE], int startRow, int startCol, int endRow, int endCol) {
    if (isValidMove(board, startRow, startCol, endRow, endCol)) {
        swap(&board[startRow][startCol], &board[endRow][endCol]);
        return 1; // Move successful
    }
    return 0; // Move failed
}

int isValidMove(char board[SIZE][SIZE], int startRow, int startCol, int endRow, int endCol) {
    if (startRow < 0 || startRow >= SIZE || startCol < 0 || startCol >= SIZE ||
        endRow < 0 || endRow >= SIZE || endCol < 0 || endCol >= SIZE) {
        return 0; // Out of bounds
    }
    
    if (!isEmpty(board, endRow, endCol)) {
        return 0; // Destination must be empty
    }
    
    char piece = board[startRow][startCol];
    if (piece == '.') {
        return 0; // No piece at starting position
    }

    // Check move is diagonal (1 row and 1 column)
    if (abs(startRow - endRow) != 1 || abs(startCol - endCol) != 1) {
        return 0; // Invalid move direction
    }
    
    return 1; // Move is valid
}

int isEmpty(char board[SIZE][SIZE], int row, int col) {
    return board[row][col] == '.';
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}