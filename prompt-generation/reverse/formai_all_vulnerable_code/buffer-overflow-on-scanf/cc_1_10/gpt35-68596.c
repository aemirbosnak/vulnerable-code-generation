//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set random seed
    srand(time(NULL));

    // Initialize variables
    int roomNumber = 1;
    int hasKey = 0;
    int ghostAppeared = 0;

    // While player is not in the final room
    while (roomNumber != 6)
    {
        printf("\nYou are in room %d\n", roomNumber);

        // Randomly determine if there is a ghost in the room
        int ghostChance = rand() % 2;
        if (ghostChance == 1 && !ghostAppeared)
        {
            printf("A ghost suddenly appears! You try to run, but the door is locked!\n");
            ghostAppeared = 1;
            continue;
        }

        // Ask user for their action
        printf("What do you want to do?\n");
        printf("1. Look for a key\n");
        printf("2. Try to open the door\n");

        int choice;
        scanf("%d", &choice);

        // Process user's action
        switch (choice)
        {
            case 1:
                if (hasKey)
                {
                    printf("You already found the key!\n");
                }
                else if (rand() % 2)
                {
                    printf("You find a key!\n");
                    hasKey = 1;
                }
                else
                {
                    printf("You search the room, but find nothing.\n");
                }
                break;
            case 2:
                if (!hasKey)
                {
                    printf("The door is locked! You need to find a key first.\n");
                }
                else if (ghostAppeared)
                {
                    printf("You use the key to unlock the door and escape the room. The ghost follows you, but disappears as you exit the room.\n");
                    roomNumber++;
                    ghostAppeared = 0;
                }
                else
                {
                    printf("You use the key to unlock the door and escape the room.\n");
                    roomNumber++;
                }
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    // Player has reached the final room
    printf("\nYou have escaped the haunted house!\n");
    printf("Congratulations!\n");

    return 0;
}