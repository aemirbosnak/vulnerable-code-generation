//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYERS 2
#define SIZE 3
#define MIN_VAL 0
#define MAX_VAL 9

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create matrices for players and the board
    int player1[SIZE][SIZE];
    int player2[SIZE][SIZE];
    int board[SIZE][SIZE];

    // Initialize matrices with random numbers
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            player1[i][j] = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
            player2[i][j] = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
            board[i][j] = 0;
        }
    }

    // Print the initial matrices
    printf("Player 1's matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", player1[i][j]);
        }
        printf("\n");
    }

    printf("Player 2's matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", player2[i][j]);
        }
        printf("\n");
    }

    // Start the game
    int turn = 1;
    while (1) {
        // Get the player's move
        int row, col;
        if (turn == 1) {
            printf("Player 1, enter a row and column (separated by a space): ");
            scanf("%d %d", &row, &col);
        } else {
            printf("Player 2, enter a row and column (separated by a space): ");
            scanf("%d %d", &row, &col);
        }

        // Check if the move is valid
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != 0) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Place the player's symbol on the board
        if (turn == 1) {
            board[row][col] = 1;
        } else {
            board[row][col] = 2;
        }

        // Check if the player has won
        int winner = check_winner(board);
        if (winner != 0) {
            // Print the winning matrix
            printf("The winner is Player %d!\n", winner);
            printf("Winning matrix:\n");
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    printf("%d ", board[i][j]);
                }
                printf("\n");
            }
            break;
        }

        // Switch turns
        turn = (turn % PLAYERS) + 1;
    }

    return 0;
}

// Function to check if a player has won
int check_winner(int board[SIZE][SIZE]) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // No winner yet
    return 0;
}