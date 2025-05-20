//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_RANGE 100 // maximum range of drone flight

// function prototype
void moveDrone(int x, int y);

int main()
{
    int x, y; // variables to store drone's position
    
    printf("Welcome to Drone Remote Control\n\n");
    printf("Please enter the starting position of the drone:\nX: ");
    scanf("%d", &x); // read x position from user
    printf("Y: ");
    scanf("%d", &y); // read y position from user
    
    printf("\nDrone is currently at position (%d, %d)\n\n", x, y);
    
    // loop to take input from user and move drone
    while (1)
    {
        char command;
        int distance;
        
        printf("Enter command (F/B/L/R) and distance (in meters), separated by a space (0 0 to exit):\n");
        scanf(" %c %d", &command, &distance);
        
        if (command == '0' && distance == 0)
        {
            printf("\nExiting Drone Remote Control...\n");
            break;
        }
        
        switch (command)
        {
            case 'F':
                if (y + distance > MAX_RANGE)
                {
                    printf("\nError: Drone is out of range.\n");
                }
                else
                {
                    printf("\nMoving drone forward by %d meters...\n", distance);
                    moveDrone(x, y + distance);
                    y += distance;
                }
                break;
                
            case 'B':
                if (y - distance < 0)
                {
                    printf("\nError: Drone is out of range.\n");
                }
                else
                {
                    printf("\nMoving drone backward by %d meters...\n", distance);
                    moveDrone(x, y - distance);
                    y -= distance;
                }
                break;
                
            case 'L':
                if (x - distance < 0)
                {
                    printf("\nError: Drone is out of range.\n");
                }
                else
                {
                    printf("\nMoving drone left by %d meters...\n", distance);
                    moveDrone(x - distance, y);
                    x -= distance;
                }
                break;
                
            case 'R':
                if (x + distance > MAX_RANGE)
                {
                    printf("\nError: Drone is out of range.\n");
                }
                else
                {
                    printf("\nMoving drone right by %d meters...\n", distance);
                    moveDrone(x + distance, y);
                    x += distance;
                }
                break;
                
            default:
                printf("\nError: Invalid command.\n");
                break;
        }
        
        printf("\nDrone is currently at position (%d, %d)\n\n", x, y);
    }
    
    return 0;
}

void moveDrone(int x, int y)
{
    // function to move drone to new position
    printf("Drone moved to position (%d, %d)\n", x, y);
}