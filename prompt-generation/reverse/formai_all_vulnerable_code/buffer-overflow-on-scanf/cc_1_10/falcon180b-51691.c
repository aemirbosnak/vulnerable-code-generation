//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: complex
// C Dice Roller Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int rollDice() {
    return rand() % 6 + 1;
}

// Function to print the result of a dice roll
void printResult(int result) {
    if (result == 1) {
        printf("You rolled a 1!\n");
    } else if (result == 2) {
        printf("You rolled a 2!\n");
    } else if (result == 3) {
        printf("You rolled a 3!\n");
    } else if (result == 4) {
        printf("You rolled a 4!\n");
    } else if (result == 5) {
        printf("You rolled a 5!\n");
    } else {
        printf("You rolled a 6!\n");
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int numRolls = 0;
    int totalResult = 0;

    // Loop until the user decides to quit
    while (1) {
        printf("How many times do you want to roll the dice? ");
        scanf("%d", &numRolls);

        // Check for invalid input
        if (numRolls <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }

        // Roll the dice numRolls times and print the results
        for (int i = 0; i < numRolls; i++) {
            int result = rollDice();
            printResult(result);
            totalResult += result;
        }

        // Ask the user if they want to roll again
        printf("Do you want to roll again? (y/n) ");
        char choice;
        scanf(" %c", &choice);

        // Check for invalid input
        if (choice!= 'y' && choice!= 'n') {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
            continue;
        }

        // Quit the program if the user chooses 'n'
        if (choice == 'n') {
            break;
        }
    }

    // Print the total result of all the dice rolls
    printf("The total result of all the dice rolls is: %d\n", totalResult);

    return 0;
}