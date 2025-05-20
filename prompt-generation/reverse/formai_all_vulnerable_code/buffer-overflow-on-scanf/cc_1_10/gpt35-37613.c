//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //seed for random number generation

    int roomNumber = 1; //starting room is 1
    int ghostAppeared = 0; //flag for if a ghost has appeared in a room

    printf("Welcome to the Haunted House Simulator!\n\n");

    do
    {
        printf("You are in room %d.\n", roomNumber);

        if(ghostAppeared == 0)
        {
            int chance = rand() % 10 + 1; //1 in 10 chance of a ghost appearing

            if(chance == 1)
            {
                printf("A ghost has appeared!\n");
                ghostAppeared = 1;
            }
        }
        else
        {
            printf("The ghost is still in the room!\n");
            ghostAppeared = 0; //reset ghost flag for next room
        }

        int choice;

        do
        {
            printf("Where would you like to go?\n");
            printf("1. Move to the next room\n");
            printf("2. Stay in this room\n");
            scanf("%d", &choice);
        } while(choice != 1 && choice != 2);

        if(choice == 1)
        {
            roomNumber++;

            if(roomNumber == 5) //final room
            {
                if(ghostAppeared == 1)
                {
                    printf("The ghost followed you to the final room and you are now trapped with it forever!\n");
                }
                else
                {
                    printf("Congratulations! You made it to the final room without encountering any ghosts!\n");
                }

                return 0;
            }
        }

    } while(1); //infinite loop until final room is reached

    return 0;
}