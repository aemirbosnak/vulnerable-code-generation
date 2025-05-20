//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MIN_VALUE 1
#define MAX_VALUE 6

typedef struct {
    int num_dice;
    int num_sides;
    int *values;
} DiceRoller;

void init_dice_roller(DiceRoller *roller, int num_dice, int num_sides) {
    roller->num_dice = num_dice;
    roller->num_sides = num_sides;
    roller->values = malloc(num_dice * sizeof(int));
    for (int i = 0; i < num_dice; i++) {
        roller->values[i] = rand() % num_sides + 1;
    }
}

void roll_dice(DiceRoller *roller) {
    for (int i = 0; i < roller->num_dice; i++) {
        printf("%d ", roller->values[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    DiceRoller roller;
    int num_dice, num_sides;

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides: ");
    scanf("%d", &num_sides);

    init_dice_roller(&roller, num_dice, num_sides);

    int sum = 0;
    while (1) {
        roll_dice(&roller);
        sum = 0;
        for (int i = 0; i < roller.num_dice; i++) {
            sum += roller.values[i];
        }
        printf("Total: %d\n", sum);

        char choice;
        printf("Roll again? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}