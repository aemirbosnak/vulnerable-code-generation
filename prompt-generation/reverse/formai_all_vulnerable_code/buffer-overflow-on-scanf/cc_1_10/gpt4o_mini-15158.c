//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define ROUNDS 5
#define WINNING_SCORE 20

void clearScreen() {
    // Clear the screen
    printf("\033[H\033[J");
}

int rollDice() {
    return (rand() % 6) + 1; // Roll a die and return value between 1 and 6
}

void printScores(int scores[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %d\n", i + 1, scores[i]);
    }
}

int main() {
    int num_players, current_round = 1;
    int scores[MAX_PLAYERS] = {0};

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to Dice Roll Poker!\n");
    printf("Enter the number of players (2 to 4): ");
    scanf("%d", &num_players);

    // Input validation for number of players
    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Number of players must be between 2 and 4.\n");
        return 1;
    }

    while (current_round <= ROUNDS) {
        clearScreen();
        printf("Round %d\n", current_round);
        printScores(scores, num_players);
        
        for (int i = 0; i < num_players; i++) {
            printf("Player %d's turn...\n", i + 1);
            printf("Press Enter to roll the dice...");
            getchar();
            getchar(); // Wait for enter key
            
            int roll1 = rollDice();
            int roll2 = rollDice();
            printf("You rolled: %d and %d\n", roll1, roll2);
            
            int total = roll1 + roll2;
            scores[i] += total;
            printf("You scored %d points! Total Score: %d\n\n", total, scores[i]);

            if (scores[i] >= WINNING_SCORE) {
                printf("Player %d wins with %d points!\n", i + 1, scores[i]);
                return 0; // End game on win
            }
        }
        current_round++;
    }

    clearScreen();
    printf("Final Scores:\n");
    printScores(scores, num_players);
    
    int winner = 0, highest_score = 0;
    for (int i = 0; i < num_players; i++) {
        if (scores[i] > highest_score) {
            highest_score = scores[i];
            winner = i + 1;
        }
    }
    printf("Player %d wins the game with %d points!\n", winner, highest_score);

    return 0;
}