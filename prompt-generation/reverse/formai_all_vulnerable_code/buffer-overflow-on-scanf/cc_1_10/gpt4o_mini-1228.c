//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 50

typedef enum {
    OFF,
    ON,
    DIMMED
} LightStatus;

typedef struct {
    char name[NAME_LENGTH];
    LightStatus status;
    int brightness; // 0-100
} SmartLight;

void initializeLights(SmartLight lights[], int count);
void displayLights(SmartLight lights[], int count);
void controlLight(SmartLight *light);
void setBrightness(SmartLight *light, int brightness);
void toggleLightStatus(SmartLight *light);
void displayMenu();

int main() {
    SmartLight lights[MAX_LIGHTS];
    int numberOfLights, choice, lightIndex;

    printf("Enter number of smart lights (max %d): ", MAX_LIGHTS);
    scanf("%d", &numberOfLights);
    
    if (numberOfLights < 1 || numberOfLights > MAX_LIGHTS) {
        printf("Invalid number of lights! Exiting...\n");
        return -1;
    }

    initializeLights(lights, numberOfLights);

    do {
        displayLights(lights, numberOfLights);
        displayMenu();
        printf("Choose an action (1-%d) or 0 to exit: ", numberOfLights+2);
        scanf("%d", &choice);

        if (choice > 0 && choice <= numberOfLights) {
            controlLight(&lights[choice - 1]);
        } else if (choice == numberOfLights + 1) {
            printf("Turning off all lights...\n");
            for (int i = 0; i < numberOfLights; i++) {
                lights[i].status = OFF;
                lights[i].brightness = 0;
            }
        } else if (choice != 0) {
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    printf("Exiting Smart Home Light Control...\n");
    return 0;
}

void initializeLights(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name for light %d: ", i + 1);
        scanf("%s", lights[i].name);
        lights[i].status = OFF;
        lights[i].brightness = 0;
    }
}

void displayLights(SmartLight lights[], int count) {
    printf("\nCurrent Status of Smart Lights:\n");
    for (int i = 0; i < count; i++) {
        printf("Light %d: %s | Status: %s | Brightness: %d\n", 
                i + 1, 
                lights[i].name, 
                (lights[i].status == OFF) ? "OFF" : (lights[i].status == ON) ? "ON" : "DIMMED",
                lights[i].brightness);
    }
    printf("\n");
}

void controlLight(SmartLight *light) {
    int choice, brightness;
    
    printf("Controlling light: %s\n", light->name);
    printf("1. Toggle Light Status\n2. Set Brightness (0-100)\n");
    printf("Choose an action: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        toggleLightStatus(light);
    } else if (choice == 2) {
        printf("Enter brightness level (0-100): ");
        scanf("%d", &brightness);
        if (brightness >= 0 && brightness <= 100) {
            setBrightness(light, brightness);
        } else {
            printf("Invalid brightness level! Please try again.\n");
        }
    } else {
        printf("Invalid choice! Returning to main menu.\n");
    }
}

void toggleLightStatus(SmartLight *light) {
    if (light->status == OFF) {
        light->status = ON;
        light->brightness = 100;
        printf("Light turned ON to full brightness.\n");
    } else if (light->status == ON) {
        light->status = DIMMED;
        light->brightness = 50; // Dimmed state with 50% brightness
        printf("Light DIMMED to 50%% brightness.\n");
    } else {
        light->status = OFF;
        light->brightness = 0;
        printf("Light turned OFF.\n");
    }
}

void setBrightness(SmartLight *light, int brightness) {
    light->brightness = brightness;
    if (brightness > 0) {
        light->status = DIMMED; // we assume any brightness > 0 means DIMMED
    } else {
        light->status = OFF;
    }
    printf("Brightness set to %d%%.\n", light->brightness);
}

void displayMenu() {
    printf("Menu Options:\n");
    printf("1. Control Light\n");
    printf("2. Turn off all lights\n");
    printf("\n");
}