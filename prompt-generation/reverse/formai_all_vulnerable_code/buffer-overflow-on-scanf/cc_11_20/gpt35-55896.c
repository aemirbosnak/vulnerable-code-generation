//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int roomNum = 0;
    int lightOn = 0;
    int ghostEncounter = 0;
    srand(time(0)); // seed random number generator

    // Intro message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a creepy old house with multiple rooms.\n");
    printf("Your goal is to navigate through all the rooms and find a way out.\n");
    printf("Be careful, as there may be ghosts haunting the place!\n\n");

    // Game loop
    while(roomNum < 5)
    {
        // Room description
        printf("You are in room %d.\n", roomNum);
        if(lightOn)
        {
            printf("The lights are on.\n");
        }
        else
        {
            printf("It is too dark to see anything.\n");
        }

        // Ghost encounter
        if(rand()%10 == 0) // 1 in 10 chance of encountering ghost
        {
            ghostEncounter = 1;
            printf("You hear strange noises and see a ghostly figure.\n");
            printf("The ghost is coming towards you!\n");
            printf("What would you like to do? (1: fight, 2: run)\n");
            
            int choice;
            scanf("%d", &choice);
            if(choice == 1)
            {
                printf("You try to fight the ghost, but your attacks are ineffective.\n");
                printf("The ghost grabs you and you feel a cold chill.\n");
                printf("You have been possessed by the ghost and can no longer escape.\n");
                return 0; // end game
            }
            else if(choice == 2)
            {
                printf("You try to run from the ghost, but it catches up to you.\n");
                printf("You have been possessed by the ghost and can no longer escape.\n");
                return 0; // end game
            }
            else
            {
                printf("You freeze in fear and the ghost possesses you.\n");
                return 0; // end game
            }
        }
        else
        {
            ghostEncounter = 0;
        }

        // Room interaction
        if(roomNum == 0)
        {
            printf("You see a flashlight on a table. Will you take it? (1: yes, 2: no)\n");
            int choice;
            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("You take the flashlight.\n");
                lightOn = 1;
            }
            else
            {
                printf("You leave the flashlight and continue on.\n");
            }
        }
        else if(roomNum == 1)
        {
            printf("You see a key on the ground. Will you take it? (1: yes, 2: no)\n");
            int choice;
            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("You take the key.\n");
            }
            else
            {
                printf("You leave the key and continue on.\n");
            }
        }
        else if(roomNum == 2)
        {
            printf("You see a door with a lock. Do you want to try the key you found? (1: yes, 2: no)\n");
            int choice;
            scanf("%d", &choice);

            if(choice == 1)
            {
                if(rand()%2 == 0) // 50/50 chance of unlocking door
                {
                    printf("The key fits the lock and the door unlocks.\n");
                    roomNum++;
                }
                else
                {
                    printf("The key doesn't fit the lock.\n");
                }
            }
            else
            {
                printf("You leave the door and continue on.\n");
            }
        }
        else if(roomNum == 3)
        {
            printf("You see a book on a shelf. Will you read it? (1: yes, 2: no)\n");
            int choice;
            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("You read the book and find a clue to the way out.\n");
                printf("You move on to the next room.\n");
                roomNum++;
            }
            else
            {
                printf("You leave the book and continue on.\n");
            }
        }
        else if(roomNum == 4)
        {
            printf("You see a window. Will you try to escape? (1: yes, 2: no)\n");
            int choice;
            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("You break through the window and escape the haunted house!\n");
                printf("Congratulations, you have won!\n");
                return 0; // end game
            }
            else
            {
                printf("You leave the window and continue on.\n");
            }
        }

        // Move player to next room
        if(!ghostEncounter)
        {
            printf("Press enter to continue to the next room.\n");
            getchar(); // wait for enter key
            roomNum++;
        }

        printf("\n");
    }

    return 0;
}