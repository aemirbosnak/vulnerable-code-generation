//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    int status; // 0 for OFF, 1 for ON
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

void initializeLights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i + 1);
        lights[i].status = 0;  // Initialize all lights to OFF
    }
    lightCount = MAX_LIGHTS;
}

void displayLights() {
    printf("\nSmart Light Control Panel:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("%s is %s\n", lights[i].name, lights[i].status ? "ON" : "OFF");
    }
    printf("\n");
}

void toggleLight(int lightIndex) {
    if (lightIndex < 0 || lightIndex >= lightCount) {
        printf("Error: Invalid light index!\n");
        return;
    }
    lights[lightIndex].status = !lights[lightIndex].status; // Toggle status
}

void turnOnLight(int lightIndex) {
    if (lightIndex < 0 || lightIndex >= lightCount) {
        printf("Error: Invalid light index!\n");
        return;
    }
    lights[lightIndex].status = 1; // Set status to ON
}

void turnOffLight(int lightIndex) {
    if (lightIndex < 0 || lightIndex >= lightCount) {
        printf("Error: Invalid light index!\n");
        return;
    }
    lights[lightIndex].status = 0; // Set status to OFF
}

void showMenu() {
    printf("Welcome to the Smart Home Light Control System!\n");
    printf("1. Display Lights\n");
    printf("2. Toggle Light\n");
    printf("3. Turn On Light\n");
    printf("4. Turn Off Light\n");
    printf("5. Exit\n");
}

int main() {
    initializeLights();
    int choice, lightIndex;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayLights();
                break;
            case 2:
                printf("Enter light index to toggle (1-%d): ", lightCount);
                scanf("%d", &lightIndex);
                toggleLight(lightIndex - 1);
                break;
            case 3:
                printf("Enter light index to turn ON (1-%d): ", lightCount);
                scanf("%d", &lightIndex);
                turnOnLight(lightIndex - 1);
                break;
            case 4:
                printf("Enter light index to turn OFF (1-%d): ", lightCount);
                scanf("%d", &lightIndex);
                turnOffLight(lightIndex - 1);
                break;
            case 5:
                printf("Exiting Smart Home Light Control System.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}