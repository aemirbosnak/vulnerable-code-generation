//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_number = 0;
    int number_of_rolls = 0;
    int sum = 0;
    int face_value = 0;
    char symbol = 'A';

    printf("Welcome to the Dice Roller!\n");

    // Loop to get the number of rolls
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &number_of_rolls);

    // Loop to roll the dice
    for (roll_number = 0; roll_number < number_of_rolls; roll_number++)
    {
        // Generate a random number between 1 and 6
        face_value = rand() % 6 + 1;

        // Add the face value to the sum
        sum += face_value;

        // Print the face value
        printf("%c rolled a %d.\n", symbol, face_value);

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

    // Print the total sum
    printf("The total sum is: %d.\n", sum);

    return 0;
}