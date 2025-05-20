//FormAI DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sides, rolls, i, j, total;
    char quit;

    srand(time(NULL)); // Set random seed using time

    printf("Welcome to the Dice Roller!\n");

    do {
        printf("\nEnter the number of sides on the die: ");
        scanf("%d", &sides);

        if (sides <= 0) {
            printf("Invalid number of sides.\n");
            continue; // Restart the loop
        }

        printf("Enter the number of times to roll the die: ");
        scanf("%d", &rolls);

        if (rolls <= 0) {
            printf("Invalid number of rolls.\n");
            continue;
        }

        total = 0;

        printf("\nRolling a %d-sided die %d times...\n", sides, rolls);

        for (i = 1; i <= rolls; i++) {
            int roll = rand() % sides + 1; // Generate a random number between 1 and sides
            printf("Roll %d: %d\n", i, roll);
            total += roll;
        }

        printf("\nTotal: %d\n", total);

        printf("\nRoll again? (Y/N): ");
        scanf(" %c", &quit);

    } while (quit == 'y' || quit == 'Y');

    printf("Goodbye!\n");

    return 0;
}