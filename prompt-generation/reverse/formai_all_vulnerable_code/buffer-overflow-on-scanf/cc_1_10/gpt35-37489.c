//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 100

int main()
{
    int num_cars, speed_limit;
    int car_speeds[MAX_CARS];
    int i,j;

    srand(time(NULL)); // initialize random number generator

    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    printf("Enter the speed limit: ");
    scanf("%d", &speed_limit);

    printf("\nGenerating speeds for %d cars...\n", num_cars);

    for(i=0; i < num_cars; i++)
    {
        car_speeds[i] = rand() % (MAX_SPEED + 1); // generate speeds between 0 and MAX_SPEED
        printf("Car %d speed: %d\n", i+1, car_speeds[i]);
    }

    printf("\nSimulating traffic flow...\n");

    for(i=0; i < num_cars; i++)
    {
        printf("Car %d is travelling at %d mph\n", i+1, car_speeds[i]);

        if(car_speeds[i] > speed_limit) // check if car is speeding
        {
            printf("Car %d is speeding! It was travelling at %d mph over the speed limit of %d mph\n", i+1, car_speeds[i] - speed_limit, speed_limit);
        }

        for(j=i+1; j < num_cars; j++)
        {
            if(car_speeds[j] < car_speeds[i]) // check if car j is going slower than car i
            {
                printf("Car %d is catching up to Car %d\n", i+1, j+1);
                break; // Car i has caught up to car j, so we move on to the next car i
            }
        }
    }

    return 0;
}