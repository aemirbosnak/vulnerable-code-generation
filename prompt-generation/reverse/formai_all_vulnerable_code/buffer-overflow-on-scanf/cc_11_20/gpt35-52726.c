//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Welcome message
    printf("Hello there! Let's control your drone!\n");
    
    // Initialize the drone and remote control
    int drone_bat = rand() % 100 + 1;
    int remote_bat = 100;
    
    // Display current battery levels
    printf("Drone battery level: %d%%\n", drone_bat);
    printf("Remote control battery level: %d%%\n\n", remote_bat);
    
    // Take user input to control the drone
    char user_input;
    while(1){
        printf("Enter 'U' to move the drone up, 'D' to move it down, 'L' to move it left, 'R' to move it right, 'C' to land the drone, and 'Q' to quit: ");
        scanf(" %c", &user_input);
        
        // Move the drone based on user input
        switch(user_input){
            case 'U':
                printf("Moving drone up...\n");
                drone_bat -= 5;
                break;
            case 'D':
                printf("Moving drone down...\n");
                drone_bat -= 5;
                break;
            case 'L':
                printf("Moving drone left...\n");
                drone_bat -= 5;
                break;
            case 'R':
                printf("Moving drone right...\n");
                drone_bat -= 5;
                break;
            case 'C':
                printf("Landing drone...\n");
                drone_bat -= 10;
                break;
            case 'Q':
                printf("Quitting program...\n");
                exit(0);
            default:
                printf("Invalid input. Try again!\n");
        }
        
        // Check if the drone or remote battery is low and display a warning message
        if(drone_bat <= 20){
            printf("Warning: Drone battery level is low! (%d%%)\n", drone_bat);
        }
        if(remote_bat <= 20){
            printf("Warning: Remote control battery level is low! (%d%%)\n", remote_bat);
        }
        
        // Update the battery levels
        drone_bat = drone_bat < 0 ? 0 : drone_bat;
        remote_bat -= 1;
        printf("Drone battery level: %d%%\n", drone_bat);
        printf("Remote control battery level: %d%%\n\n", remote_bat);
        
        // Check if the remote battery is dead and end the program
        if(remote_bat == 0){
            printf("Remote control battery is dead! Ending program...\n");
            exit(0);
        }
    }
    
    return 0;
}