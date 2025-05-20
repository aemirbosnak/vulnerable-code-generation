//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: grateful
#include <stdio.h>

int main()
{
    int speed = 0, distance = 0, sensor = 0;

    printf("Welcome to Remote Control Car simulation!\n");

    while (1)
    {
        printf("Enter a command:\n");
        printf("1. Forward\n");
        printf("2. Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn right\n");
        printf("5. Stop\n");
        printf("6. Quit\n");

        int command;
        scanf("%d", &command);

        if (command == 1)
        {
            printf("Enter distance: ");
            scanf("%d", &distance);

            printf("Enter speed: ");
            scanf("%d", &speed);

            printf("Forward for %d meters with %d speed\n", distance, speed);
        }
        else if (command == 2)
        {
            printf("Enter distance: ");
            scanf("%d", &distance);

            printf("Enter speed: ");
            scanf("%d", &speed);

            printf("Backward for %d meters with %d speed\n", distance, speed);
        }
        else if (command == 3)
        {
            printf("Turning left ...\n");
        }
        else if (command == 4)
        {
            printf("Turning right ...\n");
        }
        else if (command == 5)
        {
            printf("Stopping ...\n");
        }
        else if (command == 6)
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid command!\n");
        }

        // Update sensor value
        sensor += distance;

        // Display sensor value
        printf("Distance travelled: %d\n", sensor);
    }

    return 0;
}