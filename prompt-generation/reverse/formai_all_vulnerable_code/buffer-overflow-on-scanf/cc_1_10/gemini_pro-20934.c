//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the game board
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Initialize the player's turn
int player_turn = 1;

// Function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
int check_game_over() {
    // Check for a winner
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }

    // Check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return -1;
}

// Function to get the player's move
void get_player_move() {
    int row, col;

    printf("Player %d's turn (row, col): ", player_turn);
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
        printf("Invalid move. Please try again: ");
        scanf("%d %d", &row, &col);
    }

    // Place the player's move on the board
    board[row - 1][col - 1] = player_turn == 1 ? 'X' : 'O';

    // Switch turns
    player_turn = player_turn == 1 ? 2 : 1;
}

// Function to play the game
void play_game() {
    // Print the initial game board
    print_board();

    // Loop until the game is over
    while (check_game_over() == 0) {
        // Get the player's move
        get_player_move();

        // Print the updated game board
        print_board();
    }

    // Check if there is a winner or a tie
    int result = check_game_over();
    if (result == 1) {
        printf("Player %d wins!\n", player_turn == 1 ? 2 : 1);
    } else if (result == -1) {
        printf("Tie game!\n");
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}