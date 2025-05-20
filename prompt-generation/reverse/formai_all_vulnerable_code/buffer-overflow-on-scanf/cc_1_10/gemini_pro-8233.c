//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define the game board
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10
char board[BOARD_HEIGHT][BOARD_WIDTH];

// Define the player's position
int player_x = 0;
int player_y = 0;

// Define the goal position
int goal_x = 9;
int goal_y = 9;

// Define the number of moves the player has made
int num_moves = 0;

// Define the game state
enum game_state {
    GAME_RUNNING,
    GAME_WON,
    GAME_LOST
};
enum game_state state = GAME_RUNNING;

// Initialize the game board
void init_board() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = '.';
        }
    }

    // Place the player on the board
    board[player_y][player_x] = 'P';

    // Place the goal on the board
    board[goal_y][goal_x] = 'G';
}

// Print the game board
void print_board() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Get the player's input
void get_input() {
    char input;
    scanf(" %c", &input);

    switch (input) {
        case 'w':
            player_y--;
            break;
        case 'a':
            player_x--;
            break;
        case 's':
            player_y++;
            break;
        case 'd':
            player_x++;
            break;
        case 'q':
            state = GAME_LOST;
            break;
    }
}

// Update the game state
void update_state() {
    // Check if the player has reached the goal
    if (player_x == goal_x && player_y == goal_y) {
        state = GAME_WON;
    }

    // Check if the player has fallen off the board
    if (player_x < 0 || player_x >= BOARD_WIDTH || player_y < 0 || player_y >= BOARD_HEIGHT) {
        state = GAME_LOST;
    }
}

// Main game loop
int main() {
    // Initialize the game board
    init_board();

    // Print the game board
    print_board();

    // Get the player's input
    while (state == GAME_RUNNING) {
        get_input();

        // Update the game state
        update_state();

        // Print the game board
        print_board();
    }

    // Print the game over message
    if (state == GAME_WON) {
        printf("You win!\n");
    } else if (state == GAME_LOST) {
        printf("Game over!\n");
    }

    return 0;
}