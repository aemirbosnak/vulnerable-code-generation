//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define Drone Control Variables
int throttle = 0;
int pitch = 0;
int roll = 0;
int yaw = 0;
int altitude = 0;

// Function to Print Drone Status
void printStatus() {
    printf("Drone Status:\n");
    printf("  Throttle: %d\n", throttle);
    printf("  Pitch: %d\n", pitch);
    printf("  Roll: %d\n", roll);
    printf("  Yaw: %d\n", yaw);
    printf("  Altitude: %d\n", altitude);
}

// Function to Control Drone Throttle
void setThrottle(int newThrottle) {
    throttle = newThrottle;
    printf("Throttle set to %d\n", throttle);
}

// Function to Control Drone Pitch
void setPitch(int newPitch) {
    pitch = newPitch;
    printf("Pitch set to %d\n", pitch);
}

// Function to Control Drone Roll
void setRoll(int newRoll) {
    roll = newRoll;
    printf("Roll set to %d\n", roll);
}

// Function to Control Drone Yaw
void setYaw(int newYaw) {
    yaw = newYaw;
    printf("Yaw set to %d\n", yaw);
}

// Function to Control Drone Altitude
void setAltitude(int newAltitude) {
    altitude = newAltitude;
    printf("Altitude set to %d\n", altitude);
}

int main() {
    // Welcome Message
    printf("Welcome to the Drone Control Program!\n");

    // Initial Drone Status
    printStatus();

    // Drone Control Loop
    while(1) {
        // Get User Input
        printf("Enter Command: ");
        char command;
        scanf("%c", &command);

        // Process User Input
        switch(command) {
            case 't':
                // Increase Throttle
                if(throttle < 100) {
                    setThrottle(throttle + 1);
                }
                else {
                    printf("Throttle at maximum!\n");
                }
                break;
            case 'g':
                // Decrease Throttle
                if(throttle > 0) {
                    setThrottle(throttle - 1);
                }
                else {
                    printf("Throttle at minimum!\n");
                }
                break;
            case 'p':
                // Increase Pitch
                if(pitch < 180) {
                    setPitch(pitch + 10);
                }
                else {
                    printf("Pitch at maximum!\n");
                }
                break;
            case 'l':
                // Decrease Pitch
                if(pitch > -180) {
                    setPitch(pitch - 10);
                }
                else {
                    printf("Pitch at minimum!\n");
                }
                break;
            case 'r':
                // Increase Roll
                if(roll < 180) {
                    setRoll(roll + 10);
                }
                else {
                    printf("Roll at maximum!\n");
                }
                break;
            case 'f':
                // Decrease Roll
                if(roll > -180) {
                    setRoll(roll - 10);
                }
                else {
                    printf("Roll at minimum!\n");
                }
                break;
            case 'y':
                // Increase Yaw
                if(yaw < 180) {
                    setYaw(yaw + 10);
                }
                else {
                    printf("Yaw at maximum!\n");
                }
                break;
            case 'h':
                // Decrease Yaw
                if(yaw > -180) {
                    setYaw(yaw - 10);
                }
                else {
                    printf("Yaw at minimum!\n");
                }
                break;
            case 'u':
                // Increase Altitude
                if(altitude < 100) {
                    setAltitude(altitude + 1);
                }
                else {
                    printf("Altitude at maximum!\n");
                }
                break;
            case 'd':
                // Decrease Altitude
                if(altitude > 0) {
                    setAltitude(altitude - 1);
                }
                else {
                    printf("Altitude at minimum!\n");
                }
                break;
            case 'q':
                // Quit Program
                printf("Exiting Drone Control Program...\n");
                return 0;
            default:
                // Invalid Command
                printf("Invalid Command!\n");
        }

        // Delay for 500ms
        usleep(500000);

        // Clear Screen
        system("clear");

        // Print Drone Status
        printStatus();
    }
}