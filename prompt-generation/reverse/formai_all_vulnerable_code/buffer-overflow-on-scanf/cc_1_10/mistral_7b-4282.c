//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRATITUDE_MESSAGE "Thank you for using our Dice Roller!\n"
#define MIN_DICE 1
#define MAX_DICE 6
#define MIN_SIDES 2
#define MAX_SIDES 20
#define NUM_DICE 3

void roll_dice(int num_dice, int sides) {
    int dice_roll[num_dice];
    int i;

    srand(time(NULL));

    for (i = 0; i < num_dice; i++) {
        dice_roll[i] = rand() % sides + 1;
    }

    for (i = 0; i < num_dice; i++) {
        printf("Dice %d rolled a %d\n", i + 1, dice_roll[i]);
    }
}

int main() {
    printf("%s", GRATITUDE_MESSAGE);

    int num_dice, sides;

    printf("Please enter the number of dice to roll (min %d, max %d): ", MIN_DICE, MAX_DICE);
    scanf("%d", &num_dice);

    if (num_dice < MIN_DICE || num_dice > MAX_DICE) {
        printf("Invalid number of dice. Exiting...\n");
        return 1;
    }

    printf("Please enter the number of sides on each die (min %d, max %d): ", MIN_SIDES, MAX_SIDES);
    scanf("%d", &sides);

    if (sides < MIN_SIDES || sides > MAX_SIDES) {
        printf("Invalid number of sides. Exiting...\n");
        return 1;
    }

    roll_dice(num_dice, sides);

    return 0;
}