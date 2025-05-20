//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: light-weight
#include <stdio.h>

int main()
{
    int landing = 1; //initialize landing status to 1
    char command; //initialize command variable
    
    printf("*************DRONE REMOTE CONTROL*************\n");
    printf("Please enter your command:\n");
    printf("'U' to move the drone up\n");
    printf("'D' to move the drone down\n");
    printf("'F' to move the drone forward\n");
    printf("'B' to move the drone backward\n");
    printf("'L' to move the drone left\n");
    printf("'R' to move the drone right\n");
    printf("'S' to take a picture\n");
    printf("'Q' to quit\n");
    
    while(landing) //loop until the drone lands
    {
        scanf(" %c", &command); //read command input
        
        switch(command)
        {
            case 'U':
                printf("Moving drone up\n");
                break;
            case 'D':
                printf("Moving drone down\n");
                break;
            case 'F':
                printf("Moving drone forward\n");
                break;
            case 'B':
                printf("Moving drone backward\n");
                break;
            case 'L':
                printf("Moving drone left\n");
                break;
            case 'R':
                printf("Moving drone right\n");
                break;
            case 'S':
                printf("Taking picture\n");
                break;
            case 'Q':
                printf("Landing drone, quitting program\n");
                landing = 0; //set landing status to 0 to exit loop
                break;
            default:
                printf("Invalid command\n");
        }
    }
    
    return 0;
}