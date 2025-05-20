//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define PLAYER1 'X'
#define PLAYER2 'O'
#define EMPTY '.'

char board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
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
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int startRow, int startCol, int endRow, int endCol, char player) {
    int direction = (player == PLAYER1) ? 1 : -1; // Direction of movement depending on the player
    if (board[endRow][endCol] == EMPTY && 
        endRow == startRow + direction && 
        (endCol == startCol - 1 || endCol == startCol + 1)) {
        return 1; // Simple move
    }
    
    // Capture move
    if (board[endRow][endCol] == EMPTY &&
        endRow == startRow + 2 * direction &&
        (endCol == startCol - 2 || endCol == startCol + 2)) {
        int midRow = startRow + direction;
        int midCol = startCol + (endCol > startCol ? 1 : -1);
        return (board[midRow][midCol] != EMPTY && 
                board[midRow][midCol] != player); // Capturing an opponent piece
    }

    return 0; // Invalid move
}

void makeMove(int startRow, int startCol, int endRow, int endCol) {
    char player = board[startRow][startCol];
    board[endRow][endCol] = player;
    board[startRow][startCol] = EMPTY;

    // Check for capturing
    if (abs(endRow - startRow) == 2) {
        int midRow = (startRow + endRow) / 2;
        int midCol = (startCol + endCol) / 2;
        board[midRow][midCol] = EMPTY; // Remove the opponent piece
    }
}

int main() {
    int playerTurn = 0; // 0 for Player 1, 1 for Player 2
    char *players[] = {"Player 1 (X)", "Player 2 (O)"};
    initializeBoard();
    
    while (1) {
        printBoard();
        printf("%s's turn. Enter move (e.g., 'a3 b4'): ", players[playerTurn]);
        
        char startColChar, endColChar;
        int startRow, endRow;
        scanf(" %c%d %c%d", &startColChar, &startRow, &endColChar, &endRow);
        
        int startCol = startColChar - 'a';
        int endCol = endColChar - 'a';
        startRow -= 1; 
        endRow -= 1;

        if (startRow < 0 || startRow >= SIZE || startCol < 0 || startCol >= SIZE || 
            endRow < 0 || endRow >= SIZE || endCol < 0 || endCol >= SIZE) {
            printf("Invalid move! Out of bounds.\n");
            continue;
        }

        char currentPlayer = (playerTurn == 0) ? PLAYER1 : PLAYER2;
        if (board[startRow][startCol] != currentPlayer) {
            printf("Invalid move! Not your piece.\n");
            continue;
        }

        if (isValidMove(startRow, startCol, endRow, endCol, currentPlayer)) {
            makeMove(startRow, startCol, endRow, endCol);
            playerTurn = 1 - playerTurn; // Switch player turn
        } else {
            printf("Invalid move! Check your move.\n");
        }
    }
    
    return 0;
}