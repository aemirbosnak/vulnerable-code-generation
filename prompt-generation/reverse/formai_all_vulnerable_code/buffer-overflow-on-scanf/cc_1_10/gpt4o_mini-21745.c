//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TURNS 10

typedef struct {
    char name[50];
    int score;
} Player;

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void displayScores(Player players[], int count) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    printf("\n");
}

int rollDice() {
    return (rand() % 6) + 1;
}

void playTurn(Player *player) {
    printf("%s's Turn:\n", player->name);
    int diceRoll = rollDice();
    printf("Rolled a %d!\n", diceRoll);
    if (diceRoll == 1) {
        printf("Oh no! You lost 5 points!\n");
        player->score -= 5;
    } else {
        printf("You gained %d points!\n", diceRoll);
        player->score += diceRoll;
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Initialize random seed
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Welcome to the Dice Rolling Game!\n");

    // Get number of players
    do {
        printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
        scanf("%d", &playerCount);
    } while (playerCount < 1 || playerCount > MAX_PLAYERS);

    // Initialize player names and scores
    initializePlayers(players, playerCount);
    
    printf("\nLet's start the game!\n");

    // Game loop for a specified number of turns
    for (int turn = 0; turn < MAX_TURNS; turn++) {
        printf("Turn %d:\n", turn + 1);
        for (int i = 0; i < playerCount; i++) {
            playTurn(&players[i]);
        }
        displayScores(players, playerCount);
    }

    // Determine winner
    int winnerIndex = 0;
    for (int i = 1; i < playerCount; i++) {
        if (players[i].score > players[winnerIndex].score) {
            winnerIndex = i;
        }
    }

    printf("The winner is %s with %d points!\n", players[winnerIndex].name, players[winnerIndex].score);
    
    return 0;
}