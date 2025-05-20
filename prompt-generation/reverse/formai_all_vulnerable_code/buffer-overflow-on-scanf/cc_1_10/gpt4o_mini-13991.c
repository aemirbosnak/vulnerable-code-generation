//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int isOn;
    int r, g, b;
} Light;

void initializeLight(Light *light, const char *name) {
    strcpy(light->name, name);
    light->isOn = 0;
    light->r = 255; // Default to white if on
    light->g = 255;
    light->b = 255;
    printf("Thank you for adding the light: %s!\n", light->name);
}

void toggleLight(Light *light) {
    light->isOn = !light->isOn;
    printf("%s has been turned %s!\n", light->name, light->isOn ? "ON" : "OFF");
}

void changeColor(Light *light, int r, int g, int b) {
    if (light->isOn) {
        light->r = r;
        light->g = g;
        light->b = b;
        printf("The color of %s has been changed to RGB(%d, %d, %d)!\n", light->name, r, g, b);
    } else {
        printf("Please turn on %s first to change its color!\n", light->name);
    }
}

void displayLightStatus(const Light *light) {
    printf("\n--- Light Status: %s ---\n", light->name);
    printf("Status: %s\n", light->isOn ? "ON" : "OFF");
    if (light->isOn) {
        printf("Color: RGB(%d, %d, %d)\n", light->r, light->g, light->b);
    }
    printf("-------------------------\n");
}

int main() {
    Light livingRoomLight;
    initializeLight(&livingRoomLight, "Living Room Light");

    int choice, r, g, b;

    while (1) {
        printf("\nWelcome to the Smart Light Control System!\n");
        printf("1. Toggle Light\n");
        printf("2. Change Color\n");
        printf("3. Display Light Status\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                toggleLight(&livingRoomLight);
                break;
            case 2:
                printf("Enter new RGB values (0-255) for %s:\n", livingRoomLight.name);
                printf("Red: ");
                scanf("%d", &r);
                printf("Green: ");
                scanf("%d", &g);
                printf("Blue: ");
                scanf("%d", &b);
                changeColor(&livingRoomLight, r, g, b);
                break;
            case 3:
                displayLightStatus(&livingRoomLight);
                break;
            case 4:
                printf("Thank you for using the Smart Light Control System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}