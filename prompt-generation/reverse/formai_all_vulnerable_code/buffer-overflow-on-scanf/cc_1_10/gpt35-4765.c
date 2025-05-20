//FormAI DATASET v1.0 Category: Smart home automation ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

// Define the states of different appliances
enum ApplianceState {
    OFF,
    ON
};

// Define a data structure for the smart home
struct SmartHome {
    enum ApplianceState light;
    enum ApplianceState fan;
    enum ApplianceState tv;
    enum ApplianceState fridge;
};

// Define a function to turn on an appliance
void turnOn(enum ApplianceState* appliance) {
    *appliance = ON;
}

// Define a function to turn off an appliance
void turnOff(enum ApplianceState* appliance) {
    *appliance = OFF;
}

int main() {
    // Initialize the smart home
    struct SmartHome myHome = {
        .light = OFF,
        .fan = OFF,
        .tv = OFF,
        .fridge = OFF
    };

    // Welcome message
    printf("Welcome to my smart home!\n");

    // Main loop
    while (true) {
        // Print the current state of the smart home
        printf("Current state:\n");
        printf("Light is %s\n", myHome.light == ON ? "on" : "off");
        printf("Fan is %s\n", myHome.fan == ON ? "on" : "off");
        printf("TV is %s\n", myHome.tv == ON ? "on" : "off");
        printf("Fridge is %s\n", myHome.fridge == ON ? "on" : "off");
        printf("\n");

        // Prompt for user input
        printf("What would you like to do?\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Turn on the fan\n");
        printf("4. Turn off the fan\n");
        printf("5. Turn on the TV\n");
        printf("6. Turn off the TV\n");
        printf("7. Turn on the fridge\n");
        printf("8. Turn off the fridge\n");
        printf("9. Quit\n");
        int choice;
        scanf("%d", &choice);

        // Process user input
        switch (choice) {
            case 1:
                turnOn(&myHome.light);
                printf("Turning on the light\n");
                break;
            case 2:
                turnOff(&myHome.light);
                printf("Turning off the light\n");
                break;
            case 3:
                turnOn(&myHome.fan);
                printf("Turning on the fan\n");
                break;
            case 4:
                turnOff(&myHome.fan);
                printf("Turning off the fan\n");
                break;
            case 5:
                turnOn(&myHome.tv);
                printf("Turning on the TV\n");
                break;
            case 6:
                turnOff(&myHome.tv);
                printf("Turning off the TV\n");
                break;
            case 7:
                turnOn(&myHome.fridge);
                printf("Turning on the fridge\n");
                break;
            case 8:
                turnOff(&myHome.fridge);
                printf("Turning off the fridge\n");
                break;
            case 9:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("\n");
    }

    return 0;
}