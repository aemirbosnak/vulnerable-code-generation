//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char ch;
    int room = 1;

    printf("You wake up in a cold sweat. A strange smell fills the air.\n");

    while (1)
    {
        printf("What do you want to do? (help, explore, quit): ");
        scanf("%c", &ch);

        switch (ch)
        {
            case 'h':
                printf("You have a choice of three options:\n");
                printf("1. Explore the room.\n");
                printf("2. Examine the surroundings.\n");
                printf("3. Quit the game.\n");
                break;

            case 'e':
                if (room == 1)
                {
                    printf("The room is dark and empty. There is a door to the north and south.\n");
                }
                else if (room == 2)
                {
                    printf("You are in a bedroom. There is a bed, a dresser, and a window.\n");
                }
                else if (room == 3)
                {
                    printf("You have reached the final room. You have won!\n");
                }
                break;

            case 'q':
                exit(0);
                break;

            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        room++;
    }
}