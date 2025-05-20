//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int command;
    int upDown = 0;
    int leftRight = 0;
    int forwardBackward = 0;
    
    printf("Welcome to our C Drone Remote Control Program!\n");
    
    //start loop for controlling drone
    while(1) {
        printf("Enter a command:\n");
        printf("1 - Move up\n2 - Move down\n3 - Move left\n4 - Move right\n5 - Move forward\n6 - Move backward\n7 - Hover\n8 - Exit program\n");
        scanf("%d",&command);
        
        switch(command) {
            case 1:
                printf("Moving up...\n");
                upDown++;
                break;
            case 2:
                printf("Moving down...\n");
                upDown--;
                break;
            case 3:
                printf("Moving left...\n");
                leftRight--;
                break;
            case 4:
                printf("Moving right...\n");
                leftRight++;
                break;
            case 5:
                printf("Moving forward...\n");
                forwardBackward++;
                break;
            case 6:
                printf("Moving backward...\n");
                forwardBackward--;
                break;
            case 7:
                printf("Hovering in place...\n");
                break;
            case 8:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid command entered. Please enter a valid command.\n");
                break;
        }
        
        printf("Current drone position:\n");
        printf("Up/Down: %d\n",upDown);
        printf("Left/Right: %d\n",leftRight);
        printf("Forward/Backward: %d\n",forwardBackward);
    }
    
    return 0;
}