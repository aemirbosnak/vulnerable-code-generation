//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_num;
    int sum = 0;
    int faces = 6;
    int sides = 0;
    int face_roll;

    printf("Enter the number of rolls: ");
    scanf("%d", &roll_num);

    for (int i = 0; i < roll_num; i++)
    {
        sides = rand() % faces + 1;
        face_roll = sides;

        switch (face_roll)
        {
            case 1:
                printf("You rolled a 1.\n");
                break;
            case 2:
                printf("You rolled a 2.\n");
                break;
            case 3:
                printf("You rolled a 3.\n");
                break;
            case 4:
                printf("You rolled a 4.\n");
                break;
            case 5:
                printf("You rolled a 5.\n");
                break;
            case 6:
                printf("You rolled a 6.\n");
                break;
            default:
                printf("Error rolling the dice.\n");
                break;
        }

        sum += sides;
    }

    printf("The total sum of your rolls is: %d.\n", sum);

    return 0;
}