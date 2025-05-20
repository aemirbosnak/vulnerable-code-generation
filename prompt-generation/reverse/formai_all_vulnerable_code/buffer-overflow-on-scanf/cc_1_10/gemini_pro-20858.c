//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the game board
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Define the player symbols
char player_symbols[MAX_PLAYERS] = {'X', 'O', 'A', 'B'};

// Define the current player
int current_player = 0;

// Get the player's move
void get_move(int player) {
    int row, col;

    printf("Player %d, enter your move (row, col): ", player + 1);
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        printf("Invalid move. Try again.\n");
        get_move(player);
    }

    // Make the move
    board[row][col] = player_symbols[player];
}

// Check if there is a winner
int check_winner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    // No winner yet
    return 0;
}

// Print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Play the game
void play_game() {
    // Get the player's moves
    get_move(current_player);

    // Check if there is a winner
    int winner = check_winner();

    // Print the game board
    print_board();

    // Check if the game is over
    if (winner != 0) {
        printf("Player %d wins!\n", winner);
        return;
    }

    // Switch to the next player
    current_player = (current_player + 1) % MAX_PLAYERS;

    // Play the game again
    play_game();
}

// Main function
int main() {
    // Play the game
    play_game();

    return 0;
}