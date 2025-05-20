//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 8

// Define the player types
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Define the game states
#define GAME_IN_PROGRESS 0
#define GAME_OVER_DRAW 1
#define GAME_OVER_WIN 2

// Define the winning combinations
int winningCombinations[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

// Define the game board
char gameBoard[BOARD_SIZE];

// Function to initialize the game board
void initializeGameBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        gameBoard[i] = ' ';
    }
}

// Function to print the game board
void printGameBoard() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i % 3 == 0) {
            printf("\n");
        }
        printf(" %c |", gameBoard[i]);
    }
    printf("\n");
}

// Function to get the player's move
int getPlayerMove(char player) {
    int move;
    while (1) {
        printf("Player %c, enter your move (1-9): ", player);
        scanf("%d", &move);
        if (move >= 1 && move <= 9 && gameBoard[move - 1] == ' ') {
            return move - 1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

// Function to check if the game is over
int isGameOver() {
    // Check if there is a winner
    for (int i = 0; i < 8; i++) {
        if (gameBoard[winningCombinations[i][0]] != ' ' &&
            gameBoard[winningCombinations[i][0]] == gameBoard[winningCombinations[i][1]] &&
            gameBoard[winningCombinations[i][0]] == gameBoard[winningCombinations[i][2]]) {
            return GAME_OVER_WIN;
        }
    }

    // Check if the game is a draw
    int emptyCount = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (gameBoard[i] == ' ') {
            emptyCount++;
        }
    }
    if (emptyCount == 0) {
        return GAME_OVER_DRAW;
    }

    // Otherwise, the game is still in progress
    return GAME_IN_PROGRESS;
}

// Function to play the game
void playGame() {
    // Initialize the game board
    initializeGameBoard();

    // Set the current player to player one
    char currentPlayer = PLAYER_ONE;

    // Play the game until it is over
    while (1) {
        // Print the game board
        printGameBoard();

        // Get the player's move
        int move = getPlayerMove(currentPlayer);

        // Update the game board
        gameBoard[move] = currentPlayer;

        // Check if the game is over
        int gameState = isGameOver();
        if (gameState == GAME_OVER_WIN) {
            // Print the winning message
            printf("Player %c wins!\n", currentPlayer);
            break;
        } else if (gameState == GAME_OVER_DRAW) {
            // Print the draw message
            printf("The game is a draw.\n");
            break;
        }

        // Switch the current player
        currentPlayer = (currentPlayer == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    playGame();

    return 0;
}