//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: realistic
// This program simulates a basic remote control for a drone which can move and capture images
// The drone is connected to the remote control on a Wi-Fi network

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[50];
    int x_pos = 0, y_pos = 0;

    printf("Welcome to the drone remote control!\n");
    printf("Enter 'exit' to quit the program.\n");

    while(1)
    {
        printf("Enter a command (up, down, left, right, capture): ");
        fgets(command, 50, stdin);

        // Remove trailing newline character
        command[strlen(command)-1] = '\0';

        if(strcmp(command, "up") == 0)
        {
            // Move drone up
            y_pos++;
            printf("Drone moved up. Current position: (%d, %d)\n", x_pos, y_pos);
        }
        else if(strcmp(command, "down") == 0)
        {
            // Move drone down
            y_pos--;
            printf("Drone moved down. Current position: (%d, %d)\n", x_pos, y_pos);
        }
        else if(strcmp(command, "left") == 0)
        {
            // Move drone left
            x_pos--;
            printf("Drone moved left. Current position: (%d, %d)\n", x_pos, y_pos);
        }
        else if(strcmp(command, "right") == 0)
        {
            // Move drone right
            x_pos++;
            printf("Drone moved right. Current position: (%d, %d)\n", x_pos, y_pos);
        }
        else if(strcmp(command, "capture") == 0)
        {
            // Capture an image
            printf("Image captured at position: (%d, %d)\n", x_pos, y_pos);
        }
        else if(strcmp(command, "exit") == 0)
        {
            // Exit program
            printf("Exiting program...\n");
            break;
        }
        else
        {
            // Invalid command
            printf("Invalid command. Please enter a valid command (up, down, left, right, capture).\n");
        }
    }
    
    return 0;
}