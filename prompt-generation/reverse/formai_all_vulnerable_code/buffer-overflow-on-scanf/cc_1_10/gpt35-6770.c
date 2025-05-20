//FormAI DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the game board dimensions
#define ROWS 3
#define COLS 3

// Define constants for the players' symbols
#define PLAYER_ONE_SYMBOL 'X'
#define PLAYER_TWO_SYMBOL 'O'

// Define constants for the game status
#define IN_PROGRESS 0
#define PLAYER_ONE_WINS 1
#define PLAYER_TWO_WINS 2
#define DRAW 3

// Create a 2D array to represent the game board
char gameBoard[ROWS][COLS];

// Initialize the game board with blank spaces
void initializeGameBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = ' ';
        }
    }
}

// Display the game board
void displayGameBoard() {
    printf("  1 2 3\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c", gameBoard[i][j]);
            if (j < COLS - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < ROWS - 1) {
            printf("  -----\n");
        }
    }
}

// Get the player's move and update the game board
void makeMove(int player) {
    int row;
    int col;
    char symbol = (player == 1) ? PLAYER_ONE_SYMBOL : PLAYER_TWO_SYMBOL;
    printf("Player %d's turn\n", player);
    printf("Enter row number (1-3): ");
    scanf("%d", &row);
    printf("Enter column number (1-3): ");
    scanf("%d", &col);
    // Check if the move is valid
    if (row < 1 || row > 3 || col < 1 || col > 3 ||
        gameBoard[row - 1][col - 1] != ' ') {
        printf("Invalid move. Please try again.\n");
        makeMove(player);
        return;
    }
    gameBoard[row - 1][col - 1] = symbol;
}

// Check the game status
int checkGameStatus() {
    // Check for horizontal wins
    for (int i = 0; i < ROWS; i++) {
        if (gameBoard[i][0] == gameBoard[i][1] &&
            gameBoard[i][1] == gameBoard[i][2]) {
            if (gameBoard[i][0] == PLAYER_ONE_SYMBOL) {
                return PLAYER_ONE_WINS;
            } else if (gameBoard[i][0] == PLAYER_TWO_SYMBOL) {
                return PLAYER_TWO_WINS;
            }
        }
    }
    // Check for vertical wins
    for (int j = 0; j < COLS; j++) {
        if (gameBoard[0][j] == gameBoard[1][j] &&
            gameBoard[1][j] == gameBoard[2][j]) {
            if (gameBoard[0][j] == PLAYER_ONE_SYMBOL) {
                return PLAYER_ONE_WINS;
            } else if (gameBoard[0][j] == PLAYER_TWO_SYMBOL) {
                return PLAYER_TWO_WINS;
            }
        }
    }
    // Check for diagonal wins
    if (gameBoard[0][0] == gameBoard[1][1] &&
        gameBoard[1][1] == gameBoard[2][2]) {
        if (gameBoard[0][0] == PLAYER_ONE_SYMBOL) {
            return PLAYER_ONE_WINS;
        } else if (gameBoard[0][0] == PLAYER_TWO_SYMBOL) {
            return PLAYER_TWO_WINS;
        }
    }
    if (gameBoard[0][2] == gameBoard[1][1] &&
        gameBoard[1][1] == gameBoard[2][0]) {
        if (gameBoard[0][2] == PLAYER_ONE_SYMBOL) {
            return PLAYER_ONE_WINS;
        } else if (gameBoard[0][2] == PLAYER_TWO_SYMBOL) {
            return PLAYER_TWO_WINS;
        }
    }
    // Check for a draw
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (gameBoard[i][j] == ' ') {
                return IN_PROGRESS;
            }
        }
    }
    return DRAW;
}

int main() {
    int currentPlayer = 1;
    initializeGameBoard();
    while (1) {
        displayGameBoard();
        makeMove(currentPlayer);
        int gameStatus = checkGameStatus();
        if (gameStatus == PLAYER_ONE_WINS) {
            printf("Player 1 wins!\n");
            break;
        } else if (gameStatus == PLAYER_TWO_WINS) {
            printf("Player 2 wins!\n");
            break;
        } else if (gameStatus == DRAW) {
            printf("Draw!\n");
            break;
        }
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    return 0;
}