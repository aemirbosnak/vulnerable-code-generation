//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define BOARD_SIZE 5
#define PLAYER_1 'X'
#define PLAYER_2 'O'
#define EMPTY ' '

// Function prototypes
void initializeBoard(char board[][BOARD_SIZE]);
void printBoard(char board[][BOARD_SIZE]);
int checkWinner(char board[][BOARD_SIZE]);
void playGame(char board[][BOARD_SIZE]);

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game board
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    // Print the game board
    printBoard(board);

    // Play the game
    playGame(board);

    return 0;
}

// Initializes the game board with empty spaces
void initializeBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

// Prints the game board to the console
void printBoard(char board[][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Checks if there is a winner on the game board
int checkWinner(char board[][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != EMPTY && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // No winner yet
    return 0;
}

// Plays the game of Tic-Tac-Toe
void playGame(char board[][BOARD_SIZE]) {
    int winner = 0;
    int player = 1;

    while (winner == 0) {
        // Get the player's move
        int row, column;
        do {
            printf("Player %d, enter row and column (1-3): ", player);
            scanf("%d %d", &row, &column);
        } while (row < 1 || row > BOARD_SIZE || column < 1 || column > BOARD_SIZE || board[row - 1][column - 1] != EMPTY);

        // Place the player's mark on the board
        board[row - 1][column - 1] = player == 1 ? PLAYER_1 : PLAYER_2;

        // Print the game board
        printBoard(board);

        // Check if there is a winner
        winner = checkWinner(board);

        // Switch players
        player = player == 1 ? 2 : 1;
    }

    // Print the winner
    if (winner == PLAYER_1) {
        printf("Player 1 wins!\n");
    } else if (winner == PLAYER_2) {
        printf("Player 2 wins!\n");
    } else {
        printf("Draw!\n");
    }
}