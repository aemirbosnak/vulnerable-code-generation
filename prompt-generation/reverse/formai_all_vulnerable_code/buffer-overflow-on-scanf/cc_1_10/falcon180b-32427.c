//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

int main(int argc, char **argv)
{
    int num_dice, num_sides;
    int *dice_results;
    char repeat;

    srand(time(NULL));

    // Prompt user for number of dice and sides
    printf("Enter number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter number of sides per die: ");
    scanf("%d", &num_sides);

    // Allocate memory for dice results
    dice_results = malloc(num_dice * sizeof(int));

    // Roll the dice
    for (int i = 0; i < num_dice; i++)
    {
        dice_results[i] = rand() % num_sides + 1;
    }

    // Display the results
    printf("Dice results:\n");
    for (int i = 0; i < num_dice; i++)
    {
        printf("%d\n", dice_results[i]);
    }

    // Ask user if they want to roll again
    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &repeat);

    while (repeat == 'y' || repeat == 'Y')
    {
        for (int i = 0; i < num_dice; i++)
        {
            dice_results[i] = rand() % num_sides + 1;
        }

        printf("\nDice results:\n");
        for (int i = 0; i < num_dice; i++)
        {
            printf("%d\n", dice_results[i]);
        }

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &repeat);
    }

    free(dice_results);

    return 0;
}