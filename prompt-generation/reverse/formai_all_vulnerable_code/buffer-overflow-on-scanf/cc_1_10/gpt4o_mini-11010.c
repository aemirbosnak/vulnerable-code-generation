//GPT-4o-mini DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define NAME_LENGTH 50
#define MAX_SCORE 100

typedef struct {
    char name[NAME_LENGTH];
    int score;
} Player;

void initializePlayers(Player players[], int count);
void playGame(Player players[], int count);
void displayScores(Player players[], int count);
void swap(Player *a, Player *b);
void sortPlayerScores(Player players[], int count);

int main() {
    int playerCount;

    printf("Welcome to the Dynamic Scoring Game!\n");
    printf("How many players will be playing (Up to %d)? ", MAX_PLAYERS);
    scanf("%d", &playerCount);

    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the program and enter a valid number.\n");
        return 1;
    }

    Player *players = (Player *)malloc(playerCount * sizeof(Player));
    if (players == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    initializePlayers(players, playerCount);
    playGame(players, playerCount);

    displayScores(players, playerCount);
    sortPlayerScores(players, playerCount);
    printf("\nScores Sorted:\n");
    displayScores(players, playerCount);

    free(players);
    return 0;
}

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void playGame(Player players[], int count) {
    srand(time(NULL)); // Seed the random number generator

    for (int round = 1; round <= 5; round++) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < count; i++) {
            int roundScore = rand() % (MAX_SCORE + 1); // Random score from 0 to MAX_SCORE
            players[i].score += roundScore;
            printf("%s scored: %d\n", players[i].name, roundScore);
        }
    }
}

void displayScores(Player players[], int count) {
    printf("\n--- Player Scores ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void swap(Player *a, Player *b) {
    Player temp = *a;
    *a = *b;
    *b = temp;
}

void sortPlayerScores(Player players[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (players[j].score < players[j + 1].score) {
                swap(&players[j], &players[j + 1]);
            }
        }
    }
}