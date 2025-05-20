//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define LIGHT_ON 1
#define LIGHT_OFF 0

typedef struct {
    int id;
    char name[20];
    int status; // LIGHT_ON or LIGHT_OFF
} Light;

void initializeLights(Light lights[], int count) {
    for (int i = 0; i < count; i++) {
        lights[i].id = i + 1;
        snprintf(lights[i].name, sizeof(lights[i].name), "Light%d", i + 1);
        lights[i].status = LIGHT_OFF;
    }
}

void displayLights(Light lights[], int count) {
    printf("\nCurrent Light Status:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].status == LIGHT_ON ? "ON" : "OFF");
    }
}

void toggleLight(Light* light) {
    light->status = (light->status == LIGHT_ON) ? LIGHT_OFF : LIGHT_ON;
}

void turnOnLight(Light* light) {
    light->status = LIGHT_ON;
}

void turnOffLight(Light* light) {
    light->status = LIGHT_OFF;
}

void controlLights(Light lights[], int count) {
    int choice, lightId;
    while (1) {
        printf("\nControl Lights Menu:\n");
        printf("1. Toggle Light\n");
        printf("2. Turn On Light\n");
        printf("3. Turn Off Light\n");
        printf("4. View Status\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Light ID to toggle: ");
                scanf("%d", &lightId);
                if (lightId > 0 && lightId <= count) {
                    toggleLight(&lights[lightId - 1]);
                } else {
                    printf("Invalid Light ID!\n");
                }
                break;
            case 2:
                printf("Enter Light ID to turn on: ");
                scanf("%d", &lightId);
                if (lightId > 0 && lightId <= count) {
                    turnOnLight(&lights[lightId - 1]);
                } else {
                    printf("Invalid Light ID!\n");
                }
                break;
            case 3:
                printf("Enter Light ID to turn off: ");
                scanf("%d", &lightId);
                if (lightId > 0 && lightId <= count) {
                    turnOffLight(&lights[lightId - 1]);
                } else {
                    printf("Invalid Light ID!\n");
                }
                break;
            case 4:
                displayLights(lights, count);
                break;
            case 5:
                printf("Exiting the control panel.\n");
                return;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
}

int main() {
    Light lights[MAX_LIGHTS];
    int count = MAX_LIGHTS;

    initializeLights(lights, count);
    
    printf("Welcome to the Smart Home Light Control System\n");
    controlLights(lights, count);

    return 0;
}