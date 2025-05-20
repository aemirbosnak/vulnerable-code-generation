//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_number, number_of_rolls, side_of_die, result;
    char again;

    printf("Welcome to the Dice Roller!\n");
    printf("Please enter the number of rolls you want:");
    scanf("%d", &number_of_rolls);

    for (roll_number = 0; roll_number < number_of_rolls; roll_number++)
    {
        printf("Rolling the die...\n");
        side_of_die = rand() % 6 + 1;
        result = side_of_die;

        switch (result)
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

    printf("Thank you for playing the Dice Roller!\n");
    printf("Would you like to play again? (Y/N): ");
    scanf(" %c", &again);

    if (again == 'Y')
    {
        main();
    }

    return 0;
}