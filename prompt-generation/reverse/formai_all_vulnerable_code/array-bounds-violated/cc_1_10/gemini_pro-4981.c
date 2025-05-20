//GEMINI-pro DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the game state
#define STATE_PLAYING 0
#define STATE_DRAW 1
#define STATE_WIN 2

// Define the winning combinations
int winning_combinations[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

// Define the game board
char board[BOARD_SIZE * BOARD_SIZE];

// Define the current player
char current_player;

// Define the game state
int game_state;

// Initialize the game board
void init_board() {
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        board[i] = ' ';
    }
}

// Draw the game board
void draw_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i * BOARD_SIZE + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Get the player input
int get_player_input() {
    int input;
    printf("Enter your move (1-9): ");
    scanf("%d", &input);
    return input - 1;
}

// Check if the move is valid
int is_valid_move(int move) {
    return board[move] == ' ';
}

// Make a move
void make_move(int move, char player) {
    board[move] = player;
}

// Check if the game is over
int is_game_over() {
    // Check for a win
    for (int i = 0; i < 8; i++) {
        if (board[winning_combinations[i][0]] == board[winning_combinations[i][1]] &&
            board[winning_combinations[i][1]] == board[winning_combinations[i][2]] &&
            board[winning_combinations[i][0]] != ' ') {
            return STATE_WIN;
        }
    }

    // Check for a draw
    int count = 0;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (board[i] != ' ') {
            count++;
        }
    }
    if (count == BOARD_SIZE * BOARD_SIZE) {
        return STATE_DRAW;
    }

    // The game is still playing
    return STATE_PLAYING;
}

// Play the game
void play_game() {
    // Initialize the game
    init_board();
    current_player = PLAYER_X;
    game_state = STATE_PLAYING;

    // Game loop
    while (game_state == STATE_PLAYING) {
        // Draw the board
        draw_board();

        // Get the player input
        int move = get_player_input();

        // Check if the move is valid
        if (!is_valid_move(move)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        make_move(move, current_player);

        // Check if the game is over
        game_state = is_game_over();

        // Switch the current player
        current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Draw the board
    draw_board();

    // Announce the winner
    if (game_state == STATE_WIN) {
        printf("Player %c wins!\n", current_player);
    } else if (game_state == STATE_DRAW) {
        printf("It's a draw!\n");
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