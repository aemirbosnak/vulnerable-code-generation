//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[50];
    int score;
    bool isSuspicious;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = '\0'; // Remove newline character
        players[i].score = 0;
        players[i].isSuspicious = false;
    }
}

void printPlayers(const Player players[], int numPlayers) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d (Suspicious: %s)\n", players[i].name, players[i].score, players[i].isSuspicious ? "Yes" : "No");
    }
}

int rollDice() {
    return (rand() % 6) + 1; // Returns a random number between 1 and 6
}

bool isPlayerSuspicious() {
    return (rand() % 100) < 25; // 25% chance of being suspicious
}

void playRound(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("\nIt's %s's turn!\n", players[i].name);
        int roll = rollDice();
        players[i].score += roll;
        printf("%s rolled a %d!\n", players[i].name, roll);
        
        if (isPlayerSuspicious()) {
            players[i].isSuspicious = true;
            printf("Warning! %s is acting suspicious!\n", players[i].name);
        }
        
        printPlayers(players, numPlayers);
        
        // Randomly choose another player to accuse
        if (i != numPlayers - 1) {
            int accuseIndex = rand() % numPlayers;
            printf("%s accuses %s of cheating!\n", players[i].name, players[accuseIndex].name);
            if (players[accuseIndex].isSuspicious) {
                printf("%s was caught cheating!\n", players[accuseIndex].name);
                players[accuseIndex].score -= 5; // Deduct 5 points for cheating
            } else {
                printf("%s was innocent!\n", players[accuseIndex].name);
                players[i].score -= 2; // Deduct 2 points for wrongful accusation
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Paranoid Table Game!\n");
    printf("How many players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    getchar(); // Consume newline after the number input

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        fprintf(stderr, "Invalid number of players!\n");
        return 1;
    }

    initializePlayers(players, numPlayers);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n--- Round %d ---\n", round);
        playRound(players, numPlayers);
    }

    printf("\nFinal Scores:\n");
    printPlayers(players, numPlayers);

    // Determine the winner based on the highest score
    int winnerIndex = 0;
    for (int i = 1; i < numPlayers; i++) {
        if (players[i].score > players[winnerIndex].score) {
            winnerIndex = i;
        }
    }

    printf("Congratulations! %s wins with a score of %d!\n", players[winnerIndex].name, players[winnerIndex].score);

    return 0;
}