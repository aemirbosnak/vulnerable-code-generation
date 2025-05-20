//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    int id;
    char name[20];
    int isOn;
    int brightness; // 0-100
    char color[20];
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

// Function to add a new light
void addLight(const char* name) {
    if (lightCount >= MAX_LIGHTS) {
        printf("Cannot add more lights. Maximum limit reached.\n");
        return;
    }
    lights[lightCount].id = lightCount + 1;
    strncpy(lights[lightCount].name, name, sizeof(lights[lightCount].name) - 1);
    lights[lightCount].isOn = 0;
    lights[lightCount].brightness = 0;
    strncpy(lights[lightCount].color, "white", sizeof(lights[lightCount].color) - 1);
    lightCount++;
    printf("Light '%s' added successfully.\n", name);
}

// Function to turn a light on/off
void toggleLight(int id) {
    if (id < 1 || id > lightCount) {
        printf("Invalid light ID.\n");
        return;
    }
    lights[id - 1].isOn = !lights[id - 1].isOn;
    printf("Light '%s' has been turned %s.\n", lights[id - 1].name, lights[id - 1].isOn ? "ON" : "OFF");
}

// Function to change brightness
void setBrightness(int id, int brightness) {
    if (id < 1 || id > lightCount) {
        printf("Invalid light ID.\n");
        return;
    }
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }
    lights[id - 1].brightness = brightness;
    printf("Brightness for '%s' set to %d.\n", lights[id - 1].name, brightness);
}

// Function to change color
void setColor(int id, const char* color) {
    if (id < 1 || id > lightCount) {
        printf("Invalid light ID.\n");
        return;
    }
    strncpy(lights[id - 1].color, color, sizeof(lights[id - 1].color) - 1);
    printf("Color for '%s' set to %s.\n", lights[id - 1].name, color);
}

// Function to display the status of all lights
void displayLightsStatus() {
    printf("\nCurrent Lights Status:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("ID: %d, Name: %s, Status: %s, Brightness: %d%%, Color: %s\n",
               lights[i].id,
               lights[i].name,
               lights[i].isOn ? "ON" : "OFF",
               lights[i].brightness,
               lights[i].color);
    }
}

// Main function to run the light control system
int main() {
    int choice, id, brightness;
    char name[20], color[20];

    while (1) {
        printf("\n--- Smart Home Light Control System ---\n");
        printf("1. Add Light\n");
        printf("2. Toggle Light\n");
        printf("3. Set Brightness\n");
        printf("4. Set Color\n");
        printf("5. Display Lights Status\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                scanf("%s", name);
                addLight(name);
                break;

            case 2:
                printf("Enter light ID to toggle: ");
                scanf("%d", &id);
                toggleLight(id);
                break;

            case 3:
                printf("Enter light ID to set brightness: ");
                scanf("%d", &id);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                setBrightness(id, brightness);
                break;

            case 4:
                printf("Enter light ID to set color: ");
                scanf("%d", &id);
                printf("Enter color: ");
                scanf("%s", color);
                setColor(id, color);
                break;

            case 5:
                displayLightsStatus();
                break;

            case 6:
                printf("Exiting the Smart Home Light Control System. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}