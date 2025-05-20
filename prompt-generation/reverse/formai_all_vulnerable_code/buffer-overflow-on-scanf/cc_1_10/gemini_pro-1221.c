//GEMINI-pro DATASET v1.0 Category: Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

// Game board representation
int board[BOARD_SIZE][BOARD_SIZE];

// Player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Game state
#define GAME_NOT_OVER 0
#define PLAYER_1_WINS 1
#define PLAYER_2_WINS 2
#define TIE 3

// Function to check if a player has won
int check_winner(char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return player == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return player == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return player == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return player == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }

    // No winner yet
    return GAME_NOT_OVER;
}

// Function to check if the game is a tie
int check_tie() {
    // Check if all cells are filled
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return GAME_NOT_OVER;
            }
        }
    }

    // No empty cells, so it's a tie
    return TIE;
}

// Function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to get player input
int get_player_input(char player) {
    int row, col;

    printf("Player %c, enter your move (row, col): ", player);
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        printf("Invalid move! Try again.\n");
        return get_player_input(player);
    }

    return row * BOARD_SIZE + col;
}

// Function to main game loop
void play_game() {
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Set the current player
    char current_player = PLAYER_1;

    // Game loop
    while (1) {
        // Get player input
        int move = get_player_input(current_player);

        // Update the game board
        int row = move / BOARD_SIZE;
        int col = move % BOARD_SIZE;
        board[row][col] = current_player;

        // Print the game board
        print_board();

        // Check if the game is over
        int game_state = check_winner(current_player);
        if (game_state != GAME_NOT_OVER) {
            if (game_state == PLAYER_1_WINS) {
                printf("Player 1 wins!\n");
            } else if (game_state == PLAYER_2_WINS) {
                printf("Player 2 wins!\n");
            } else {
                printf("Tie!\n");
            }
            break;
        }

        // Check if the game is a tie
        game_state = check_tie();
        if (game_state == TIE) {
            printf("Tie!\n");
            break;
        }

        // Switch to the other player
        current_player = current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
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