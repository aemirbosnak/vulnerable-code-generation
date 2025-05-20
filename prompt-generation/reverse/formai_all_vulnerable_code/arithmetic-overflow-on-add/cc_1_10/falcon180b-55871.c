//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRolls;
    int numDice;
    int sides;
    int i, j, k;
    int roll;
    int total = 0;
    int freq[6] = {0};
    char choice;

    printf("Welcome to the Dice Roller!\n");
    printf("Please choose the number of dice you want to roll (1-6): ");
    scanf("%d", &numDice);

    printf("Please choose the number of sides on each die (4-20): ");
    scanf("%d", &sides);

    printf("Please choose the number of rolls you want to make (1-1000): ");
    scanf("%d", &numRolls);

    srand(time(NULL));

    for (i = 0; i < numRolls; i++) {
        for (j = 0; j < numDice; j++) {
            roll = rand() % sides + 1;
            total += roll;
            freq[roll-1]++;
        }
    }

    printf("Total: %d\n", total);

    printf("Frequency:\n");
    for (k = 1; k <= sides; k++) {
        printf("%d: %d\n", k, freq[k-1]);
    }

    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Thank you for using the Dice Roller!\n");
        return 0;
    }
}