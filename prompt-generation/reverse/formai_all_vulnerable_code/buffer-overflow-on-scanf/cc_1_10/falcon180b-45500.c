//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 100
#define MAX_VALUE 6

int roll_dice(int num_dice, int max_value) {
    int i, sum = 0;
    for (i = 0; i < num_dice; i++) {
        sum += rand() % max_value + 1;
    }
    return sum;
}

int main() {
    int num_dice, max_value, sum;
    char choice;

    printf("Welcome to the C Dice Roller!\n");
    printf("How many dice do you want to roll (1-100)? ");
    scanf("%d", &num_dice);

    while (num_dice < 1 || num_dice > NUM_DICE) {
        printf("Invalid number of dice. Please enter a number between 1 and %d: ", NUM_DICE);
        scanf("%d", &num_dice);
    }

    printf("What is the maximum value on each die (1-6)? ");
    scanf("%d", &max_value);

    while (max_value < 1 || max_value > MAX_VALUE) {
        printf("Invalid maximum value. Please enter a number between 1 and %d: ", MAX_VALUE);
        scanf("%d", &max_value);
    }

    sum = roll_dice(num_dice, max_value);

    printf("\nYou rolled %d dice with a maximum value of %d:\n", num_dice, max_value);
    printf("The sum of the rolls is: %d\n", sum);

    printf("Do you want to roll again? (y/n) ");
    scanf(" %c", &choice);

    while (choice!= 'y' && choice!= 'n') {
        printf("Invalid choice. Please enter 'y' or 'n': ");
        scanf(" %c", &choice);
    }

    if (choice == 'y') {
        main();
    } else {
        printf("Thank you for using the C Dice Roller!\n");
        return 0;
    }
}