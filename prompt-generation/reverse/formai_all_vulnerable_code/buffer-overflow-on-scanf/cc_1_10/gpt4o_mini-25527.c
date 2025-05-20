//GPT-4o-mini DATASET v1.0 Category: Game ; Style: rigorous
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
        printf("Enter the name of player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0;  // Remove newline character
        players[i].score = 0;
    }
}

void printScores(Player players[], int numPlayers) {
    printf("\nScores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int rollDice() {
    return (rand() % 6) + 1;
}

void playRound(Player players[], int numPlayers) {
    printf("\nNew Round!\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s's turn:\n", players[i].name);
        int roll = rollDice();
        printf("Rolled a %d!\n", roll);
        players[i].score += roll;
    }
}

void announceWinner(Player players[], int numPlayers) {
    int highestScore = -1;
    int winnerIndex = -1;
    
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].score > highestScore) {
            highestScore = players[i].score;
            winnerIndex = i;
        }
    }
    
    printf("\nThe winner is %s with a score of %d!\n", players[winnerIndex].name, players[winnerIndex].score);
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;

    srand(time(NULL));

    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    getchar();  // Clear the newline character left by scanf

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    initializePlayers(players, numPlayers);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n--- Round %d of %d ---\n", round, MAX_ROUNDS);
        playRound(players, numPlayers);
        printScores(players, numPlayers);
    }

    announceWinner(players, numPlayers);

    return 0;
}