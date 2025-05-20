//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int battery_level = 100;
    int altitude = 0;
    int pitch = 0;
    int roll = 0;
    int yaw = 0;
    char command = ' ';
    
    printf("Welcome to the C Drone Remote Control Interface!\n");
    
    while(command != 'q' && battery_level > 0)
    {
        // Display drone information
        printf("\nBattery Level: %d%\n", battery_level);
        printf("Current Altitude: %d meters\n", altitude);
        printf("Current Pitch: %d degrees\n", pitch);
        printf("Current Roll: %d degrees\n", roll);
        printf("Current Yaw: %d degrees\n", yaw);
        
        // Prompt user for input
        printf("\nEnter a command (u/d/f/b/l/r/c/q): ");
        scanf(" %c", &command);
        
        // Process user input
        switch(command)
        {
            case 'u':
                altitude += 10;
                break;
            case 'd':
                altitude -= 10;
                break;
            case 'f':
                pitch += 5;
                break;
            case 'b':
                pitch -= 5;
                break;
            case 'l':
                roll -= 5;
                break;
            case 'r':
                roll += 5;
                break;
            case 'c':
                printf("Calibrating...\n");
                pitch = 0;
                roll = 0;
                yaw = 0;
                break;
            case 'q':
                printf("Shutting down.\n");
                break;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }
        
        // Update battery level
        battery_level -= 1;
    }
    
    // Check if battery is empty
    if(battery_level == 0)
    {
        printf("\nThe battery is empty. Returning to home base.\n");
    }
    
    return 0;
}