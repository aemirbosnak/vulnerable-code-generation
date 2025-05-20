//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayWelcomeMessage() {
    printf("=====================================\n");
    printf("         Welcome to Dice Roller      \n");
    printf("=====================================\n");
    printf("Roll virtual dice and enjoy the game!\n");
    printf("You can roll one or more dice, anytime!\n");
    printf("=====================================\n\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1; // Generates a random number between 1 and 'sides'
}

void rollMultipleDice(int numDice, int sides) {
    int total = 0;
    printf("Rolling %d dice with %d sides...\n", numDice, sides);
    for (int i = 0; i < numDice; i++) {
        int roll = rollDice(sides);
        printf("Die %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
}

void playDiceGame() {
    int choice = 0;
    int numDice, sides;

    while (choice != 3) {
        printf("\nChoose an option:\n");
        printf("1. Roll the dice\n");
        printf("2. Change dice sides\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of dice to roll: ");
                scanf("%d", &numDice);
                printf("Enter the number of sides per die: ");
                scanf("%d", &sides);
                rollMultipleDice(numDice, sides);
                break;
            case 2:
                printf("Enter the number of sides per die: ");
                scanf("%d", &sides);
                printf("Dice sides set to: %d\n", sides);
                break;
            case 3:
                printf("Thank you for playing!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for randomness
    displayWelcomeMessage();
    playDiceGame();
    return 0;
}