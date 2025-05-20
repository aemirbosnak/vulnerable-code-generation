//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void displayWelcomeMessage() {
    printf("************************************\n");
    printf("*          DICE ROLLER            *\n");
    printf("************************************\n");
    printf("Welcome, Brave Adventurer!\n");
    printf("Are you ready to roll some dice?\n");
    printf("************************************\n");
}

void displayGoodbyeMessage() {
    printf("Thanks for playing! May your journeys be forever bold!\n");
    printf("************************************\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int sides;
    char choice;

    displayWelcomeMessage();

    // Main loop for rolling dice
    do {
        printf("Enter the number of sides on your die (e.g., 6 for a standard die): ");
        scanf("%d", &sides);

        if (sides < 1) {
            printf("The number of sides must be at least 1. Try again!\n");
            continue;
        }

        int roll = rollDice(sides);
        printf("You rolled a %d on a %d-sided die!\n", roll, sides);

        printf("Do you wish to roll again? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');

    displayGoodbyeMessage();
    return 0;
}