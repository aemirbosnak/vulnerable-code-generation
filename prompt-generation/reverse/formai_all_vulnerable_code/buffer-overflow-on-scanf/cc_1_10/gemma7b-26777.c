//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int roll_number = 0;
    int number_of_rolls = 0;

    while (1)
    {
        int roll_result = roll_dice();
        if (roll_result == 6)
        {
            roll_number++;
            number_of_rolls++;
            printf("Congratulations, you rolled a 6 on the %d roll.\n", roll_number);
        }
        else
        {
            printf("Try again, you did not roll a 6 on the %d roll.\n", roll_number);
        }

        if (number_of_rolls == 10)
        {
            printf("Sorry, you have reached the maximum number of rolls. Better luck next time.\n");
            break;
        }

        printf("Do you want to roll again? (Y/N): ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'Y')
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return 0;
}

int roll_dice()
{
    int roll_result = rand() % 6 + 1;
    return roll_result;
}