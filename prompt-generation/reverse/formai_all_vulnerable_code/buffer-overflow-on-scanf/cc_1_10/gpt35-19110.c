//FormAI DATASET v1.0 Category: Smart home automation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program is an example of a smart home automation system
// It manages a house with a set of smart devices and has the following functionalities:
// - Turning on/off devices
// - Changing the temperature of the AC
// - Setting a timer for devices
// - Sending notifications if devices are turned on for too long
// - Counting the total electricity consumption of the devices

// Define the maximum number of devices supported
#define MAX_DEVICES 10

// Define the maximum length for the device name and the notification message
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 50

// Define a structure to hold information about a smart device
struct Device {
    char name[MAX_NAME_LENGTH];
    int isOn;
    int hasTimer;
    int minutesRemaining;
    int wattage;
};

// Define a function to turn on a device
void turnOnDevice(struct Device* d) {
    if (!d->isOn) {
        printf("Turning on device %s\n", d->name);
        d->isOn = 1;
    }
}

// Define a function to turn off a device
void turnOffDevice(struct Device* d) {
    if (d->isOn) {
        printf("Turning off device %s\n", d->name);
        d->isOn = 0;
    }
}

// Define a function to change the temperature of the AC
void setACTemperature(int temperature) {
    printf("Setting AC temperature to %d degrees Celsius\n", temperature);
}

// Define a function to start a timer for a device
void startDeviceTimer(struct Device* d, int minutes) {
    if (!d->hasTimer) {
        printf("Starting timer for device %s: %d minutes\n", d->name, minutes);
        d->hasTimer = 1;
        d->minutesRemaining = minutes;
    }
}

// Define a function to check if a device's timer has expired
void checkDeviceTimer(struct Device* d) {
    if (d->hasTimer && d->minutesRemaining == 0) {
        printf("Device %s timer has expired\n", d->name);
        turnOffDevice(d);
        d->hasTimer = 0;
    }
}

// Define a function to send a notification if a device has been turned on for too long
void sendDeviceNotification(struct Device* d) {
    if (d->isOn && !d->hasTimer) {
        char message[MAX_MESSAGE_LENGTH];
        sprintf(message, "Device %s has been turned on for too long", d->name);
        printf("Sending notification: %s\n", message);
    }
}

// Define the main function
int main() {
    // Initialize the smart devices
    struct Device devices[MAX_DEVICES];
    devices[0] = (struct Device){"Living Room Light", 0, 0, 0, 40};
    devices[1] = (struct Device){"Kitchen Light", 0, 0, 0, 30};
    devices[2] = (struct Device){"Bedroom Light", 0, 0, 0, 35};
    devices[3] = (struct Device){"Living Room TV", 0, 1, 120, 70};
    devices[4] = (struct Device){"Bedroom TV", 0, 1, 90, 60};
    devices[5] = (struct Device){"Living Room AC", 0, 0, 0, 1000};
    devices[6] = (struct Device){"Bedroom AC", 0, 0, 0, 800};
    int numDevices = 7;

    // Initialize the timer variables
    int timerCounter = 0;
    int notificationCounter = 0;

    // Loop through the main program
    while (1) {
        // Display the menu
        printf("\nSMART HOME AUTOMATION SYSTEM\n");
        printf("1. Turn on a device\n");
        printf("2. Turn off a device\n");
        printf("3. Set the AC temperature\n");
        printf("4. Start a timer for a device\n");
        printf("5. Exit\n");

        // Read the user's choice
        int choice;
        scanf("%d", &choice);

        // Perform the selected action
        if (choice == 1) {
            // Turn on a device
            printf("Enter the name of the device to turn on: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            int found = 0;
            for (int i = 0; i < numDevices; i++) {
                if (strcmp(devices[i].name, name) == 0) {
                    turnOnDevice(&devices[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Device not found!\n");
            }
        } else if (choice == 2) {
            // Turn off a device
            printf("Enter the name of the device to turn off: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            int found = 0;
            for (int i = 0; i < numDevices; i++) {
                if (strcmp(devices[i].name, name) == 0) {
                    turnOffDevice(&devices[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Device not found!\n");
            }
        } else if (choice == 3) {
            // Set the AC temperature
            printf("Enter the temperature in degrees Celsius: ");
            int temperature;
            scanf("%d", &temperature);
            setACTemperature(temperature);
        } else if (choice == 4) {
            // Start a timer for a device
            printf("Enter the name of the device to set a timer for: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            int found = 0;
            for (int i = 0; i < numDevices; i++) {
                if (strcmp(devices[i].name, name) == 0) {
                    printf("Enter the duration of the timer in minutes: ");
                    int minutes;
                    scanf("%d", &minutes);
                    startDeviceTimer(&devices[i], minutes);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Device not found!\n");
            }
        } else if (choice == 5) {
            // Exit the program
            break;
        }

        // Decrement the device timers and check them
        for (int i = 0; i < numDevices; i++) {
            if (devices[i].hasTimer) {
                devices[i].minutesRemaining--;
                checkDeviceTimer(&devices[i]);
            }
        }

        // Send device notifications every 3 minutes
        if (notificationCounter == 3) {
            for (int i = 0; i < numDevices; i++) {
                sendDeviceNotification(&devices[i]);
            }
            notificationCounter = 0;
        } else {
            notificationCounter++;
        }

        // Calculate the electricity consumption of the devices every 5 minutes
        if (timerCounter == 5) {
            int totalWattage = 0;
            for (int i = 0; i < numDevices; i++) {
                if (devices[i].isOn) {
                    totalWattage += devices[i].wattage;
                }
            }
            float totalConsumption = totalWattage * 5.0 / 60 / 1000;
            printf("\nTotal electricity consumption in the past 5 minutes: %.2f kWh\n", totalConsumption);
            timerCounter = 0;
        } else {
            timerCounter++;
        }
    }

    return 0;
}