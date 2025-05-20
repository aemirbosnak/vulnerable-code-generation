//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandomNumber(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    srand(time(0)); // Seed the random number generator

    printf("\nWelcome to the Haunted House Simulator!\n\n");
    printf("You are alone in a post-apocalyptic world and have stumbled upon an abandoned house.\n");
    printf("You decide to enter the house to search for supplies.\n\n");

    int roomNumber = 1;
    char input;

    // Loop until the player exits the house or dies
    while (roomNumber > 0 && roomNumber < 10)
    {
        printf("You are in room #%d.\n", roomNumber);

        // Generate a random number to determine what happens in the room
        int roomEvent = generateRandomNumber(1, 3);

        if (roomEvent == 1)
        {
            printf("You found some supplies!\n");
            printf("Press any key to continue...\n");
            scanf(" %c", &input);
            roomNumber++;
        }
        else if (roomEvent == 2)
        {
            printf("You hear a noise coming from upstairs and decide to investigate.\n");
            printf("As you climb the stairs, a zombie jumps out and attacks you!\n");
            printf("GAME OVER.\n");
            roomNumber = -1;
        }
        else
        {
            printf("As you enter the room, you feel a sudden chill.\n");
            printf("You turn around to leave but the door is gone!\n");
            printf("You are trapped in the room!\n");
            printf("Press any key to continue...\n");
            scanf(" %c", &input);

            // Generate another random number to determine if the player escapes
            int escapeChance = generateRandomNumber(1, 2);

            if (escapeChance == 1)
            {
                printf("You manage to find a hidden door and escape!\n");
                roomNumber++;
            }
            else
            {
                printf("You are stuck in the room forever and eventually die of starvation.\n");
                printf("GAME OVER.\n");
                roomNumber = -1;
            }
        }
    }

    printf("\nThank you for playing the Haunted House Simulator in a post-apocalyptic style!\n");

    return 0;
}