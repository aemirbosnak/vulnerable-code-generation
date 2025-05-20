//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: curious
// Embark on a smart home adventure where curiosity reigns supreme!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Let's define our smart home's quirky components
enum DeviceType {
    Bulb,
    Thermostat,
    Sprinkler,
    Fan
};

struct Device {
    enum DeviceType type;
    char* name;
    int state; // 0 for off, 1 for on
};

// An array to hold our curious devices
struct Device devices[] = {
    { Bulb, "Spotty", 0 },
    { Thermostat, "Shivery", 0 },
    { Sprinkler, "Drippy", 0 },
    { Fan, "Breezy", 0 }
};

// Now, let's introduce our curious user interface
void displayUI() {
    printf("\nWelcome to your curious smart home!\n");
    printf("Your devices are feeling a bit playful today:\n");
    for (int i = 0; i < 4; i++) {
        printf(" - %s the %s is %s\n", devices[i].name,
               devices[i].type == Bulb ? "Bulb" : devices[i].type == Thermostat ? "Thermostat" : devices[i].type == Sprinkler ? "Sprinkler" : "Fan",
               devices[i].state ? "on" : "off");
    }
    printf("\nWhat would you like to do next?\n");
    printf("1. Toggle a device\n2. Randomly turn devices on or off\n3. Quit\n");
}

// Time for some curious device interactions
void toggleDevice() {
    int deviceIndex;
    printf("Which device would you like to toggle? (Enter a number from 1 to 4): ");
    scanf("%d", &deviceIndex);
    if (deviceIndex < 1 || deviceIndex > 4) {
        printf("Oops, that's not a valid device. Try again!\n");
    } else {
        devices[deviceIndex - 1].state = !devices[deviceIndex - 1].state;
        printf("%s is now %s!\n", devices[deviceIndex - 1].name, devices[deviceIndex - 1].state ? "on" : "off");
    }
}

void randomizeDevices() {
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        devices[i].state = rand() % 2;
    }
    printf("Your devices have now been randomly turned on or off. Let's see what they're up to:\n");
    displayUI();
}

// And finally, a grand exit
void quit() {
    printf("Goodbye from your curious smart home! May your devices continue to spark your imagination.\n");
    exit(0);
}

int main() {
    int choice;
    displayUI();
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                toggleDevice();
                break;
            case 2:
                randomizeDevices();
                break;
            case 3:
                quit();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}