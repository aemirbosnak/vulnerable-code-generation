//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int num_sides = 6;
    int roll_result = 0;
    int roll_again = 0;

    printf("Welcome to the Dungeon of Doom!");
    printf("\n");

    while (roll_again == 0)
    {
        printf("Roll the dice: ");
        roll_result = rand() % num_sides + 1;

        switch (roll_result)
        {
            case 1:
                printf("You rolled a 1, prepare for a trip to the dungeon!");
                break;
            case 2:
                printf("You rolled a 2, the dragon is weak!");
                break;
            case 3:
                printf("You rolled a 3, the wizard is defeated!");
                break;
            case 4:
                printf("You rolled a 4, the evil queen is on your side!");
                break;
            case 5:
                printf("You rolled a 5, the treasure is yours!");
                break;
            case 6:
                printf("You rolled a 6, prepare for a feast!");
                break;
        }

        printf("\n");

        printf("Do you want to roll again? (Y/N): ");
        scanf(" %c", &roll_again);

        if (roll_again == 'Y')
        {
            roll_again = 1;
        }
    }

    printf("Thank you for playing in the Dungeon of Doom!");
    return 0;
}