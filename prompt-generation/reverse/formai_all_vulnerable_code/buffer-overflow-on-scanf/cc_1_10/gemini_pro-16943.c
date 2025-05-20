//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 10
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player's position
int player_x, player_y;

// Define the goal position
int goal_x, goal_y;

// Define the number of moves the player has made
int moves;

// Initialize the game board
void init_board() {
    // Set all cells to empty
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Place the player in the starting position
    player_x = 0;
    player_y = 0;

    // Place the goal in a random position
    srand(time(NULL));
    goal_x = rand() % BOARD_SIZE;
    goal_y = rand() % BOARD_SIZE;

    // Set the number of moves to 0
    moves = 0;
}

// Draw the game board
void draw_board() {
    // Print the top border
    printf("+");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("-");
    }
    printf("+\n");

    // Print the rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("|\n");
    }

    // Print the bottom border
    printf("+");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("-");
    }
    printf("+\n");
}

// Get the player's input
char get_input() {
    char input;
    printf("Enter your move (w, a, s, d): ");
    scanf(" %c", &input);
    return input;
}

// Move the player
void move_player(char input) {
    switch (input) {
    case 'w':
        if (player_y > 0) {
            player_y--;
        }
        break;
    case 'a':
        if (player_x > 0) {
            player_x--;
        }
        break;
    case 's':
        if (player_y < BOARD_SIZE - 1) {
            player_y++;
        }
        break;
    case 'd':
        if (player_x < BOARD_SIZE - 1) {
            player_x++;
        }
        break;
    }
    // Increment the number of moves
    moves++;
}

// Check if the player has won
int check_win() {
    return player_x == goal_x && player_y == goal_y;
}

// Main game loop
int main() {
    // Initialize the game board
    init_board();

    // Draw the game board
    draw_board();

    // Get the player's input
    char input;

    // Loop until the player wins or quits
    while (!check_win() && input != 'q') {
        // Get the player's input
        input = get_input();

        // Move the player
        move_player(input);

        // Draw the game board
        draw_board();
    }

    // Print the game over message
    if (check_win()) {
        printf("You win!\n");
        printf("Number of moves: %d\n", moves);
    } else {
        printf("Game over!\n");
    }

    return 0;
}