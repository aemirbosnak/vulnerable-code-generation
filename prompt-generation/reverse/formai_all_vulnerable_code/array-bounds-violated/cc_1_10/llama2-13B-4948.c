//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAYERS 4
#define GAME_LENGTH 10

// Structure to hold player data
typedef struct {
    int score;
    char name[20];
} player_t;

// Array to hold player data
player_t players[PLAYERS];

// Function to print the current state of the game
void print_state(void);

// Function to handle player input
void handle_input(int input);

// Function to update the game state and check for wins
void update_game(void);

// Function to print the final result and exit
void end_game(int winner);

int main(void) {
    // Initialize player data
    for (int i = 0; i < PLAYERS; i++) {
        players[i].score = 0;
        strcpy(players[i].name, "Player ");
        players[i].name[9] = i + '1';
    }

    // Set the game length
    srand(time(NULL));
    for (int i = 0; i < GAME_LENGTH; i++) {
        // Print the current state of the game
        print_state();

        // Handle player input
        handle_input(getchar());

        // Update the game state and check for wins
        update_game();
    }

    // Print the final result and exit
    end_game(get_winner());

    return 0;
}

// Function to print the current state of the game
void print_state(void) {
    printf("--- Game State ---\n");
    for (int i = 0; i < PLAYERS; i++) {
        printf("Player %d: %d\n", i + 1, players[i].score);
    }
}

// Function to handle player input
void handle_input(int input) {
    // Check for valid input
    if (input < '1' || input > '4') {
        printf("Invalid input. Please enter a number from 1 to 4.\n");
        return;
    }

    // Update the player's score
    players[input - '1'].score++;
}

// Function to update the game state and check for wins
void update_game(void) {
    // Check for wins
    for (int i = 0; i < PLAYERS; i++) {
        if (players[i].score == GAME_LENGTH) {
            // Print the winner
            printf("Player %d won the game!\n", i + 1);
            return;
        }
    }

    // If no one has won, print the current state
    print_state();
}

// Function to print the final result and exit
void end_game(int winner) {
    if (winner == -1) {
        printf("The game ended in a tie.\n");
    } else {
        printf("Player %d won the game.\n", winner + 1);
    }
    exit(0);
}

// Function to get the winner of the game
int get_winner(void) {
    int winner = -1;
    for (int i = 0; i < PLAYERS; i++) {
        if (players[i].score > players[winner].score) {
            winner = i;
        }
    }
    return winner;
}