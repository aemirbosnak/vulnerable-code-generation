//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Function to check if the drone is on or off
bool isOn(bool onOff) {
    return onOff;
}

// Function to get current location of the drone
void getLocation() {
    // Code to get location
    printf("Current location: (50.1234, -120.5678)\n");
}

// Function to move the drone
void move(int x, int y) {
    // Code to move drone to (x,y) location
    printf("Moving drone to location: (%d, %d)\n", x, y);
}

// Function to take a picture
void takePicture() {
    // Code to take picture
    printf("Taking picture...\n");
}

// Main function
int main() {
    bool onOff = false;
    int choice, x, y;

    printf("Welcome to the C Drone Remote Control Program\n");

    while(true) {
        printf("\nChoose an option:\n");
        printf("1. Turn On/Off Drone\n");
        printf("2. Get Current Location\n");
        printf("3. Move Drone\n");
        printf("4. Take Picture\n");
        printf("5. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                onOff = !onOff;
                if(isOn(onOff)) {
                    printf("Drone turned on!\n");
                }
                else {
                    printf("Drone turned off!\n");
                }
                break;

            case 2:
                if(isOn(onOff)) {
                    getLocation();
                }
                else {
                    printf("Drone is off! Turn on the drone to get location.\n");
                }
                break;

            case 3:
                if(isOn(onOff)) {
                    printf("Enter x and y coordinates to move the drone: ");
                    scanf("%d%d", &x, &y);
                    move(x, y);
                }
                else {
                    printf("Drone is off! Turn on the drone to move.\n");
                }
                break;

            case 4:
                if(isOn(onOff)) {
                    takePicture();
                }
                else {
                    printf("Drone is off! Turn on the drone to take picture.\n");
                }
                break;

            case 5:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid Option! Please enter again.\n");
                break;
        }

        // Delay added to simulate processing time
        usleep(500000);
    }

    return 0;
}