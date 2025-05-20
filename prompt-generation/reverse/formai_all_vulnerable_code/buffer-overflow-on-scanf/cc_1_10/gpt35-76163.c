//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multivariable
#include <stdio.h>

// function to move the vehicle
void move(int* x, int* y, char direction)
{
    switch(direction)
    {
        case 'U': // move up
            (*y)++;
            break;
        case 'D': // move down
            (*y)--;
            break;
        case 'R': // move right
            (*x)++;
            break;
        case 'L': // move left
            (*x)--;
            break;
        default:
            printf("Invalid direction\n");
    }
}

int main()
{
    int x = 0, y = 0; // starting position
    char command[100]; // to store the user's command
    
    // print instructions
    printf("Welcome to the remote control vehicle simulation!\n");
    printf("Use the following commands to move the vehicle:\n");
    printf("'U' to move up\n");
    printf("'D' to move down\n");
    printf("'R' to move right\n");
    printf("'L' to move left\n");
    
    // loop until the user enters 'X' to exit
    while(1)
    {
        printf("Enter your command (or 'X' to exit): ");
        scanf(" %s", command);
        
        if(command[0] == 'X') // check if user wants to exit
        {
            printf("Exiting...\n");
            break;
        }
        
        // loop through each character of the command and move the vehicle accordingly
        for(int i=0; command[i]!='\0'; i++)
        {
            move(&x, &y, command[i]);
        }
        
        // print the final position of the vehicle
        printf("Final position: (%d, %d)\n", x, y);
    }
    
    return 0;
}