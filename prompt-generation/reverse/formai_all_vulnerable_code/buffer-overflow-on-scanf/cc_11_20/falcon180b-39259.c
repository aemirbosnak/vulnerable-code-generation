//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, sides, roll, total = 0;
    char playAgain;

    srand(time(NULL)); // Seed the random number generator with the current time

    do {
        printf("Enter the number of dice you want to roll: ");
        scanf("%d", &numDice);

        if (numDice <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numDice <= 0);

    do {
        printf("Enter the number of sides on each die: ");
        scanf("%d", &sides);

        if (sides <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (sides <= 0);

    for (int i = 0; i < numDice; i++) {
        roll = rand() % sides + 1; // Generate a random number between 1 and the number of sides on the die
        total += roll; // Add the roll to the total
        printf("Roll %d: %d\n", i + 1, roll); // Print the result of the roll
    }

    printf("Total: %d\n", total); // Print the total of all the rolls

    do {
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &playAgain);

        if (playAgain!= 'y' && playAgain!= 'n') {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    } while (playAgain!= 'y' && playAgain!= 'n');

    if (playAgain == 'y') {
        main(); // Call the main function recursively to start a new game
    } else {
        printf("Thanks for playing!\n");
    }

    return 0;
}