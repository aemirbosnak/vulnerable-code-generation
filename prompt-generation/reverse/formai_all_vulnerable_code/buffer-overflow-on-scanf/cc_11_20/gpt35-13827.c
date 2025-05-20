//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Press ENTER to start...");
    getchar();

    srand(time(NULL)); // initializing random seed

    int room = 1;
    int ghost = 0;
    int health = 100;
    int key = 0;
    int flashlight = 0;

    while (room <= 6 && health > 0)
    {
        printf("\nYou are now in Room %d.\n", room);

        // determine if there is a ghost in the room
        if (rand() % 2 == 0)
        {
            ghost = 1;
            printf("Uh oh! There's a ghost in this room!\n");

            // if the player has a flashlight, the ghost is scared away
            if (flashlight)
            {
                printf("You shine your flashlight and scare away the ghost.\n");
                ghost = 0;
            }
            else
            {
                printf("You don't have a flashlight, and the ghost attacks you!\n");
                health -= rand() % 50 + 1; // subtract random amount of health
            }
        }

        // determine if there is a key in the room
        if (rand() % 3 == 0)
        {
            key = 1;
            printf("You found a key in this room!\n");
        }

        // give the player a flashlight in Room 3
        if (room == 3)
        {
            printf("You found a flashlight in this room!\n");
            flashlight = 1;
        }

        // give the player a health boost in Room 6
        if (room == 6)
        {
            printf("You found a first aid kit in this room!\n");
            health += 50;
            if (health > 100)
            {
                health = 100; // prevent health from going over 100%
            }
        }

        // ask the player which direction to go
        int direction;
        printf("Which direction do you want to go? (1 for left, 2 for right): ");
        scanf("%d", &direction);

        if (direction == 1)
        {
            printf("You went left.\n");
            room++;
        }
        else if (direction == 2)
        {
            printf("You went right.\n");
            room++;
        }
        else
        {
            printf("Invalid input. Try again.\n");
        }
    }

    // check if the player made it out of the house
    if (health > 0 && key)
    {
        printf("\nCongratulations! You made it out of the haunted house with the key!\n");
    }
    else
    {
        printf("\nOh no! You didn't make it out of the haunted house.\n");
        if (health <= 0)
        {
            printf("You died in the house. Game Over.\n");
        }
        else
        {
            printf("You didn't find the key. Game Over.\n");
        }
    }

    return 0;
}