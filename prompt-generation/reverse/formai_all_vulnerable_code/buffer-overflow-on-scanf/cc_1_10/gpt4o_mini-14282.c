//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single dice and return the result
int rollDice() {
    return (rand() % 6) + 1; // Returns a value between 1 and 6
}

// Function to display welcome message
void displayWelcome() {
    printf("🎲🎉 Welcome to the Cheerful Dice Roller! 🎉🎲\n");
    printf("Let's have some fun rolling some dice!\n\n");
}

// Function to get the number of dice to roll from the user
int getNumberOfDice() {
    int numDice;
    printf("How many dice would you like to roll? (1-10): ");
    scanf("%d", &numDice);
    
    while(numDice < 1 || numDice > 10) {
        printf("Please enter a valid number of dice (1-10): ");
        scanf("%d", &numDice);
    }
    
    return numDice;
}

// Function to roll and display the results of multiple dice rolls
void rollAndDisplayResults(int numDice) {
    int total = 0;
    printf("\n🎲 Rolling %d dice... 🎲\n", numDice);
    
    for (int i = 0; i < numDice; i++) {
        int roll = rollDice();
        printf("Dice %d rolled a %d!\n", i + 1, roll);
        total += roll;
    }
    
    printf("\n🥳 Total of all dice: %d 🥳\n", total);
}

// Function to ask the user if they want to roll again
int askToRollAgain() {
    char choice;
    printf("Would you like to roll again? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        return 1;
    } else {
        printf("Thank you for playing! 🎉 Until next time! 🎉\n");
        return 0;
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator for different results
    int keepRolling = 1;

    displayWelcome();

    while (keepRolling) {
        int numDice = getNumberOfDice();
        rollAndDisplayResults(numDice);
        keepRolling = askToRollAgain();
    }

    return 0;
}