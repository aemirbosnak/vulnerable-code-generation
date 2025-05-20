//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3 // Constants for Tic Tac Toe board size
#define PLAYER1 'X' // Constants for players symbols
#define PLAYER2 'O'

char board[BOARD_SIZE][BOARD_SIZE]; // The Tic Tac Toe board
bool player1Turn = true; // Keeps track of the current player

// Function to initialize the board with blank spaces
void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard() {
    printf("-------------\n"); // Print the top border
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|"); // Print the left border
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]); // Print the cell contents and the right border
        }
        printf("\n-------------\n"); // Print the bottom border
    }
}

// Function to check if the game is over
bool isGameOver() {
    // Check if any player has won
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') || // Check rows
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') || // Check columns
            (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') || // Check diagonal
            (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) { // Check diagonal
            return true;
        }
    }
    // Check if the board is full (tie)
    bool isFull = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                isFull = false;
                break;
            }
        }
        if (!isFull) {
            break;
        }
    }
    return isFull;
}

// Function to get the next move from the player
void getNextMove(int* row, int* col) {
    do {
        printf("Enter row (1-3) and column (1-3) separated by a space: ");
        scanf("%d %d", row, col);
        (*row)--;
        (*col)--;
    } while (!(0 <= *row && *row < BOARD_SIZE && 0 <= *col && *col < BOARD_SIZE && board[*row][*col] == ' '));
}

// Function to get the AI move
void getAIMove(int* row, int* col) {
    // TODO: Implement AI logic
    do {
        *row = rand() % BOARD_SIZE; // Random row
        *col = rand() % BOARD_SIZE; // Random column
    } while (board[*row][*col] != ' ');
}

// Function to play one turn of the game
void playTurn() {
    int row, col;
    if (player1Turn) {
        printf("Player 1's turn (X):\n");
        getNextMove(&row, &col);
        board[row][col] = PLAYER1;
    } else {
        printf("Player 2's turn (O):\n");
        getAIMove(&row, &col);
        board[row][col] = PLAYER2;
    }
    printBoard();
    player1Turn = !player1Turn; // Switch turns
}

// Main function
int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("To play, enter the row (1-3) and column (1-3) of the cell where you want to put your symbol.\n");
    printf("Player 1 (X) will go first.\n");
    srand(time(NULL)); // Initialize random seed
    initializeBoard();
    printBoard();
    while (!isGameOver()) {
        playTurn();
    }
    if (player1Turn) {
        printf("Player 2 (O) wins!\n");
    } else {
        printf("Player 1 (X) wins!\n");
    }
    return 0;
}