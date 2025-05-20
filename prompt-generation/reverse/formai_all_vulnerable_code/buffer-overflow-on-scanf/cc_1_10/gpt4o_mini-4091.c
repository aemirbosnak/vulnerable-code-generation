//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void printWelcomeMessage() {
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*         Welcome to the Dice Roller       *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
}

void getUserInput(int* numDice, int* numSides) {
    printf("Enter the number of dice to roll (1-%d): ", MAX_DICE);
    scanf("%d", numDice);
    if (*numDice < 1 || *numDice > MAX_DICE) {
        printf("Invalid input! Setting number of dice to 1.\n");
        *numDice = 1;
    }
    
    printf("Enter the number of sides on each die (4, 6, 8, 10, 12, 20): ");
    scanf("%d", numSides);
    if (*numSides != 4 && *numSides != 6 && *numSides != 8 && 
        *numSides != 10 && *numSides != 12 && *numSides != 20) {
        printf("Invalid input! Defaulting to 6 sides.\n");
        *numSides = 6;
    }
}

void rollDice(int numDice, int numSides) {
    int results[MAX_DICE];
    int total = 0;
    
    printf("Rolling %d dice with %d sides...\n", numDice, numSides);
    for (int i = 0; i < numDice; i++) {
        results[i] = (rand() % numSides) + 1; // Roll the dice
        total += results[i];
        printf("Die %d: %d\n", i + 1, results[i]);
    }
    
    printf("Total rolled: %d\n", total);
}

void saveResultsToFile(int numDice, int numSides, int* results) {
    FILE* file = fopen("dice_roll_results.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    fprintf(file, "Dice Roll Results:\n");
    fprintf(file, "Number of Dice: %d, Number of Sides: %d\n", numDice, numSides);
    fprintf(file, "Results: ");
    for (int i = 0; i < numDice; i++) {
        fprintf(file, "%d ", results[i]);
    }
    fprintf(file, "\n");
    fclose(file);

    printf("Results saved to 'dice_roll_results.txt'\n");
}

int main() {
    int numDice = 0, numSides = 0;
    int results[MAX_DICE];

    // Initialize random seed
    srand(time(NULL));

    printWelcomeMessage();
    getUserInput(&numDice, &numSides);
    
    rollDice(numDice, numSides);
    
    // Call function to save results to file
    saveResultsToFile(numDice, numSides, results);
    
    printf("Thank you for using the Dice Roller!\n");
    return 0;
}