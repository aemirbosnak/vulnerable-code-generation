//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(void)
{
    int i, j, r, t;
    char c;
    time_t start_time, end_time;

    start_time = time(NULL);

    system("clear");
    printf("You have entered the Haunted House!\n");
    printf("-------------------------\n");
    printf("Press any key to continue...\n");
    c = getchar();

    system("clear");
    printf("The door creaks open...\n");
    printf("A cold wind whispers through the halls...\n");
    printf("You hear a distant scream...\n");

    for (i = 0; i < 10; i++)
    {
        system("clear");
        printf("The footsteps echo through the house...\n");
        printf("Do you hear something?\n");
        r = rand() % 2;
        if (r == 0)
        {
            printf("You see a ghostly figure!\n");
        }
        else
        {
            printf("There is nothing there.\n");
        }
        printf("Press any key to continue...\n");
        c = getchar();
    }

    end_time = time(NULL);
    t = end_time - start_time;

    system("clear");
    printf("You have escaped the Haunted House!\n");
    printf("-------------------------\n");
    printf("Time spent in the haunted house: %d seconds\n", t);

    return;
}

int main()
{
    haunted_house();

    return 0;
}