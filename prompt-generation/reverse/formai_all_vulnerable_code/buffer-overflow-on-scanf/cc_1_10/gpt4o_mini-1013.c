//GPT-4o-mini DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[20];
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void printScores(Player players[], int numPlayers) {
    printf("\nScores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void playRound(Player players[], int numPlayers) {
    int roundWinner = -1;
    int maxScore = -1;

    printf("\nPlaying round...\n");
    for (int i = 0; i < numPlayers; i++) {
        int score = rand() % 10; // Random score between 0-9
        players[i].score += score;
        printf("%s scores %d!\n", players[i].name, score);
        
        // Determine round winner
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            roundWinner = i;
        }
    }

    if (roundWinner != -1) {
        printf("%s wins this round!\n", players[roundWinner].name);
    }
}

void declareWinner(Player players[], int numPlayers) {
    int overallWinner = -1;
    int maxScore = -1;
    
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            overallWinner = i;
        }
    }

    if (overallWinner != -1) {
        printf("Overall winner is %s with a score of %d!\n", players[overallWinner].name, players[overallWinner].score);
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Score Game!\n");
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return EXIT_FAILURE;
    }

    initializePlayers(players, numPlayers);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n--- Round %d ---\n", round);
        playRound(players, numPlayers);
        printScores(players, numPlayers);
    }

    declareWinner(players, numPlayers);

    printf("Thank you for playing!\n");
    return EXIT_SUCCESS;
}