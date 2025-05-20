//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variables for drone control
    int pitch = 0;
    int roll = 0;
    int yaw = 0;
    int throttle = 0;
    
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Use the following commands to control the drone:\n");
    printf("p: Increase pitch angle by 5 degrees\n");
    printf("P: Decrease pitch angle by 5 degrees\n");
    printf("r: Increase roll angle by 5 degrees\n");
    printf("R: Decrease roll angle by 5 degrees\n");
    printf("y: Increase yaw angle by 5 degrees\n");
    printf("Y: Decrease yaw angle by 5 degrees\n");
    printf("t: Increase throttle by 10 units\n");
    printf("T: Decrease throttle by 10 units\n");
    printf("q: Quit the program\n");
    
    char command; // Variable to store user input
    
    while (command != 'q') {
        printf("Pitch: %d, Roll: %d, Yaw: %d, Throttle: %d\n", pitch, roll, yaw, throttle);
        printf("Enter command: ");
        scanf(" %c", &command);
        
        switch(command) {
            case 'p':
                pitch += 5;
                break;
            case 'P':
                pitch -= 5;
                break;
            case 'r':
                roll += 5;
                break;
            case 'R':
                roll -= 5;
                break;
            case 'y':
                yaw += 5;
                break;
            case 'Y':
                yaw -= 5;
                break;
            case 't':
                throttle += 10;
                break;
            case 'T':
                throttle -= 10;
                break;
            case 'q':
                break;
            default:
                printf("Invalid command. Please try again.\n");
        }
    }
    
    printf("Goodbye!\n");
    
    return 0;
}