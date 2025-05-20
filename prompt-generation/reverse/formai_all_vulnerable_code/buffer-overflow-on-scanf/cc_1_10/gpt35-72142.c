//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

// Struct for player information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int download_speed;
    int upload_speed;
} Player;

// Function to generate random speeds
int generate_speed() {
    return rand() % 101;
}

int main() {
    // Initialize variables
    Player players[MAX_PLAYERS];
    int num_players = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of players
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    // Make sure the number of players is within the limit
    if (num_players > MAX_PLAYERS) {
        printf("Error: too many players. Maximum is %d\n", MAX_PLAYERS);
        return 0;
    }

    // Get the names and generate speeds for each player
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].download_speed = generate_speed();
        players[i].upload_speed = generate_speed();
        printf("%s's download speed: %d\n", players[i].name, players[i].download_speed);
        printf("%s's upload speed: %d\n", players[i].name, players[i].upload_speed);
    }

    // Print out the results
    printf("Results:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s's download speed: %d\n", players[i].name, players[i].download_speed);
        printf("%s's upload speed: %d\n", players[i].name, players[i].upload_speed);
        printf("\n");
    }

    return 0;
}