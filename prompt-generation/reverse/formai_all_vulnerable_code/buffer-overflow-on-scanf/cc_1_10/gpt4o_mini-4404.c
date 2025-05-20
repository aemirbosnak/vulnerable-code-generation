//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[50];
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void displayScores(Player players[], int numPlayers) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    printf("\n");
}

int performRound(int round) {
    return (rand() % 6) + 1; // Simulate a dice roll (1 to 6)
}

void playGame(Player players[], int numPlayers, int numRounds) {
    for (int round = 1; round <= numRounds; round++) {
        printf("Round %d\n", round);
        for (int i = 0; i < numPlayers; i++) {
            printf("%s's turn:\n", players[i].name);
            int roll = performRound(round);
            players[i].score += roll;
            printf("%s rolled a %d and now has %d points.\n", players[i].name, roll, players[i].score);
        }
        displayScores(players, numPlayers);
    }
}

void declareWinner(Player players[], int numPlayers) {
    int maxScore = players[0].score;
    char winner[50];
    strncpy(winner, players[0].name, sizeof(winner));

    for (int i = 1; i < numPlayers; i++) {
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            strncpy(winner, players[i].name, sizeof(winner));
        }
    }

    printf("The winner is %s with a score of %d!\n", winner, maxScore);
}

void printInstructions() {
    printf("Welcome to the Dice Table Game!\n");
    printf("Each player will roll a dice each round.\n");
    printf("The player with the highest score after a set number of rounds wins.\n");
    printf("Instructions:\n");
    printf("1. Enter your name when prompted.\n");
    printf("2. Roll the dice by pressing enter when it's your turn.\n");
    printf("3. Enjoy the game!\n\n");
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers, numRounds;

    srand(time(NULL)); // Seed random number generator

    printInstructions();
    
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting the game.\n");
        return 1;
    }

    printf("Enter the number of rounds to play (max %d): ", MAX_ROUNDS);
    scanf("%d", &numRounds);
    if (numRounds < 1 || numRounds > MAX_ROUNDS) {
        printf("Invalid number of rounds. Exiting the game.\n");
        return 1;
    }

    initializePlayers(players, numPlayers);
    playGame(players, numPlayers, numRounds);
    declareWinner(players, numPlayers);

    return 0;
}