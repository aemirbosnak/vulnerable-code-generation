//Gemma-7B DATASET v1.0 Category: Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int r_side = 0, j_side = 0, game_over = 0;
    char r_name[20], j_name[20];

    printf("Enter the name of the Romeo side:");
    scanf("%s", r_name);

    printf("Enter the name of the Juliet side:");
    scanf("%s", j_name);

    printf("Let the battle begin!\n");

    while (!game_over)
    {
        printf("Enter 'r' to attack from the Romeo side or 'j' to attack from the Juliet side:");
        char side = getchar();

        switch (side)
        {
            case 'r':
                r_side++;
                printf("%s has attacked!\n", r_name);
                break;
            case 'j':
                j_side++;
                printf("%s has attacked!\n", j_name);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        if (r_side > j_side)
        {
            game_over = 1;
            printf("Romeo has won!\n");
        }
        else if (j_side > r_side)
        {
            game_over = 1;
            printf("Juliet has won!\n");
        }
    }

    return;
}