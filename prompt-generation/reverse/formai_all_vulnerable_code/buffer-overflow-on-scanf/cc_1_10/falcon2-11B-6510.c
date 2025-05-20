//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_ROTATION 360
#define MAX_VELOCITY 20
#define MAX_ACCELERATION 10

int main()
{
    srand(time(NULL));

    int rc_vehicle[3];
    rc_vehicle[0] = 0; // Throttle
    rc_vehicle[1] = 0; // Steering
    rc_vehicle[2] = 0; // Brake

    printf("Welcome to the Remote Control Vehicle Simulator!\n");

    while (1)
    {
        printf("\nThrottle: %d | Steering: %d | Brake: %d\n", rc_vehicle[0], rc_vehicle[1], rc_vehicle[2]);

        printf("Enter throttle (0-100): ");
        scanf("%d", &rc_vehicle[0]);

        printf("Enter steering (0-100): ");
        scanf("%d", &rc_vehicle[1]);

        printf("Enter brake (0-100): ");
        scanf("%d", &rc_vehicle[2]);

        if (rc_vehicle[0] > 100)
            rc_vehicle[0] = 100;
        if (rc_vehicle[0] < 0)
            rc_vehicle[0] = 0;

        if (rc_vehicle[1] > 100)
            rc_vehicle[1] = 100;
        if (rc_vehicle[1] < 0)
            rc_vehicle[1] = 0;

        if (rc_vehicle[2] > 100)
            rc_vehicle[2] = 100;
        if (rc_vehicle[2] < 0)
            rc_vehicle[2] = 0;

        sleep(1);
    }

    return 0;
}