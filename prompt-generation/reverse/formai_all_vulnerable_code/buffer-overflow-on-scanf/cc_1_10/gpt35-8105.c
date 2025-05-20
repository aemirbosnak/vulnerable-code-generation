//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 10

// Custom struct for representing a wifi signal
typedef struct wifi_signal {
    char ssid[20];
    int strength;
} wifi_signal;

// Custom struct for representing a player
typedef struct player {
    char name[20];
    wifi_signal signals[5];
} player;

// Global variables
player players[MAX_PLAYERS];
int num_players = 0;

// Helper function for comparing two wifi signals based on their strength
int compare_signals(const void* sig1, const void* sig2) {
    return ((wifi_signal*)sig2)->strength - ((wifi_signal*)sig1)->strength;
}

// Function for adding a player to the game
void add_player() {
    if (num_players == MAX_PLAYERS) {
        printf("Maximum number of players reached. Cannot add more players.\n");
        return;
    }
    printf("Enter name of player %d: ", num_players+1);
    scanf("%s", players[num_players].name);
    printf("Enter wifi signal strengths (in dBm) for player %d:\n", num_players+1);
    for (int i=0; i<5; i++) {
        printf("SSID %d: ", i+1);
        scanf("%s", players[num_players].signals[i].ssid);
        printf("Strength (in dBm): ");
        scanf("%d", &players[num_players].signals[i].strength);
    }
    num_players++;
    printf("Player successfully added!\n");
}

// Function for comparing two players based on the sum of their wifi signal strengths
int compare_players(const void* pl1, const void* pl2) {
    player* player1 = (player*)pl1;
    player* player2 = (player*)pl2;

    int sum_strengths1 = 0, sum_strengths2 = 0;
    for (int i=0; i<5; i++) {
        sum_strengths1 += player1->signals[i].strength;
        sum_strengths2 += player2->signals[i].strength;
    }

    return sum_strengths2 - sum_strengths1;
}

// Function for displaying the list of players in order of their wifi signal strengths
void display_players() {
    qsort(players, num_players, sizeof(player), compare_players);
    printf("Players ranked by wifi signal strength:\n");
    for (int i=0; i<num_players; i++) {
        printf("%d. %s\n", i+1, players[i].name);
        qsort(players[i].signals, 5, sizeof(wifi_signal), compare_signals);
        printf("strongest wifi signal: %s (strength: %d dBm)\n", players[i].signals[0].ssid, players[i].signals[0].strength);
    }
}

// Main function
int main() {
    int choice = 0;
    while (choice != 3) {
        printf("\n----------------------\n");
        printf("Wifi Signal Strength Analyzer\n");
        printf("----------------------\n");
        printf("1. Add player\n");
        printf("2. Display players\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_player(); break;
            case 2: display_players(); break;
            case 3: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    }
    return 0;
}