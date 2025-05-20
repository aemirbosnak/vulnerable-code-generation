//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE]; // Game board
char currentPlayer;      // Current player ('X' or 'O')

// Function prototypes
void initializeBoard();
void printBoard();
bool isMoveValid(int row, int col);
bool isWinningMove();
bool isBoardFull();
void playGame();
void switchPlayer();

int main() {
    printf("Welcome to Tic-Tac-Toe!\n");
    playGame();
    return 0;
}

// Function to initialize the game board
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X'; // X starts first
}

// Function to print the current board state
void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if a move is valid
bool isMoveValid(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false; // Move out of bounds
    }
    return board[row][col] == ' '; // Check if the cell is empty
}

// Function to check if the current move results in a win
bool isWinningMove() {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    
    return false;
}

// Function to check if the board is full
bool isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false; // Found an empty cell
            }
        }
    }
    return true; // No empty cells left
}

// Main game loop
void playGame() {
    initializeBoard();
    bool gameWon = false;

    while (!gameWon && !isBoardFull()) {
        printBoard();
        
        int row, col;
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (isMoveValid(row, col)) {
            board[row][col] = currentPlayer; // Place the move
            gameWon = isWinningMove(); // Check if the current player won
            if (!gameWon) {
                switchPlayer(); // Switch to the other player
            }
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    printBoard(); // Print final board state

    if (gameWon) {
        printf("Congratulations Player %c! You've won!\n", currentPlayer);
    } else {
        printf("It's a draw!\n");
    }
}

// Function to switch player
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}