//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_ANGLE 360
#define MIN_ANGLE 0
#define MAX_SPEED 100
#define MIN_SPEED 0

int main() 
{
    int angle = 0;
    int speed = 0;
    int isOn = 0;

    // Initialize the remote control
    printf("Initializing the remote control...\n\n");

    // Turn on the drone
    printf("Turn on the drone? (1 for Yes, 0 for No): ");
    scanf("%d", &isOn);

    if (isOn) 
    {
        printf("\nDrone is now on.\n\n");

        while (isOn) 
        {
            // Get user input for angle and speed
            printf("Enter angle (0-360): ");
            scanf("%d", &angle);

            // Ensure angle is within valid range
            if (angle < MIN_ANGLE || angle > MAX_ANGLE) 
            {
                printf("Invalid angle. Please try again.\n");
                continue;
            }

            printf("Enter speed (0-100): ");
            scanf("%d", &speed);

            // Ensure speed is within valid range
            if (speed < MIN_SPEED || speed > MAX_SPEED) 
            {
                printf("Invalid speed. Please try again.\n");
                continue;
            }

            // Send commands to drone
            printf("\nSending commands to drone...\n");
            printf("Angle: %d\n", angle);
            printf("Speed: %d\n\n", speed);

            // Prompt user to turn off or continue
            printf("Would you like to turn off the drone? (1 for Yes, 0 for No): ");
            scanf("%d", &isOn);
            printf("\n");
        }
    }
    else 
    {
        printf("\nDrone is off. Turning off remote control...\n");
    }

    printf("Remote control is now off.\n");

    return 0;
}