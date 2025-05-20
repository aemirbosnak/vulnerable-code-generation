//FormAI DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global Variables
int temperature = 20; // Default temperature
bool lightsOn = false; // Lights off by default
bool doorLocked = true; // Door is locked by default

// Function Prototypes
int increaseTemperature(int currentTemp);
int decreaseTemperature(int currentTemp);
void turnOnLights();
void turnOffLights();
void lockDoor();
void unlockDoor();

// Main Function
int main()
{
    int choice;

    while (true) {
        printf("\nWelcome to Smart Home Automation!\n");
        printf("1. Increase Temperature\n");
        printf("2. Decrease Temperature\n");
        printf("3. Turn on Lights\n");
        printf("4. Turn off Lights\n");
        printf("5. Lock Door\n");
        printf("6. Unlock Door\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                temperature = increaseTemperature(temperature);
                break;
            case 2:
                temperature = decreaseTemperature(temperature);
                break;
            case 3:
                turnOnLights();
                break;
            case 4:
                turnOffLights();
                break;
            case 5:
                lockDoor();
                break;
            case 6:
                unlockDoor();
                break;
            case 7:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to increase temperature
int increaseTemperature(int currentTemp)
{
    printf("\nCurrent Temperature: %dC\n", currentTemp);
    currentTemp += 1;
    printf("Temperature Increased to: %dC\n", currentTemp);
    return currentTemp;
}

// Function to decrease temperature
int decreaseTemperature(int currentTemp)
{
    printf("\nCurrent Temperature: %dC\n", currentTemp);
    currentTemp -= 1;
    printf("Temperature Decreased to: %dC\n", currentTemp);
    return currentTemp;
}

// Function to turn on lights
void turnOnLights()
{
    if (lightsOn == true) {
        printf("Lights are already on.\n");
    }
    else {
        printf("Turning on lights...\n");
        lightsOn = true;
    }
}

// Function to turn off lights
void turnOffLights()
{
    if (lightsOn == false) {
        printf("Lights are already off.\n");
    }
    else {
        printf("Turning off lights...\n");
        lightsOn = false;
    }
}

// Function to lock door
void lockDoor()
{
    if (doorLocked == true) {
        printf("Door is already locked.\n");
    }
    else {
        printf("Locking the door...\n");
        doorLocked = true;
    }
}

// Function to unlock door
void unlockDoor()
{
    if (doorLocked == false) {
        printf("Door is already unlocked.\n");
    }
    else {
        printf("Unlocking the door...\n");
        doorLocked = false;
    }
}