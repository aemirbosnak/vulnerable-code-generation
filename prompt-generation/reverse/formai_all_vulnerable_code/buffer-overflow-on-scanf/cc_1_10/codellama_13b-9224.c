//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: happy
// A happy Terminal Based Game example program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the game board
void displayBoard(int board[6][6]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is won
int checkWin(int board[6][6], int player) {
    // Check rows
    for (int i = 0; i < 6; i++) {
        int count = 0;
        for (int j = 0; j < 6; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == 6) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 6; i++) {
        int count = 0;
        for (int j = 0; j < 6; j++) {
            if (board[j][i] == player) {
                count++;
            }
        }
        if (count == 6) {
            return 1;
        }
    }

    // Check diagonals
    int count = 0;
    for (int i = 0; i < 6; i++) {
        if (board[i][i] == player) {
            count++;
        }
    }
    if (count == 6) {
        return 1;
    }

    count = 0;
    for (int i = 0; i < 6; i++) {
        if (board[i][5-i] == player) {
            count++;
        }
    }
    if (count == 6) {
        return 1;
    }

    return 0;
}

// Function to make a move
void makeMove(int board[6][6], int player) {
    int row, col;
    printf("Enter the row and column: ");
    scanf("%d %d", &row, &col);
    board[row][col] = player;
}

// Function to check if the game is over
int checkGameOver(int board[6][6]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Main function
int main() {
    // Initialize the game board
    int board[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    // Initialize the player and turn
    int player = 1;
    int turn = 0;

    // Game loop
    while (1) {
        // Display the game board
        displayBoard(board);

        // Check if the game is over
        if (checkGameOver(board)) {
            printf("Game over!\n");
            break;
        }

        // Make a move
        makeMove(board, player);

        // Check if the game is won
        if (checkWin(board, player)) {
            printf("Player %d wins!\n", player);
            break;
        }

        // Switch player
        player = (player == 1) ? 2 : 1;

        // Increment turn
        turn++;
    }

    return 0;
}