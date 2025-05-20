//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    int numDice, numRolls, i, j, total = 0;
    char playAgain;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of dice and the number of rolls from the user
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);

    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    // Roll the dice and display the results
    for (i = 1; i <= numRolls; i++) {
        printf("Roll %d: ", i);
        for (j = 1; j <= numDice; j++) {
            printf("%d ", rollDice());
        }
        printf("\n");
    }

    // Calculate the total of all the rolls
    for (i = 1; i <= numRolls; i++) {
        total += rollDice();
    }

    // Display the total
    printf("Total: %d\n", total);

    // Ask the user if they want to play again
    printf("Play again? (y/n): ");
    scanf(" %c", &playAgain);

    // Loop until the user decides to quit
    while (playAgain == 'y' || playAgain == 'Y') {
        main();
    }

    return 0;
}