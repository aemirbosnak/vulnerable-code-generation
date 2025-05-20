//FormAI DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_LENGTH 10
#define MAX_DEVICES 10

// Define a structure for each light device
typedef struct {
  char *name;
  int brightness;
  int status;
} Light;

// Function prototypes
void printWelcomeMenu();
int convertUserInput(char *input);
int handleUserCommand(int command, Light *devices, int numDevices);
void printDeviceMenu(Light *devices, int numDevices);
void changeBrightness(Light *device, int newBrightness);
void changeStatus(Light *device, int newStatus);

int main() {
    // Create some sample light devices
    Light lights[MAX_DEVICES] = {{"Living Room Light", 75, 1},
                                 {"Kitchen Light", 100, 1},
                                 {"Bedroom Light", 50, 0}};
    int numLights = 3;

    // Print welcome message and menu for user
    printWelcomeMenu();

    // Keep prompting user input until they exit
    int userInput = -1;
    while (userInput != 0) {
        char input[CMD_LENGTH];
        fgets(input, CMD_LENGTH, stdin);
        userInput = convertUserInput(input);
        handleUserCommand(userInput, lights, numLights);
    }

    return 0;
}

// Print the welcome message and light control options
void printWelcomeMenu() {
    printf("Welcome to your smart home! You have the following lights:\n");
    printf("1. Living Room Light\n2. Kitchen Light\n3. Bedroom Light\n\n");
    printf("Enter 0 to exit.\n");
    printf("Enter 1 to see device statuses.\n");
    printf("Enter 2 to adjust device brightness.\n");
    printf("Enter 3 to turn devices on or off.\n");
}

// Convert user input to an integer command
int convertUserInput(char *input) {
    int command = atoi(input);
    return command;
}

// Handle user input
int handleUserCommand(int command, Light *devices, int numDevices) {
    switch (command) {
        case 0:
            return 0;
        case 1:
            printDeviceMenu(devices, numDevices);
            break;
        case 2:
            printf("Enter the device number you want to adjust brightness for:");
            int deviceNum;
            scanf("%d", &deviceNum);
            Light *device = &devices[deviceNum-1];
            printf("Enter the brightness percentage (0-100) you want to set for %s:", device->name);
            int brightness;
            scanf("%d", &brightness);
            changeBrightness(device, brightness);
            break;
        case 3:
            printf("Enter the device number you want to turn on or off:");
            int deviceNum2;
            scanf("%d", &deviceNum2);
            Light *device2 = &devices[deviceNum2-1];
            printf("Enter 1 to turn on or 0 to turn off %s:", device2->name);
            int status;
            scanf("%d", &status);
            changeStatus(device2, status);
            break;
        default:
            printf("Invalid command. Please try again.\n");
            break;
    }

    return 1;
}

// Print menu of devices and their current status
void printDeviceMenu(Light *devices, int numDevices) {
    printf("Current device statuses:\n");
    for(int i = 0; i < numDevices; i++) {
        int statusInt = devices[i].status;
        char *statusStr = statusInt == 1 ? "on" : "off";
        printf("%d. %s is %s\n", i+1, devices[i].name, statusStr);
    }
}

// Change brightness of given device to newBrightness
void changeBrightness(Light *device, int newBrightness) {
    if (newBrightness < 0 || newBrightness > 100) {
        printf("Invalid brightness. Please enter a value between 0 and 100.\n");
    } else {
        device->brightness = newBrightness;
        printf("%s brightness set to %d percent.\n", device->name, device->brightness);
    }
}

// Change status of given device to newStatus
void changeStatus(Light *device, int newStatus) {
    if (newStatus < 0 || newStatus > 1) {
        printf("Invalid status. Please enter 0 for off or 1 for on.\n");
    } else {
        device->status = newStatus;
        char *statusStr = newStatus == 1 ? "on" : "off";
        printf("%s turned %s.\n", device->name, statusStr);
    }
}