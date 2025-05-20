//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Linus Torvalds
// Tic Tac Toe AI in Linus Torvalds style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
char board[3][3];
char player = 'X';
char cpu = 'O';
int turn = 1;
int moves = 0;

// Function to display the board
void display_board() {
    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the board is empty
int is_empty(char c) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == c) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if the board is full
int is_full() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if the player has won
int has_won(char c) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == c && board[1][j] == c && board[2][j] == c) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) {
        return 1;
    } else if (board[0][2] == c && board[1][1] == c && board[2][0] == c) {
        return 1;
    }
    return 0;
}

// Function to make a random move
void random_move() {
    srand(time(NULL));
    int row = rand() % 3;
    int col = rand() % 3;
    if (board[row][col] == ' ') {
        board[row][col] = cpu;
        turn = 0;
    } else {
        random_move();
    }
}

// Main function
int main() {
    // Initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    // Play the game
    while (moves < 9) {
        // Display the board
        display_board();
        // Check if the game is over
        if (has_won(player)) {
            printf("You have won!\n");
            break;
        } else if (has_won(cpu)) {
            printf("The computer has won!\n");
            break;
        } else if (is_full()) {
            printf("The game is a draw!\n");
            break;
        }
        // Make a move
        if (turn) {
            int row, col;
            printf("Enter the row and column: ");
            scanf("%d %d", &row, &col);
            if (board[row][col] == ' ') {
                board[row][col] = player;
                turn = 0;
            } else {
                printf("Invalid move. Try again.\n");
            }
        } else {
            random_move();
        }
        moves++;
    }
    return 0;
}