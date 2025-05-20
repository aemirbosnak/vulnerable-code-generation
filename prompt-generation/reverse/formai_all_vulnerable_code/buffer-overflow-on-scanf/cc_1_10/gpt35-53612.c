//FormAI DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include<stdio.h>
#include<stdbool.h>

// Define constants for various devices in the home
#define LIGHT 101
#define AC 102
#define TV 103

// Define constants for the available commands
#define ON 1
#define OFF 0

// Define function to toggle the state of a device
void toggleDevice(int deviceID, int* deviceState){
    if (*deviceState == ON){
        printf("Turning off device %d\n", deviceID);
        *deviceState = OFF;
    }
    else{
        printf("Turning on device %d\n", deviceID);
        *deviceState = ON;
    }
}

int main(){
    // Initialize the state of all devices to OFF
    int lightState = OFF;
    int acState = OFF;
    int tvState = OFF;

    // Print initial status of all devices
    printf("Initial Status:\n");
    printf("Light: %d\n", lightState);
    printf("AC: %d\n", acState);
    printf("TV: %d\n", tvState);

    // Take input from the user to turn on/off devices
    while(true){
        int command, deviceID;
        printf("Enter command (1 for ON, 0 for OFF): ");
        scanf("%d", &command);
        printf("Enter device ID: ");
        scanf("%d", &deviceID);

        // Call function to toggle device state based on user input
        switch(deviceID){
            case LIGHT:
                toggleDevice(LIGHT, &lightState);
                break;
            case AC:
                toggleDevice(AC, &acState);
                break;
            case TV:
                toggleDevice(TV, &tvState);
                break;
            default:
                printf("Invalid device ID\n");
        }

        // Print new status of all devices
        printf("Updated Status:\n");
        printf("Light: %d\n", lightState);
        printf("AC: %d\n", acState);
        printf("TV: %d\n", tvState);
    }

    return 0;
}