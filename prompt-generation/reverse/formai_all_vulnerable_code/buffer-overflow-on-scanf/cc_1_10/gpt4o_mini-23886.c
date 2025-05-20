//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE], char player);
int isBoardFull(char board[SIZE][SIZE]);
void playGame();

int main() {
    printf("Tic-Tac-Toe Game\n");
    printf("Developed in C\n");
    playGame();
    return 0;
}

// Function to initialize the game board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the game board
void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Function to check for a win
int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Found an empty space
            }
        }
    }
    return 1; // The board is full
}

// Function that contains the game loop
void playGame() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    int row, col;

    initializeBoard(board);
    printBoard(board);

    // Game loop
    while (1) {
        printf("Player %c's turn. Enter row (0, 1, 2) and column (0, 1, 2): ", currentPlayer);
        if (scanf("%d %d", &row, &col) != 2 || row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Invalid input! Please enter numbers from 0 to 2.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        if (board[row][col] != ' ') {
            printf("Cell already occupied! Choose another.\n");
            continue;
        }

        // Update the board
        board[row][col] = currentPlayer;
        printBoard(board);

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        // Check for a draw
        if (isBoardFull(board)) {
            printf("The game is a draw!\n");
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printf("Game Over!\n");
}