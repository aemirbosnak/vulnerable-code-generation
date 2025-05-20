//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_FORTUNES 10

// Array of fortunes
char *fortunes[] = {
    "You will have a great fortune!",
    "You will have a long and happy life!",
    "You will find true love!",
    "You will be successful in your career!",
    "You will be rich and famous!",
    "You will travel the world!",
    "You will make a difference in the world!",
    "You will be happy and content!",
    "You will have a family and friends who love you!",
    "You will live a long and prosperous life!"
};

// Array of player names
char *player_names[NUM_PLAYERS];

// Get player names from the user
void get_player_names() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        player_names[i] = malloc(256);
        scanf("%s", player_names[i]);
    }
}

// Get a random fortune
char *get_random_fortune() {
    srand(time(NULL));
    int index = rand() % NUM_FORTUNES;
    return fortunes[index];
}

// Print the fortunes for all players
void print_fortunes() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        char *fortune = get_random_fortune();
        printf("%s's fortune: %s\n", player_names[i], fortune);
    }
}

// Free the memory allocated for player names
void free_player_names() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        free(player_names[i]);
    }
}

int main() {
    // Get player names
    get_player_names();

    // Print the fortunes
    print_fortunes();

    // Free the memory allocated for player names
    free_player_names();

    return 0;
}