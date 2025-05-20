//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

int main() {
    int num_dice, sides;
    int *dice_values;
    char play_again;

    do {
        printf("Enter number of dice: ");
        scanf("%d", &num_dice);
        if (num_dice <= 0 || num_dice > MAX_DICE) {
            printf("Invalid number of dice.\n");
        }
    } while (num_dice <= 0 || num_dice > MAX_DICE);

    do {
        printf("Enter number of sides per die: ");
        scanf("%d", &sides);
        if (sides <= 1 || sides > MAX_SIDES) {
            printf("Invalid number of sides.\n");
        }
    } while (sides <= 1 || sides > MAX_SIDES);

    dice_values = (int *) malloc(num_dice * sizeof(int));
    if (dice_values == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < num_dice; i++) {
        dice_values[i] = rand() % sides + 1;
    }

    printf("Rolling %d dice with %d sides:\n", num_dice, sides);
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", dice_values[i]);
    }
    printf("\n");

    do {
        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again!= 'y' && play_again!= 'n');

    if (play_again == 'y') {
        main();
    } else {
        free(dice_values);
        exit(0);
    }

    return 0;
}