//FormAI DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("Hello! Welcome to the Dice-Roller program. Are you ready to roll the dice? (y/n)\n");
    char choice;
    
    do {
        scanf(" %c", &choice);
    } while(choice != 'y' && choice != 'n');
    
    if(choice == 'n') {
        printf("Oh come on! Don't be a spoilsport. Let's roll!\n");
        choice = 'y';
    }
    
    printf("Great! How many dice do you want to roll?\n");
    int numDice;
    scanf("%d", &numDice);
    
    while(numDice <= 0) {
        printf("Invalid input! You must roll at least one dice. Please enter a valid number.\n");
        scanf("%d", &numDice);
    }
    
    printf("How many sides should each die have?\n");
    int numSides;
    scanf("%d", &numSides);
    
    while(numSides <= 1) {
        printf("Invalid input! Dice must have at least 2 sides. Please enter a valid number.\n");
        scanf("%d", &numSides);
    }
    
    // Seed the random number generator
    srand(time(NULL));
    
    printf("Rolling...\n");
    int totalRoll = 0;
    
    for(int i = 0; i < numDice; i++) {
        int diceRoll = rand() % numSides + 1;
        printf("Die %d: %d\n", i+1, diceRoll);
        totalRoll += diceRoll;
    }
    
    printf("Total roll: %d\n", totalRoll);
    
    if(totalRoll == 69) {
        printf("Nice.\n");
    } else if(totalRoll == 420) {
        printf("Blaze it.\n");
    } else if(totalRoll == 666) {
        printf("Hail Satan!\n");
    }
    
    printf("Do you want to roll again? (y/n)\n");
    do {
        scanf(" %c", &choice);
    } while(choice != 'y' && choice != 'n');
    
    if(choice == 'y') {
        printf("Let's try again!\n");
        main();     // recursive call to start over
    } else {
        printf("Thanks for playing! Have a great day!\n");
    }
    
    return 0;
    
}