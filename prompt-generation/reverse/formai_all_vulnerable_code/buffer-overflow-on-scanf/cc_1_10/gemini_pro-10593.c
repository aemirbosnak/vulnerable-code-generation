//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of players
#define NUM_PLAYERS 4

// Define the maximum number of rounds
#define MAX_ROUNDS 10

// Define the maximum number of dice per player
#define MAX_DICE 5

// Structure to represent a player
typedef struct {
    char name[20];
    int score;
    int dice[MAX_DICE];
    int num_dice;
} Player;

// Function to roll the dice for a player
void roll_dice(Player *player) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Roll each die and store the result in the player's dice array
    for (int i = 0; i < player->num_dice; i++) {
        player->dice[i] = rand() % 6 + 1;
    }
}

// Function to calculate the score for a player
int calculate_score(Player *player) {
    int score = 0;

    // Add up the values of all the dice
    for (int i = 0; i < player->num_dice; i++) {
        score += player->dice[i];
    }

    return score;
}

// Function to print the results of a round
void print_results(Player *players, int num_players, int round) {
    printf("Round %d results:\n", round);

    // Print the name and score of each player
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    // Print a newline
    printf("\n");
}

// Function to play a game of dice
void play_game(Player *players, int num_players) {
    // Play a maximum of MAX_ROUNDS rounds
    for (int round = 1; round <= MAX_ROUNDS; round++) {
        // Roll the dice for each player
        for (int i = 0; i < num_players; i++) {
            roll_dice(&players[i]);
        }

        // Calculate the score for each player
        for (int i = 0; i < num_players; i++) {
            players[i].score = calculate_score(&players[i]);
        }

        // Print the results of the round
        print_results(players, num_players, round);
    }
}

// Main function
int main() {
    // Create an array of players
    Player players[NUM_PLAYERS];

    // Get the name of each player
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    // Set the number of dice for each player
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter the number of dice for player %s: ", players[i].name);
        scanf("%d", &players[i].num_dice);
    }

    // Play the game
    play_game(players, NUM_PLAYERS);

    return 0;
}