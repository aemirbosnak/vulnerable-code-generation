//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: artistic
#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

// Function to display the tic tac toe board
void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    printf("  0   1   2\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c   ", board[i][j]);
            if (j < SIZE - 1) {
                printf("| ");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf(" ---+---+---\n");
        }
    }
    printf("\n");
}

// Function to check if a player has won
bool checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full
bool isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function for AI to make a move
void aiMove(char board[SIZE][SIZE], char aiPlayer, char humanPlayer) {
    // AI's logic to find the best move
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = aiPlayer;
                if (checkWin(board, aiPlayer)) {
                    return; // AI wins
                }
                board[i][j] = ' '; // Reset the cell
            }
        }
    }
    
    // Block human player from winning
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = humanPlayer;
                if (checkWin(board, humanPlayer)) {
                    board[i][j] = aiPlayer; // Block
                    return;
                }
                board[i][j] = ' '; // Reset the cell
            }
        }
    }

    // Take center if available
    if (board[1][1] == ' ') {
        board[1][1] = aiPlayer;
        return;
    }

    // Take a corner if available
    for (int i = 0; i < SIZE; i += 2) {
        for (int j = 0; j < SIZE; j += 2) {
            if (board[i][j] == ' ') {
                board[i][j] = aiPlayer;
                return;
            }
        }
    }

    // Take any available empty space
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = aiPlayer;
                return;
            }
        }
    }
}

// Function to play the game
void playGame() {
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char humanPlayer = 'X';
    char aiPlayer = 'O';
    bool humanTurn = true;

    while (true) {
        displayBoard(board);
        if (humanTurn) {
            int row, col;
            printf("Enter your move (row and column): ");
            scanf("%d %d", &row, &col);
            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
                board[row][col] = humanPlayer;
                if (checkWin(board, humanPlayer)) {
                    displayBoard(board);
                    printf("Congratulations! You win!\n");
                    return;
                }
                humanTurn = false;
            } else {
                printf("Invalid move! Try again.\n");
            }
        } else {
            aiMove(board, aiPlayer, humanPlayer);
            if (checkWin(board, aiPlayer)) {
                displayBoard(board);
                printf("AI wins!\n");
                return;
            }
            humanTurn = true;
        }
        if (isBoardFull(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            return;
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe! Play against the AI!\n");
    playGame();
    return 0;
}