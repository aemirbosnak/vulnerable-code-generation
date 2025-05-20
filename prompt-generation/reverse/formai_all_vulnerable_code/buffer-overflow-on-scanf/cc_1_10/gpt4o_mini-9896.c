//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage() {
    printf("################################################\n");
    printf("####         Welcome to the Dice Roller      ####\n");
    printf("####  Roll the dice and let fate determine    ####\n");
    printf("####         your destiny in this game!      ####\n");
    printf("################################################\n\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1; // Generate a random number between 1 and the number of sides
}

void rollMultipleDice(int numDice, int sides) {
    int total = 0;
    printf("You rolled %d dice with %d sides:\n", numDice, sides);
    for (int i = 0; i < numDice; i++) {
        int result = rollDice(sides);
        total += result;
        printf("  Dice %d: rolled a %d\n", i + 1, result);
    }
    printf("Total of all rolls: %d\n\n", total);
}

void playGame() {
    int numDice, sides, playAgain = 1;

    while (playAgain) {
        printf("Enter the number of dice you want to roll: ");
        scanf("%d", &numDice);
        
        printf("Enter the number of sides on each die: ");
        scanf("%d", &sides);

        if (numDice <= 0 || sides <= 0) {
            printf("Invalid input! Please enter positive integer values.\n\n");
            continue;
        }

        rollMultipleDice(numDice, sides);
        
        printf("Would you like to roll again? (1 for yes, 0 for no): ");
        scanf("%d", &playAgain);
    }
    
    printf("Thank you for playing the Dice Roller! May your rolls be ever in your favor!\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    welcomeMessage();
    playGame();

    return 0;
}