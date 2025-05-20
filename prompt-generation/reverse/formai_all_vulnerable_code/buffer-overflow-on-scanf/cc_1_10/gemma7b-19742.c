//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GORE 5

void play_haunted_house(void)
{
    int i, j, choice, gore_num = 0;
    char name[20];

    printf("Welcome to the Haunted Castle of Thornkeep.\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("You have entered the cursed halls of Thornkeep. Prepare for a fright!\n");

    // Create a loop to simulate the haunted house experience
    for (i = 0; i < 5; i++)
    {
        // Display the options available to the player
        printf("You have three choices: \n");
        printf("1. Proceed forward\n");
        printf("2. Turn right\n");
        printf("3. Turn left\n");

        // Get the player's choice
        printf("Please make your choice: ");
        scanf("%d", &choice);

        // Implement the player's choice
        switch (choice)
        {
            case 1:
                // The player proceeds forward
                printf("You continue down the main corridor. You hear the sound of your own heartbeat and the echoes of your footsteps.\n");
                break;
            case 2:
                // The player turns right
                printf("You turn right into a side corridor. The air is thick with the smell of decay and blood. You hear a shuffling sound coming from the end of the corridor.\n");
                break;
            case 3:
                // The player turns left
                printf("You turn left into a secret passage. The walls of the passage are covered in blood and gore. You hear the sound of a dripping blade and the screams of the damned.\n");
                gore_num++;
                break;
        }

        // Check if the player has encountered any gore
        if (gore_num >= NUM_GORE)
        {
            printf("You have encountered too much gore. You are no longer able to continue playing.\n");
            break;
        }
    }

    // The player has escaped the haunted house
    printf("You have escaped Thornkeep. You are free from the clutches of the damned.\n");
}

int main(void)
{
    play_haunted_house();

    return 0;
}