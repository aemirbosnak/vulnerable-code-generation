//GEMINI-pro DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER1_SYMBOL 'X'
#define PLAYER2_SYMBOL 'O'

// Define the game state
enum GameState {
    PLAYING,
    PLAYER1_WIN,
    PLAYER2_WIN,
    DRAW
};

// Define the game board
char gameBoard[BOARD_SIZE][BOARD_SIZE];

// Define the current player
int currentPlayer = PLAYER1_SYMBOL;

// Define the game state
enum GameState gameState = PLAYING;

// Function to initialize the game board
void initializeGameBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            gameBoard[i][j] = ' ';
        }
    }
}

// Function to print the game board
void printGameBoard() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}

// Function to get the player input
void getPlayerInput() {
    int row, column;

    printf("Enter the row and column (0-2): ");
    scanf("%d %d", &row, &column);

    // Check if the input is valid
    if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE) {
        printf("Invalid input. Please enter a valid row and column.\n");
        getPlayerInput();
        return;
    }

    // Check if the cell is empty
    if (gameBoard[row][column] != ' ') {
        printf("Cell is not empty. Please enter an empty cell.\n");
        getPlayerInput();
        return;
    }

    // Update the game board
    gameBoard[row][column] = currentPlayer;
}

// Function to check if there is a winner
enum GameState checkForWinner() {
    // Check for rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ') {
            return currentPlayer == PLAYER1_SYMBOL ? PLAYER1_WIN : PLAYER2_WIN;
        }
    }

    // Check for columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' ') {
            return currentPlayer == PLAYER1_SYMBOL ? PLAYER1_WIN : PLAYER2_WIN;
        }
    }

    // Check for diagonals
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != ' ') {
        return currentPlayer == PLAYER1_SYMBOL ? PLAYER1_WIN : PLAYER2_WIN;
    }
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != ' ') {
        return currentPlayer == PLAYER1_SYMBOL ? PLAYER1_WIN : PLAYER2_WIN;
    }

    // Check for a draw
    int emptyCells = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (gameBoard[i][j] == ' ') {
                emptyCells++;
            }
        }
    }
    if (emptyCells == 0) {
        return DRAW;
    }

    return PLAYING;
}

// Function to switch the current player
void switchPlayer() {
    currentPlayer = currentPlayer == PLAYER1_SYMBOL ? PLAYER2_SYMBOL : PLAYER1_SYMBOL;
}

int main() {
    // Initialize the game board
    initializeGameBoard();

    // Print the game board
    printGameBoard();

    // Game loop
    while (gameState == PLAYING) {
        // Get the player input
        getPlayerInput();

        // Check for a winner
        gameState = checkForWinner();

        // Switch the current player
        switchPlayer();

        // Print the game board
        printGameBoard();
    }

    // Print the game result
    switch (gameState) {
        case PLAYER1_WIN:
            printf("Player 1 wins!\n");
            break;
        case PLAYER2_WIN:
            printf("Player 2 wins!\n");
            break;
        case DRAW:
            printf("Draw!\n");
            break;
    }

    return 0;
}