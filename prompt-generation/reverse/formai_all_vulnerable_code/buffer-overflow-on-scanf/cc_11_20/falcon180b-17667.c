//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 100

int main()
{
    int num_dice, num_sides, total_sides;
    int *dice_values;
    int i, j, k;
    char repeat;

    do
    {
        printf("Enter the number of dice: ");
        scanf("%d", &num_dice);
        if (num_dice <= 0 || num_dice > MAX_DICE)
        {
            printf("Invalid number of dice.\n");
        }
    } while (num_dice <= 0 || num_dice > MAX_DICE);

    do
    {
        printf("Enter the number of sides per die: ");
        scanf("%d", &num_sides);
        if (num_sides <= 0 || num_sides > MAX_SIDES)
        {
            printf("Invalid number of sides.\n");
        }
    } while (num_sides <= 0 || num_sides > MAX_SIDES);

    dice_values = (int *)malloc(num_dice * sizeof(int));
    if (dice_values == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    srand(time(NULL));

    for (i = 0; i < num_dice; i++)
    {
        dice_values[i] = rand() % num_sides + 1;
        printf("Die %d rolled a %d.\n", i + 1, dice_values[i]);
    }

    total_sides = num_dice * num_sides;
    printf("\nTotal number of sides: %d\n", total_sides);

    while (1)
    {
        printf("\nRoll again? (y/n): ");
        scanf(" %c", &repeat);
        if (repeat == 'y' || repeat == 'Y')
        {
            for (i = 0; i < num_dice; i++)
            {
                dice_values[i] = rand() % num_sides + 1;
                printf("Die %d rolled a %d.\n", i + 1, dice_values[i]);
            }
            total_sides = num_dice * num_sides;
            printf("\nTotal number of sides: %d\n", total_sides);
        }
        else
        {
            break;
        }
    }

    free(dice_values);
    return 0;
}