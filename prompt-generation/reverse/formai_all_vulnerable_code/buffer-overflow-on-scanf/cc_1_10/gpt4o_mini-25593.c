//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// Enum for player pieces
typedef enum { EMPTY, PLAYER1, PLAYER2 } Piece;

// Struct for the board
typedef struct {
    Piece board[SIZE][SIZE];
} Board;

// Function declarations
void initializeBoard(Board* b);
void printBoard(Board* b);
int movePiece(Board* b, int startX, int startY, int endX, int endY, Piece player);
int isValidMove(Board* b, int startX, int startY, int endX, int endY, Piece player);
void switchPlayer(Piece* currentPlayer);
void playGame();

int main() {
    playGame();
    return 0;
}

// Initialize the board with pieces in place
void initializeBoard(Board* b) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0 && i < 3) {
                b->board[i][j] = PLAYER1;
            } else if ((i + j) % 2 != 0 && i > 4) {
                b->board[i][j] = PLAYER2;
            } else {
                b->board[i][j] = EMPTY;
            }
        }
    }
}

// Print the game board
void printBoard(Board* b) {
    printf("\n   A B C D E F G H\n");
    printf("  +----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < SIZE; j++) {
            switch (b->board[i][j]) {
                case PLAYER1: printf(" X "); break;
                case PLAYER2: printf(" O "); break;
                case EMPTY:   printf(" . "); break;
            }
        }
        printf("|\n");
    }
    printf("  +----------------+\n");
}

// Move a piece on the board
int movePiece(Board* b, int startX, int startY, int endX, int endY, Piece player) {
    if (isValidMove(b, startX, startY, endX, endY, player)) {
        b->board[endX][endY] = player;
        b->board[startX][startY] = EMPTY;
        return 1;
    }
    return 0;
}

// Check if the move is valid
int isValidMove(Board* b, int startX, int startY, int endX, int endY, Piece player) {
    if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE ||
        endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) {
        return 0; // Out of bounds
    }
    if (b->board[startX][startY] != player || b->board[endX][endY] != EMPTY) {
        return 0; // Not player's piece or destination not empty
    }
    if ((player == PLAYER1 && endX - startX == 1 && abs(endY - startY) == 1) ||
        (player == PLAYER2 && endX - startX == -1 && abs(endY - startY) == 1)) {
        return 1; // Valid simple move
    }
    return 0;
}

// Function to switch the current player
void switchPlayer(Piece* currentPlayer) {
    if (*currentPlayer == PLAYER1) {
        *currentPlayer = PLAYER2;
    } else {
        *currentPlayer = PLAYER1;
    }
}

// The main game loop
void playGame() {
    Board board;
    Piece currentPlayer = PLAYER1;
    int startX, startY, endX, endY;

    initializeBoard(&board);
    while (1) {
        printBoard(&board);
        printf("Player %d's turn. Enter move (e.g., 1A 2B): ", currentPlayer);
        char start[3], end[3];
        scanf("%s %s", start, end);
        
        startX = start[0] - '1'; // Convert to 0-based index
        startY = start[1] - 'A'; // Convert to 0-based index
        endX = end[0] - '1';     // Convert to 0-based index
        endY = end[1] - 'A';     // Convert to 0-based index

        if (movePiece(&board, startX, startY, endX, endY, currentPlayer)) {
            switchPlayer(&currentPlayer);
        } else {
            printf("Invalid Move! Try again.\n");
        }
    }
}