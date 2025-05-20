//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t = time(NULL);
    srand(t);

    int num_haunts = rand() % 5 + 1;
    int i;

    for (i = 0; i < num_haunts; i++)
    {
        int haunt_type = rand() % 3;

        switch (haunt_type)
        {
            case 0:
                printf("The door swings open, and a cold wind whips through the halls.\n");
                printf("You hear whispers in the wind, 'Get out while you can...' \n");
                break;
            case 1:
                printf("A cold hand brushes against your skin, and you feel a sharp, icy sting.\n");
                printf("You hear a disembodied voice, 'You're not welcome here...' \n");
                break;
            case 2:
                printf("A ghostly figure appears before you, its eyes burning with rage.\n");
                printf("The figure speaks, 'You will pay for your sins...' \n");
                break;
        }

        printf("You feel a sense of dread and fear, and your heart skips a beat.\n");
        printf("Do you want to run or hide?\n");

        char answer;
        scanf(" %c", &answer);

        if (answer == 'r')
        {
            printf("You flee from the house, running as fast as you can.\n");
        }
        else if (answer == 'h')
        {
            printf("You hide in a closet, waiting for the terror to pass.\n");
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}