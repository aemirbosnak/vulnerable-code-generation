//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // seed the random number generator with the current time
    int fuel = 100; // start with full fuel
    int distance = 0; // start at 0 distance

    printf("Welcome to Space Adventure!\n");

    while (distance < 1000 && fuel > 0) // while the player hasn't reached 1000 distance or run out of fuel
    {
        printf("You are currently %dkm from Earth and have %d units of fuel.\n", distance, fuel);

        int decision;
        printf("What would you like to do?\n");
        printf("1. Travel to the nearest planet\n");
        printf("2. Refuel at a space station\n");
        printf("3. Exit the program\n");
        scanf("%d", &decision);

        switch (decision)
        {
            case 1:
                printf("Traveling to the nearest planet...\n");
                int random_distance = rand() % 500 + 500; // travel a random distance between 500-1000km
                printf("You traveled %dkm\n", random_distance);
                distance += random_distance; // add the random distance to the total distance
                fuel -= distance/10; // use 1 fuel unit for every 10km traveled
                break;
            case 2:
                printf("Refueling at a space station...\n");
                fuel = 100; // refill fuel to max
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }
    }

    if (distance >= 1000) // if the player reached 1000km
    {
        printf("Congratulations, you have completed your space adventure!\n");
    }
    else // if the player ran out of fuel
    {
        printf("You ran out of fuel and your space adventure has ended.\n");
    }

    return 0;
}