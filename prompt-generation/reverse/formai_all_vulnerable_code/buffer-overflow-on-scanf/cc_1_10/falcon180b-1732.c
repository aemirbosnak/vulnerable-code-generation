//Falcon-180B DATASET v1.0 Category: Table Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game board
#define BOARD_SIZE 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game board with empty spaces
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Print the game board
void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if a player has won the game
int checkWin(char symbol) {
    // Check horizontal lines
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }

    // Check vertical lines
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return 1;
        }
    }

    // Check diagonal lines
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }

    return 0;
}

// Play the game
void playGame() {
    int players = 2;
    int currentPlayer = 0;
    char symbols[2] = {'X', 'O'};

    // Initialize the game board
    initBoard();

    // Print the game board
    printBoard();

    // Start the game loop
    while (1) {
        // Get the current player's move
        int row, col;
        printf("Player %d's turn. Enter row and column: ", currentPlayer + 1);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col]!= '-') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Update the game board
        board[row][col] = symbols[currentPlayer];

        // Check if the game is over
        if (checkWin(symbols[currentPlayer])) {
            printf("Player %d wins!\n", currentPlayer + 1);
            break;
        }

        // Switch to the next player
        currentPlayer = (currentPlayer + 1) % players;

        // Print the game board
        printBoard();
    }
}

// Main function
int main() {
    srand(time(NULL));

    int players = rand() % 3 + 2; // Randomly choose the number of players (2 or 3)

    playGame();

    return 0;
}