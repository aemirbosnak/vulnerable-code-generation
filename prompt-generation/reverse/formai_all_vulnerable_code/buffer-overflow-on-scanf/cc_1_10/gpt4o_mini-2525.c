//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define MAX_NAME_LEN 40

typedef struct {
    char name[MAX_NAME_LEN];
    int score;
} Player;

void initGame(Player* players, int numPlayers);
void playGame(Player* players, int numPlayers);
void displayScores(Player* players, int numPlayers);
void sortScores(Player* players, int numPlayers);

int main() {
    srand(time(NULL));
    int numPlayers = 0;
    
    printf("Enter the number of players (1 - %d): ", MAX);
    scanf("%d", &numPlayers);
    
    while (numPlayers < 1 || numPlayers > MAX) {
        printf("Invalid number of players! Please enter a number between 1 and %d: ", MAX);
        scanf("%d", &numPlayers);
    }

    Player* players = (Player*)malloc(numPlayers * sizeof(Player));
    if (!players) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    initGame(players, numPlayers);
    playGame(players, numPlayers);
    sortScores(players, numPlayers);
    displayScores(players, numPlayers);
    
    free(players);
    return 0;
}

void initGame(Player* players, int numPlayers) {
    printf("Welcome to the Cryptic Score Game!\n");
    
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0; // Initialize score to zero
    }
}

void playGame(Player* players, int numPlayers) {
    int rounds = 5;
    
    for (int round = 1; round <= rounds; round++) {
        printf("\n--- Round %d ---\n", round);
        
        for (int i = 0; i < numPlayers; i++) {
            int randomScore = rand() % 100; // Random score between 0 and 99
            players[i].score += randomScore; // Update score
            printf("%s scored: %d\n", players[i].name, randomScore);
        }
    }
}

void displayScores(Player* players, int numPlayers) {
    printf("\nFinal Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void sortScores(Player* players, int numPlayers) {
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = 0; j < numPlayers - i - 1; j++) {
            if (players[j].score < players[j + 1].score) { // Descending order
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
}