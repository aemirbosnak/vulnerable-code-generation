//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LIGHTS 10
#define LIGHT_NAME_LENGTH 20

typedef enum { OFF, ON } LightStatus;

typedef struct {
    char name[LIGHT_NAME_LENGTH];
    LightStatus status;
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

void initializeLights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, LIGHT_NAME_LENGTH, "Light_%d", i + 1);
        lights[i].status = OFF;
    }
    lightCount = MAX_LIGHTS;
}

void displayLights() {
    printf("\nLight Control System:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].status == ON ? "ON" : "OFF");
    }
}

void toggleLight(int index) {
    if (index >= 0 && index < lightCount) {
        lights[index].status = (lights[index].status == ON) ? OFF : ON;
        printf("Toggled %s to %s.\n", lights[index].name, lights[index].status == ON ? "ON" : "OFF");
    } else {
        printf("Invalid light index: %d\n", index);
    }
}

void turnOnLight(int index) {
    if (index >= 0 && index < lightCount) {
        lights[index].status = ON;
        printf("Turned on %s.\n", lights[index].name);
    } else {
        printf("Invalid light index: %d\n", index);
    }
}

void turnOffLight(int index) {
    if (index >= 0 && index < lightCount) {
        lights[index].status = OFF;
        printf("Turned off %s.\n", lights[index].name);
    } else {
        printf("Invalid light index: %d\n", index);
    }
}

void showMenu() {
    printf("\nLight Control Menu:\n");
    printf("1. Display lights\n");
    printf("2. Toggle light\n");
    printf("3. Turn on light\n");
    printf("4. Turn off light\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    initializeLights();
    int choice;
    int lightIndex;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayLights();
                break;
            case 2:
                printf("Enter light index to toggle (0 - %d): ", lightCount - 1);
                scanf("%d", &lightIndex);
                toggleLight(lightIndex);
                break;
            case 3:
                printf("Enter light index to turn on (0 - %d): ", lightCount - 1);
                scanf("%d", &lightIndex);
                turnOnLight(lightIndex);
                break;
            case 4:
                printf("Enter light index to turn off (0 - %d): ", lightCount - 1);
                scanf("%d", &lightIndex);
                turnOffLight(lightIndex);
                break;
            case 5:
                printf("Exiting the Smart Light Control System.\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}