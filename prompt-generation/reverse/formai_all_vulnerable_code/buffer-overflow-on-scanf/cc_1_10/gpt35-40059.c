//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_STEER 90
#define MIN_STEER -90

int main()
{
    int speed = 0;
    int steering_angle = 0;

    printf("Welcome to the Remote Control Vehicle Simulator!\n");

    while (1)
    {
        printf("\nEnter a speed between %d and %d: ", MIN_SPEED, MAX_SPEED);
        scanf("%d", &speed);

        if (speed < MIN_SPEED)
        {
            printf("Invalid speed. Too slow. Setting speed to minimum.\n");
            speed = MIN_SPEED;
        }
        else if (speed > MAX_SPEED)
        {
            printf("Invalid speed. Too fast. Setting speed to maximum.\n");
            speed = MAX_SPEED;
        }

        printf("Enter a steering angle between %d and %d: ", MIN_STEER, MAX_STEER);
        scanf("%d", &steering_angle);

        if (steering_angle < MIN_STEER)
        {
            printf("Invalid steering angle. Too far left. Setting angle to minimum.\n");
            steering_angle = MIN_STEER;
        }
        else if (steering_angle > MAX_STEER)
        {
            printf("Invalid steering angle. Too far right. Setting angle to maximum.\n");
            steering_angle = MAX_STEER;
        }

        printf("Sending speed %d and steering angle %d to vehicle...\n", speed, steering_angle);

        // TODO: Send speed and steering angle to vehicle

        printf("Press any key to continue or 'q' to quit...");
        char input;
        scanf(" %c", &input);

        if (input == 'q')
        {
            printf("Exiting program...\n");
            break;
        }
    }

    return 0;
}