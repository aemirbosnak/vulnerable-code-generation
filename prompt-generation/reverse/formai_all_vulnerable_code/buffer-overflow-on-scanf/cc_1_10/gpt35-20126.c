//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program simulates a remote control vehicle through user input commands */

int main() {
    int x = 0, y = 0; // starting position of the vehicle
    int speed = 2; // default speed of the vehicle
    char input[20]; // stores user input commands
    
    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("Your vehicle is currently located at (%d, %d).\n", x, y);

    while (1) { // loop to continually prompt for user input
        
        printf("\nEnter a command (up, down, left, right, speed, exit): ");
        fgets(input, 20, stdin); // read in user input
        
        if (strcmp(input, "up\n") == 0) { // move vehicle up
            y += speed;
            printf("Vehicle moved up to (%d, %d).\n", x, y);
        }
        else if (strcmp(input, "down\n") == 0) { // move vehicle down
            y -= speed;
            printf("Vehicle moved down to (%d, %d).\n", x, y);
        }
        else if (strcmp(input, "left\n") == 0) { // move vehicle left
            x -= speed;
            printf("Vehicle moved left to (%d, %d).\n", x, y);
        }
        else if (strcmp(input, "right\n") == 0) { // move vehicle right
            x += speed;
            printf("Vehicle moved right to (%d, %d).\n", x, y);
        }
        else if (strcmp(input, "speed\n") == 0) { // change speed of vehicle
            printf("Enter the new speed of the vehicle: ");
            scanf("%d", &speed);
            getchar(); // discard newline character
            printf("Vehicle speed set to %d.\n", speed);
        }
        else if (strcmp(input, "exit\n") == 0) { // exit program
            printf("Exiting Remote Control Vehicle Simulator...\n");
            break;
        }
        else { // invalid input
            printf("Invalid command.\n");
        }
    }

    return 0;
}