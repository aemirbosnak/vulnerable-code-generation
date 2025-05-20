//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    int brightness; // 0 to 100
    int status; // 0: Off, 1: On
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

// Function to add a light
void addLight(const char* name) {
    if (lightCount >= MAX_LIGHTS) {
        printf("Cannot add more lights, maximum limit reached!\n");
        return;
    }
    strcpy(lights[lightCount].name, name);
    lights[lightCount].brightness = 0;
    lights[lightCount].status = 0;
    lightCount++;
    printf("Light '%s' added successfully!\n", name);
}

// Function to display the status of all lights
void displayLights() {
    printf("\nSmart Home Lights Status:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("Light: %s, Brightness: %d%%, Status: %s\n", 
               lights[i].name, 
               lights[i].brightness, 
               lights[i].status ? "On" : "Off");
    }
}

// Function to turn on a light
void turnOnLight(const char* name) {
    for (int i = 0; i < lightCount; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].status = 1;
            printf("Light '%s' turned on.\n", name);
            return;
        }
    }
    printf("Light '%s' not found!\n", name);
}

// Function to turn off a light
void turnOffLight(const char* name) {
    for (int i = 0; i < lightCount; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].status = 0;
            printf("Light '%s' turned off.\n", name);
            return;
        }
    }
    printf("Light '%s' not found!\n", name);
}

// Function to set brightness of a light
void setBrightness(const char* name, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Brightness level must be between 0 and 100.\n");
        return;
    }
    for (int i = 0; i < lightCount; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].brightness = brightness;
            printf("Light '%s' brightness set to %d%%.\n", name, brightness);
            return;
        }
    }
    printf("Light '%s' not found!\n", name);
}

// Main function acting as user interface
int main() {
    int choice;
    char name[20];
    int brightness;

    while (1) {
        printf("\nSmart Home Light Control Menu:\n");
        printf("1. Add Light\n");
        printf("2. Display Lights\n");
        printf("3. Turn On Light\n");
        printf("4. Turn Off Light\n");
        printf("5. Set Brightness\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                scanf("%s", name);
                addLight(name);
                break;
            case 2:
                displayLights();
                break;
            case 3:
                printf("Enter light name to turn on: ");
                scanf("%s", name);
                turnOnLight(name);
                break;
            case 4:
                printf("Enter light name to turn off: ");
                scanf("%s", name);
                turnOffLight(name);
                break;
            case 5:
                printf("Enter light name to set brightness: ");
                scanf("%s", name);
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                setBrightness(name, brightness);
                break;
            case 6:
                printf("Exiting smart home light control.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}