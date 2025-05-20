//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for the maximum number of players and the maximum name length
#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

// Struct to hold information about each player
struct Player {
    char name[MAX_NAME_LENGTH];
    int health;
    int energy;
    int ammo;
    int x_pos;
    int y_pos;
};

// Function to initialize a player with random values
struct Player initialize_player(char* name) {
    struct Player player;
    strcpy(player.name, name);
    player.health = rand() % 100 + 1;
    player.energy = rand() % 100 + 1;
    player.ammo = rand() % 100 + 1;
    player.x_pos = rand() % 100;
    player.y_pos = rand() % 100;
    return player;
}

// Function to print out information about all players
void print_players(struct Player players[], int num_players) {
    printf("Current players:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Name: %s\n", players[i].name);
        printf("Health: %d\n", players[i].health);
        printf("Energy: %d\n", players[i].energy);
        printf("Ammo: %d\n", players[i].ammo);
        printf("Location: (%d, %d)\n", players[i].x_pos, players[i].y_pos);
        printf("------------------------------\n");
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create an array to store all the players
    struct Player players[MAX_PLAYERS];

    // Ask the user how many players there will be
    int num_players;
    printf("How many players will there be? (max %d) ", MAX_PLAYERS);
    scanf("%d", &num_players);
    if (num_players > MAX_PLAYERS) {
        printf("Sorry, the maximum number of players is %d\n", MAX_PLAYERS);
        return 1;
    }

    // Ask the user to enter a name for each player and initialize them with random values
    for (int i = 0; i < num_players; i++) {
        char name[MAX_NAME_LENGTH];
        printf("Enter a name for player %d: ", i+1);
        scanf("%s", name);
        players[i] = initialize_player(name);
    }

    // Print out information about all the players
    print_players(players, num_players);

    return 0;
}