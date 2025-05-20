//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_DICE 10
#define MAX_NUM_SIDES 20
#define MAX_ROLLS 10

void clearBuffer() {
    while (getchar() != '\n');  // Clear the input buffer
}

int validateInput(int input, int max) {
    if (input < 1 || input > max) {
        printf("Invalid input! Must be between 1 and %d.\n", max);
        return 0; 
    }
    return 1; 
}

void rollDice(int numDice, int numSides) {
    if (numDice < 1 || numDice > MAX_NUM_DICE || numSides < 2 || numSides > MAX_NUM_SIDES) {
        printf("Parameter error: Can't roll %d dice with %d sides!\n", numDice, numSides);
        return; 
    }
    
    int rolls[MAX_ROLLS];
    for (int i = 0; i < MAX_ROLLS; i++) {
        rolls[i] = 0; 
    }

    printf("Rolling %d dice with %d sides...\n", numDice, numSides);
    
    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % numSides) + 1; 
        rolls[i] = roll; 
        printf("Dice %d rolled: %d\n", (i + 1), roll); 
    }
    
    int total = 0;
    for (int i = 0; i < numDice; i++) {
        total += rolls[i];
    }
    
    printf("Total roll is: %d\n", total); 
}

void paranoidRoll() {
    int numDice, numSides;

    printf("Welcome to the paranoid dice roller. Remember, trust no one!\n");
    printf("How many dice do you want to roll? (1 to %d)\n", MAX_NUM_DICE);
    
    while (1) {
        printf("> ");
        scanf("%d", &numDice);
        clearBuffer(); // Safety first, clear the buffer!
        
        if (validateInput(numDice, MAX_NUM_DICE)) {
            break; 
        }
    }

    printf("How many sides should each die have? (2 to %d)\n", MAX_NUM_SIDES);
    
    while (1) {
        printf("> ");
        scanf("%d", &numSides);
        clearBuffer(); // Always paranoid, always clear the buffer!

        if (validateInput(numSides, MAX_NUM_SIDES)) {
            break; 
        }
    }

    rollDice(numDice, numSides);
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    
    char choice;
    
    do {
        paranoidRoll();
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
        clearBuffer();
        if (choice != 'y' && choice != 'n') {
            printf("Suspicious input! Please enter 'y' or 'n'.\n");
            choice = 'y'; // Default to 'yes' to avoid unending prompts.
        }
    } while (choice == 'y');
    
    printf("Goodbye, and remember: stay vigilant!\n");
    return 0;
}