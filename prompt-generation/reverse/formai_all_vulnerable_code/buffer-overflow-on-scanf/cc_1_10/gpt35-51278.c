//FormAI DATASET v1.0 Category: Dice Roller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A decentralized style C program to simulate rolling of a dice

// Function declaration
int rollDice();

int main() {

    // Seed for random number generation
    srand(time(0));

    // Frequency of each roll
    int freq[6] = {0};

    // Number of rolls
    int numOfRolls = 0;

    char choice;
    do {
        int result = rollDice();

        // Update frequency of each roll
        freq[result-1]++;

        numOfRolls++;

        printf("\nYou rolled a %d", result);
        printf("\nDo you want to roll again? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    // Output result
    printf("\n\nFrequency of each roll: \n");
    for(int i=0; i<6; i++) {
        printf("Side %d: %d times\n", i+1, freq[i]);
    }

    printf("\nTotal number of rolls: %d\n", numOfRolls);

    return 0;
}

// Function definition
int rollDice() {
    return (rand() % 6) + 1;
}