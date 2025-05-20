//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_DICE 5
#define MAX_DICE_VALUE 6

// Player struct
typedef struct {
    char name[20];
    int score;
} Player;

// Function to roll a single die
int roll_die() {
    return (rand() % MAX_DICE_VALUE) + 1;
}

// Function to roll all of a player's dice
void roll_dice(Player *player) {
    for (int i = 0; i < NUM_DICE; i++) {
        player->score += roll_die();
    }
}

// Function to print the scores of all players
void print_scores(Player *players) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

// Function to determine the winner of the game
Player *get_winner(Player *players) {
    int max_score = 0;
    Player *winner = NULL;

    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            winner = &players[i];
        }
    }

    return winner;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the players
    Player players[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Roll the dice for each player
    for (int i = 0; i < NUM_PLAYERS; i++) {
        roll_dice(&players[i]);
    }

    // Print the scores of all players
    print_scores(players);

    // Get the winner of the game
    Player *winner = get_winner(players);

    // Print the name of the winner
    printf("The winner is %s!\n", winner->name);

    return 0;
}