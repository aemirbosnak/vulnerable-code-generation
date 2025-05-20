//FormAI DATASET v1.0 Category: Smart home automation ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void turnOnLights(bool livingRoom, bool bedroom);
void turnOffLights(bool livingRoom, bool bedroom);
void lockHouse(bool lock);

int main() {
    // Variables to track state
    bool livingRoomLightsOn = false;
    bool bedroomLightsOn = false;
    bool houseLocked = true;

    // Welcome message
    printf("Welcome to your futuristic smart home!\n");

    // Main menu loop
    while (true) {
        // Display options
        printf("\nWhat would you like to do?\n");
        printf("1. Turn on living room lights\n");
        printf("2. Turn on bedroom lights\n");
        printf("3. Turn off living room lights\n");
        printf("4. Turn off bedroom lights\n");
        printf("5. Lock/unlock house\n");
        printf("6. Quit\n");

        // Get user choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                turnOnLights(true, false);
                livingRoomLightsOn = true;
                break;
            case 2:
                turnOnLights(false, true);
                bedroomLightsOn = true;
                break;
            case 3:
                turnOffLights(true, false);
                livingRoomLightsOn = false;
                break;
            case 4:
                turnOffLights(false, true);
                bedroomLightsOn = false;
                break;
            case 5:
                lockHouse(!houseLocked);
                houseLocked = !houseLocked;
                break;
            case 6:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }

        // Display current state
        printf("\nCurrent state:\n");
        printf("Living room lights are %s.\n", livingRoomLightsOn ? "on" : "off");
        printf("Bedroom lights are %s.\n", bedroomLightsOn ? "on" : "off");
        printf("The house is %s.\n", houseLocked ? "locked" : "unlocked");
    }

    return 0;
}

// Turn on/off living room and bedroom lights
void turnOnLights(bool livingRoom, bool bedroom) {
    printf("Turning on lights...\n");
    if (livingRoom) {
        printf("Living room lights are on.\n");
    }
    if (bedroom) {
        printf("Bedroom lights are on.\n");
    }
}

void turnOffLights(bool livingRoom, bool bedroom) {
    printf("Turning off lights...\n");
    if (livingRoom) {
        printf("Living room lights are off.\n");
    }
    if (bedroom) {
        printf("Bedroom lights are off.\n");
    }
}

// Lock/unlock the house
void lockHouse(bool lock) {
    if (lock) {
        printf("Locking the house...\n");
    } else {
        printf("Unlocking the house...\n");
    }
}