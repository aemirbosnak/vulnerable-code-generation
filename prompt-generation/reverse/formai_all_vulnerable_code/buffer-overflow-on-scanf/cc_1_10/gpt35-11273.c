//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 5

// Struct defining each player
typedef struct {
    char name[20];
    int score;
    int living;
} Player;

// Function prototypes
void play_game(Player[], int);
int roll_dice();
void print_scores(Player[], int);
int get_living_players(Player[], int);

int main() {
    int num_players;
    printf("Welcome to the multiplayer dice rolling game!\n");
    printf("How many players will be playing (2-5)? ");
    scanf("%d", &num_players);

    // Validate number of players
    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting program.\n");
        return 1;
    }

    Player players[num_players];

    // Prompt for player names and initialize scores and living status
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of Player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].living = 1; // 1 if player is still in the game, 0 otherwise
    }

    play_game(players, num_players);

    return 0;
}

// Function to play the game
void play_game(Player players[], int num_players) {
    printf("Let the game begin!\n");

    while (get_living_players(players, num_players) > 1) {
        for (int i = 0; i < num_players; i++) {
            if (players[i].living) {
                printf("%s, it's your turn to roll the dice!\n", players[i].name);
                int roll = roll_dice();

                if (roll == 1) {
                    players[i].living = 0;
                    printf("Uh oh, you rolled a 1. You're out of the game, %s.\n", players[i].name);
                } else {
                    players[i].score += roll;
                    printf("You rolled a %d. Your current score is %d, %s.\n", roll, players[i].score, players[i].name);
                }

                print_scores(players, num_players);
            }
        }
    }

    // Game is over; print out winners
    printf("Game over! Winners:\n");
    for (int i = 0; i < num_players; i++) {
        if (players[i].living) {
            printf("- %s with a score of %d!\n", players[i].name, players[i].score);
        }
    }
}

// Function to simulate rolling a dice
int roll_dice() {
    srand(time(NULL));
    return (rand() % 6) + 1; // returns a random number from 1 to 6
}

// Function to print out the score of each player
void print_scores(Player players[], int num_players) {
    printf("Current scores:\n");
    for (int i = 0; i < num_players; i++) {
        if (players[i].living) {
            printf("- %s: %d\n", players[i].name, players[i].score);
        }
    }
}

// Function to get the number of players still in the game (i.e. living)
int get_living_players(Player players[], int num_players) {
    int count = 0;
    for (int i = 0; i < num_players; i++) {
        if (players[i].living) {
            count++;
        }
    }
    return count;
}