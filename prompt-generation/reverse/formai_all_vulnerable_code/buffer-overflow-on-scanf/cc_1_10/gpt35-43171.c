//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISTANCE 100 // Maximum distance the drone can fly

// Enum to represent the possible commands
typedef enum {
    TAKE_OFF,
    LAND,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_FORWARD,
    MOVE_BACKWARD,
    MOVE_LEFT,
    MOVE_RIGHT
} Command;

// Function to handle the user input and execute the command
void executeCommand(Command command, int distance)
{
    switch (command)
    {
        case TAKE_OFF:
            printf("Drone taking off!\n");
            break;
        case LAND:
            printf("Drone landing!\n");
            break;
        case MOVE_UP:
            printf("Drone moving up %d meters!\n", distance);
            break;
        case MOVE_DOWN:
            printf("Drone moving down %d meters!\n", distance);
            break;
        case MOVE_FORWARD:
            printf("Drone moving forward %d meters!\n", distance);
            break;
        case MOVE_BACKWARD:
            printf("Drone moving backward %d meters!\n", distance);
            break;
        case MOVE_LEFT:
            printf("Drone moving left %d meters!\n", distance);
            break;
        case MOVE_RIGHT:
            printf("Drone moving right %d meters!\n", distance);
            break;
        default:
            printf("Invalid command!\n");
            break;
    }
}

// Function to check if the drone is within the maximum distance limit
bool isWithinDistanceLimit(int distance)
{
    return distance <= MAX_DISTANCE;
}

int main()
{
    int distance; // Distance to move
    Command command; // User command

    // Prompt the user to enter the command and distance
    printf("Enter the command:\n");
    printf("0 - Take off\n1 - Land\n2 - Move up\n3 - Move down\n4 - Move forward\n5 - Move backward\n6 - Move left\n7 - Move right\n");
    scanf("%d", &command);
    printf("Enter the distance: ");
    scanf("%d", &distance);

    // Check if the drone is within the maximum distance limit
    if (!isWithinDistanceLimit(distance))
    {
        printf("Drone cannot travel that far!\n");
        return 1;
    }

    // Execute the command 
    executeCommand(command, distance);
    
    return 0;
}