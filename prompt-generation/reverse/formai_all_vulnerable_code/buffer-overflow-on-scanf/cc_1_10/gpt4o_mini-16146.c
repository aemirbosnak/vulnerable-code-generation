//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Function prototypes
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]);
bool isValidMove(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol, char player);
bool makeMove(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol);
bool checkForWin(char board[BOARD_SIZE][BOARD_SIZE], char player);
char switchPlayer(char currentPlayer);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer = 'X';
    int startRow, startCol, endRow, endCol;

    printf("Welcome to the Checkers Game! Are you ready? Let's go!\n");
    initializeBoard(board);
    displayBoard(board);

    while (true) {
        printf("Player %c, enter your move (startRow startCol endRow endCol): ", currentPlayer);
        scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);

        if (makeMove(board, startRow, startCol, endRow, endCol)) {
            displayBoard(board);
            if (checkForWin(board, currentPlayer)) {
                printf("Player %c wins! What a shocking twist!\n", currentPlayer);
                break;
            }
            currentPlayer = switchPlayer(currentPlayer);
        } else {
            printf("Invalid move! Please try again... How shocking!\n");
        }
    }

    return 0;
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Filling up the board with pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1 && i < 3) {
                board[i][j] = 'X';
            } else if ((i + j) % 2 == 1 && i > 4) {
                board[i][j] = 'O';
            } else {
                board[i][j] = '.';
            }
        }
    }
}

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isValidMove(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol, char player) {
    if (board[startRow][startCol] != player) {
        return false;
    }
    
    if (board[endRow][endCol] != '.' || abs(startRow - endRow) > 2 || abs(startCol - endCol) > 2) {
        return false;
    }

    if (abs(startRow - endRow) == 1 && abs(startCol - endCol) == 1) {
        return true; // normal move
    }

    if (abs(startRow - endRow) == 2 && abs(startCol - endCol) == 2) {
        int middleRow = (startRow + endRow) / 2;
        int middleCol = (startCol + endCol) / 2;
        return (board[middleRow][middleCol] != '.' && board[middleRow][middleCol] != player);
    }

    return false;
}

bool makeMove(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol) {
    char currentPlayer = board[startRow][startCol];
    
    if (!isValidMove(board, startRow, startCol, endRow, endCol, currentPlayer)) {
        return false; // move invalid
    }

    board[endRow][endCol] = currentPlayer; // move piece
    board[startRow][startCol] = '.'; // vacate original spot

    // Check for jump
    if (abs(startRow - endRow) == 2 && abs(startCol - endCol) == 2) {
        int middleRow = (startRow + endRow) / 2;
        int middleCol = (startCol + endCol) / 2;
        board[middleRow][middleCol] = '.'; // capture opponent
    }

    return true;
}

bool checkForWin(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check for the absence of opponent pieces
    char opponent = (player == 'X') ? 'O' : 'X';
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == opponent) {
                return false; // still have opponent pieces
            }
        }
    }
    return true; // opponent has no pieces left
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X'; // switch between players
}