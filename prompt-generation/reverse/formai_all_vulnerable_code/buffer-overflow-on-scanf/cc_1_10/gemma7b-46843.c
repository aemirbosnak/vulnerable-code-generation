//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void roll_dice()
{
    int roll_result = rand() % 6 + 1;
    switch (roll_result)
    {
        case 1:
            printf("You rolled a 1!\n");
            break;
        case 2:
            printf("You rolled a 2!\n");
            break;
        case 3:
            printf("You rolled a 3!\n");
            break;
        case 4:
            printf("You rolled a 4!\n");
            break;
        case 5:
            printf("You rolled a 5!\n");
            break;
        case 6:
            printf("You rolled a 6!\n");
            break;
    }
}

int main()
{
    int num_rolls = 0;

    // Loop until the user enters a valid number of rolls
    while (1)
    {
        printf("Enter the number of rolls you want: ");
        int num_rolls_temp = 0;
        scanf("%d", &num_rolls_temp);

        if (num_rolls_temp < 1)
        {
            printf("Invalid input. Please try again.\n");
        }
        else
        {
            num_rolls = num_rolls_temp;
            break;
        }
    }

    // Roll the dice the specified number of times
    for (int i = 0; i < num_rolls; i++)
    {
        roll_dice();
    }

    // Print the number of rolls and the total number of points
    printf("You rolled a total of %d points.\n", num_rolls);

    return 0;
}