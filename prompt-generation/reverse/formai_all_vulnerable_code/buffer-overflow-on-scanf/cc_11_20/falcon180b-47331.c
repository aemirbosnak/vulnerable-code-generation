//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int main() {
    int num_dice, sides, total = 0;
    char choice;
    srand(time(NULL));

    do {
        printf("Enter number of dice to roll: ");
        scanf("%d", &num_dice);
        if (num_dice < 1) {
            printf("Invalid number of dice.\n");
        }
    } while (num_dice < 1);

    do {
        printf("Enter number of sides on each die: ");
        scanf("%d", &sides);
        if (sides < 1) {
            printf("Invalid number of sides.\n");
        }
    } while (sides < 1);

    printf("Rolling %d %d-sided dice...\n", num_dice, sides);
    for (int i = 0; i < num_dice; i++) {
        int roll = rand() % sides + 1;
        total += roll;
        printf("Dice %d rolled a %d.\n", i+1, roll);
    }

    printf("Total: %d\n", total);

    do {
        printf("Play again? (y/n): ");
        scanf(" %c", &choice);
        if (choice!= 'y' && choice!= 'n') {
            printf("Invalid choice.\n");
        }
    } while (choice!= 'y' && choice!= 'n');

    if (choice == 'y') {
        main();
    }

    return 0;
}