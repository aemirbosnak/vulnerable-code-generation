//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

// Function prototypes
void initializeBoard();
void printBoard();
int isValidMove(int startX, int startY, int endX, int endY, char player);
void makeMove(int startX, int startY, int endX, int endY);
int isGameOver(char player);
void swap(int *a, int *b);

int main() {
    int startX, startY, endX, endY;
    char currentPlayer = 'R'; // 'R' for Red and 'B' for Black
    int moves = 0;

    initializeBoard();

    while (!isGameOver(currentPlayer)) {
        printBoard();
        printf("Player %c's turn. Enter move (startX startY endX endY): ", currentPlayer);
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

        // Check if the move is valid
        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
            makeMove(startX, startY, endX, endY);
            currentPlayer = (currentPlayer == 'R') ? 'B' : 'R'; // Switch player
            moves++;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    // End of the game
    printBoard();
    printf("Player %c wins!\n", currentPlayer);
    return 0;
}

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = ' '; // Empty squares
            } else {
                if (i < 3) {
                    board[i][j] = 'B'; // Black pieces
                } else if (i > 4) {
                    board[i][j] = 'R'; // Red pieces
                } else {
                    board[i][j] = ' '; // Empty squares
                }
            }
        }
    }
}

void printBoard() {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int startX, int startY, int endX, int endY, char player) {
    // Check if the source and destination are within bounds
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE ||
        endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0; // Out of bounds
    }
    
    char targetPiece = board[endX][endY];
    if (board[startX][startY] != player || targetPiece != ' ') {
        return 0; // Invalid: Not player's piece or target not empty
    }

    // Normal move conditions
    int direction = (player == 'R') ? 1 : -1; // Red moves down, Black moves up
    if (endX == startX + direction && (endY == startY - 1 || endY == startY + 1)) {
        return 1; // Valid normal move
    }
    // Capture move conditions
    if (endX == startX + 2 * direction) {
        if (endY == startY - 2 || endY == startY + 2) {
            int midX = startX + direction;
            int midY = (endY + startY) / 2; // Find middle square
            if (board[midX][midY] != ' ' && board[midX][midY] != player) {
                return 1; // Valid capture move
            }
        }
    }

    return 0; // Move not valid
}

void makeMove(int startX, int startY, int endX, int endY) {
    // Move the piece
    board[endX][endY] = board[startX][startY]; // Move piece to destination
    board[startX][startY] = ' '; // Empty the old position

    // Check for capturing
    if (abs(endX - startX) == 2) {
        int midX = (startX + endX) / 2; // Mid position
        int midY = (startY + endY) / 2;
        board[midX][midY] = ' '; // Remove captured piece
    }
}

int isGameOver(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                return 0; // Game is not over
            }
        }
    }
    return 1; // No pieces left, game is over
}