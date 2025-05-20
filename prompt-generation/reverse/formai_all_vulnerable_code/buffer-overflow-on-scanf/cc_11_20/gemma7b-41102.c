//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char choice;
    int i, j, r, t, ghosts_num = 3;

    // Setting up the haunted house
    char map[5][5] =
    {
        { 'H', 'H', 'H', 'O', 'H' },
        { 'H', 'A', 'A', 'A', 'H' },
        { 'H', 'A', 'A', 'A', 'H' },
        { 'O', 'A', 'A', 'A', 'O' },
        { 'H', 'H', 'H', 'H', 'H' }
    };

    // Initializing the timer
    time_t start_time, end_time;
    start_time = time(NULL);

    // Moving the ghosts
    for (i = 0; i < ghosts_num; i++)
    {
        r = rand() % 4;
        t = rand() % 3;
        map[r][t] = 'G';
    }

    // Displaying the haunted house
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    // Asking the player to choose a path
    printf("Enter your choice (N, E, S, W): ");
    scanf("%c", &choice);

    // Checking if the player has chosen the right path
    if (choice == 'N' && map[0][0] == 'G')
    {
        printf("You have chosen the northern path. You have entered the haunted hall.\n");
    }
    else if (choice == 'E' && map[0][1] == 'G')
    {
        printf("You have chosen the eastern path. You have entered the haunted dining hall.\n");
    }
    else if (choice == 'S' && map[0][2] == 'G')
    {
        printf("You have chosen the southern path. You have entered the haunted library.\n");
    }
    else if (choice == 'W' && map[0][3] == 'G')
    {
        printf("You have chosen the western path. You have entered the haunted bedroom.\n");
    }
    else
    {
        printf("Invalid choice.\n");
    }

    // Ending the timer
    end_time = time(NULL);
    printf("Time spent in the haunted house: %d seconds\n", end_time - start_time);

    return 0;
}