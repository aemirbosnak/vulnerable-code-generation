//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int isValidMove(char piece, int startX, int startY, int endX, int endY, char board[SIZE][SIZE]);
void movePiece(char board[SIZE][SIZE], int startX, int startY, int endX, int endY);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    printBoard(board);

    int startX, startY, endX, endY;
    char discard[10]; // To catch unwanted inputs

    while (1) {
        printf("Enter move (startX startY endX endY) or 'exit' to quit: ");
        
        if (scanf("%d %d %d %d", &startX, &startY, &endX, &endY) != 4) {
            scanf("%s", discard);  // discard invalid input
            if (strcmp(discard, "exit") == 0) {
                printf("Exiting the Chess Wizard. Goodbye!\n");
                break;
            }
            printf("Invalid input. Please enter numbers or 'exit'.\n");
            continue;
        }

        if (isValidMove(board[startX][startY], startX, startY, endX, endY, board)) {
            movePiece(board, startX, startY, endX, endY);
            printBoard(board);
        } else {
            printf("Invalid move! Please try again.\n");
        }
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    // Initialize empty board
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = '.';

    // Place pawns
    for (int i = 0; i < SIZE; i++) {
        board[1][i] = 'P'; // White pawns
        board[6][i] = 'p'; // Black pawns
    }

    // Place knights
    board[0][1] = board[0][6] = 'N'; // White knights
    board[7][1] = board[7][6] = 'n'; // Black knights
}

void printBoard(char board[SIZE][SIZE]) {
    printf("  A B C D E F G H\n");
    printf(" +----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf(" +----------------+\n");
}

int isValidMove(char piece, int startX, int startY, int endX, int endY, char board[SIZE][SIZE]) {
    // Validate indices
    if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE ||
        endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) {
        return 0;
    }

    // Validate if there's a piece at the starting position
    if (piece == '.') {
        return 0;
    }

    // Implement simple movement rules
    int dx = endX - startX;
    int dy = endY - startY;

    // Check for Pawn movement
    if (piece == 'P' && dy == 0 && dx == 1 && board[endX][endY] == '.') {
        return 1;  // Move forward
    }
    if (piece == 'p' && dy == 0 && dx == -1 && board[endX][endY] == '.') {
        return 1;  // Move forward
    }
    if (piece == 'P' && (dx == 1 && (dy == -1 || dy == 1)) && board[endX][endY] != '.') {
        return 1;  // Capture
    }
    if (piece == 'p' && (dx == -1 && (dy == -1 || dy == 1)) && board[endX][endY] != '.') {
        return 1;  // Capture
    }
    
    // Check for Knight movement
    if (piece == 'N' || piece == 'n') {
        if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)) {
            return 1;  // Knight move
        }
    }

    return 0; // Invalid move
}

void movePiece(char board[SIZE][SIZE], int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY]; // Move the piece
    board[startX][startY] = '.'; // Clear the starting position
}