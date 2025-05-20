//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY '-'
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[BOARD_SIZE][BOARD_SIZE];

// Function Prototypes
void initializeBoard();
void printBoard();
int isValidMove(int startRow, int startCol, int endRow, int endCol, char player);
void makeMove(int startRow, int startCol, int endRow, int endCol);
int isGameOver(char player);
void getInput(int *startRow, int *startCol, int *endRow, int *endCol);

int main() {
    char currentPlayer = PLAYER1;
    
    printf("Welcome to Checkers! Player 1 is 'X' and Player 2 is 'O'.\n");
    
    initializeBoard();
    
    while(1) {
        printBoard();
        printf("Player '%c', it's your turn.\n", currentPlayer);
        
        int startRow, startCol, endRow, endCol;
        getInput(&startRow, &startCol, &endRow, &endCol);
        
        if (isValidMove(startRow, startCol, endRow, endCol, currentPlayer)) {
            makeMove(startRow, startCol, endRow, endCol);
            if (isGameOver(currentPlayer)) {
                printBoard();
                printf("Player '%c' wins!\n", currentPlayer);
                break;
            }
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    
    return 0;
}

void initializeBoard() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 1 && row < 3) {
                board[row][col] = PLAYER1; // Player 1's pieces
            } else if ((row + col) % 2 == 1 && row > 4) {
                board[row][col] = PLAYER2; // Player 2's pieces
            } else {
                board[row][col] = EMPTY; // Empty squares
            }
        }
    }
}

void printBoard() {
    printf("\nCheckers Board:\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

int isValidMove(int startRow, int startCol, int endRow, int endCol, char player) {
    // Check if starting position is valid
    if (startRow < 0 || startRow >= BOARD_SIZE || startCol < 0 || startCol >= BOARD_SIZE || 
        endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE || 
        board[startRow][startCol] != player || board[endRow][endCol] != EMPTY) {
        return 0;
    }
    
    // Check if move is one square diagonal
    if (abs(endRow - startRow) == 1 && abs(endCol - startCol) == 1) {
        return 1;
    }
    
    // Check if move is a jump
    if (abs(endRow - startRow) == 2 && abs(endCol - startCol) == 2) {
        int middleRow = (startRow + endRow) / 2;
        int middleCol = (startCol + endCol) / 2;
        char opponent = (player == PLAYER1) ? PLAYER2 : PLAYER1;
        if (board[middleRow][middleCol] == opponent) {
            return 1; // valid jump over opponent piece
        }
    }
    
    return 0;
}

void makeMove(int startRow, int startCol, int endRow, int endCol) {
    // Move the piece
    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = EMPTY;
    
    // Check for capture
    if (abs(endRow - startRow) == 2) {
        int middleRow = (startRow + endRow) / 2;
        int middleCol = (startCol + endCol) / 2;
        board[middleRow][middleCol] = EMPTY; // Remove opponent's piece
    }
}

int isGameOver(char player) {
    // Check for remaining pieces of the opposite player
    char opponent = (player == PLAYER1) ? PLAYER2 : PLAYER1;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == opponent) {
                return 0; // Game is not over
            }
        }
    }
    return 1; // Game over
}

void getInput(int *startRow, int *startCol, int *endRow, int *endCol) {
    printf("Enter your move (startRow startCol endRow endCol): ");
    scanf("%d %d %d %d", startRow, startCol, endRow, endCol);
}