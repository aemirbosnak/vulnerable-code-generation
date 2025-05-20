//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: inquisitive
#include <stdio.h>

#define MAX_DISTANCE 10000 // in meters
#define MAX_SPEED 120 // in km/h
#define ACCELERATION 8 // in m/s^2
#define DECELERATION 6 // in m/s^2

int main()
{
    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("Please enter the distance to your destination in meters: ");

    int distance;
    scanf("%d", &distance);

    if (distance > MAX_DISTANCE)
    {
        printf("Sorry, the maximum distance allowed is %d meters.\n", MAX_DISTANCE);
        return 1;
    }

    printf("Please enter the speed limit in km/h: ");

    int speedLimit;
    scanf("%d", &speedLimit);

    if (speedLimit > MAX_SPEED)
    {
        printf("Sorry, the maximum speed allowed is %d km/h.\n", MAX_SPEED);
        return 1;
    }

    int speed = 0;
    int time = 0;
    int position = 0;

    printf("\nStarting simulation...\n");

    while (position < distance)
    {
        if (speed < speedLimit)
        {
            speed += ACCELERATION;
        }
        else if (speed > speedLimit)
        {
            speed -= DECELERATION;
        }

        if (speed > MAX_SPEED)
        {
            speed = MAX_SPEED;
        }

        int distanceRemaining = distance - position;
        int timeRemaining = distanceRemaining / speed;

        printf("\nAt time %d seconds:\n", time);
        printf("    - Position: %d meters.\n", position);
        printf("    - Speed: %d km/h.\n", speed);
        printf("    - Time to destination: %d seconds.\n", timeRemaining);

        time++;
        position += (speed * 1000 / 3600); // convert km/h to m/s
    }

    printf("\nCongratulations, you have arrived at your destination in %d seconds!\n", time);

    return 0;
}