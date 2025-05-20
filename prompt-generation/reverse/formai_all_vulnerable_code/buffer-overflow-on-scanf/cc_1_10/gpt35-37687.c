//FormAI DATASET v1.0 Category: Robot movement control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Grateful Robot Movement Control Example Program

int main()
{
    printf("Hello and welcome to the Grateful Robot Movement Control Example Program!\n");
    printf("Please input your command to move the robot.\n");
    
    char command;
    int x = 0; // x-coordinate of robot
    int y = 0; // y-coordinate of robot

    while(true)
    {
        scanf("%c", &command);
        if(command == '\n')
            continue;

        switch(command)
        {
            case 'U': // move up
                y += 1;
                printf("Robot moved up! Current position: (%d, %d)\n", x, y);
                break;
            case 'D': // move down
                y -= 1;
                printf("Robot moved down! Current position: (%d, %d)\n", x, y);
                break;
            case 'L': // move left
                x -= 1;
                printf("Robot moved left! Current position: (%d, %d)\n", x, y);
                break;
            case 'R': // move right
                x += 1;
                printf("Robot moved right! Current position: (%d, %d)\n", x, y);
                break;
            case 'Q': // quit program
                printf("Thank you for using the Grateful Robot Movement Control Example Program!\n");
                exit(0);
            default:
                printf("Invalid command! Please try again.\n");
                break;
        }
    }

    return 0;
}