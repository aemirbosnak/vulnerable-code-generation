//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if the drone is connected
bool checkConnection(bool connected) {
    if (connected) {
        printf("Drone connected and ready to fly!\n");
    } else {
        printf("Drone not connected. Please connect the drone first.\n");
    }
    return connected;
}

// Function to take off the drone
void takeOff(bool connected, bool landed) {
    if (checkConnection(connected)) {
        if (landed) {
            printf("Drone is taking off...\n");
            landed = false;
        } else {
            printf("Drone is already in the air.\n");
        }
    }
}

// Function to land the drone
void land(bool connected, bool landed) {
    if (checkConnection(connected)) {
        if (!landed) {
            printf("Drone is landing...\n");
            landed = true;
        } else {
            printf("Drone is already landed.\n");
        }
    }
}

// Function to move the drone forward
void moveForward(bool connected, bool landed) {
    if (checkConnection(connected)) {
        if (!landed) {
            printf("Moving drone forward...\n");
        } else {
            printf("Drone is landed. Cannot move forward.\n");
        }
    }
}

// Main function
int main() {
    bool connected = true;
    bool landed = true;

    // Print menu options
    printf("Drone Remote Control Options:\n");
    printf("1. Take off\n");
    printf("2. Land\n");
    printf("3. Move forward\n");
    printf("4. Exit\n");

    // Loop until user exits
    while (true) {
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                takeOff(connected, landed);
                break;

            case 2:
                land(connected, landed);
                break;

            case 3:
                moveForward(connected, landed);
                break;

            case 4:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}