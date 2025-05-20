//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void printInstructions();
int rollDice(int sides);
void displayRollResults(int rolls[], int numDice, int sides);
void saveResultsToFile(int rolls[], int numDice, int sides, const char *filename);

int main() {
    int numDice, sides, choice;
    
    // Seed the random number generator
    srand(time(NULL));

    printInstructions();

    // Get number of dice and sides from the user
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides);

    // Allocate memory to store roll results
    int *rolls = (int *)malloc(numDice * sizeof(int));
    if (rolls == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    do {
        // Roll the dice
        for (int i = 0; i < numDice; i++) {
            rolls[i] = rollDice(sides);
        }

        // Display the results
        displayRollResults(rolls, numDice, sides);

        // Ask the user if they want to save the results
        printf("Do you want to save the results to a file? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        if (choice == 1) {
            char filename[50];
            printf("Enter the filename to save results: ");
            scanf("%s", filename);
            saveResultsToFile(rolls, numDice, sides, filename);
            printf("Results saved to %s\n", filename);
        }

        // Ask the user if they want to roll again
        printf("Do you want to roll again? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    // Free allocated memory
    free(rolls);
    printf("Thank you for using the dice roller!\n");
    return 0;
}

// Function to print instructions
void printInstructions() {
    printf("Welcome to the Dice Roller Program!\n");
    printf("You can roll dice of any number of sides and any number of dice.\n");
    printf("You will have the option to save the results to a file.\n");
}

// Function to roll a die and return the result
int rollDice(int sides) {
    return (rand() % sides) + 1;  // Random number between 1 and 'sides'
}

// Function to display the roll results
void displayRollResults(int rolls[], int numDice, int sides) {
    printf("You rolled %d dice with %d sides each:\n", numDice, sides);
    for (int i = 0; i < numDice; i++) {
        printf("Die %d: %d\n", i + 1, rolls[i]);
    }
}

// Function to save the results to a file
void saveResultsToFile(int rolls[], int numDice, int sides, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    fprintf(file, "Dice Roll Results:\n");
    fprintf(file, "Rolled %d dice with %d sides each:\n", numDice, sides);
    for (int i = 0; i < numDice; i++) {
        fprintf(file, "Die %d: %d\n", i + 1, rolls[i]);
    }
    fclose(file);
}