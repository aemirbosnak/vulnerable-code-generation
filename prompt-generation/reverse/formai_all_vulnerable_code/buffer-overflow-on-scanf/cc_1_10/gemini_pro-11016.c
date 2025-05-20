//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// The game board
int table[TABLE_SIZE][TABLE_SIZE];

// The player's position
int player_x, player_y;

// The goal position
int goal_x, goal_y;

// The number of moves made
int num_moves;

// Initialize the game board
void init_game() {
    // Set all cells to 0
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            table[i][j] = 0;
        }
    }

    // Set the player's position
    player_x = 0;
    player_y = 0;

    // Set the goal position
    goal_x = TABLE_SIZE - 1;
    goal_y = TABLE_SIZE - 1;

    // Set the number of moves made to 0
    num_moves = 0;
}

// Print the game board
void print_board() {
    // Print the top border
    printf("+");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("---+");
    }
    printf("\n");

    // Print each row of the board
    for (int i = 0; i < TABLE_SIZE; i++) {
        // Print the left border
        printf("| ");

        // Print each cell in the row
        for (int j = 0; j < TABLE_SIZE; j++) {
            // Print the cell value
            printf("%d ", table[i][j]);
        }

        // Print the right border
        printf("|");
        printf("\n");
    }

    // Print the bottom border
    printf("+");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("---+");
    }
    printf("\n");
}

// Get the player's input
void get_input() {
    // Get the player's input
    char input;
    scanf(" %c", &input);

    // Update the player's position
    switch (input) {
        case 'w':
            player_y--;
            break;
        case 's':
            player_y++;
            break;
        case 'a':
            player_x--;
            break;
        case 'd':
            player_x++;
            break;
    }

    // Increment the number of moves made
    num_moves++;
}

// Check if the player has won
int check_win() {
    // Check if the player is at the goal position
    if (player_x == goal_x && player_y == goal_y) {
        return 1;
    }

    // Otherwise, return 0
    return 0;
}

// Main game loop
int main() {
    // Initialize the game
    init_game();

    // Print the game board
    print_board();

    // Get the player's input
    while (!check_win()) {
        get_input();

        // Print the game board
        print_board();
    }

    // Print the number of moves made
    printf("You win in %d moves!\n", num_moves);

    return 0;
}