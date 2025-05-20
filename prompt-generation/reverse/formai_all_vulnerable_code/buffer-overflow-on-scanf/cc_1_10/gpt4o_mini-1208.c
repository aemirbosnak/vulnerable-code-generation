//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

// Function prototypes
void displayBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
void resetBoard(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    char player = 'X';
    int row, col, moveCount = 0;

    resetBoard(board);
    printf("Welcome to the Exciting 3x3 Tic Tac Toe Game!\n");

    while (1) {
        displayBoard(board);
        
        // Player's turn
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        
        // Validate input
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = player;
        moveCount++;

        // Check for a win
        if (checkWin(board)) {
            displayBoard(board);
            printf("Congratulations Player %c! You've won!\n", player);
            break;
        }

        // Check for a tie
        if (moveCount == SIZE * SIZE) {
            displayBoard(board);
            printf("It's a tie! Well played everyone!\n");
            break;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

// Function to display the board
void displayBoard(char board[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE - 1; k++) printf("---+");
            printf("---");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check for a win condition
int checkWin(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return 1;
        }
    }
    
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    
    return 0;
}

// Function to reset the game board
void resetBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}