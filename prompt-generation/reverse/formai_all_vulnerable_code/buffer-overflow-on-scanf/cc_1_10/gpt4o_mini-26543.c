//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20
#define NUM_ROLLS 10

void rollDice(int dice[], int numDice, int sides);
void displayResults(int results[], int rollCount);
void showStatistics(int results[], int rollCount);

int main() {
    srand(time(NULL));  // Seed the random number generator

    int numDice, sides, results[NUM_ROLLS] = {0}, rollCount = 0;

    printf("Welcome to the Dice Roller program!\n");
    printf("How many dice would you like to roll (1-%d): ", MAX_DICE);
    scanf("%d", &numDice);
    if(numDice < 1 || numDice > MAX_DICE) {
        printf("Invalid number of dice. Exiting...\n");
        return 1;
    }

    printf("How many sides should each die have (1-%d): ", MAX_SIDES);
    scanf("%d", &sides);
    if(sides < 1 || sides > MAX_SIDES) {
        printf("Invalid number of sides. Exiting...\n");
        return 1;
    }

    char choice;
    do {
        rollDice(results, numDice, sides);
        rollCount++;

        printf("Roll %d results: ", rollCount);
        displayResults(results, rollCount);

        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nTotal rolls: %d\n", rollCount);
    showStatistics(results, rollCount);
    printf("Thank you for using the Dice Roller!\n");

    return 0;
}

void rollDice(int results[], int numDice, int sides) {
    int rollResult = 0;
    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % sides) + 1;  // Generate a random roll
        rollResult += roll;                // Accumulate the results
        printf("Die %d rolled: %d\n", i + 1, roll);
    }
    results[numDice - 1] += rollResult;  // Store the total result of this roll
}

void displayResults(int results[], int rollCount) {
    for (int i = 0; i < NUM_ROLLS; i++) {
        if (i < rollCount) {
            printf("%d ", results[i]);
        } else {
            printf("X ");
        }
    }
    printf("\n");
}

void showStatistics(int results[], int rollCount) {
    int totalScore = 0;
    for (int i = 0; i < rollCount; i++) {
        totalScore += results[i];
    }

    double average = (double)totalScore / rollCount;
    printf("Total Score: %d\n", totalScore);
    printf("Average Score: %.2f\n", average);
}