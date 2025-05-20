//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[30];
    int isOn;
    int brightness; // brightness level from 0 to 100
} Light;

Light lights[MAX_LIGHTS];
int lightCount = 0;

void initializeLights() {
    // Initialize some lights
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i + 1);
        lights[i].isOn = 0;
        lights[i].brightness = 0;
    }
    lightCount = MAX_LIGHTS;
}

void displayLights() {
    printf("\nCurrent Light Status:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("%s - Status: %s, Brightness: %d%%\n", 
                lights[i].name, 
                lights[i].isOn ? "On" : "Off", 
                lights[i].brightness);
    }
}

void turnOnLight(int index) {
    if (index < lightCount) {
        lights[index].isOn = 1;
        printf("%s is turned ON.\n", lights[index].name);
    } else {
        printf("Invalid light index.\n");
    }
}

void turnOffLight(int index) {
    if (index < lightCount) {
        lights[index].isOn = 0;
        printf("%s is turned OFF.\n", lights[index].name);
    } else {
        printf("Invalid light index.\n");
    }
}

void adjustBrightness(int index, int brightness) {
    if (index < lightCount) {
        if (brightness >= 0 && brightness <= 100) {
            lights[index].brightness = brightness;
            printf("Brightness of %s set to %d%%.\n", lights[index].name, brightness);
        } else {
            printf("Brightness value must be between 0 and 100.\n");
        }
    } else {
        printf("Invalid light index.\n");
    }
}

void controlLight() {
    int choice, index, brightness;
    
    while (1) {
        printf("\nLight Control Menu:\n");
        printf("1. Turn On Light\n");
        printf("2. Turn Off Light\n");
        printf("3. Adjust Brightness\n");
        printf("4. Display Current Light Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter light index (0-%d): ", lightCount - 1);
                scanf("%d", &index);
                turnOnLight(index);
                break;
            case 2:
                printf("Enter light index (0-%d): ", lightCount - 1);
                scanf("%d", &index);
                turnOffLight(index);
                break;
            case 3:
                printf("Enter light index (0-%d): ", lightCount - 1);
                scanf("%d", &index);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                adjustBrightness(index, brightness);
                break;
            case 4:
                displayLights();
                break;
            case 5:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Smart Home Light Control System!\n");
    initializeLights();
    controlLight();
    return 0;
}