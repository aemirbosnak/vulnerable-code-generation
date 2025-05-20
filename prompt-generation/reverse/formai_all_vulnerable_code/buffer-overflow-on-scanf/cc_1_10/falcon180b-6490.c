//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

struct dice {
    int num_sides;
    int *sides;
};

int main() {
    int num_dice, i, j, roll_count = 0;
    struct dice dice[MAX_DICE];

    // Initialize random seed
    srand(time(NULL));

    // Get number of dice and number of sides for each dice
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    for (i = 0; i < num_dice; i++) {
        printf("Enter the number of sides for dice %d: ", i+1);
        scanf("%d", &dice[i].num_sides);
        dice[i].sides = (int*)malloc(dice[i].num_sides * sizeof(int));

        // Get the values for each side of the dice
        for (j = 1; j <= dice[i].num_sides; j++) {
            printf("Enter the value for side %d of dice %d: ", j, i+1);
            scanf("%d", &dice[i].sides[j-1]);
        }
    }

    // Roll the dice
    int total_rolls = 0;
    while (total_rolls < 100) {
        for (i = 0; i < num_dice; i++) {
            int result = rand() % dice[i].num_sides;
            printf("Dice %d rolled %d\n", i+1, dice[i].sides[result]);
            roll_count++;
            total_rolls++;
        }
    }

    // Display statistics
    printf("\nTotal rolls: %d\n", total_rolls);
    printf("Roll count for each dice:\n");
    for (i = 0; i < num_dice; i++) {
        printf("Dice %d: %d\n", i+1, roll_count/num_dice);
    }

    return 0;
}