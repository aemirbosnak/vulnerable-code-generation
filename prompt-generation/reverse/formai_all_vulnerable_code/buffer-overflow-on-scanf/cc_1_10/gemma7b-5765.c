//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int choice, direction, speed, distance;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please select an option:\n");
    printf("1. Forward\n");
    printf("2. Backward\n");
    printf("3. Left\n");
    printf("4. Right\n");
    printf("5. Stop\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            direction = 1;
            speed = rand() % 5 + 1;
            distance = rand() % 10 + 1;
            printf("The vehicle is moving forward with speed %d and distance %d.\n", speed, distance);
            break;
        case 2:
            direction = -1;
            speed = rand() % 5 + 1;
            distance = rand() % 10 + 1;
            printf("The vehicle is moving backward with speed %d and distance %d.\n", speed, distance);
            break;
        case 3:
            direction = -2;
            speed = rand() % 5 + 1;
            distance = rand() % 10 + 1;
            printf("The vehicle is moving left with speed %d and distance %d.\n", speed, distance);
            break;
        case 4:
            direction = 2;
            speed = rand() % 5 + 1;
            distance = rand() % 10 + 1;
            printf("The vehicle is moving right with speed %d and distance %d.\n", speed, distance);
            break;
        case 5:
            direction = 0;
            speed = 0;
            distance = 0;
            printf("The vehicle is stopped.\n");
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}