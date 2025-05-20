//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int speed = 0; // initial speed
    int direction = 0; // initial direction, 0 for forward, 1 for backward
    int distance = 0; // initial distance travelled
    int battery = 100; // initial battery level

    while (battery > 0 && distance < 1000) // while battery is not empty and distance travelled is less than 1000
    {
        printf("Current Speed: %d\n", speed);
        printf("Current Direction: %d\n", direction);
        printf("Current Distance: %d\n", distance);
        printf("Current Battery: %d\n\n", battery);

        int choice;
        printf("Choose an option:\n");
        printf("1. Increase Speed\n");
        printf("2. Decrease Speed\n");
        printf("3. Change Direction\n");
        printf("4. Travel Forward\n");
        printf("5. Travel Backward\n");
        printf("6. Check Battery Level\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (speed < 10)
                {
                    speed++;
                    printf("Speed increased to %d\n", speed);
                }
                else
                {
                    printf("Maximum speed reached\n");
                }
                break;
            case 2:
                if (speed > 0)
                {
                    speed--;
                    printf("Speed decreased to %d\n", speed);
                }
                else
                {
                    printf("Vehicle is already stopped\n");
                }
                break;
            case 3:
                if (direction == 0)
                {
                    direction = 1;
                    printf("Direction changed to backward\n");
                }
                else
                {
                    direction = 0;
                    printf("Direction changed to forward\n");
                }
                break;
            case 4:
                if (battery >= 10)
                {
                    distance += speed;
                    battery--;
                    printf("Vehicle moved %d units forward\n", speed);
                }
                else
                {
                    printf("Battery level too low to travel\n");
                }
                break;
            case 5:
                if (battery >= 10)
                {
                    distance -= speed;
                    battery--;
                    printf("Vehicle moved %d units backward\n", speed);
                }
                else
                {
                    printf("Battery level too low to travel\n");
                }
                break;
            case 6:
                printf("Battery level: %d\n", battery);
                break;
            case 7:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    if (battery == 0)
    {
        printf("Battery empty, simulation over\n");
    }
    else if (distance >= 1000)
    {
        printf("Vehicle reached destination, simulation over\n");
    }

    return 0;
}