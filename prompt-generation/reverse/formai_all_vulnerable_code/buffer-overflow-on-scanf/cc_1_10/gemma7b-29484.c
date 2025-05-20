//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int face, number, roll_count = 0, total = 0, current_face = 0;

    printf("Press 'r' to roll the dice, 'q' to quit: ");
    char input;

    while (1)
    {
        scanf(" %c", &input);

        if (input == 'r')
        {
            roll_count++;
            number = rand() % 6 + 1;
            current_face = number;

            switch (number)
            {
                case 1:
                    printf("The die landed on face 1.\n");
                    break;
                case 2:
                    printf("The die landed on face 2.\n");
                    break;
                case 3:
                    printf("The die landed on face 3.\n");
                    break;
                case 4:
                    printf("The die landed on face 4.\n");
                    break;
                case 5:
                    printf("The die landed on face 5.\n");
                    break;
                case 6:
                    printf("The die landed on face 6.\n");
                    break;
            }

            total += number;
            printf("Total: %d\n", total);
        }

        if (input == 'q')
        {
            break;
        }
    }

    printf("Number of rolls: %d\n", roll_count);
    printf("Total number of points: %d\n", total);

    return 0;
}