//FormAI DATASET v1.0 Category: Smart home automation ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
void checkTemperature();
void turnOnLight();
void turnOffLight();
void unlockDoor();
void lockDoor();

int main()
{
    // Variables to hold the current state of the devices
    bool isTemperatureOptimal = false;
    bool isLightOn = false;
    bool isDoorLocked = true;

    printf("Welcome to Smart Home System!\n");

    // Main loop for the system
    while (true)
    {
        char userInput[10];

        printf("\nPlease select an action:\n");
        printf("[1] Check temperature\n");
        printf("[2] Turn on light\n");
        printf("[3] Turn off light\n");
        printf("[4] Unlock door\n");
        printf("[5] Lock door\n");
        printf("[6] Quit program\n");
        scanf("%s", userInput);

        if (strcmp(userInput, "1") == 0)
        {
            checkTemperature();
            isTemperatureOptimal = true;
        }
        else if (strcmp(userInput, "2") == 0)
        {
            turnOnLight();
            isLightOn = true;
        }
        else if (strcmp(userInput, "3") == 0)
        {
            turnOffLight();
            isLightOn = false;
        }
        else if (strcmp(userInput, "4") == 0)
        {
            unlockDoor();
            isDoorLocked = false;
        }
        else if (strcmp(userInput, "5") == 0)
        {
            lockDoor();
            isDoorLocked = true;
        }
        else if (strcmp(userInput, "6") == 0)
        {
            printf("Program terminated.\n");
            break;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }

        // Check if all devices are in their optimal state
        if (isTemperatureOptimal && isLightOn && isDoorLocked)
        {
            printf("All devices are optimal. Enjoy your smart home!\n");
        }
        else
        {
            printf("Devices are not optimal. Please check their status.\n");
        }
    }

    return 0;
}

// Function to simulate checking temperature
void checkTemperature()
{
    printf("Checking temperature...\n");
    printf("Temperature is optimal.\n");
}

// Function to simulate turning on light
void turnOnLight()
{
    printf("Turning on light...\n");
    printf("Light is on.\n");
}

// Function to simulate turning off light
void turnOffLight()
{
    printf("Turning off light...\n");
    printf("Light is off.\n");
}

// Function to simulate unlocking door
void unlockDoor()
{
    printf("Unlocking door...\n");
    printf("Door is unlocked.\n");
}

// Function to simulate locking door
void lockDoor()
{
    printf("Locking door...\n");
    printf("Door is locked.\n");
}