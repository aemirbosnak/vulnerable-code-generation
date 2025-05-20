//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_haunted_house(void)
{
    int i, j, k, r, t = 0;
    char c;
    time_t start, end;

    system("CLS");
    printf("Welcome to the Haunted House!\n");
    printf("-------------------------\n");

    start = time(NULL);

    // Generate random sounds
    for (i = 0; i < 5; i++)
    {
        r = rand() % 3;
        switch (r)
        {
            case 0:
                printf("Footsteps...\n");
                break;
            case 1:
                printf("Screams...\n");
                break;
            case 2:
                printf("Doors slamming...\n");
                break;
        }
    }

    // Create a spooky atmosphere
    for (j = 0; j < 3; j++)
    {
        system("pause");
        printf("Something sinister is lurking nearby...\n");
    }

    // Play a haunting melody
    system("start music/spooky.mp3");

    // Ask the player to press any key to continue
    printf("Press any key to continue...\n");
    c = getchar();

    end = time(NULL);

    // Calculate the time spent in the haunted house
    t = end - start;

    // Display the time spent in the haunted house
    printf("You spent %d seconds in the haunted house.\n", t);

    // Play a sound effect
    system("start music/exit.wav");

    // End the game
    system("pause");
}

int main()
{
    play_haunted_house();

    return 0;
}