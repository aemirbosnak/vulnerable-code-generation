//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int direction = 0;
    int speed = 0;
    char key;

    printf("Welcome to the Wild Ride Simulator!\n");
    printf("Press 'w' to go forward, 'a' to turn left, 's' to go back, 'd' to turn right, and 'q' to quit.\n");

    while (key != 'q')
    {
        scanf(" %c", &key);

        switch (key)
        {
            case 'w':
                direction = 1;
                speed = 5;
                break;
            case 'a':
                direction = 2;
                speed = 3;
                break;
            case 's':
                direction = 3;
                speed = 5;
                break;
            case 'd':
                direction = 4;
                speed = 3;
                break;
            case 'q':
                printf("Thank you for riding with us! See you next time.\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        switch (direction)
        {
            case 1:
                printf("The vehicle is going forward at %d miles per hour.\n", speed);
                break;
            case 2:
                printf("The vehicle is turning left at %d miles per hour.\n", speed);
                break;
            case 3:
                printf("The vehicle is going back at %d miles per hour.\n", speed);
                break;
            case 4:
                printf("The vehicle is turning right at %d miles per hour.\n", speed);
                break;
        }
    }

    return 0;
}