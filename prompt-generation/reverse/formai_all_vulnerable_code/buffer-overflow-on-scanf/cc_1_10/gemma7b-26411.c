//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_number = 0;
    int face_number = 0;
    int total_sum = 0;
    int number_of_rolls = 0;
    char roll_again = 'y';

    while (roll_again == 'y')
    {
        roll_number = rand() % 6 + 1;
        face_number = roll_number;

        switch (face_number)
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

        total_sum += roll_number;
        number_of_rolls++;

        printf("Do you want to roll again (y/n)? ");
        scanf("%c", &roll_again);
    }

    printf("Your total sum is: %d\n", total_sum);
    printf("Number of rolls: %d\n", number_of_rolls);

    return 0;
}