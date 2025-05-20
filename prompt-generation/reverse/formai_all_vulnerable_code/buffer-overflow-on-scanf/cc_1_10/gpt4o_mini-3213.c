//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum number of multipliers
#define MAX_MULTIPLIERS 5
// The range of multipliers
#define MULTIPLIER_MIN 1
#define MULTIPLIER_MAX 10

// Function to display the menu
void displayMenu() {
    printf("\n--- Table Racer Game ---\n");
    printf("1. Start Game\n");
    printf("2. Exit\n");
    printf("Select an option: ");
}

// Function to generate random multipliers
void generateMultipliers(int multipliers[]) {
    for (int i = 0; i < MAX_MULTIPLIERS; i++) {
        multipliers[i] = rand() % (MULTIPLIER_MAX - MULTIPLIER_MIN + 1) + MULTIPLIER_MIN;
    }
}

// Function to display the multipliers
void displayMultipliers(int multipliers[]) {
    printf("Available Multipliers: ");
    for (int i = 0; i < MAX_MULTIPLIERS; i++) {
        printf("%d ", multipliers[i]);
    }
    printf("\n");
}

// Function to play the game
void playGame() {
    int multipliers[MAX_MULTIPLIERS];
    int currentScore = 1; // Starting score
    int targetScore;
    int choice;

    // Generate random multipliers
    generateMultipliers(multipliers);

    // Ask the user for a target score
    printf("Enter a target score (greater than 1): ");
    scanf("%d", &targetScore);

    if (targetScore <= 1) {
        printf("Target score should be greater than 1!\n");
        return;
    }

    while (currentScore < targetScore) {
        printf("\nCurrent Score: %d\n", currentScore);
        displayMultipliers(multipliers);
        
        printf("Select a multiplier (1-%d): ", MAX_MULTIPLIERS);
        scanf("%d", &choice);
        
        // Validate the choice
        if (choice < 1 || choice > MAX_MULTIPLIERS) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        // Apply multiplier
        currentScore *= multipliers[choice - 1];
        printf("Updated Score: %d\n", currentScore);
        
        // Provide feedback
        if (currentScore >= targetScore) {
            printf("Congratulations! You've reached the target score!\n");
            break;
        }
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                playGame();
                break;
            case 2:
                printf("Exiting the game. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}