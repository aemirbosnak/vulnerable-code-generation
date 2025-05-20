//GEMINI-pro DATASET v1.0 Category: Game ; Style: Ada Lovelace
// A most wondrous example of a C game, crafted in the spirit of the great Ada Lovelace

#include <stdio.h>

// Initialize the board, with each space marked as unoccupied
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Define the player symbols
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Keep track of the current player
char current_player = PLAYER_ONE;

// Display the board
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if a player has won
int check_win() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }

    // No winner yet
    return 0;
}

// Get the player's move
int get_move() {
    int row, column;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &row, &column);

    // Check if the move is valid
    if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE || board[row][column] != ' ') {
        printf("Invalid move. Please try again.\n");
        return get_move();
    }

    // Make the move
    board[row][column] = current_player;

    return 1;
}

// Switch the current player
void switch_player() {
    current_player = (current_player == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
}

int main() {
    // Welcome the players
    printf("Welcome to the most extraordinary game of tic-tac-toe, crafted in the spirit of the great Ada Lovelace!\n");

    // Loop until someone wins
    while (!check_win()) {
        // Display the board
        print_board();

        // Get the player's move
        get_move();

        // Switch the player
        switch_player();
    }

    // Declare the winner
    printf("Congratulations, %c! You have won the game!\n", current_player);

    return 0;
}