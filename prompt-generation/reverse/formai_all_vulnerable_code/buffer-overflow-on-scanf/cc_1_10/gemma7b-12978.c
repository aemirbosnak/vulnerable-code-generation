//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_number;
    int result;
    char symbol;

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of rolls from the user
    printf("Enter the number of rolls: ");
    scanf("%d", &roll_number);

    // Roll the dice for the specified number of times
    for (int i = 0; i < roll_number; i++)
    {
        // Get a random number between 1 and 6
        result = rand() % 6 + 1;

        // Translate the result into a symbol
        switch (result)
        {
            case 1:
                symbol = 'A';
                break;
            case 2:
                symbol = 'B';
                break;
            case 3:
                symbol = 'C';
                break;
            case 4:
                symbol = 'D';
                break;
            case 5:
                symbol = 'E';
                break;
            case 6:
                symbol = 'F';
                break;
        }

        // Print the result
        printf("Roll %d: %c\n", i + 1, symbol);
    }

    // Thank the user
    printf("Thank you for playing!");

    return 0;
}