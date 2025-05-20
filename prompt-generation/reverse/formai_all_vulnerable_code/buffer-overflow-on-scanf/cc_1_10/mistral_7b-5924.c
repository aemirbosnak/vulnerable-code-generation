//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_DICE 1
#define MAX_DICE 6
#define MIN_FACE 1
#define MAX_FACE 6

typedef struct {
    int num_dice;
    int sides;
} dice_t;

void roll_dice(dice_t *dice) {
    int *results = malloc(dice->num_dice * sizeof(int));
    int total = 0;

    for (int i = 0; i < dice->num_dice; i++) {
        results[i] = rand() % (dice->sides + 1);
        total += results[i];
        printf("Dice %d rolled: %d\n", i + 1, results[i]);
    }

    printf("Total: %d\n", total);
    free(results);
}

int main() {
    srand(time(NULL));

    dice_t dice;
    int choice;

    do {
        printf("\nWelcome to the Dice Roller!\n");
        printf("1. Roll a single dice\n");
        printf("2. Roll multiple dice\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                dice.num_dice = 1;
                dice.sides = MAX_FACE;
                roll_dice(&dice);
                break;
            case 2:
                {
                    int num_dice, sides;
                    printf("Enter the number of dice: ");
                    scanf("%d", &num_dice);
                    printf("Enter the number of sides: ");
                    scanf("%d", &sides);

                    if (num_dice < MIN_DICE || sides < MIN_FACE || num_dice > MAX_DICE || sides > MAX_FACE) {
                        printf("Invalid input. Please try again.\n");
                        continue;
                    }

                    dice.num_dice = num_dice;
                    dice.sides = sides;
                    roll_dice(&dice);
                }
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}