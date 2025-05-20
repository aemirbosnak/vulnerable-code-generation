//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TURNS 5

typedef struct {
    char name[50];
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void displayScores(Player players[], int numPlayers) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int rollDice() {
    return (rand() % 6) + 1;
}

void playTurn(Player* player) {
    int diceRoll = rollDice();
    printf("%s rolled a %d!\n", player->name, diceRoll);
    player->score += diceRoll;
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Dice Rolling Game!\n");
    printf("How many players (up to %d)? ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting game.\n");
        return 1;
    }

    initializePlayers(players, numPlayers);

    for (int turn = 1; turn <= MAX_TURNS; turn++) {
        printf("\n--- Turn %d ---\n", turn);
        for (int i = 0; i < numPlayers; i++) {
            playTurn(&players[i]);
        }
        displayScores(players, numPlayers);
    }

    // Find the winner
    Player* winner = &players[0];
    for (int i = 1; i < numPlayers; i++) {
        if (players[i].score > winner->score) {
            winner = &players[i];
        }
    }

    printf("\nCongratulations %s, you are the winner with %d points!\n", winner->name, winner->score);
    return 0;
}