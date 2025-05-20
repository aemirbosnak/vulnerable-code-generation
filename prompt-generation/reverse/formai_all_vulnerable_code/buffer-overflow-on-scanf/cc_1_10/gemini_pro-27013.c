//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Define the game states
enum GameState {
    PLAYING,
    X_WINS,
    O_WINS,
    TIE
};

// Define the players
enum Player {
    X,
    O
};

// Function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
enum GameState check_win() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0] == 'X' ? X_WINS : O_WINS;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i] == 'X' ? X_WINS : O_WINS;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0] == 'X' ? X_WINS : O_WINS;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2] == 'X' ? X_WINS : O_WINS;
    }

    // Check for a tie
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == 9) {
        return TIE;
    }

    // No winner yet
    return PLAYING;
}

// Function to get the player's move
int get_move(enum Player player) {
    int row, col;

    while (1) {
        printf("Player %c, enter your move (row, column): ", player == X ? 'X' : 'O');
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Return the move
        return row * 3 + col;
    }
}

// Function to play the game
void play_game() {
    // Initialize the game state
    enum GameState state = PLAYING;

    // Initialize the current player
    enum Player player = X;

    // Play the game until there is a winner or a tie
    while (state == PLAYING) {
        // Get the player's move
        int move = get_move(player);

        // Update the game board
        board[(move - 1) / 3][(move - 1) % 3] = player == X ? 'X' : 'O';

        // Check if there is a winner
        state = check_win();

        // Switch the player
        player = player == X ? O : X;
    }

    // Print the game board
    print_board();

    // Print the winner or tie message
    switch (state) {
        case X_WINS:
            printf("Player X wins!\n");
            break;
        case O_WINS:
            printf("Player O wins!\n");
            break;
        case TIE:
            printf("Tie game!\n");
            break;
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