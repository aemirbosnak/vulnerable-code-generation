//Falcon-180B DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

// Structure to hold player information
typedef struct {
    char name[20];
    int score;
} Player;

// Function to initialize a player's score to 0
void initPlayer(Player* player) {
    player->score = 0;
}

// Function to print a player's name and score
void printPlayer(Player* player) {
    printf("%s: %d\n", player->name, player->score);
}

// Function to roll a dice
int rollDice() {
    return rand() % 6 + 1;
}

// Function to play a round of the game
void playRound(Player* players, int numPlayers, int numDice) {
    int i;
    for (i = 0; i < numPlayers; i++) {
        printf("Round %d for %s\n", i+1, players[i].name);
        int total = 0;
        int numRolls = 0;
        while (numRolls < numDice) {
            int roll = rollDice();
            total += roll;
            printf("%d\n", roll);
            numRolls++;
        }
        players[i].score += total;
        printf("Total score for this round: %d\n\n", total);
    }
}

// Function to play multiple rounds of the game
void playGame(Player* players, int numPlayers, int numRounds, int numDice) {
    int i;
    for (i = 0; i < numRounds; i++) {
        playRound(players, numPlayers, numDice);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers = 0;

    // Initialize players
    while (numPlayers < MAX_PLAYERS) {
        printf("Enter name for player %d: ", numPlayers+1);
        scanf("%s", players[numPlayers].name);
        initPlayer(&players[numPlayers]);
        numPlayers++;
    }

    // Play game
    int numRounds = 0;
    while (numRounds < MAX_ROUNDS) {
        playGame(players, numPlayers, numRounds, 3);
        numRounds++;
    }

    // Print final scores
    printf("\nFinal scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printPlayer(&players[i]);
    }

    return 0;
}