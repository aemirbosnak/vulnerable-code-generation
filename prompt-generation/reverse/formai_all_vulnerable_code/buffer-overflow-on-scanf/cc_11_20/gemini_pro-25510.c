//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game states
#define GAME_STATE_PLAYING 0
#define GAME_STATE_PLAYER_1_WIN 1
#define GAME_STATE_PLAYER_2_WIN 2
#define GAME_STATE_TIE 3

// Create the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Create the game state
int game_state = GAME_STATE_PLAYING;

// Create the current player
char current_player = PLAYER_1;

// Create the game loop
bool game_loop() {
    // Print the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Get the player's move
    int row, col;
    printf("Player %c, enter your move (row, col): ", current_player);
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        printf("Invalid move. Please try again.\n");
        return false;
    }

    // Make the move
    board[row][col] = current_player;

    // Check if the game is over
    game_state = check_game_state();

    // Swap the current player
    current_player = (current_player == PLAYER_1) ? PLAYER_2 : PLAYER_1;

    return true;
}

// Check the game state
int check_game_state() {
    // Check if there are three of the same symbol in a row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == PLAYER_1) ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
        }
    }

    // Check if there are three of the same symbol in a column
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return (board[0][j] == PLAYER_1) ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
        }
    }

    // Check if there are three of the same symbol in a diagonal
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == PLAYER_1) ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == PLAYER_1) ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
    }

    // Check if there are no more empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return GAME_STATE_PLAYING;
            }
        }
    }

    // Otherwise, it's a tie
    return GAME_STATE_TIE;
}

// Main function
int main() {
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Start the game loop
    while (game_state == GAME_STATE_PLAYING) {
        if (!game_loop()) {
            continue;
        }
    }

    // Print the game result
    switch (game_state) {
        case GAME_STATE_PLAYER_1_WIN:
            printf("Player 1 wins!\n");
            break;
        case GAME_STATE_PLAYER_2_WIN:
            printf("Player 2 wins!\n");
            break;
        case GAME_STATE_TIE:
            printf("Tie!\n");
            break;
    }

    return 0;
}