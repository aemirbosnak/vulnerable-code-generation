//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'

int main()
{
    char direction;
    int speed, distance, battery = 100;
    int left_motor, right_motor;
    
    printf("*** Remote Control Vehicle Simulation ***\n\n");
    
    while(battery > 0)
    {
        printf("Enter direction (F/B/L/R): ");
        scanf(" %c", &direction);
        
        switch(direction)
        {
            case FORWARD:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                printf("Enter distance (in meters): ");
                scanf("%d", &distance);
                left_motor = right_motor = speed;
                printf("\nMoving FORWARD with %d speed and %d distance.\n\n", speed, distance);
                battery -= distance * speed;
                break;
            
            case BACKWARD:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                printf("Enter distance (in meters): ");
                scanf("%d", &distance);
                left_motor = right_motor = -speed;
                printf("\nMoving BACKWARD with %d speed and %d distance.\n\n", speed, distance);
                battery -= distance * speed;
                break;
            
            case LEFT:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                printf("Enter angle (in degrees): ");
                scanf("%d", &distance);
                left_motor = -speed;
                right_motor = speed;
                printf("\nTurning LEFT with %d speed and %d angle.\n\n", speed, distance);
                battery -= distance * 2;
                break;
            
            case RIGHT:
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                printf("Enter angle (in degrees): ");
                scanf("%d", &distance);
                left_motor = speed;
                right_motor = -speed;
                printf("\nTurning RIGHT with %d speed and %d angle.\n\n", speed, distance);
                battery -= distance * 2;
                break;
            
            default:
                printf("Invalid direction!\n\n");
                break;
        }
    }
    
    printf("Battery level: %d (Out of charge!)\n", battery);
    printf("*** Vehicle Stopped ***\n");
    
    return 0;
}