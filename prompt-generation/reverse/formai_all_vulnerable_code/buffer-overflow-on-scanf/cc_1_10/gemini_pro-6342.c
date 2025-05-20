//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 5
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1_SYMBOL 'X'
#define PLAYER2_SYMBOL 'O'

// Define the game state
enum GameState {
    GAME_IN_PROGRESS,
    PLAYER1_WINS,
    PLAYER2_WINS,
    TIE
};

// Initialize the game board
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the game board
void printBoard() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Get player input
int getPlayerInput(char playerSymbol) {
    int row, col;
    printf("Player %c, enter your move (row, col): ", playerSymbol);
    scanf("%d %d", &row, &col);
    return row * BOARD_SIZE + col;
}

// Check if the game is over
enum GameState checkGameState() {
    // Check for horizontal wins
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
            return board[i][0] == PLAYER1_SYMBOL ? PLAYER1_WINS : PLAYER2_WINS;
        }
    }

    // Check for vertical wins
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[3][j] == board[4][j]) {
            return board[0][j] == PLAYER1_SYMBOL ? PLAYER1_WINS : PLAYER2_WINS;
        }
    }

    // Check for diagonal wins
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
        return board[0][0] == PLAYER1_SYMBOL ? PLAYER1_WINS : PLAYER2_WINS;
    }
    if (board[0][4] != ' ' && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
        return board[0][4] == PLAYER1_SYMBOL ? PLAYER1_WINS : PLAYER2_WINS;
    }

    // Check for a tie
    int numEmptyCells = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                numEmptyCells++;
            }
        }
    }
    if (numEmptyCells == 0) {
        return TIE;
    }

    // The game is still in progress
    return GAME_IN_PROGRESS;
}

// Play the game
void playGame() {
    // Initialize the game board
    initBoard();

    // Print the initial game board
    printBoard();

    // Get player input and update the game board
    int move;
    char playerSymbol;
    enum GameState gameState;
    do {
        // Get player 1's input
        playerSymbol = PLAYER1_SYMBOL;
        move = getPlayerInput(playerSymbol);
        board[move / BOARD_SIZE][move % BOARD_SIZE] = playerSymbol;

        // Print the updated game board
        printBoard();

        // Check if the game is over
        gameState = checkGameState();
        if (gameState != GAME_IN_PROGRESS) {
            break;
        }

        // Get player 2's input
        playerSymbol = PLAYER2_SYMBOL;
        move = getPlayerInput(playerSymbol);
        board[move / BOARD_SIZE][move % BOARD_SIZE] = playerSymbol;

        // Print the updated game board
        printBoard();

        // Check if the game is over
        gameState = checkGameState();
    } while (gameState == GAME_IN_PROGRESS);

    // Print the final game board
    printBoard();

    // Announce the winner or tie
    switch (gameState) {
        case PLAYER1_WINS:
            printf("Player 1 wins!\n");
            break;
        case PLAYER2_WINS:
            printf("Player 2 wins!\n");
            break;
        case TIE:
            printf("Tie!\n");
            break;
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