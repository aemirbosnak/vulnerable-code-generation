//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int state; // 0 for off, 1 for on
    int brightness; // 0 to 100%
} Light;

// Function prototypes
void initializeLights(Light lights[], int count);
void displayLightStatus(Light lights[], int count);
void turnOnLight(Light* light);
void turnOffLight(Light* light);
void setLightBrightness(Light* light, int brightness);
void controlLight(Light lights[], int count);

int main() {
    Light lights[MAX_LIGHTS];
    int lightCount;

    printf("Enter the number of lights (max %d): ", MAX_LIGHTS);
    scanf("%d", &lightCount);
    if (lightCount > MAX_LIGHTS || lightCount <= 0) {
        printf("Invalid number of lights. Exiting program.\n");
        return 1;
    }

    initializeLights(lights, lightCount);
    controlLight(lights, lightCount);
    return 0;
}

void initializeLights(Light lights[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for light %d: ", i + 1);
        scanf("%s", lights[i].name);
        lights[i].state = 0; // All lights start as off
        lights[i].brightness = 0; // All lights start with 0% brightness
    }
}

void displayLightStatus(Light lights[], int count) {
    printf("\nLight Status:\n");
    for (int i = 0; i < count; i++) {
        printf("Light: %s | State: %s | Brightness: %d%%\n", 
               lights[i].name, 
               lights[i].state ? "On" : "Off", 
               lights[i].brightness);
    }
}

void turnOnLight(Light* light) {
    light->state = 1;
    light->brightness = 100; // Default to full brightness when turned on
    printf("%s is now turned ON at 100%% brightness.\n", light->name);
}

void turnOffLight(Light* light) {
    light->state = 0;
    light->brightness = 0; // Turn off brightness
    printf("%s is now turned OFF.\n", light->name);
}

void setLightBrightness(Light* light, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Invalid brightness level. Please enter a value between 0 and 100.\n");
    } else {
        light->brightness = brightness;
        printf("Brightness of %s set to %d%%.\n", light->name, light->brightness);
    }
}

void controlLight(Light lights[], int count) {
    int choice, lightIndex;

    while (1) {
        displayLightStatus(lights, count);
        
        printf("\nMenu:\n");
        printf("1. Turn ON Light\n");
        printf("2. Turn OFF Light\n");
        printf("3. Set Brightness of Light\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the light number to turn ON (1 to %d): ", count);
                scanf("%d", &lightIndex);
                if (lightIndex > 0 && lightIndex <= count) {
                    turnOnLight(&lights[lightIndex - 1]);
                } else {
                    printf("Invalid light number.\n");
                }
                break;
            case 2:
                printf("Enter the light number to turn OFF (1 to %d): ", count);
                scanf("%d", &lightIndex);
                if (lightIndex > 0 && lightIndex <= count) {
                    turnOffLight(&lights[lightIndex - 1]);
                } else {
                    printf("Invalid light number.\n");
                }
                break;
            case 3:
                printf("Enter the light number to set brightness (1 to %d): ", count);
                scanf("%d", &lightIndex);
                if (lightIndex > 0 && lightIndex <= count) {
                    int brightness;
                    printf("Enter brightness level (0-100): ");
                    scanf("%d", &brightness);
                    setLightBrightness(&lights[lightIndex - 1], brightness);
                } else {
                    printf("Invalid light number.\n");
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                return;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
}