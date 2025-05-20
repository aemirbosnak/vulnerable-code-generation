//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_number = 0, result = 0, side_effect = 0;
    char symbol = '\0';

    printf("Welcome to the C Dice Roller!\n");

    // Loop until the user enters a valid number of rolls
    while (roll_number < 1)
    {
        printf("Enter the number of rolls you want: ");
        scanf("%d", &roll_number);

        if (roll_number < 1)
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    // Roll the dice
    for (int i = 0; i < roll_number; i++)
    {
        result = rand() % 6 + 1;
        symbol = 'A' + result - 1;

        // Apply side effects
        switch (result)
        {
            case 1:
                side_effect = 2;
                break;
            case 2:
                side_effect = 4;
                break;
            case 3:
                side_effect = 6;
                break;
            case 4:
                side_effect = 8;
                break;
            case 5:
                side_effect = 10;
                break;
            case 6:
                side_effect = 12;
                break;
        }

        // Print the result
        printf("Roll %d: %c - Side effect: %d\n", i + 1, symbol, side_effect);
    }

    // Thank the user
    printf("Thank you for playing the C Dice Roller!\n");

    return 0;
}