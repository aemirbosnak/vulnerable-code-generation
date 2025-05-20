//FormAI DATASET v1.0 Category: Smart home automation ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isLocked = true;
bool hasLightsOn = false;
bool isGarageClosed = false;
bool isAlarmEnabled = true;
bool isMotionDetected = false;

// function to toggle the lock state of the smart home
void toggleLock(int pin) {
    if (isLocked) {
        printf("Unlocking home...\n");
        printf("Please enter pin to unlock: ");
        int enteredPin;
        scanf("%d", &enteredPin);
        if (enteredPin == pin) {
            isLocked = false;
            printf("Home is unlocked.\n\n");
        } else {
            printf("Incorrect pin entered. Try again.\n\n");
        }
    } else {
        printf("Locking home...\n");
        isLocked = true;
        printf("Home is locked.\n\n");
    }
}

// function to toggle the lights in the smart home
void toggleLights() {
    if (hasLightsOn) {
        printf("Turning off lights...\n");
        hasLightsOn = false;
        printf("Lights are off.\n\n");
    } else {
        printf("Turning on lights...\n");
        hasLightsOn = true;
        printf("Lights are on.\n\n");
    }
}

// function to toggle the garage state in the smart home
void toggleGarage() {
    if (isGarageClosed) {
        printf("Opening garage...\n");
        isGarageClosed = false;
        printf("Garage is open.\n\n");
    } else {
        printf("Closing garage...\n");
        isGarageClosed = true;
        printf("Garage is closed.\n\n");
    }
}

// function to toggle the alarm state in the smart home
void toggleAlarm() {
    if (isAlarmEnabled) {
        printf("Disabling alarm...\n");
        isAlarmEnabled = false;
        printf("Alarm is disabled.\n\n");
    } else {
        printf("Enabling alarm...\n");
        isAlarmEnabled = true;
        printf("Alarm is enabled.\n\n");
    }
}

// function to detect motion in the smart home
void detectMotion() {
    if (!hasLightsOn && isAlarmEnabled) {
        printf("Motion detected!\n");
        printf("Activating alarm...\n");
        isMotionDetected = true;
    } else {
        printf("No motion detected.\n\n");
    }
}

int main() {
    int pin = 1234; // default pin
    int option;

    printf("Welcome to the paranoid smart home automation system!\n");
    printf("Please enter your pin to continue: ");
    int enteredPin;
    scanf("%d", &enteredPin);
    if (enteredPin != pin) {
        printf("Incorrect pin entered. Exiting...\n");
        return 0;
    }

    while (true) {
        printf("Options:\n");
        printf("1. Toggle lock\n");
        printf("2. Toggle lights\n");
        printf("3. Toggle garage\n");
        printf("4. Toggle alarm\n");
        printf("5. Detect motion\n");
        printf("6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                toggleLock(pin);
                break;
            case 2:
                toggleLights();
                break;
            case 3:
                toggleGarage();
                break;
            case 4:
                toggleAlarm();
                break;
            case 5:
                detectMotion();
                break;
            case 6:
                printf("Exiting paranoid smart home automation system...\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n\n");
                break;
        }

        if (isMotionDetected) {
            printf("Warning: motion detected! Entering lockdown mode...\n");
            toggleAlarm();
            toggleLights();
            toggleGarage();
            toggleLock(pin);
            printf("Lockdown successful.\n\n");
            isMotionDetected = false;
        }
    }

    return 0;
}