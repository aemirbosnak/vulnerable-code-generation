//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    int haunt_number = rand() % 3;

    switch (haunt_number)
    {
        case 0:
            printf("You have entered the Haunted House of Shadows. Prepare for a chilling experience.\n");
            break;
        case 1:
            printf("You have entered the Haunted House of Screams. Get ready for a terrifying night.\n");
            break;
        case 2:
            printf("You have entered the Haunted House of Whispers. Prepare for a haunting encounter.\n");
            break;
    }

    int choice;
    printf("Enter 1 to explore the house, 2 to leave: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You cautiously explore the house, encountering creepy sounds and eerie sights. Do you want to continue exploring? (Y/N): ");
            char answer;
            scanf("%c", &answer);

            if (answer == 'Y')
            {
                int rooms_visited = 0;
                while (rooms_visited < 5)
                {
                    int room_number = rand() % 3;

                    switch (room_number)
                    {
                        case 0:
                            printf("You enter a dark and dusty bedroom. The smell of decay and mildew fills the air. You hear a scratching sound behind you.\n");
                            break;
                        case 1:
                            printf("You enter a bloodstained hallway. The walls are adorned with grotesque paintings of torture and suffering. You hear a chilling scream.\n");
                            break;
                        case 2:
                            printf("You enter a haunted dining hall. The table is set for a feast, but the food is cold and rotting. You hear a ghostly whisper.\n");
                            break;
                    }

                    rooms_visited++;
                }

                printf("You have escaped the Haunted House of Horrors. You are safe... for now.\n");
            }
            else
            {
                printf("You flee the Haunted House, leaving the horrors behind.\n");
            }
            break;
        case 2:
            printf("You leave the Haunted House, relieved to be alive.\n");
            break;
    }

    return;
}