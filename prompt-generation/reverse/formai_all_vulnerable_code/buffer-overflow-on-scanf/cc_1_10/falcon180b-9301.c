//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SPEED 100
#define MIN_SPEED 50
#define TURN_RADIUS 50

int main()
{
    int choice, speed = 0, turn = 0;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please choose an option:\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Stop\n");
    scanf("%d", &choice);

    while(choice!= 4)
    {
        switch(choice)
        {
            case 1:
                speed = MAX_SPEED;
                break;
            case 2:
                turn = -TURN_RADIUS;
                break;
            case 3:
                turn = TURN_RADIUS;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("The vehicle is moving at %d units/second and turning at %d degrees.\n", speed, turn);

        if(speed > MIN_SPEED)
        {
            printf("The vehicle is moving fast!\n");
        }
        else if(speed < MIN_SPEED)
        {
            printf("The vehicle is moving slow.\n");
        }

        if(turn > 0)
        {
            printf("The vehicle is turning right.\n");
        }
        else if(turn < 0)
        {
            printf("The vehicle is turning left.\n");
        }

        printf("Press any key to continue...\n");
        getchar();

        choice = 4;
    }

    printf("The vehicle has stopped.\n");

    return 0;
}