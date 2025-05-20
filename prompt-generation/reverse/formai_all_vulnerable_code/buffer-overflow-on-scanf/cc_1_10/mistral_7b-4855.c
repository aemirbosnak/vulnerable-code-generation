//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_DICE 1
#define MAX_DICE 10
#define MIN_SIDES 2
#define MAX_SIDES 100

void roll_dice(int num_dice, int num_sides) {
    int dice[num_dice];
    int i, total = 0;

    srand(time(NULL)); // Seed the random number generator

    for (i = 0; i < num_dice; i++) {
        dice[i] = rand() % num_sides + 1;
        total += dice[i];
    }

    printf("Rolled %d dice with %d sides each:\n", num_dice, num_sides);
    for (i = 0; i < num_dice; i++) {
        printf("Die %d rolled a %d.\n", i + 1, dice[i]);
    }
    printf("Total: %d\n", total);
}

int main() {
    int num_dice, num_sides;
    char choice;

    do {
        printf("Enter the number of dice to roll (1-10): ");
        scanf("%d", &num_dice);

        if (num_dice < MIN_DICE || num_dice > MAX_DICE) {
            printf("Invalid number of dice. Try again.\n");
            continue;
        }

        printf("Enter the number of sides on each die (2-100): ");
        scanf("%d", &num_sides);

        if (num_sides < MIN_SIDES || num_sides > MAX_SIDES) {
            printf("Invalid number of sides. Try again.\n");
            continue;
        }

        roll_dice(num_dice, num_sides);

        printf("Do you want to roll again? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice != 'N');

    return 0;
}