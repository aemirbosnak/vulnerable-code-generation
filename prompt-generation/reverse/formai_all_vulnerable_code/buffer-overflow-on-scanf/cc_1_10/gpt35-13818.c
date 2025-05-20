//FormAI DATASET v1.0 Category: Smart home automation ; Style: genious
// Welcome to my genius Smart Home Automation Program!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the functions used in our program
void turnOn(int device);
void turnOff(int device);
void updateTemp(int temp);

// List of all the devices in our smart home
int light = 0;
int fan = 0;
int tv = 0;
int ac = 0;

// Main function to run our program
int main(void) {
    int choice;
    int temperature = 25;

    // Loop continuously until the user exits
    while(1) {
        printf("Welcome to the Smart Home Automation System!\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Turn on the fan\n");
        printf("4. Turn off the fan\n");
        printf("5. Turn on the TV\n");
        printf("6. Turn off the TV\n");
        printf("7. Turn on the AC\n");
        printf("8. Turn off the AC\n");
        printf("9. Set the temperature\n");
        printf("10. Exit\n\n");

        // Ask the user to enter a choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process the user's choice
        switch(choice) {
            case 1:
                turnOn(light);
                break;
            case 2:
                turnOff(light);
                break;
            case 3:
                turnOn(fan);
                break;
            case 4:
                turnOff(fan);
                break;
            case 5:
                turnOn(tv);
                break;
            case 6:
                turnOff(tv);
                break;
            case 7:
                turnOn(ac);
                break;
            case 8:
                turnOff(ac);
                break;
            case 9:
                printf("Enter the desired temperature: ");
                scanf("%d", &temperature);
                updateTemp(temperature);
                break;
            case 10:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to turn on a device
void turnOn(int device) {
    if(device == 0) {
        printf("The device is now turned on.\n");
        device = 1;
    } else {
        printf("The device is already turned on.\n");
    }
}

// Function to turn off a device
void turnOff(int device) {
    if(device == 1) {
        printf("The device is now turned off.\n");
        device = 0;
    } else {
        printf("The device is already turned off.\n");
    }
}

// Function to update the temperature
void updateTemp(int temp) {
    printf("The temperature is now set to %d degrees.\n", temp);
}