//FormAI DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define maximum length of player names
#define NAME_LENGTH 20

// Define maximum number of players
#define MAX_PLAYERS 4

// Define maximum number of rounds
#define MAX_ROUNDS 5

/*
 * Struct to hold player information
 */
typedef struct {
    char name[NAME_LENGTH];
    int score;
} player;

/*
 * Function to get player names and store them in the player array
 */
void get_player_names(player *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

/*
 * Function to play a round of the game
 */
void play_round(player *players, int num_players) {
    // Generate a random number between 1 and 10
    int target = rand() % 10 + 1;
    
    printf("The target number is %d\n", target);
    
    // Loop through each player and ask them to guess the target number
    for (int i = 0; i < num_players; i++) {
        int guess;
        printf("%s, enter your guess: ", players[i].name);
        scanf("%d", &guess);
        players[i].score += abs(target - guess);
    }
}

/*
 * Function to display the current scores
 */
void display_scores(player *players, int num_players, int round) {
    printf("Scores after round %d:\n", round);
    
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

/*
 * Function to determine the winner of the game
 */
int get_winner(player *players, int num_players) {
    int winner = 0;
    
    for (int i = 1; i < num_players; i++) {
        if (players[i].score < players[winner].score) {
            winner = i;
        }
    }
    
    return winner;
}

int main() {
    int num_players;
    player players[MAX_PLAYERS];
    
    // Get the number of players
    do {
        printf("Enter the number of players (2-4): ");
        scanf("%d", &num_players);
    } while (num_players < 2 || num_players > 4);
    
    // Get player names
    get_player_names(players, num_players);
    
    // Play the game
    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("Round %d\n", round);
        play_round(players, num_players);
        display_scores(players, num_players, round);
    }
    
    // Determine the winner
    int winner = get_winner(players, num_players);
    printf("The winner is %s with a score of %d!\n", players[winner].name, players[winner].score);
    
    return 0;
}