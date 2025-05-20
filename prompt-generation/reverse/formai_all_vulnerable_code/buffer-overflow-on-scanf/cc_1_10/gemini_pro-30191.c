//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define GRID_SIZE 5
char grid[GRID_SIZE][GRID_SIZE];

// Define the player's position
int player_x = 0;
int player_y = 0;

// Define the goal position
int goal_x = GRID_SIZE - 1;
int goal_y = GRID_SIZE - 1;

// Define the number of moves the player has made
int moves = 0;

// Define the function to initialize the game board
void init_game() {
    // Set all the squares on the game board to be empty
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = ' ';
        }
    }

    // Set the player's position to the starting position
    player_x = 0;
    player_y = 0;

    // Set the goal position to the ending position
    goal_x = GRID_SIZE - 1;
    goal_y = GRID_SIZE - 1;

    // Set the number of moves the player has made to 0
    moves = 0;
}

// Define the function to print the game board
void print_game() {
    // Print the top border of the game board
    printf("+---+---+---+---+---+\n");

    // Print each row of the game board
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c | ", grid[i][j]);
        }
        printf("\n+---+---+---+---+---+\n");
    }
}

// Define the function to get the player's move
char get_move() {
    // Prompt the player for a move
    printf("Enter your move (w, a, s, d): ");

    // Read the player's move from the console
    char move;
    scanf(" %c", &move);

    // Return the player's move
    return move;
}

// Define the function to make a move
void make_move(char move) {
    // Check if the move is valid
    if (move == 'w' && player_y > 0) {
        player_y--;
    } else if (move == 'a' && player_x > 0) {
        player_x--;
    } else if (move == 's' && player_y < GRID_SIZE - 1) {
        player_y++;
    } else if (move == 'd' && player_x < GRID_SIZE - 1) {
        player_x++;
    }

    // Increment the number of moves the player has made
    moves++;
}

// Define the function to check if the player has won
int check_win() {
    // Check if the player is at the goal position
    if (player_x == goal_x && player_y == goal_y) {
        return 1;
    } else {
        return 0;
    }
}

// Define the main function
int main() {
    // Initialize the game board
    init_game();

    // Print the game board
    print_game();

    // Get the player's move
    char move = get_move();

    // Make the move
    make_move(move);

    // Check if the player has won
    int win = check_win();

    // If the player has won, print a victory message
    if (win) {
        printf("You win!\n");
    } else {
        // If the player has not won, print a game over message
        printf("Game over!\n");
    }

    // Return 0 to indicate that the program has terminated successfully
    return 0;
}