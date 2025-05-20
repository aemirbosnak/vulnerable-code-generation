//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die
int rollDie(int sides) {
    return (rand() % sides) + 1; // Returns a random number between 1 and 'sides'
}

// Function to display the results of the rolls
void displayResults(int rolls[], int numRolls, int sides) {
    printf("Results of %d rolls of a %d-sided die:\n", numRolls, sides);
    for (int i = 0; i < numRolls; i++) {
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }
    printf("\n");
}

// Function to calculate and display average of rolls
void displayAverage(int rolls[], int numRolls) {
    int sum = 0;
    for (int i = 0; i < numRolls; i++) {
        sum += rolls[i];
    }
    double average = (double)sum / numRolls;
    printf("Average of the rolls: %.2f\n\n", average);
}

// Function to display the histogram of rolls
void displayHistogram(int rolls[], int numRolls, int sides) {
    int frequency[sides + 1]; // Array to count frequency of each side
    for (int i = 0; i <= sides; i++) {
        frequency[i] = 0; // Initialize frequencies to zero
    }

    for (int i = 0; i < numRolls; i++) {
        frequency[rolls[i]]++; // Increment the relevant frequency
    }

    printf("Histogram of Rolls:\n");
    for (int i = 1; i <= sides; i++) {
        printf("%d: ", i);
        for (int j = 0; j < frequency[i]; j++) {
            printf("*"); // Print asterisks for each occurrence
        }
        printf(" (%d)\n", frequency[i]); // Show frequency count
    }
    printf("\n");
}

int main() {
    int sides, numRolls;

    // Seed the random number generator
    srand(time(NULL));

    // User input for number of sides on the die and number of rolls
    printf("Welcome to the C Dice Roller Program!\n");

    printf("Enter the number of sides on the die: ");
    scanf("%d", &sides);
    if (sides < 1) {
        printf("The number of sides must be at least 1.\n");
        return 1;
    }

    printf("Enter the number of times to roll the die: ");
    scanf("%d", &numRolls);
    if (numRolls < 1) {
        printf("The number of rolls must be at least 1.\n");
        return 1;
    }

    int *rolls = malloc(numRolls * sizeof(int)); // Dynamic array for rolls
    if (rolls == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Roll the die numRolls times
    for (int i = 0; i < numRolls; i++) {
        rolls[i] = rollDie(sides);
    }

    // Display results, average, and histogram of rolls
    displayResults(rolls, numRolls, sides);
    displayAverage(rolls, numRolls);
    displayHistogram(rolls, numRolls, sides);

    // Free allocated memory
    free(rolls);
    
    printf("Thank you for using the C Dice Roller Program!\n");

    return 0;
}