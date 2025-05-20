//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_PLAYERS 4
#define MAX_LOCATIONS 3
#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE -30
#define ROUNDS 5

void generateTemperature(int *actualTemps) {
    for (int i = 0; i < MAX_LOCATIONS; i++) {
        actualTemps[i] = (rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1)) + MIN_TEMPERATURE;
    }
}

void displayActualTemperatures(int *actualTemps) {
    printf("Actual Temperatures:\n");
    for (int i = 0; i < MAX_LOCATIONS; i++) {
        printf("Location %d: %d°C\n", i + 1, actualTemps[i]);
    }
}

void displayScores(int *scores) {
    printf("Current Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: %d points\n", i + 1, scores[i]);
    }
}

int calculateScore(int guess, int actual) {
    return (actual >= guess - 5 && actual <= guess + 5) ? 10 : 0; // Close guess earns points
}

void clearScreen() {
    printf("\033[H\033[J");
}

int main() {
    srand(time(NULL)); // Seed for random temperature generation
    int actualTemps[MAX_LOCATIONS];
    int scores[MAX_PLAYERS] = {0};
    char playerNames[MAX_PLAYERS][20];
    
    // Get player names
    printf("Enter names of %d players:\n", MAX_PLAYERS);
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: ", i + 1);
        scanf("%s", playerNames[i]);
    }

    // Game starts
    printf("Welcome to the Temperature Monitoring Game!\n");
    printf("You will have %d rounds to guess the temperatures of %d locations.\n", ROUNDS, MAX_LOCATIONS);
    
    for (int round = 0; round < ROUNDS; round++) {
        clearScreen();
        
        generateTemperature(actualTemps);
        displayActualTemperatures(actualTemps);

        for (int player = 0; player < MAX_PLAYERS; player++) {
            int guess[MAX_LOCATIONS];

            printf("%s, enter your guesses for the temperatures of %d locations:\n", playerNames[player], MAX_LOCATIONS);
            for (int loc = 0; loc < MAX_LOCATIONS; loc++) {
                printf("Location %d: ", loc + 1);
                scanf("%d", &guess[loc]);
            }

            for (int loc = 0; loc < MAX_LOCATIONS; loc++) {
                scores[player] += calculateScore(guess[loc], actualTemps[loc]);
            }

            displayScores(scores);
            sleep(2);
        }
    }

    // End game
    clearScreen();
    int winner = 0;
    for (int i = 1; i < MAX_PLAYERS; i++) {
        if (scores[i] > scores[winner]) {
            winner = i;
        }
    }

    printf("Final Scores:\n");
    displayScores(scores);
    printf("Congratulations %s! You are the winner!\n", playerNames[winner]);

    return 0;
}