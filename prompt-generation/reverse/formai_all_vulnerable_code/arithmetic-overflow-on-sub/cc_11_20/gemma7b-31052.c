//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

int main()
{
    int speed = 0;
    int direction = 0;
    char command = ' ';

    printf("Welcome to 221B Baker Street, Mr. Holmes.\n");
    printf("Please enter a command (forward, back, left, right, stop): ");

    scanf("%c", &command);

    switch (command)
    {
        case 'f':
            speed = MAX_SPEED;
            direction = 1;
            break;
        case 'b':
            speed = MAX_SPEED;
            direction = -1;
            break;
        case 'l':
            speed = MAX_SPEED;
            direction = -2;
            break;
        case 'r':
            speed = MAX_SPEED;
            direction = 2;
            break;
        case 's':
            speed = 0;
            direction = 0;
            break;
        default:
            printf("Invalid command.\n");
            break;
    }

    time_t start_time = time(NULL);

    while (speed > 0)
    {
        int elapsed_time = time(NULL) - start_time;

        switch (direction)
        {
            case 1:
                printf("The vehicle is moving forward at a speed of %d km/h.\n", speed);
                break;
            case -1:
                printf("The vehicle is moving back at a speed of %d km/h.\n", speed);
                break;
            case -2:
                printf("The vehicle is moving left at a speed of %d km/h.\n", speed);
                break;
            case 2:
                printf("The vehicle is moving right at a speed of %d km/h.\n", speed);
                break;
        }

        sleep(elapsed_time);

        speed -= 1;
        start_time = time(NULL);
    }

    printf("The vehicle has stopped.\n");

    return 0;
}