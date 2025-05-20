//GEMINI-pro DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 5

// Define the player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the game state
#define GAME_STATE_PLAYING 0
#define GAME_STATE_X_WON 1
#define GAME_STATE_O_WON 2
#define GAME_STATE_DRAW 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the game board
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
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
}

// Function to check if a player has won
int check_win(char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return player == PLAYER_X ? GAME_STATE_X_WON : GAME_STATE_O_WON;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return player == PLAYER_X ? GAME_STATE_X_WON : GAME_STATE_O_WON;
        }
    }

    // Check diagonals
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] == player) {
            count1++;
        }
        if (board[i][BOARD_SIZE - i - 1] == player) {
            count2++;
        }
    }
    if (count1 == BOARD_SIZE || count2 == BOARD_SIZE) {
        return player == PLAYER_X ? GAME_STATE_X_WON : GAME_STATE_O_WON;
    }

    // No winner yet
    return GAME_STATE_PLAYING;
}

// Function to get the next move from a player
int get_next_move(char player) {
    int move;
    do {
        printf("Player %c, enter your move (1-9): ", player);
        scanf("%d", &move);
    } while (move < 1 || move > 9 || board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] != ' ');
    return move;
}

// Function to play the game
void play_game() {
    // Initialize the game board
    init_board();

    // Set the current player to X
    char current_player = PLAYER_X;

    // Play the game until someone wins or there is a draw
    int game_state = GAME_STATE_PLAYING;
    while (game_state == GAME_STATE_PLAYING) {
        // Get the next move from the current player
        int move = get_next_move(current_player);

        // Place the player's symbol on the board
        board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] = current_player;

        // Print the game board
        print_board();

        // Check if the player has won
        game_state = check_win(current_player);

        // Switch the current player
        current_player = current_player == PLAYER_X ? PLAYER_O : PLAYER_X;
    }

    // Print the game result
    if (game_state == GAME_STATE_X_WON) {
        printf("Player X wins!\n");
    } else if (game_state == GAME_STATE_O_WON) {
        printf("Player O wins!\n");
    } else if (game_state == GAME_STATE_DRAW) {
        printf("Draw!\n");
    }
}

int main() {
    // Play the game
    play_game();

    return 0;
}