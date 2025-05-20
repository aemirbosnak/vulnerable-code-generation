//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_DICE 1
#define MAX_DICE 6
#define MIN_ROLLS 1
#define MAX_ROLLS 100

void roll_dice(int num_dice, int sides, int rolls[], int roll_count) {
    for (int i = 0; i < roll_count; i++) {
        rolls[i] = rand() % sides + 1;
        printf("Roll %d: ", i + 1);
        for (int j = 0; j < num_dice; j++) {
            printf("%d ", rolls[i] + (j * sides));
        }
        printf("\n");
    }
}

int main() {
    int num_dice, sides, rolls, roll_count;

    printf("Welcome to the Dice Roller 5000!\n");
    printf("Get ready for some roll-tastic excitement!\n\n");

    srand(time(NULL)); // Seed the random number generator

    do {
        printf("Enter the number of dice (1-%d): ", MAX_DICE);
        scanf("%d", &num_dice);
    } while (num_dice < MIN_DICE || num_dice > MAX_DICE);

    do {
        printf("Enter the number of sides on each die (1-%d): ", MAX_DICE);
        scanf("%d", &sides);
    } while (sides < MIN_DICE || sides > MAX_DICE);

    do {
        printf("Enter the number of rolls (1-%d): ", MAX_ROLLS);
        scanf("%d", &rolls);
    } while (rolls < MIN_ROLLS || rolls > MAX_ROLLS);

    int rolls_array[rolls];

    printf("\nRolling the dice...\n");
    roll_dice(num_dice, sides, rolls_array, rolls);

    printf("\nYour rolls:\n");
    for (int i = 0; i < rolls; i++) {
        printf("%d ", rolls_array[i]);
    }
    printf("\n\nPress any key to exit...\n");

    getchar();
    getchar();
    return 0;
}