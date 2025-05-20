//FormAI DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Error codes
#define ERR_NO_ERROR 0
#define ERR_INVALID_INPUT 1
#define ERR_REPEATED_INPUT 2

// Global variables
int player_scores[2] = {0, 0};
int last_input[2] = {-1, -1};

// Function prototypes
int take_input(int player);
int validate_input(int input);
void print_score();
void print_error(int error_code);
void print_winner();

int main() {
    int winner = -1;
    srand(time(NULL));  // Seed the random number generator

    printf("Welcome to the Multiplayer Error Handling Game!\n");

    // Game loop
    while (winner == -1) {
        for (int i = 0; i < 2; i++) {
            printf("Player %d's turn:\n", i+1);

            // Take input from player
            int input = take_input(i);

            // Validate the input
            int error_code = validate_input(input);

            if (error_code != ERR_NO_ERROR) {
                // If there is an error, print the error message and skip this round
                print_error(error_code);
                continue;
            }

            // Add the player's input to their score
            player_scores[i] += input;
            last_input[i] = input;

            // Print the updated score
            print_score();

            if (player_scores[i] >= 100) {
                // If any of the players score more than or equal to 100, end the game
                winner = i+1;
                break;
            }
        }
    }

    // Print the winner
    printf("Player %d wins!\n", winner);
    print_winner();

    return 0;
}

// Function to take input from a player
int take_input(int player) {
    printf("Enter a number between 1 and 10: ");
    int input;
    scanf("%d", &input);
    return input;
}

// Function to validate the input
int validate_input(int input) {
    if (input < 1 || input > 10) {
        return ERR_INVALID_INPUT;
    }

    for (int i = 0; i < 2; i++) {
        if (input == last_input[i]) {
            return ERR_REPEATED_INPUT;
        }
    }

    return ERR_NO_ERROR;
}

// Function to print the current score
void print_score() {
    printf("Player 1 score: %d\n", player_scores[0]);
    printf("Player 2 score: %d\n", player_scores[1]);
}

// Function to print an error message
void print_error(int error_code) {
    switch(error_code) {
        case ERR_INVALID_INPUT:
            printf("Error: Invalid input. Please enter a number between 1 and 10.\n");
            break;
        case ERR_REPEATED_INPUT:
            printf("Error: You cannot repeat the same number as your last input.\n");
            break;
        default:
            printf("Unknown error\n");
    }
}

// Function to print the winner's score and the score difference between the two players
void print_winner() {
    printf("Player 1 score: %d\n", player_scores[0]);
    printf("Player 2 score: %d\n", player_scores[1]);
    printf("Score difference: %d\n", abs(player_scores[0] - player_scores[1]));
}