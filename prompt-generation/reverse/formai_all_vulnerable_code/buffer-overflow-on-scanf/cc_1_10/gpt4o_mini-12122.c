//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;

// Function to compare scores for sorting
int compare(const void* a, const void* b) {
    Player* playerA = (Player*)a;
    Player* playerB = (Player*)b;
    return playerB->score - playerA->score; // Descending order
}

// Thread function for each player to simulate score update
void* player_thread(void* arg) {
    Player* player = (Player*)arg;
    for (int i = 0; i < 5; i++) {
        int score_increase = rand() % 10; // Randomly increase score
        player->score += score_increase;
        printf("%s's new score: %d\n", player->name, player->score);
        sleep(1);
    }
    return NULL;
}

// Function to create player threads
void start_game() {
    pthread_t threads[MAX_PLAYERS];
    for (int i = 0; i < player_count; i++) {
        if (pthread_create(&threads[i], NULL, player_thread, (void*)&players[i]) != 0) {
            fprintf(stderr, "Error creating thread for %s\n", players[i].name);
            exit(1);
        }
    }

    // Wait for all player threads to finish
    for (int i = 0; i < player_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

// Function to display results
void display_results() {
    // Sort players based on scores
    qsort(players, player_count, sizeof(Player), compare);

    printf("\nFinal Scores:\n");
    for (int i = 0; i < player_count; i++) {
        printf("%d. %s: %d points\n", i + 1, players[i].name, players[i].score);
    }
}

int main() {
    printf("Welcome to the Multiplayer Sorting Game!\n");

    // Input player names and initialize scores
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);

    if (player_count > MAX_PLAYERS || player_count <= 0) {
        fprintf(stderr, "Invalid number of players. Please enter 1 to %d.\n", MAX_PLAYERS);
        return 1;
    }

    for (int i = 0; i < player_count; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0; // Initialize scores to 0
    }

    // Start the game
    start_game();

    // Display results after the game
    display_results();

    return 0;
}