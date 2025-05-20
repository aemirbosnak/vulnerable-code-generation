//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Player struct
typedef struct {
    char name[32];
    int steps;
    int distance;
    int calories;
    int rank;
} Player;

// Global variables
int num_players;
Player players[10];
pthread_mutex_t mutex;

// Function to compare players by rank
int compare_players(const void *a, const void *b) {
    Player *player1 = (Player *)a;
    Player *player2 = (Player *)b;
    return player2->rank - player1->rank;
}

// Function to update a player's stats
void update_player(Player *player, int steps, int distance, int calories) {
    player->steps += steps;
    player->distance += distance;
    player->calories += calories;

    // Calculate player's rank
    player->rank = 0;
    for (int i = 0; i < num_players; i++) {
        if (players[i].steps > player->steps) {
            player->rank++;
        }
    }
}

// Function to handle player input
void *player_input(void *arg) {
    Player *player = (Player *)arg;

    // Get player input
    int steps, distance, calories;
    printf("Enter your steps, distance, and calories: ");
    scanf("%d %d %d", &steps, &distance, &calories);

    // Update player's stats
    pthread_mutex_lock(&mutex);
    update_player(player, steps, distance, calories);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Main function
int main() {
    // Get number of players
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    // Create players
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].steps = 0;
        players[i].distance = 0;
        players[i].calories = 0;
        players[i].rank = 0;
    }

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t threads[num_players];
    for (int i = 0; i < num_players; i++) {
        pthread_create(&threads[i], NULL, player_input, &players[i]);
    }

    // Join threads
    for (int i = 0; i < num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    // Sort players by rank
    qsort(players, num_players, sizeof(Player), compare_players);

    // Print player stats
    printf("Player Stats:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d steps, %d distance, %d calories, rank %d\n", players[i].name, players[i].steps, players[i].distance, players[i].calories, players[i].rank);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}