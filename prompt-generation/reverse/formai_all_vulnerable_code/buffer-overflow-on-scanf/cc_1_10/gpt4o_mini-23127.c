//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIDES 6 // Number of sides on the dice
#define MAX_ROLLS 100 // Maximum number of rolls

// Structure to hold statistics for rolling
typedef struct {
    int rolls;
    int counts[NUM_SIDES + 1]; // to count rolls for each face (1 to 6)
} DiceStatistics;

// Function to initialize dice statistics
void initStatistics(DiceStatistics *stats) {
    stats->rolls = 0;
    for(int i = 0; i <= NUM_SIDES; i++) {
        stats->counts[i] = 0;
    }
}

// Function to roll a dice and update statistics
int rollDice(DiceStatistics *stats) {
    int roll = (rand() % NUM_SIDES) + 1; // Rolling dice logic
    stats->rolls++;
    stats->counts[roll]++;
    return roll;
}

// Function to display statistics
void displayStatistics(DiceStatistics *stats) {
    printf("\n== Dice Roll Statistics ==\n");
    printf("Total Rolls: %d\n", stats->rolls);
    for(int i = 1; i <= NUM_SIDES; i++) {
        printf("Face %d: %d times (%.2f%%)\n", i, stats->counts[i], 
               (100.0 * stats->counts[i] / stats->rolls));
    }
    printf("============================\n");
}

// Main function to run the dice roller
int main() {
    srand(time(NULL)); // Seed the random number generator
    DiceStatistics stats;
    initStatistics(&stats);

    int choice;
    printf("Welcome to the Dice Roller!\n");
    
    do {
        printf("\nPress 1 to roll the dice, or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int rollResult = rollDice(&stats);
            printf("You rolled a %d!\n", rollResult);
        } else if (choice != 0) {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0 && stats.rolls < MAX_ROLLS);

    if (stats.rolls > 0) {
        displayStatistics(&stats);
    } else {
        printf("No rolls were made.\n");
    }

    printf("Thank you for using the Dice Roller!\n");
    return 0;
}