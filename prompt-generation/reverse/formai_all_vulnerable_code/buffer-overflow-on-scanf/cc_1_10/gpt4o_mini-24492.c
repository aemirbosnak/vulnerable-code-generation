//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define ROUNDS 10

typedef struct {
    char name[30];
    int score;
} Player;

void initialize_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline character
        players[i].score = 0;
    }
}

void print_scores(Player players[], int num_players) {
    printf("\n--- Current Scores ---\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
    printf("----------------------\n");
}

int random_event() {
    return rand() % 20 + 1; // Random event score between 1 and 20
}

void play_round(Player players[], int num_players) {
    printf("\n--- New Round ---\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s's turn!\n", players[i].name);
        int score = random_event();
        players[i].score += score;
        printf("%s scored %d points!\n", players[i].name, score);
    }
    print_scores(players, num_players);
}

void print_final_scores(Player players[], int num_players) {
    printf("\n--- Final Scores ---\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
    printf("----------------------\n");
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players;

    srand(time(NULL));  // Seed for random number generator

    printf("Welcome to the Statistical Table Game!\n");
    printf("How many players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar(); // Clear newline from the input buffer

    // Check for valid number of players
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting game.\n");
        return 1;
    }

    initialize_players(players, num_players);
    
    for (int i = 0; i < ROUNDS; i++) {
        printf("\n--- Round %d ---\n", i + 1);
        play_round(players, num_players);
    }

    print_final_scores(players, num_players);

    // Determine and print the winner
    int winner_index = 0;
    for (int i = 1; i < num_players; i++) {
        if (players[i].score > players[winner_index].score) {
            winner_index = i;
        }
    }
    printf("\nCongratulations, %s! You are the winner with %d points!\n", players[winner_index].name, players[winner_index].score);
    
    return 0;
}