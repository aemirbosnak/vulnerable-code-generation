//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunt(int, int);

int main()
{
    srand(time(NULL));
    int choice, floor, ghosts;

    printf("Welcome to the Haunted Mansion of Spook Manor!\n");
    printf("Please select a floor: ");
    scanf("%d", &floor);

    printf("How many ghosts do you want to encounter? ");
    scanf("%d", &ghosts);

    haunt(floor, ghosts);

    return 0;
}

void haunt(int floor, int ghosts)
{
    int i, j, random_number, ghost_location;

    for (i = 0; i < ghosts; i++)
    {
        printf("Ghost %d is roaming the halls of floor %d...\n", i + 1, floor);

        for (j = 0; j < 5; j++)
        {
            random_number = rand() % 10;
            ghost_location = random_number * 5;

            switch (ghost_location)
            {
                case 0:
                    printf("Ghost is in the foyer.\n");
                    break;
                case 1:
                    printf("Ghost is in the dining hall.\n");
                    break;
                case 2:
                    printf("Ghost is in the living room.\n");
                    break;
                case 3:
                    printf("Ghost is in the bedroom.\n");
                    break;
                case 4:
                    printf("Ghost is in the bathroom.\n");
                    break;
            }
        }
    }
}