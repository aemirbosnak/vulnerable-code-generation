//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Game board size
#define BOARD_SIZE 3

// Game states
enum GameState {
    PLAYING,
    WIN,
    LOSS
};

// Game board
char board[BOARD_SIZE][BOARD_SIZE];

// Current player
enum Player {
    PLAYER1,
    PLAYER2
};

// Current game state
enum GameState state;

// Initialize the game board
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the game board
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if a player has won
int check_win(enum Player player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    // No winner yet
    return 0;
}

// Check if the game is a draw
int check_draw() {
    // Check if all cells are filled
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Not a draw yet
            }
        }
    }

    // It's a draw
    return 1;
}

// Get the next player's move
int get_move(enum Player player) {
    int row, col;

    // Prompt the player for a move
    printf("Player %d, enter your move (row, col): ", player + 1);
    scanf("%d %d", &row, &col);

    // Validate the move
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        printf("Invalid move. Please try again.\n");
        return -1; // Invalid move
    }

    // Return the move
    return row * BOARD_SIZE + col;
}

// Main game loop
void game_loop() {
    // Initialize the game
    init_board();

    // Set the initial game state
    state = PLAYING;

    // Main game loop
    while (state == PLAYING) {
        // Get the next move for player 1
        int move1 = get_move(PLAYER1);

        // If the move is invalid, continue to the next player's turn
        if (move1 == -1) {
            continue;
        }

        // Update the game board
        board[move1 / BOARD_SIZE][move1 % BOARD_SIZE] = 'X';

        // Check if player 1 has won
        if (check_win(PLAYER1)) {
            state = WIN;
            break;
        }

        // Check if the game is a draw
        if (check_draw()) {
            state = LOSS;
            break;
        }

        // Get the next move for player 2
        int move2 = get_move(PLAYER2);

        // If the move is invalid, continue to the next player's turn
        if (move2 == -1) {
            continue;
        }

        // Update the game board
        board[move2 / BOARD_SIZE][move2 % BOARD_SIZE] = 'O';

        // Check if player 2 has won
        if (check_win(PLAYER2)) {
            state = WIN;
            break;
        }

        // Check if the game is a draw
        if (check_draw()) {
            state = LOSS;
            break;
        }
    }

    // Print the final game board
    print_board();

    // Print the game result
    switch (state) {
        case WIN:
            printf("Player %d wins!\n", (state == WIN) ? 1 : 2);
            break;
        case LOSS:
            printf("It's a draw!\n");
            break;
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Start the game loop
    game_loop();

    return 0;
}