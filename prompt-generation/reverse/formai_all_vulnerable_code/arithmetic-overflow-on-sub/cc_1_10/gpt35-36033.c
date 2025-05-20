//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
#include <stdio.h>

//define constants for drone movements
#define FORWARD 1
#define BACKWARD -1
#define UP 1
#define DOWN -1
#define LEFT -1
#define RIGHT 1

//function to move the drone forward or backward
void moveForwardOrBackward(int direction)
{
    if (direction == FORWARD)
        printf("Drone moving forward.\n");
    else if (direction == BACKWARD)
        printf("Drone moving backward.\n");
    else
        printf("Invalid direction.\n");
}

//function to move the drone up or down
void moveUpOrDown(int direction)
{
    if (direction == UP)
        printf("Drone moving up.\n");
    else if (direction == DOWN)
        printf("Drone moving down.\n");
    else
        printf("Invalid direction.\n");
}

//function to move the drone left or right
void moveLeftOrRight(int direction)
{
    if (direction == LEFT)
        printf("Drone moving left.\n");
    else if (direction == RIGHT)
        printf("Drone moving right.\n");
    else
        printf("Invalid direction.\n");
}

int main()
{
    //variables to hold drone's current position
    int x = 0; //left-right position
    int y = 0; //back-forth position
    int z = 0; //up-down position
    
    //variables to hold user's input
    char input;
    int distance;
    
    printf("Welcome to the C Drone Remote Control Program.\n");
    
    //infinite loop to get user's input and move drone accordingly
    while(1)
    {
        //print current position of the drone
        printf("Current position: (%d, %d, %d)\n", x, y, z);
        
        //ask for user's input
        printf("Enter a command: ");
        scanf(" %c", &input);
        
        //move the drone accordingly
        switch(input)
        {
            case 'f':
                printf("Enter distance to move forward: ");
                scanf("%d", &distance);
                y += distance;
                moveForwardOrBackward(FORWARD);
                break;
            case 'b':
                printf("Enter distance to move backward: ");
                scanf("%d", &distance);
                y -= distance;
                moveForwardOrBackward(BACKWARD);
                break;
            case 'u':
                printf("Enter distance to move up: ");
                scanf("%d", &distance);
                z += distance;
                moveUpOrDown(UP);
                break;
            case 'd':
                printf("Enter distance to move down: ");
                scanf("%d", &distance);
                z -= distance;
                moveUpOrDown(DOWN);
                break;
            case 'l':
                printf("Enter distance to move left: ");
                scanf("%d", &distance);
                x += distance;
                moveLeftOrRight(LEFT);
                break;
            case 'r':
                printf("Enter distance to move right: ");
                scanf("%d", &distance);
                x -= distance;
                moveLeftOrRight(RIGHT);
                break;
            case 'q':
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid command.\n");
        }
    }
    
    return 0;
}