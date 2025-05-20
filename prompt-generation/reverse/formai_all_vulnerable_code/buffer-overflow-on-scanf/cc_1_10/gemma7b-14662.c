//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_number = 0;
    int result = 0;
    int sides_number = 6;
    char symbol = 'A';

    printf("Welcome to the Dice Roller Game!\n");

    // Get the number of rolls from the user
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &roll_number);

    // Loop for the number of rolls
    for (int i = 0; i < roll_number; i++)
    {
        // Generate a random number between 1 and the number of sides
        result = rand() % sides_number + 1;

        // Print the result
        printf("%c rolled a %d!\n", symbol, result);

        // Update the symbol
        if (symbol == 'A')
        {
            symbol = 'B';
        }
        else if (symbol == 'B')
        {
            symbol = 'C';
        }
        else if (symbol == 'C')
        {
            symbol = 'D';
        }
        else if (symbol == 'D')
        {
            symbol = 'E';
        }
        else if (symbol == 'E')
        {
            symbol = 'F';
        }
    }

    // Thank the user
    printf("Thank you for playing the Dice Roller Game!\n");

    return 0;
}