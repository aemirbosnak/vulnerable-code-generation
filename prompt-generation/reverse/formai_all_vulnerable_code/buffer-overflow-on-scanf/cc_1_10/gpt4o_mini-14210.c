//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 30

// Enum to define the status of the light
typedef enum {
    OFF,
    ON
} LightStatus;

// Structure to represent a smart light bulb
typedef struct {
    char name[NAME_LENGTH];
    LightStatus status;
    int brightness; // Range from 0 to 100
} SmartLight;

// Function declarations
void initializeLights(SmartLight lights[], int count);
void toggleLight(SmartLight *light);
void setBrightness(SmartLight *light, int brightness);
void displayLightStatus(SmartLight lights[], int count);
void commandPrompt(SmartLight lights[], int count);
void displayMenu();

// Main function
int main() {
    SmartLight lights[MAX_DEVICES];
    int deviceCount;

    printf("Enter the number of smart lights (max %d): ", MAX_DEVICES);
    scanf("%d", &deviceCount);

    if (deviceCount < 1 || deviceCount > MAX_DEVICES) {
        printf("Invalid number of devices. Exiting.\n");
        return 1;
    }

    initializeLights(lights, deviceCount);
    commandPrompt(lights, deviceCount);

    return 0;
}

// Function to initialize smart lights
void initializeLights(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Setting up smart light %d\n", i + 1);
        printf("Enter the name for light %d: ", i + 1);
        scanf("%s", lights[i].name);
        lights[i].status = OFF;
        lights[i].brightness = 0;
    }
}

// Function to toggle the status of a light
void toggleLight(SmartLight *light) {
    if (light->status == OFF) {
        light->status = ON;
        printf("%s is now ON.\n", light->name);
    } else {
        light->status = OFF;
        printf("%s is now OFF.\n", light->name);
    }
}

// Function to set the brightness of a light
void setBrightness(SmartLight *light, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Invalid brightness level. Please set between 0 and 100.\n");
    } else {
        light->brightness = brightness;
        if (light->status == ON) {
            printf("Brightness of %s set to %d.\n", light->name, brightness);
        } else {
            printf("%s is OFF. Turn it ON to adjust brightness.\n", light->name);
        }
    }
}

// Function to display the status of all lights
void displayLightStatus(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Light: %s, Status: %s, Brightness: %d%%\n", 
               lights[i].name, 
               lights[i].status == ON ? "ON" : "OFF", 
               lights[i].brightness);
    }
}

// Command prompt for user interaction
void commandPrompt(SmartLight lights[], int count) {
    int choice, lightIndex, brightness;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayLightStatus(lights, count);
                break;
            case 2:
                printf("Enter the light index (1 to %d): ", count);
                scanf("%d", &lightIndex);
                if (lightIndex >= 1 && lightIndex <= count) {
                    toggleLight(&lights[lightIndex - 1]);
                } else {
                    printf("Invalid light index.\n");
                }
                break;
            case 3:
                printf("Enter the light index (1 to %d): ", count);
                scanf("%d", &lightIndex);
                if (lightIndex >= 1 && lightIndex <= count) {
                    printf("Enter brightness level (0 to 100): ");
                    scanf("%d", &brightness);
                    setBrightness(&lights[lightIndex - 1], brightness);
                } else {
                    printf("Invalid light index.\n");
                }
                break;
            case 0:
                printf("Exiting the program.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to display menu options
void displayMenu() {
    printf("\nSmart Home Light Control Menu:\n");
    printf("1. Display Light Status\n");
    printf("2. Toggle Light\n");
    printf("3. Set Brightness\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}