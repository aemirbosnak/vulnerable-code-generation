//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define TABLE_SIZE 10

typedef struct {
    char name[50];
    int score;
    int position;
} Player;

void initPlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline
        players[i].score = 0;
        players[i].position = 0;
    }
}

void displayTable(Player players[], int numPlayers) {
    printf("\nCurrent Table:\n");
    printf("Position\tPlayer Name\tScore\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%d\t\t%s\t\t%d\n", players[i].position + 1, players[i].name, players[i].score);
    }
    printf("\n");
}

void updatePositions(Player players[], int numPlayers, int diceRolls[]) {
    for (int i = 0; i < numPlayers; i++) {
        players[i].position += diceRolls[i];
        if (players[i].position >= TABLE_SIZE) {
            players[i].position = TABLE_SIZE;
        }
    }
}

void displayWinner(Player players[], int numPlayers) {
    int highestScoreIndex = 0;
    for (int i = 1; i < numPlayers; i++) {
        if (players[i].score > players[highestScoreIndex].score) {
            highestScoreIndex = i;
        }
    }
    printf("\nCongratulations %s, You are the Winner with a Score of: %d\n", players[highestScoreIndex].name, players[highestScoreIndex].score);
}

int rollDice() {
    return (rand() % 6) + 1; // Roll a die (1-6)
}

int main() {
    srand(time(NULL));
    
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Table Game! How many players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    getchar(); // Clear newline from input

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    initPlayers(players, numPlayers);
    
    int rounds = 5;
    for (int r = 0; r < rounds; r++) {
        printf("\n--- Round %d ---\n", r + 1);
        int diceRolls[MAX_PLAYERS];
        
        for (int i = 0; i < numPlayers; i++) {
            diceRolls[i] = rollDice();
            players[i].score += diceRolls[i];
            printf("%s rolled a %d\n", players[i].name, diceRolls[i]);
        }

        updatePositions(players, numPlayers, diceRolls);
        displayTable(players, numPlayers);
    }

    displayWinner(players, numPlayers);
    
    return 0;
}