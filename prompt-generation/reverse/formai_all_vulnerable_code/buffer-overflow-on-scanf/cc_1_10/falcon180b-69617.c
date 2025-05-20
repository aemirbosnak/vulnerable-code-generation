//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the maximum number of rounds
#define MAX_ROUNDS 10

// Define the number of sides of a die
#define NUM_SIDES 6

// Define the number of players
int num_players;

// Define the scores of the players
int scores[MAX_PLAYERS];

// Define the function prototypes
void roll_die(int *die_value);
void play_round(int player_num);
void play_game();

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Prompt the user for the number of players
    printf("Enter the number of players (1-4): ");
    scanf("%d", &num_players);

    // Initialize the scores of the players
    for (int i = 0; i < num_players; i++) {
        scores[i] = 0;
    }

    // Play the game
    play_game();

    // Print the final scores of the players
    printf("\nFinal Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %d\n", i+1, scores[i]);
    }

    return 0;
}

// This function simulates the rolling of a die
void roll_die(int *die_value) {
    *die_value = rand() % NUM_SIDES + 1;
}

// This function plays a single round of the game
void play_round(int player_num) {
    // Roll the die for the current player
    int die_value = 0;
    roll_die(&die_value);

    // Add the value of the die to the player's score
    scores[player_num-1] += die_value;

    // Print the result of the roll
    printf("Player %d rolled a %d.\n", player_num, die_value);
}

// This function plays the entire game
void play_game() {
    // Play the specified number of rounds
    for (int i = 0; i < MAX_ROUNDS; i++) {
        // Play a round for each player
        for (int j = 1; j <= num_players; j++) {
            play_round(j);
        }
    }
}