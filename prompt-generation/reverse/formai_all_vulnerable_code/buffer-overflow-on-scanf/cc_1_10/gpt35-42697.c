//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void turnOnLights();
void turnOffLights();
void lockDoors();
void unlockDoors();
void setTemperature(int);
void turnOnTV();
void turnOffTV();

// Global variables
bool lightsOn = false;
bool doorsLocked = true;
int temperature = 70;
bool tvOn = false;

int main() {
    int choice;
    bool quit = false;
    while(!quit) {
        printf("\nWelcome to Smart Home Automation Menu\n");
        printf("1. Turn on lights\n");
        printf("2. Turn off lights\n");
        printf("3. Lock doors\n");
        printf("4. Unlock doors\n");
        printf("5. Set temperature\n");
        printf("6. Turn on TV\n");
        printf("7. Turn off TV\n");
        printf("8. Quit program\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                turnOnLights();
                break;
            case 2:
                turnOffLights();
                break;
            case 3:
                lockDoors();
                break;
            case 4:
                unlockDoors();
                break;
            case 5:
                printf("Enter temperature desired: ");
                scanf("%d", &temperature);
                setTemperature(temperature);
                break;
            case 6:
                turnOnTV();
                break;
            case 7:
                turnOffTV();
                break;
            case 8:
                printf("Thank you for using Smart Home Automation!\n");
                quit = true;
                break;
            default:
                printf("Invalid choice. Please enter a number between 1-8.\n");
                break;
        }
    }
    return 0;
}

void turnOnLights() {
    lightsOn = true;
    printf("Lights are now turned on.\n");
}

void turnOffLights() {
    lightsOn = false;
    printf("Lights are now turned off.\n");
}

void lockDoors() {
    doorsLocked = true;
    printf("Doors are now locked.\n");
}

void unlockDoors() {
    doorsLocked = false;
    printf("Doors are now unlocked.\n");
}

void setTemperature(int temp) {
    temperature = temp;
    printf("Temperature is now set to %d degrees.\n", temperature);
}

void turnOnTV() {
    tvOn = true;
    printf("TV is now turned on.\n");
}

void turnOffTV() {
    tvOn = false;
    printf("TV is now turned off.\n");
}