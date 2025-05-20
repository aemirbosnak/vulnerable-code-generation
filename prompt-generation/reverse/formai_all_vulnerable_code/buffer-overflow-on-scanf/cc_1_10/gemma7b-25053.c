//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("I am not a cat, I am a human.\n");
    printf("But I can draw ASCII art like nobody's business.\n");
    printf("Would you like to see a demonstration?\n");

    char answer;
    scanf("%c", &answer);

    if (answer == 'y')
    {
        printf("Sure, here's what I can do:\n");

        int height = 5;
        int width = 20;

        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < width; col++)
            {
                if (col == 0 || col == width - 1)
                {
                    printf("%c", '-');
                }
                else if (row == 0)
                {
                    printf("%c", '=');
                }
                else
                {
                    printf("%c", ' ');
                }
            }

            printf("\n");
        }

        printf("That's it! I've drawn a magnificent ASCII artwork.\n");
    }
    else
    {
        printf("Oh well, I guess I'll just have to entertain you with something else.\n");
    }

    return 0;
}