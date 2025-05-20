//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define GAME_TURN_TIME 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void initializePlayers(Player players[], int count);
void displayScores(Player players[], int count);
void takeTurn(Player *player);
void handleError(const char *message);

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;
    
    printf("Welcome to the Multiplayer Game!\n");
    printf("Enter number of players (1-%d): ", MAX_PLAYERS);
    
    // Input validation for number of players
    if (scanf("%d", &playerCount) != 1 || playerCount < 1 || playerCount > MAX_PLAYERS) {
        handleError("Invalid number of players.");
    }

    initializePlayers(players, playerCount);
    
    // Start game loop
    for (int turn = 0; turn < GAME_TURN_TIME; turn++) {
        for (int i = 0; i < playerCount; i++) {
            printf("\nPlayer %s's turn!\n", players[i].name);
            takeTurn(&players[i]);
        }
    }

    displayScores(players, playerCount);
    return 0;
}

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for Player %d: ", i + 1);
        if (scanf("%s", players[i].name) != 1) {
            handleError("Failed to read player name.");
        }
        players[i].score = 0;
    }
}

void displayScores(Player players[], int count) {
    printf("\nFinal Scores:\n");
    for (int i = 0; i < count; i++) {
        printf("Player %s: %d points\n", players[i].name, players[i].score);
    }
}

void takeTurn(Player *player) {
    int pointsEarned = rand() % 10; // Random points between 0 and 9
    sleep(1); // Simulate time taken for the turn
    player->score += pointsEarned;
    printf("Player %s earned %d points!\n", player->name, pointsEarned);
}

void handleError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}