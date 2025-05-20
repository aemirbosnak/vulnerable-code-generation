//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    system("CLS");
    srand(time(NULL));

    // Create a haunted house
    int house[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Place the ghosts
    house[2] = 1;
    house[5] = 2;
    house[7] = 3;

    // Set the trapdoors
    house[1] = 4;
    house[3] = 5;
    house[6] = 6;

    // Start the game
    int player_location = 0;
    int direction = 0;

    // Loop until the player escapes or dies
    while (1)
    {
        // Display the house
        for (int i = 0; i < 10; i++)
        {
            if (house[i] == 1)
            {
                printf("G");
            }
            else if (house[i] == 2)
            {
                printf("M");
            }
            else if (house[i] == 3)
            {
                printf("A");
            }
            else
            {
                printf(".");
            }
        }

        // Get the player's input
        printf("Enter direction (N, S, E, W): ");
        scanf("%d", &direction);

        // Move the player
        switch (direction)
        {
            case 1:
                player_location--;
                break;
            case 2:
                player_location++;
                break;
            case 3:
                player_location++;
                break;
            case 4:
                player_location--;
                break;
        }

        // Check if the player has escaped or died
        if (player_location == 9)
        {
            printf("You escaped the haunted house!");
            break;
        }
        else if (house[player_location] == 4)
        {
            printf("You fell through a trapdoor and died!");
            break;
        }
    }

    return 0;
}