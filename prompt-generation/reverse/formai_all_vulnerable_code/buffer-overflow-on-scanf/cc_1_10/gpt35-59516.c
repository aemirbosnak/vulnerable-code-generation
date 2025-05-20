//FormAI DATASET v1.0 Category: Robot movement control ; Style: Alan Touring
#include <stdio.h>

int main()
{
    int x = 0, y = 0, z = 0;
    char command;
    
    printf("Welcome to the robot movement control system!\n");
    printf("Enter 'f' to move forward, 'b' to move backward, 'l' to turn left, 'r' to turn right, and 's' to stop\n");
    
    while(1)
    {
        printf("Enter command: ");
        scanf(" %c", &command);
        
        switch(command)
        {
            case 'f':
                printf("Moving forward...\n");
                x++;
                break;
                
            case 'b':
                printf("Moving backward...\n");
                x--;
                break;
                
            case 'l':
                printf("Turning left...\n");
                z--;
                break;
                
            case 'r':
                printf("Turning right...\n");
                z++;
                break;
                
            case 's':
                printf("Stopped.\n");
                break;
                
            default:
                printf("Invalid command.\n");
                break;
        }
        
        // Display current position
        printf("Current position: (%d, %d, %d)\n", x, y, z);
    }
    
    return 0;
}