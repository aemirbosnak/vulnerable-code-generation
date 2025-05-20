//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

int main() {
    int num_dice, num_sides, i, j, k, total_sides, roll, *dice;
    char repeat;

    srand(time(NULL));

    do {
        printf("Enter the number of dice: ");
        scanf("%d", &num_dice);
    } while (num_dice <= 0 || num_dice > MAX_DICE);

    do {
        printf("Enter the number of sides for each dice: ");
        scanf("%d", &num_sides);
    } while (num_sides <= 1 || num_sides > MAX_SIDES);

    dice = (int *)malloc(num_dice * sizeof(int));

    for (i = 0; i < num_dice; i++) {
        dice[i] = rand() % num_sides + 1;
    }

    total_sides = num_dice * num_sides;

    printf("Rolling %d dice with %d sides each...\n", num_dice, num_sides);

    for (i = 0; i < num_dice; i++) {
        printf("Dice %d: ", i + 1);
        for (j = 0; j < num_sides; j++) {
            roll = dice[i] % num_sides + 1;
            printf("%d ", roll);
        }
        printf("\n");
    }

    printf("Total number of sides rolled: %d\n", total_sides);

    free(dice);

    do {
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &repeat);
    } while (repeat!= 'y' && repeat!= 'n');

    if (repeat == 'y') {
        main();
    }

    return 0;
}