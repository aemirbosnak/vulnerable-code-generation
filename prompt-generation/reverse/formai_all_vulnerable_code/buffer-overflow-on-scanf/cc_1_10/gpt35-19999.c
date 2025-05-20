//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 20
#define MAX_TURN_ANGLE 45

int main()
{
    srand(time(NULL));

    int speed, direction, distance, turn_angle, i;
    char commands[] = {'F', 'B', 'L', 'R'};
    char command;

    printf("Enter speed (1-10): ");
    scanf("%d", &speed);

    printf("Enter distance (1-%d): ", MAX_DISTANCE);
    scanf("%d", &distance);

    printf("Enter direction (0-360): ");
    scanf("%d", &direction);

    printf("Enter turn angle (1-%d): ", MAX_TURN_ANGLE);
    scanf("%d", &turn_angle);

    printf("\nStarting simulation...\n");

    for(i=0; i<distance; i++){
        command = commands[rand() % 4];
        switch(command){
            case 'F':
                printf("Moving forward %d units...\n", speed);
                break;
            case 'B':
                printf("Moving backward %d units...\n", speed);
                break;
            case 'L':
                direction -= turn_angle;
                if(direction < 0){
                    direction += 360;
                }
                printf("Turning left %d degrees...\n", turn_angle);
                break;
            case 'R':
                direction += turn_angle;
                if(direction >= 360){
                    direction -= 360;
                }
                printf("Turning right %d degrees...\n", turn_angle);
                break;
        }
    }

    printf("\nSimulation complete. Final direction: %d\n", direction);

    return 0;
}