//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Donald Knuth
#include <stdio.h>

#define MAX_THROTTLE 100
#define MIN_THROTTLE 0
#define MAX_ANGLE 45
#define MIN_ANGLE -45

int main()
{
    int throttle = 0;
    int pitch = 0;
    int roll = 0;
    int yaw = 0;

    while (1)
    {
        printf("Enter throttle (0-100): ");
        scanf("%d", &throttle);

        if (throttle < MIN_THROTTLE || throttle > MAX_THROTTLE)
        {
            printf("Invalid throttle value\n");
            continue;
        }

        printf("Enter pitch (-45 to 45): ");
        scanf("%d", &pitch);

        if (pitch < MIN_ANGLE || pitch > MAX_ANGLE)
        {
            printf("Invalid pitch value\n");
            continue;
        }

        printf("Enter roll (-45 to 45): ");
        scanf("%d", &roll);

        if (roll < MIN_ANGLE || roll > MAX_ANGLE)
        {
            printf("Invalid roll value\n");
            continue;
        }

        printf("Enter yaw (-45 to 45): ");
        scanf("%d", &yaw);

        if (yaw < MIN_ANGLE || yaw > MAX_ANGLE)
        {
            printf("Invalid yaw value\n");
            continue;
        }

        // send throttle, pitch, roll, and yaw values to the drone
        printf("Throttle: %d\tPitch: %d\tRoll: %d\tYaw: %d\n", throttle, pitch, roll, yaw);
    }

    return 0;
}