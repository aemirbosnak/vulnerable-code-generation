//FormAI DATASET v1.0 Category: Smart home automation ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

// Function to turn the lights on
void turnLightsOn() {
    printf("Lights on\n");
}

// Function to turn the lights off
void turnLightsOff() {
    printf("Lights off\n");
}

// Function to lock the doors
void lockDoors() {
    printf("Doors locked\n");
}

// Function to unlock the doors
void unlockDoors() {
    printf("Doors unlocked\n");
}

// Main function
int main() {
    bool isHome = false; // Variable to store if someone is home
    int temp = 70; // Variable to store the temperature
    bool lightsOn = false; // Variable to store if the lights are on
    bool doorsLocked = true; // Variable to store if the doors are locked
    
    // Check if someone is home
    printf("Is someone home? (y/n)\n");
    char response = getchar(); // Get user input
    if(response == 'y' || response == 'Y') {
        isHome = true;
    }
    
    // Check the temperature
    printf("What is the temperature? (in degrees F)\n");
    scanf("%d", &temp); // Get user input
    
    // Check if it's dark outside
    printf("Is it dark outside? (y/n)\n");
    getchar(); // Consume the previous newline character
    response = getchar(); // Get user input
    if(response == 'y' || response == 'Y') {
        turnLightsOn();
        lightsOn = true;
    }
    
    // Check if doors need to be locked
    printf("Do you want to lock the doors? (y/n)\n");
    getchar(); // Consume the previous newline character
    response = getchar(); // Get user input
    if(response == 'y' || response == 'Y') {
        lockDoors();
        doorsLocked = true;
    }
    
    // Check if doors need to be unlocked
    printf("Do you want to unlock the doors? (y/n)\n");
    getchar(); // Consume the previous newline character
    response = getchar(); // Get user input
    if(response == 'y' || response == 'Y') {
        unlockDoors();
        doorsLocked = false;
    }
    
    // Check if temperature is too high or too low
    if(temp > 75 && isHome) {
        printf("Temperature is too high. Turning on the air conditioner.\n");
    } else if(temp < 65 && isHome) {
        printf("Temperature is too low. Turning on the heater.\n");
    }
    
    // Check if lights need to be turned off
    if(lightsOn && !isHome) {
        turnLightsOff();
    }
    
    // Check if doors need to be locked
    if(!doorsLocked && !isHome) {
        lockDoors();
    }
    
    return 0;
}