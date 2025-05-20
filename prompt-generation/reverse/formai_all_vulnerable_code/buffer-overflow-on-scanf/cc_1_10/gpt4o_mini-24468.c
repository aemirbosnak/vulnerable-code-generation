//GPT-4o-mini DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50
#define MAX_ROUNDS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void welcomeMessage() {
    printf("Welcome to the Ultimate Dice Game!\n");
    printf("Roll the dice and score points based on the outcome.\n");
    printf("Let's see who can reach the highest score in %d rounds!\n", MAX_ROUNDS);
}

void getPlayerNames(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline character
        players[i].score = 0;
    }
}

void rollDiceAndScore(Player *player) {
    int roll = (rand() % 6) + 1;  // Roll a die (1-6)
    player->score += roll;
    printf("%s rolled a %d! Total Score: %d\n", player->name, roll, player->score);
}

void playRound(Player players[], int numPlayers) {
    printf("\nStarting a new round!\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("It's %s's turn.\n", players[i].name);
        rollDiceAndScore(&players[i]);
    }
}

void displayScores(Player players[], int numPlayers) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
}

void findWinner(Player players[], int numPlayers) {
    Player *winner = &players[0];
    for (int i = 1; i < numPlayers; i++) {
        if (players[i].score > winner->score) {
            winner = &players[i];
        }
    }
    printf("\nThe winner is %s with %d points!\n", winner->name, winner->score);
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int numPlayers;

    welcomeMessage();

    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    getchar(); // Consume newline character left by scanf
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting the game.\n");
        return 1;
    }

    getPlayerNames(players, numPlayers);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n---- Round %d ----\n", round);
        playRound(players, numPlayers);
        displayScores(players, numPlayers);
    }

    findWinner(players, numPlayers);
    return 0;
}