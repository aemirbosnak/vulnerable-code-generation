//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, numRolls, diceSides, i;
    char playAgain = 'Y';

    srand(time(NULL)); // Initialize random seed

    printf("Welcome to Retro Dice Roller!\n");

    while(playAgain == 'Y') {
        // Get user's choice of dice
        printf("Choose a dice to roll:\n");
        printf("1. D4\n");
        printf("2. D6\n");
        printf("3. D8\n");
        printf("4. D10\n");
        printf("5. D12\n");
        printf("6. D20\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                diceSides = 4;
                break;
            case 2:
                diceSides = 6;
                break;
            case 3:
                diceSides = 8;
                break;
            case 4:
                diceSides = 10;
                break;
            case 5:
                diceSides = 12;
                break;
            case 6:
                diceSides = 20;
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
                continue;
        }

        // Get user's number of rolls
        printf("How many rolls do you want to make? ");
        scanf("%d", &numRolls);

        // Roll the dice!
        printf("\n[Rolling %d %d-sided dice]\n", numRolls, diceSides);
        for(i = 0; i < numRolls; i++) {
            printf("Roll %d: %d\n", i+1, rand() % diceSides + 1);
        }

        // Ask if user wants to play again
        printf("\nPlay again? (Y/N) ");
        scanf(" %c", &playAgain);
        playAgain = toupper(playAgain);
    }

    printf("\nThanks for playing Retro Dice Roller!\n");

    return 0;
}