//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_DIE_SIDES 1
#define MAX_DIE_SIDES 6
#define MAX_DIE_COUNT 10

void roll_dice(int die_sides, int die_count, int *results) {
    int total = 0;
    srand(time(NULL));

    for (int i = 0; i < die_count; i++) {
        int roll = rand() % die_sides + 1;
        results[i] = roll;
        total += roll;
    }

    printf("Rolled: ");
    for (int i = 0; i < die_count; i++) {
        printf("%d ", results[i]);
    }
    printf("\nTotal: %d\n", total);
}

int main(void) {
    int die_sides = 0;
    int die_count = 0;
    int custom_sides[MAX_DIE_COUNT];
    int results[MAX_DIE_COUNT];

    while (die_sides <= 0 || die_count <= 0 || die_count > MAX_DIE_COUNT) {
        printf("Enter number of sides for each die (min %d, max %d): ", MIN_DIE_SIDES, MAX_DIE_SIDES);
        scanf("%d", &die_sides);

        if (die_sides < MIN_DIE_SIDES || die_sides > MAX_DIE_SIDES) {
            printf("Invalid number of sides. Please enter a valid number.\n");
            continue;
        }

        printf("Enter number of dice to roll: ");
        scanf("%d", &die_count);

        if (die_count > MAX_DIE_COUNT) {
            printf("Too many dice to roll. Max is %d.\n", MAX_DIE_COUNT);
            continue;
        }

        for (int i = 0; i < die_count; i++) {
            printf("Enter number of sides for die %d (default %d): ", i+1, MIN_DIE_SIDES);
            scanf("%d", &custom_sides[i]);

            if (custom_sides[i] < MIN_DIE_SIDES) {
                custom_sides[i] = MIN_DIE_SIDES;
            }
        }

        roll_dice(die_sides, die_count, results);

        break;
    }

    return 0;
}