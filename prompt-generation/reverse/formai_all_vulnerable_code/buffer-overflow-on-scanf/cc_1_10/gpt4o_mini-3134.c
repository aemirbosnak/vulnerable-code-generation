//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5
#define MAX_FACE 6

typedef struct {
    char name[50];
    int score;
} Player;

void initializePlayers(Player players[], int playerCount);
void displayScores(Player players[], int playerCount);
int rollDice();
void playRound(Player players[], int playerCount);
int findWinner(Player players[], int playerCount);

int main() {
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Enter number of players (2 to %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    if (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Invalid player count. Exiting...\n");
        return 1;
    }

    initializePlayers(players, playerCount);
    
    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n--- Round %d ---\n", round);
        playRound(players, playerCount);
        displayScores(players, playerCount);
    }

    int winnerIndex = findWinner(players, playerCount);
    printf("\nThe winner is: %s with a score of %d!\n", players[winnerIndex].name, players[winnerIndex].score);
    
    return 0;
}

void initializePlayers(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void displayScores(Player players[], int playerCount) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int rollDice() {
    return (rand() % MAX_FACE) + 1; // returns a number between 1 and 6
}

void playRound(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("%s's turn. Press Enter to roll the dice...", players[i].name);
        getchar(); // to consume the newline left by scanf
        getchar(); // wait for user to press enter

        int roll = rollDice();
        printf("%s rolled a %d!\n", players[i].name, roll);
        players[i].score += roll;
    }
}

int findWinner(Player players[], int playerCount) {
    int winnerIndex = 0;
    for (int i = 1; i < playerCount; i++) {
        if (players[i].score > players[winnerIndex].score) {
            winnerIndex = i;
        }
    }
    return winnerIndex;
}