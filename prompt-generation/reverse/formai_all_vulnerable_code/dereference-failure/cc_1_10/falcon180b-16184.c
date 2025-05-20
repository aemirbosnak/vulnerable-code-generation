//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 100

typedef struct {
    int num_dice;
    int num_sides;
    int *dice_values;
} RollResult;

void init_dice(int *dice_values, int num_dice, int num_sides) {
    for (int i = 0; i < num_dice; i++) {
        dice_values[i] = rand() % num_sides + 1;
    }
}

void roll_dice(int *dice_values, int num_dice, int num_sides) {
    for (int i = 0; i < num_dice; i++) {
        dice_values[i] = rand() % num_sides + 1;
    }
}

int main() {
    srand(time(NULL));

    int num_dice, num_sides;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);

    int *dice_values = malloc(num_dice * sizeof(int));
    init_dice(dice_values, num_dice, num_sides);

    printf("Initial roll:\n");
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", dice_values[i]);
    }
    printf("\n");

    RollResult result;
    result.num_dice = num_dice;
    result.num_sides = num_sides;
    result.dice_values = dice_values;

    while (1) {
        printf("Enter 'r' to roll the dice or 'q' to quit:\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'r') {
            roll_dice(result.dice_values, result.num_dice, result.num_sides);
            printf("Roll result:\n");
            for (int i = 0; i < result.num_dice; i++) {
                printf("%d ", result.dice_values[i]);
            }
            printf("\n");
        } else if (choice == 'q') {
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    free(result.dice_values);
    return 0;
}