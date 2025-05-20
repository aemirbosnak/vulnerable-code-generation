//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PLAYERS 5

typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

// Function to allocate memory for players
Player* allocatePlayers(int count) {
    Player* players = (Player*)malloc(count * sizeof(Player));
    if (!players) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return players;
}

// Function to input player details
void inputPlayers(Player* players, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, MAX_NAME_LENGTH, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = '\0'; // Remove newline
        players[i].score = 0; // Initialize score
    }
}

// Function to simulate scoring for each player
void simulateScoring(Player* players, int count) {
    for (int i = 0; i < count; i++) {
        players[i].score = rand() % 101; // Random score between 0 and 100
        printf("Player %s scored %d points.\n", players[i].name, players[i].score);
    }
}

// Function to display player scores
void displayScores(Player* players, int count) {
    printf("\n=== Player Scores ===\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
    printf("=====================\n");
}

// Function to free allocated memory
void freePlayers(Player* players) {
    free(players);
}

int main() {
    int playerCount = 0;

    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    getchar(); // Consume newline character left by scanf

    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        fprintf(stderr, "Invalid player count. Must be between 1 and %d.\n", MAX_PLAYERS);
        return EXIT_FAILURE;
    }

    // Dynamic memory allocation for players
    Player* players = allocatePlayers(playerCount);
    
    // Input player details
    inputPlayers(players, playerCount);

    // Simulate scoring for each player
    simulateScoring(players, playerCount);

    // Display the scores
    displayScores(players, playerCount);

    // Free dynamically allocated memory
    freePlayers(players);

    return EXIT_SUCCESS;
}