//GEMINI-pro DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game states
#define GAME_IN_PROGRESS 0
#define PLAYER_1_WIN 1
#define PLAYER_2_WIN 2
#define DRAW 3

// Create the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game state
int game_state = GAME_IN_PROGRESS;

// Get the player's move
int get_player_move(char player) {
    int row, col;

    // Get the row and column from the player
    printf("Player %c, enter your move (row, column): ", player);
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        printf("Invalid move. Try again.\n");
        return -1;
    }

    // Return the move
    return row * BOARD_SIZE + col;
}

// Check if the game is over
int check_game_over() {
    int i, j;

    // Check for a win in rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == PLAYER_1 ? PLAYER_1_WIN : PLAYER_2_WIN;
        }
    }

    // Check for a win in columns
    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j] == PLAYER_1 ? PLAYER_1_WIN : PLAYER_2_WIN;
        }
    }

    // Check for a win in diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == PLAYER_1 ? PLAYER_1_WIN : PLAYER_2_WIN;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == PLAYER_1 ? PLAYER_1_WIN : PLAYER_2_WIN;
    }

    // Check for a draw
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return GAME_IN_PROGRESS;
            }
        }
    }

    // If none of the above conditions are met, the game is over
    return DRAW;
}

// Print the game board
void print_board() {
    int i, j;

    // Print the top border
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("+---");
    }
    printf("+\n");

    // Print the rows
    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %d |", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");

        // Print the horizontal border
        printf("   ");
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("+---");
        }
        printf("+\n");
    }
}

// Play the game
void play_game() {
    int move;
    char player = PLAYER_1;

    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Loop until the game is over
    while (game_state == GAME_IN_PROGRESS) {
        // Print the game board
        print_board();

        // Get the player's move
        move = get_player_move(player);

        // Update the game board
        board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

        // Check if the game is over
        game_state = check_game_over();

        // Switch players
        player = player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
    }

    // Print the game over message
    switch (game_state) {
    case PLAYER_1_WIN:
        printf("Player 1 wins!\n");
        break;
    case PLAYER_2_WIN:
        printf("Player 2 wins!\n");
        break;
    case DRAW:
        printf("Draw!\n");
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