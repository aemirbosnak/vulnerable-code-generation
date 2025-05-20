//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, d, sum = 0, roll_again = 1;
    char again_yn;

    printf("Welcome to the Dice Roller!\n");

    // Loop until the user enters a valid number of rolls
    while (1)
    {
        printf("How many rolls do you want? (Enter an integer): ");
        scanf("%d", &n);

        if (n < 1)
        {
            printf("Invalid number of rolls. Please try again.\n");
        }
        else
        {
            break;
        }
    }

    // Loop to roll the dice
    for (int i = 0; i < n; i++)
    {
        // Generate a random number between 1 and 6
        d = rand() % 6 + 1;

        // Add the roll to the sum
        sum += d;

        // Print the roll
        printf("Roll: %d\n", d);
    }

    // Print the total sum
    printf("Total Sum: %d\n", sum);

    // Ask the user if they want to roll again
    printf("Do you want to roll again? (Y/N): ");
    scanf("%c", &again_yn);

    // If the user wants to roll again, start the loop again
    if (again_yn == 'Y' || again_yn == 'y')
    {
        roll_again = 1;
    }

    // Thank the user for playing
    printf("Thank you for playing the Dice Roller!\n");

    return 0;
}