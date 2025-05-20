//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef enum { OFF, ON } LightState;

typedef struct {
    char name[50];
    LightState state;
    int brightness;  // Range from 0 to 100
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

void initializeLights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i + 1);
        lights[i].state = OFF;
        lights[i].brightness = 0;
    }
    lightCount = MAX_LIGHTS;
}

void printLightStatus() {
    printf("\n--- Current Smart Light Status ---\n");
    for (int i = 0; i < lightCount; i++) {
        printf("Name: %s | State: %s | Brightness: %d%%\n", 
                lights[i].name, 
                lights[i].state == ON ? "ON" : "OFF", 
                lights[i].brightness);
    }
    printf("-----------------------------------\n");
}

void toggleLight(int index) {
    if (index >= 0 && index < lightCount) {
        lights[index].state = lights[index].state == ON ? OFF : ON;
        printf("%s is now %s.\n", lights[index].name, 
               lights[index].state == ON ? "ON" : "OFF");
    } else {
        printf("Invalid light index.\n");
    }
}

void setBrightness(int index, int brightness) {
    if (index >= 0 && index < lightCount) {
        if (brightness < 0 || brightness > 100) {
            printf("Brightness must be between 0 and 100.\n");
        } else {
            lights[index].brightness = brightness;
            printf("Brightness of %s set to %d%%.\n", lights[index].name, brightness);
        }
    } else {
        printf("Invalid light index.\n");
    }
}

int main() {
    initializeLights();
    int choice, lightIndex, brightness;

    while (1) {
        printLightStatus();
        printf("Choose an option:\n");
        printf("1. Toggle Light\n");
        printf("2. Change Brightness\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light index (0-%d): ", lightCount - 1);
                scanf("%d", &lightIndex);
                toggleLight(lightIndex);
                break;
            case 2:
                printf("Enter light index (0-%d): ", lightCount - 1);
                scanf("%d", &lightIndex);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                setBrightness(lightIndex, brightness);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}