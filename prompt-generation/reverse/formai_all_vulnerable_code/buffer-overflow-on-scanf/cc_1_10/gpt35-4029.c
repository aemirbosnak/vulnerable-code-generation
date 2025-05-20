//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int room = 1;
    int ghost = rand() % 3 + 1;
    int door;

    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You wake up in a dark room. You can see the faint outline of a door in front of you.\n");
    printf("You stand up and walk towards the door. What do you do?\n");

    while(room < 4)
    {
        printf("\n1. Open the door\n");
        printf("2. Look around the room\n");
        printf("3. Try to find a light switch\n");

        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nYou open the door and step through.\n");
                room++;
                ghost = rand() % 3 + 1;
                break;
            case 2:
                printf("\nYou look around the room but find nothing of interest.\n");
                break;
            case 3:
                printf("\nYou fumble around in the dark trying to find a light switch but come up empty handed.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

        if(room == 2)
        {
            printf("\nYou find yourself in a long hallway. There are three doors in front of you.\n");
            printf("Which door do you choose?\n");

            printf("\n1. Door 1\n");
            printf("2. Door 2\n");
            printf("3. Door 3\n");

            scanf("%d", &door);

            if(door == ghost)
            {
                printf("\nAs you open the door, a ghostly apparition appears before you!\n");
                printf("You scream and run back into the hallway, slamming the door shut behind you.\n");
            }
            else
            {
                printf("\nYou open the door and find a treasure chest full of gold!\n");
                printf("You take the gold and move on to the next room.\n");
            }
        }

        if(room == 3)
        {
            printf("\nYou enter a room with a large red button in the center.\n");
            printf("What do you do?\n");

            printf("\n1. Press the button\n");
            printf("2. Leave the room\n");

            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("\nYou press the button and suddenly the room begins to shake.\n");
                printf("The walls crumble around you and a giant monster emerges from the rubble!\n");
                printf("You make a run for it back to the hallway.\n");
            }
            else
            {
                printf("\nYou decide not to press the button and leave the room.\n");
            }
        }
    }

    printf("\nYou have made it out of the haunted house alive!\n");
    printf("Congratulations!\n");

    return 0;
}