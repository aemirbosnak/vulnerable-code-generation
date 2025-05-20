//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5

typedef struct {
    char name[30];
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        players[i].score = 0; // Initialize score to 0
    }
}

void displayScores(Player players[], int numPlayers) {
    printf("\n=== Scores ===\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
    printf("================\n");
}

int getRandomNumber() {
    return rand() % 100 + 1; // Random number between 1 and 100
}

void getPlayerGuess(Player *player) {
    printf("%s, enter your guess (1-100): ", player->name);
    scanf("%d", &(player->score));   // Use a temporary variable to store guess
}

int calculatePoints(int guess, int secretNumber) {
    return (guess == secretNumber) ? 10 : (100 - abs(guess - secretNumber)) / 10;
}

void playRound(Player players[], int numPlayers) {
    int secretNumber = getRandomNumber();
    printf("\nSecret Number has been chosen (1-100).\n");

    for (int i = 0; i < numPlayers; i++) {
        getPlayerGuess(&players[i]);
        players[i].score = calculatePoints(players[i].score, secretNumber);
        printf("%s guessed: %d (Secret Number was: %d)\n", players[i].name, players[i].score, secretNumber);
    }

    int maxScore = 0;
    int winnerIndex = -1;
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            winnerIndex = i;
        }
    }

    printf("Round Winner: %s with %d points!\n", players[winnerIndex].name, maxScore);
    players[winnerIndex].score += 1; // Incrementing round win count
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to Number Battles!\n");
    printf("Enter number of players (1-4): ");
    scanf("%d", &numPlayers);

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n=== Starting Round %d ===\n", round);
        playRound(players, numPlayers);
        displayScores(players, numPlayers);
    }

    printf("\nGame Over! Final Scores:\n");
    displayScores(players, numPlayers);
    
    return 0;
}