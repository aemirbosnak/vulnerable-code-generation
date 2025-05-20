//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //set random seed based on current time

    printf("Welcome to the Remote Control Vehicle Simulation!\n");

    //initialize variables
    int obstacleDistance;
    int batteryLife = 100;
    int position = 0;
    int distance = 0;
    char command;
    int count = 0;

    //print initial status
    printf("Battery life: %d\n", batteryLife);
    printf("Position: %d\n", position);
    printf("Distance travelled: %d\n", distance);

    while(batteryLife > 0)
    {
        printf("Enter command (F/B/L/R): ");
        scanf(" %c", &command); //get user input
        
        obstacleDistance = rand() % 11; //generate random obstacle distance between 0-10
        
        switch(command)
        {
            case 'F':
                if(obstacleDistance > 2) //check for obstacle within 2 meters
                {
                    printf("Moving forward...\n");
                    position++;
                    distance++;
                    count++;
                    if(count == 5) //every 5 moves, battery life decreases by 1
                    {
                        batteryLife--;
                        count = 0;
                    }
                }
                else
                {
                    printf("Obstacle detected, cannot move forward.\n");
                }
                break;
            case 'B':
                printf("Moving backward...\n");
                position--;
                distance++;
                count++;
                if(count == 5)
                {
                    batteryLife--;
                    count = 0;
                }
                break;
            case 'L':
                printf("Turning left...\n");
                position-=2;
                distance++;
                count++;
                if(count == 5)
                {
                    batteryLife--;
                    count = 0;
                }
                break;
            case 'R':
                printf("Turning right...\n");
                position+=2;
                distance++;
                count++;
                if(count == 5)
                {
                    batteryLife--;
                    count = 0;
                }
                break;
            default:
                printf("Invalid command, please try again.\n");
                break;
        }

        if(batteryLife == 0) //if battery life reaches 0, exit loop
        {
            break;
        }

        printf("Battery life: %d\n", batteryLife);
        printf("Position: %d\n", position);
        printf("Distance travelled: %d\n", distance);
    }

    printf("Game over. Battery life: %d, Distance travelled: %d\n", batteryLife, distance);

    return 0;
}