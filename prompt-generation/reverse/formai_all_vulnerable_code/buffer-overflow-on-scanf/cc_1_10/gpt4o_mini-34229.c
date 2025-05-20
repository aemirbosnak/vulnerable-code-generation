//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die of specified sides
int rollDie(int sides) {
    return (rand() % sides) + 1;
}

// Function to display the results of the dice rolls
void displayResults(int rolls[], int numRolls, int sides) {
    printf("Rolling %d D%d:\n", numRolls, sides);
    for (int i = 0; i < numRolls; i++) {
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int sides;
    int numRolls;

    printf("Welcome to the Dice Roller!\n");
    printf("Choose the type of die to roll:\n");
    printf("1. D4\n");
    printf("2. D6\n");
    printf("3. D8\n");
    printf("4. D10\n");
    printf("5. D12\n");
    printf("6. D20\n");
    
    // Get user input for die type
    printf("Enter your choice (1-6): ");
    scanf("%d", &sides);
    
    switch(sides) {
        case 1: sides = 4; break;
        case 2: sides = 6; break;
        case 3: sides = 8; break;
        case 4: sides = 10; break;
        case 5: sides = 12; break;
        case 6: sides = 20; break;
        default:
            printf("Invalid choice, exiting program.\n");
            return 1;
    }
    
    // Get user input for number of rolls
    printf("How many dice do you want to roll? ");
    scanf("%d", &numRolls);
    
    if (numRolls <= 0) {
        printf("Number of rolls must be positive. Exiting program.\n");
        return 1;
    }

    int rolls[numRolls]; // Array to hold the results of rolls

    // Roll the specified number of dice
    for (int i = 0; i < numRolls; i++) {
        rolls[i] = rollDie(sides);
    }

    // Display the results
    displayResults(rolls, numRolls, sides);
    
    // Ask user if they want to roll again
    char choice;
    printf("Would you like to roll again? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        // Repeating rolling process
        printf("Choose the type of die to roll:\n");
        printf("1. D4\n");
        printf("2. D6\n");
        printf("3. D8\n");
        printf("4. D10\n");
        printf("5. D12\n");
        printf("6. D20\n");
        
        printf("Enter your choice (1-6): ");
        scanf("%d", &sides);
        
        switch(sides) {
            case 1: sides = 4; break;
            case 2: sides = 6; break;
            case 3: sides = 8; break;
            case 4: sides = 10; break;
            case 5: sides = 12; break;
            case 6: sides = 20; break;
            default:
                printf("Invalid choice, exiting program.\n");
                return 1;
        }
        
        printf("How many dice do you want to roll? ");
        scanf("%d", &numRolls);
        
        if (numRolls <= 0) {
            printf("Number of rolls must be positive. Exiting program.\n");
            return 1;
        }
        
        for (int i = 0; i < numRolls; i++) {
            rolls[i] = rollDie(sides);
        }
        
        displayResults(rolls, numRolls, sides);
        
        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using the Dice Roller! Goodbye!\n");

    return 0;
}