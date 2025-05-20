//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game board
void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    board[i][j] = 'B';  // Black pieces
                } else if (i > 4) {
                    board[i][j] = 'R';  // Red pieces
                } else {
                    board[i][j] = '.';  // Empty space
                }
            } else {
                board[i][j] = ' ';  // Non-playable space
            }
        }
    }
}

// Print the board to the console
void printBoard() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Validate the move
int isValidMove(int startX, int startY, int endX, int endY, char player) {
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE)
        return 0; // Out of bounds

    char opponentPiece = (player == 'R') ? 'B' : 'R';
    char emptySpace = '.';
    
    if (board[endX][endY] != emptySpace) return 0; // Not an empty space

    int dx = abs(endX - startX);
    int dy = abs(endY - startY);

    if (dx == 1 && dy == 1) return 1; // Regular move

    if (dx == 2 && dy == 2) {
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;
        if (board[midX][midY] == opponentPiece) return 1; // Capture
    }

    return 0; // Invalid move
}

// Move the piece on the board
void movePiece(int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY]; // Move piece
    board[startX][startY] = '.'; // Clear old position
}

// Play the game
void playGame() {
    char currentPlayer = 'R';
    int movesRemaining = 12;

    while (1) {
        printBoard();
        printf("Current Player: %c\n", currentPlayer);
        printf("Enter your move (e.g., A3 B4): ");
        
        char start[3], end[3];
        scanf("%s %s", start, end);

        int startX = start[1] - '1'; // Convert to zero-index
        int startY = start[0] - 'A'; // Convert to column
        int endX = end[1] - '1'; // Convert to zero-index
        int endY = end[0] - 'A'; // Convert to column

        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
            movePiece(startX, startY, endX, endY);
            movesRemaining--;
        } else {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        // Check for win condition
        if (movesRemaining == 0) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        
        currentPlayer = (currentPlayer == 'R') ? 'B' : 'R'; // Switch player
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}