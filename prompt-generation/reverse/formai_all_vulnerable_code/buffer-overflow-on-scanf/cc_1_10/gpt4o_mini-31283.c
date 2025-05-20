//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayInstructions() {
    printf("==================================\n");
    printf("   Welcome to the Dice Rolling\n");
    printf("       Challenge of the Realm!\n");
    printf("==================================\n");
    printf("Choose your destiny!\n");
    printf("1. Roll a six-sided die\n");
    printf("2. Roll a twelve-sided die\n");
    printf("3. Roll a twenty-sided die\n");
    printf("4. Exit the game\n");
    printf("==================================\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;  // Roll between 1 and the number of sides
}

void rollSixSided() {
    printf("You have chosen to roll a six-sided die...\n");
    printf("The result of your roll is: %d\n", rollDice(6));
}

void rollTwelveSided() {
    printf("You have chosen to roll a twelve-sided die...\n");
    printf("The result of your roll is: %d\n", rollDice(12));
}

void rollTwentySided() {
    printf("You have chosen to roll a twenty-sided die...\n");
    printf("The result of your roll is: %d\n", rollDice(20));
}

int main() {
    int choice;
    srand(time(NULL));  // Seed the random number generator

    do {
        displayInstructions();
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                rollSixSided();
                break;
            case 2:
                rollTwelveSided();
                break;
            case 3:
                rollTwentySided();
                break;
            case 4:
                printf("Farewell, brave adventurer! Until our paths cross again!\n");
                break;
            default:
                printf("Alas! That choice is not recognized. Please try again.\n");
        }
        
        printf("\n");
        
    } while (choice != 4);

    return 0;
}