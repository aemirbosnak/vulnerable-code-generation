//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_TURN 100
#define MIN_TURN 0
#define MAX_DISTANCE 100
#define MIN_DISTANCE 0
#define MAX_ANGLE 100
#define MIN_ANGLE 0
#define MAX_TIME 1000
#define MIN_TIME 0

int main()
{
    int speed, turn, distance, angle, time;
    int choice;
    char input[10];

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please enter your choice of control mode:\n");
    printf("1. Speed\n2. Turn\n3. Distance\n4. Angle\n5. Time\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Please enter the speed (0-100): ");
            scanf("%d", &speed);
            if(speed >= MIN_SPEED && speed <= MAX_SPEED)
            {
                printf("Vehicle is moving at %d speed.\n", speed);
            }
            else
            {
                printf("Invalid speed input.\n");
            }
            break;

        case 2:
            printf("Please enter the turn (0-100): ");
            scanf("%d", &turn);
            if(turn >= MIN_TURN && turn <= MAX_TURN)
            {
                printf("Vehicle is turning at %d turn.\n", turn);
            }
            else
            {
                printf("Invalid turn input.\n");
            }
            break;

        case 3:
            printf("Please enter the distance (0-100): ");
            scanf("%d", &distance);
            if(distance >= MIN_DISTANCE && distance <= MAX_DISTANCE)
            {
                printf("Vehicle is traveling %d distance.\n", distance);
            }
            else
            {
                printf("Invalid distance input.\n");
            }
            break;

        case 4:
            printf("Please enter the angle (0-100): ");
            scanf("%d", &angle);
            if(angle >= MIN_ANGLE && angle <= MAX_ANGLE)
            {
                printf("Vehicle is turning at %d angle.\n", angle);
            }
            else
            {
                printf("Invalid angle input.\n");
            }
            break;

        case 5:
            printf("Please enter the time (0-1000): ");
            scanf("%d", &time);
            if(time >= MIN_TIME && time <= MAX_TIME)
            {
                printf("Vehicle is running for %d time.\n", time);
            }
            else
            {
                printf("Invalid time input.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}