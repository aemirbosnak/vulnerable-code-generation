//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 1000

// Function to simulate rolling a die
int rollDie() {
    return (rand() % 6) + 1; // Returns a value between 1 and 6
}

// Function to display the statistics of the rolls
void displayStatistics(int rolls[], int totalRolls) {
    printf("Roll Statistics:\n");
    printf("-------------------------\n");

    for (int i = 1; i <= 6; i++) {
        printf("Number of times %d was rolled: %d (%.2f%%)\n", 
                i, rolls[i], (rolls[i] / (float)totalRolls) * 100);
    }

    printf("-------------------------\n");
    printf("Total Rolls: %d\n", totalRolls);
}

int main() {
    int totalRolls;
    int rolls[7] = {0}; // Array to store counts of rolls, index 0 unused

    // Seed the random number generator with time
    srand(time(NULL));

    // Get user input for number of rolls
    printf("Enter the number of dice rolls (1 to %d): ", MAX_ROLLS);
    scanf("%d", &totalRolls);

    // Check that the number of rolls is within the allowed range
    if (totalRolls < 1 || totalRolls > MAX_ROLLS) {
        printf("Please enter a valid number of rolls (1 to %d).\n", MAX_ROLLS);
        return 1;
    }

    // Simulate rolling the die for the specified number of rolls
    for (int i = 0; i < totalRolls; i++) {
        int result = rollDie();
        rolls[result]++; // Increment the count for rolled number
    }

    // Display the results and statistics
    displayStatistics(rolls, totalRolls);

    return 0;
}