//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house
#define NUM_ROOMS 10
char *room_descriptions[NUM_ROOMS] = {
    "A dark and dusty living room.",
    "A cobwebbed dining room.",
    "A shadowy library.",
    "A creaky master bedroom.",
    "A spooky guest room.",
    "A haunted attic.",
    "A creepy basement.",
    "A mysterious secret passage.",
    "A terrifying dungeon.",
    "A horrifying torture chamber."
};

// Define the player's stats
#define MAX_HEALTH 100
#define MAX_SANITY 100
struct player {
    int health;
    int sanity;
    int room;
};

// Initialize the player
struct player player = {
    .health = MAX_HEALTH,
    .sanity = MAX_SANITY,
    .room = 0
};

// Generate a random number between min and max
int rand_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Print the player's stats
void print_stats() {
    printf("Health: %d\n", player.health);
    printf("Sanity: %d\n", player.sanity);
    printf("Room: %s\n", room_descriptions[player.room]);
}

// Handle player input
void handle_input() {
    char input[10];
    printf("> ");
    scanf("%s", input);

    if (strcmp(input, "n") == 0) {
        player.room = (player.room + 1) % NUM_ROOMS;
    } else if (strcmp(input, "s") == 0) {
        player.room = (player.room - 1 + NUM_ROOMS) % NUM_ROOMS;
    } else if (strcmp(input, "e") == 0) {
        player.health -= rand_range(1, 10);
        player.sanity -= rand_range(1, 10);
    } else if (strcmp(input, "w") == 0) {
        player.health += rand_range(1, 10);
        player.sanity += rand_range(1, 10);
    } else if (strcmp(input, "q") == 0) {
        exit(0);
    }
}

// Update the player's stats
void update_stats() {
    // Check if the player has died
    if (player.health <= 0) {
        printf("You have died!\n");
        exit(0);
    }

    // Check if the player has gone insane
    if (player.sanity <= 0) {
        printf("You have gone insane!\n");
        exit(0);
    }
}

// Main game loop
int main() {
    srand(time(NULL));

    while (1) {
        print_stats();
        handle_input();
        update_stats();
    }

    return 0;
}