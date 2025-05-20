//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global constants
#define MAX_DISTANCE 1000
#define MAX_SPEED 100
#define MAX_COMMANDS 10

// Global variables
int batteryLevel = 100;   // Percentage of battery level remaining
int distanceTravelled = 0;   // Distance travelled by vehicle
int speed = 0;   // Speed of vehicle
int signalStrength = 100;   // Strength of signal
char commandList[MAX_COMMANDS][50];   // List of commands entered by the user

// Function to display the battery level
void displayBatteryLevel() {
    printf("Battery level: %d%%\n", batteryLevel);
    if (batteryLevel < 20) {
        printf("Low battery! Please return to base.\n");
    }
}

// Function to display the distance travelled
void displayDistanceTravelled() {
    printf("Distance travelled: %d meters\n", distanceTravelled);
    if (distanceTravelled > MAX_DISTANCE) {
        printf("Maximum distance reached! Please return to base.\n");
    }
}

// Function to display the speed
void displaySpeed() {
    printf("Current speed: %d km/hr\n", speed);
    if (speed > MAX_SPEED) {
        printf("Maximum speed reached! Please slow down.\n");
    }
}

// Function to display the signal strength
void displaySignalStrength() {
    printf("Signal strength: %d%%\n", signalStrength);
    if (signalStrength < 50) {
        printf("Weak signal! Please return to base.\n");
    }
}

// Function to display the list of commands entered by the user
void displayCommandList() {
    printf("List of commands entered:\n");
    for (int i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(commandList[i], "") != 0) {
            printf("%s\n", commandList[i]);
        }
    }
}

int main() {
    printf("Welcome to Remote Control Vehicle Simulation!\n");
    printf("Enter your commands below:\n");
    
    // A paranoid coder's nightmare - every command is verified multiple times
    char command[50];
    while (1) {
        scanf("%s", command);
        
        // Verify command inputs
        if (strcmp(command, "forward") == 0) {
            // Verify the battery level before executing command
            if (batteryLevel < 10) {
                printf("Error: Not enough battery! Please return to base.\n");
            } else if (speed < 80) {
                printf("Error: Speed too slow! Please accelerate to at least 80 km/hr.\n");
            } else if (distanceTravelled > MAX_DISTANCE) {
                printf("Error: Maximum distance reached! Please return to base.\n");
            } else {
                printf("Moving forward...\n");
                batteryLevel -= 10;
                distanceTravelled += 50;
                signalStrength -= 5;
                displayBatteryLevel();
                displayDistanceTravelled();
                displaySignalStrength();
                strcpy(commandList[MAX_COMMANDS - 1], command);
            }
        } else if (strcmp(command, "reverse") == 0) {
            // Verify the battery level before executing command
            if (batteryLevel < 10) {
                printf("Error: Not enough battery! Please return to base.\n");
            } else {
                printf("Moving in reverse...\n");
                batteryLevel -= 5;
                distanceTravelled -= 25;
                signalStrength -= 2;
                displayBatteryLevel();
                displayDistanceTravelled();
                displaySignalStrength();
                strcpy(commandList[MAX_COMMANDS - 1], command);
            }
        } else if (strcmp(command, "accelerate") == 0) {
            // Verify the battery level before executing command
            if (batteryLevel < 5) {
                printf("Error: Not enough battery! Please return to base.\n");
            } else if (speed == MAX_SPEED) {
                printf("Error: Maximum speed reached! Please slow down.\n");
            } else {
                printf("Accelerating...\n");
                batteryLevel -= 5;
                speed += 10;
                signalStrength -= 2;
                displayBatteryLevel();
                displaySpeed();
                displaySignalStrength();
                strcpy(commandList[MAX_COMMANDS - 1], command);
            }
        } else if (strcmp(command, "decelerate") == 0) {
            // Verify the battery level before executing command
            if (batteryLevel < 5) {
                printf("Error: Not enough battery! Please return to base.\n");
            } else {
                printf("Decelerating...\n");
                batteryLevel -= 5;
                speed -= 10;
                signalStrength -= 2;
                displayBatteryLevel();
                displaySpeed();
                displaySignalStrength();
                strcpy(commandList[MAX_COMMANDS - 1], command);
            }
        } else if (strcmp(command, "stop") == 0) {
            printf("Stopping vehicle...\n");
            speed = 0;
            displaySpeed();
            strcpy(commandList[MAX_COMMANDS - 1], command);
        } else if (strcmp(command, "status") == 0) {
            printf("Vehicle status:\n");
            displayBatteryLevel();
            displayDistanceTravelled();
            displaySpeed();
            displaySignalStrength();
            displayCommandList();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting vehicle simulation...\n");
            return 0;
        } else {
            printf("Error: Invalid command!\n");
        }
    }
    return 0;
}