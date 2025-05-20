//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MAX_SIDES 20
#define NUM_ROLLS 3

void printWelcomeMessage() {
    printf("************************************\n");
    printf("* Welcome to the Squirrel Dice Duel *\n");
    printf("************************************\n");
    printf("In this magical contest, mighty squirrels will battle by rolling enchanted dice!\n");
    printf("Prepare to roll and witness the grandest of outcomes!\n");
    printf("************************************\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1; // Roll the dice and range from 1 to sides
}

void rollPlayerDice(int player_id, int sides) {
    printf("Squirrel %d rolls the enchanted %d-sided dice:\n", player_id + 1, sides);
    int totalScore = 0;

    for (int i = 0; i < NUM_ROLLS; i++) {
        int roll = rollDice(sides);
        printf("  Roll %d: %d\n", i + 1, roll);
        totalScore += roll;
    }
    printf("Total score for Squirrel %d: %d\n\n", player_id + 1, totalScore);
}

void declareWinner(int scores[], int playerCount) {
    int maxScore = -1, winnerIndex = -1;
    for (int i = 0; i < playerCount; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            winnerIndex = i;
        }
    }
    printf("And the winner is Squirrel %d with a total score of %d!\n", winnerIndex + 1, maxScore);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    printWelcomeMessage();

    int playerCount = 0;
    printf("Enter the number of squirrels (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the game!\n");
        return 1;
    }

    int diceSides = 0;
    printf("Choose the number of sides on your enchanted dice (1 - %d): ", MAX_SIDES);
    scanf("%d", &diceSides);
    
    if (diceSides < 1 || diceSides > MAX_SIDES) {
        printf("Invalid number of sides. Please restart the game!\n");
        return 1;
    }

    int scores[MAX_PLAYERS] = {0};

    for (int i = 0; i < playerCount; i++) {
        rollPlayerDice(i, diceSides);
        scores[i] = rollDice(diceSides * NUM_ROLLS); // Store the total score
    }

    declareWinner(scores, playerCount);
    
    printf("Thank you for playing! May your dice always roll in your favor!\n");
    return 0;
}