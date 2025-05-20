//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_again = 1;
    int number_rolled = 0;
    int face_of_the_die = 0;

    while (roll_again)
    {
        face_of_the_die = rand() % 6 + 1;
        number_rolled++;

        switch (face_of_the_die)
        {
            case 1:
                printf("You rolled a 1! Better luck next time, loser!\n");
                break;
            case 2:
                printf("You rolled a 2! You're a lucky dog, but not today.\n");
                break;
            case 3:
                printf("You rolled a 3! You're close, but not quite.\n");
                break;
            case 4:
                printf("You rolled a 4! Keep rolling!\n");
                break;
            case 5:
                printf("You rolled a 5! You're a winner!\n");
                break;
            case 6:
                printf("You rolled a 6! Congratulations, you're the champion!\n");
                break;
        }

        printf("Number of rolls: %d\n", number_rolled);

        if (number_rolled >= 3)
        {
            roll_again = 0;
        }
        else
        {
            printf("Do you want to roll again? (Y/N): ");
            char answer;
            scanf(" %c", &answer);

            if (answer == 'Y')
            {
                roll_again = 1;
            }
            else
            {
                roll_again = 0;
            }
        }
    }

    printf("Thank you for playing! See you next time.\n");

    return 0;
}