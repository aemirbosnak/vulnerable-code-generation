//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Initialize variables for drone status and GPS location
bool isArmed = false;
bool isFlying = false;
int latitude = 0;
int longitude = 0;

// Function to arm the drone
void armDrone() {
    if (!isArmed) {
        isArmed = true;
        printf("Drone armed and ready!\n");
    } else {
        printf("Drone is already armed.\n");
    }
}

// Function to disarm the drone
void disarmDrone() {
    if (isArmed && !isFlying) {
        isArmed = false;
        printf("Drone disarmed.\n");
    } else if (isFlying) {
        printf("Cannot disarm drone while it is in flight.\n");
    } else {
        printf("Drone is already disarmed.\n");
    }
}

// Function to take off
void takeOff() {
    if (isArmed && !isFlying) {
        isFlying = true;
        printf("Drone taking off!\n");
    } else if (!isArmed) {
        printf("Cannot take off without arming the drone.\n");
    } else {
        printf("Drone is already in flight.\n");
    }
}

// Function to land the drone
void land() {
    if (isFlying) {
        isFlying = false;
        printf("Drone landing.\n");
    } else {
        printf("Drone is not in flight.\n");
    }
}

// Function to update GPS location
void updateLocation(char* location) {
    char* token;
    int count = 0;

    token = strtok(location, ",");

    while (token != NULL) {
        if (count == 0) {
            latitude = atoi(token);
        } else {
            longitude = atoi(token);
        }

        count++;
        token = strtok(NULL, ",");
    }

    printf("Updated GPS location: Latitude - %d, Longitude - %d\n", latitude, longitude);
}

// Main function to start program
int main() {
    char command[25];
    char input[50];

    printf("Welcome to C Drone Remote Control!\n");

    while (true) {
        printf("\nEnter command: ");
        fgets(input, 50, stdin);
        sscanf(input, "%s", command);

        if (strcmp(command, "arm") == 0) {
            armDrone();
        } else if (strcmp(command, "disarm") == 0) {
            disarmDrone();
        } else if (strcmp(command, "takeoff") == 0) {
            takeOff();
        } else if (strcmp(command, "land") == 0) {
            land();
        } else if (strcmp(command, "gps") == 0) {
            char location[50];
            printf("Enter new GPS location (latitude,longitude): ");
            fgets(location, 50, stdin);
            updateLocation(location);
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}