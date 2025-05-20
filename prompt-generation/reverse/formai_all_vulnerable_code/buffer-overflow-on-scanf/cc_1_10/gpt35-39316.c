//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cryptic style Dice Roller program

int main() {
    int numRolls, sides, i, sum = 0;
    char c;

    srand(time(NULL));

    printf("Welcome to the Dice Roller program.\n");
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    printf("Enter the number of sides: ");
    scanf("%d", &sides);

    printf("Rolling the dice...\n\n");

    for (i = 1; i <= numRolls; i++) {
        int roll = rand() % sides + 1;
        sum += roll;

        printf("Roll %d: %d\n", i, roll);
    }

    if (numRolls == 1) {
        printf("\nYour roll is %d.\n", sum);
    } else {
        printf("\nThe sum of your rolls is %d.\n", sum);
    }

    printf("\nWould you like to roll again? (Y/N) ");
    scanf(" %c", &c);

    // Cryptic loop to randomly change case of 'c'
    for (i = 1; i <= (rand() % 5 + 1); i++) {
        if (rand() % 2 == 0) {
            c += 32; // Convert to lowercase ASCII
        } else {
            c -= 32; // Convert to uppercase ASCII
        }
    }

    if (c == 'y') {
        printf("\nRestarting the program...\n");
        main();
    } else {
        printf("\nExiting the program...\n");
        exit(0);
    }

    return 0;
}