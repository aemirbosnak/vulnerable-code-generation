//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initializing all variables
    int throttle, pitch, roll, yaw;
    char input;

    // Welcoming the user to the program
    printf("Welcome to the 'Drone Party Control Center'! \n");
    printf("Please use the following keys to control the drone: \n");
    printf(" - 't' increases throttle, 'T' decreases throttle; \n");
    printf(" - 'p' makes the drone lean forwards, 'P' makes it lean backwards; \n");
    printf(" - 'r' makes the drone roll to the right, 'R' makes it roll to the left; \n");
    printf(" - 'y' makes the drone turn clockwise, 'Y' makes it turn counter-clockwise. \n");

    // Starting up the drone
    printf("\n\nStarting up drone...\n");

    // Setting the starting position and throttle
    throttle = 50; pitch = 0; roll = 0; yaw = 0;

    // Keeping the program running until user exits
    while(1) {
        // Printing the current status of the drone
        printf("Drone status: Throttle: %d, Pitch: %d, Roll: %d, Yaw: %d \n", throttle, pitch, roll, yaw);

        // Getting user input
        printf("Please enter a command: ");
        scanf(" %c", &input);

        // Executing commands based on user input
        switch(input) {
            case 't':
                throttle += 10;
                printf("Throttle increased to %d.\n", throttle);
                break;
            case 'T':
                throttle -= 10;
                printf("Throttle decreased to %d.\n", throttle);
                break;
            case 'p':
                pitch += 10;
                printf("Drone leaning forwards! Pitch increased to %d.\n", pitch);
                break;
            case 'P':
                pitch -= 10;
                printf("Drone leaning backwards! Pitch decreased to %d.\n", pitch);
                break;
            case 'r':
                roll += 10;
                printf("Drone rolling to the right! Roll increased to %d.\n", roll);
                break;
            case 'R':
                roll -= 10;
                printf("Drone rolling to the left! Roll decreased to %d.\n", roll);
                break;
            case 'y':
                yaw += 10;
                printf("Drone turning clockwise! Yaw increased to %d.\n", yaw);
                break;
            case 'Y':
                yaw -= 10;
                printf("Drone turning counter-clockwise! Yaw decreased to %d.\n", yaw);
                break;
            default:
                printf("Invalid command entered. Try again.\n");
                break;
        }

        // Checking if the drone hit something or ran out of battery
        if(pitch < -50 || pitch > 50 || roll < -50 || roll > 50 || yaw < -50 || yaw > 50) {
            printf("Drone crashed! You owe me a new one.\n");
            break;
        }
        else if(throttle <= 0) {
            printf("Drone ran out of battery and crashed! That's going to hurt...\n");
            break;
        }
    }

    printf("Thanks for choosing Drone Party Control Center! Goodbye!\n");
    return 0;
}