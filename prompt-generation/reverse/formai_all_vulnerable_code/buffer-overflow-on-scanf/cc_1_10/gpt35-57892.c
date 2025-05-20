//FormAI DATASET v1.0 Category: Smart home automation ; Style: high level of detail
// This program is a smart home automation example 
#include <stdio.h>
#include <stdbool.h>

// Function to turn on/off the lights
void lightControl(bool light_status) {
    if (light_status) {
        printf("Turning on the lights.\n");
    } else {
        printf("Turning off the lights.\n");
    }
}

// Function to control the temperature in the house
void temperatureControl(int temperature) {
    if (temperature > 25) {
        printf("The temperature is too high. Decreasing it to 25 degrees.\n");
        temperature = 25;
    } else if (temperature < 10) {
        printf("The temperature is too low. Increasing it to 10 degrees.\n");
        temperature = 10;
    }
    printf("Setting the temperature to %d degrees.\n", temperature);
}

int main() {
    bool isLightOn = false;
    int currentTemperature = 20;
    printf("Welcome to Smart Home Automation!\n");
    printf("Current Light Status: %s\n", isLightOn ? "ON" : "OFF");
    printf("Current Temperature: %d degrees.\n", currentTemperature);
    printf("Press 1 to turn on/off the lights.\n");
    printf("Press 2 to set the temperature.\n");
    printf("Press 0 to exit.\n");

    int userInput;
    do {
        scanf("%d", &userInput);
        if (userInput == 1) {
            isLightOn = !isLightOn;
            lightControl(isLightOn);
        } else if (userInput == 2) {
            printf("Enter the desired temperature: ");
            scanf("%d", &currentTemperature);
            temperatureControl(currentTemperature);
        } else {
            printf("Invalid input. Please try again.\n");
        }
        printf("Current Light Status: %s\n", isLightOn ? "ON" : "OFF");
        printf("Current Temperature: %d degrees.\n", currentTemperature);
        printf("Press 1 to turn on/off the lights.\n");
        printf("Press 2 to set the temperature.\n");
        printf("Press 0 to exit.\n");
    } while (userInput != 0);

    printf("Thank you for using Smart Home Automation!");
    return 0;
}