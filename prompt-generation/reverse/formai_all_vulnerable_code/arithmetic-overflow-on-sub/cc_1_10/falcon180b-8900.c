//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MIN_SIDES 1

// Function to generate a random number between min and max
int rand_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to roll a dice with n sides
int roll_dice(int n)
{
    return rand_int(1, n);
}

// Function to roll multiple dice with n sides
void roll_dice_multiple(int n, int count, int *result)
{
    int i;
    for (i = 0; i < count; i++)
    {
        result[i] = roll_dice(n);
    }
}

int main()
{
    int num_dice, sides, count, i;
    int *result;

    // Get number of dice and number of sides from user
    printf("Enter number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter number of sides for each dice: ");
    scanf("%d", &sides);

    // Allocate memory for result array
    result = (int *)malloc(num_dice * sizeof(int));

    // Roll dice and store results in array
    roll_dice_multiple(sides, num_dice, result);

    // Print results
    printf("Results:\n");
    for (i = 0; i < num_dice; i++)
    {
        printf("%d\n", result[i]);
    }

    // Free memory
    free(result);

    return 0;
}