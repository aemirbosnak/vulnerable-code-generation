//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5

void initializeGame(int *numPlayers);
void rollDice(int numPlayers, int diceResults[]);
void displayResults(int numPlayers, int diceResults[], int round);
int determineWinner(int numPlayers, int diceResults[]);
void playAgain();

int main() {
    int numPlayers;
    int diceResults[MAX_PLAYERS];
    
    srand(time(NULL)); // Seed for random number generation

    do {
        initializeGame(&numPlayers);
        
        for (int round = 1; round <= MAX_ROUNDS; round++) {
            printf("\nRound %d\n", round);
            rollDice(numPlayers, diceResults);
            displayResults(numPlayers, diceResults, round);
            int winner = determineWinner(numPlayers, diceResults);
            printf("The winner of Round %d is Player %d!\n", round, winner + 1);
        }

        playAgain();
    } while (1);

    return 0;
}

void initializeGame(int *numPlayers) {
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", numPlayers);
    while (*numPlayers < 1 || *numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players! Please enter a number between 1 and %d: ", MAX_PLAYERS);
        scanf("%d", numPlayers);
    }
}

void rollDice(int numPlayers, int diceResults[]) {
    for (int i = 0; i < numPlayers; i++) {
        diceResults[i] = rand() % 6 + 1; // Roll a dice (1 to 6)
        printf("Player %d rolled: %d\n", i + 1, diceResults[i]);
    }
}

void displayResults(int numPlayers, int diceResults[], int round) {
    printf("\nResults after Round %d:\n", round);
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %d\n", i + 1, diceResults[i]);
    }
}

int determineWinner(int numPlayers, int diceResults[]) {
    int maxRoll = diceResults[0];
    int winner = 0;

    for (int i = 1; i < numPlayers; i++) {
        if (diceResults[i] > maxRoll) {
            maxRoll = diceResults[i];
            winner = i;
        }
    }

    return winner;
}

void playAgain() {
    char choice;
    printf("Do you want to play again? (y/n): ");
    getchar(); // consume newline character left in input buffer
    scanf("%c", &choice);
    
    if (choice != 'y' && choice != 'Y') {
        printf("Thank you for playing!\n");
        exit(0);
    }
}