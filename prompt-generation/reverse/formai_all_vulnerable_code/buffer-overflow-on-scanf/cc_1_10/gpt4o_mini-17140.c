//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[30];
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for(int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline
        players[i].score = 0;
    }
}

void displayScores(Player players[], int numPlayers) {
    printf("\nCurrent Scores:\n");
    for(int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int playRound(Player players[], int numPlayers, int round) {
    int roundScores[MAX_PLAYERS] = {0};
    printf("\n--- Round %d ---\n", round + 1);
    for(int i = 0; i < numPlayers; i++) {
        int throw1 = rand() % 6 + 1; // Simulates a dice roll
        int throw2 = rand() % 6 + 1; // Simulates a dice roll

        roundScores[i] = throw1 + throw2;
        printf("%s rolled: %d + %d = %d\n", players[i].name, throw1, throw2, roundScores[i]);

        if (roundScores[i] > 7) { // Example bonus rule
            printf("Bonus for %s! +5 points!\n", players[i].name);
            roundScores[i] += 5;
        }
        players[i].score += roundScores[i];
    }

    return 0;
}

void declareWinner(Player players[], int numPlayers) {
    Player *winner = &players[0];
    for(int i = 1; i < numPlayers; i++) {
        if(players[i].score > winner->score) {
            winner = &players[i];
        }
    }
    printf("\n** Winner is %s with a score of %d! **\n", winner->name, winner->score);
}

int main() {
    srand(time(NULL));
    
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Dice Duel Game!\n");
    do {
        printf("Enter number of players (2-%d): ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
        getchar(); // Consume the newline character
    } while(numPlayers < 2 || numPlayers > MAX_PLAYERS);

    initializePlayers(players, numPlayers);

    for(int round = 0; round < MAX_ROUNDS; round++) {
        playRound(players, numPlayers, round);
        displayScores(players, numPlayers);
    }

    declareWinner(players, numPlayers);

    printf("Thank you for playing!\n");
    return 0;
}