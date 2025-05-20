//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int brightness; // 0 to 100
    int status; // 0 for off, 1 for on
} SmartLight;

void initializeLight(SmartLight *light, const char *name) {
    strncpy(light->name, name, NAME_LENGTH);
    light->brightness = 0; // initial brightness is off
    light->status = 0;     // initial status is off
}

void printLightStatus(SmartLight *light) {
    printf("Light: %s\n", light->name);
    printf("Status: %s\n", light->status ? "On" : "Off");
    printf("Brightness: %d%%\n\n", light->brightness);
}

void turnOnLight(SmartLight *light) {
    light->status = 1;
    light->brightness = 100; // Set to max brightness when turned on
    printf("The light '%s' has been turned on.\n\n", light->name);
}

void turnOffLight(SmartLight *light) {
    light->status = 0;
    light->brightness = 0; // Set to zero brightness when turned off
    printf("The light '%s' has been turned off.\n\n", light->name);
}

void setBrightness(SmartLight *light, int brightness) {
    if (light->status) {
        if (brightness >= 0 && brightness <= 100) {
            light->brightness = brightness;
            printf("Brightness of '%s' set to %d%%.\n\n", light->name, light->brightness);
        } else {
            printf("Brightness value out of range. Please use a value between 0 and 100.\n\n");
        }
    } else {
        printf("Cannot set brightness. The light '%s' is off.\n\n", light->name);
    }
}

void showMenu() {
    printf("------------------------------------------------\n");
    printf("Welcome to the Smart Light Control System\n");
    printf("1. Turn On Light\n");
    printf("2. Turn Off Light\n");
    printf("3. Set Brightness\n");
    printf("4. Show Light Status\n");
    printf("5. Exit\n");
    printf("------------------------------------------------\n");
}

int main() {
    SmartLight livingRoom, kitchen, bedroom;
    initializeLight(&livingRoom, "Living Room");
    initializeLight(&kitchen, "Kitchen");
    initializeLight(&bedroom, "Bedroom");

    int choice, brightness;

    while (1) {
        showMenu();
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Choose a light to turn on:\n1. Living Room\n2. Kitchen\n3. Bedroom\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (choice == 1) turnOnLight(&livingRoom);
                else if (choice == 2) turnOnLight(&kitchen);
                else if (choice == 3) turnOnLight(&bedroom);
                else printf("Invalid selection. Please try again.\n\n");
                break;

            case 2:
                printf("Choose a light to turn off:\n1. Living Room\n2. Kitchen\n3. Bedroom\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (choice == 1) turnOffLight(&livingRoom);
                else if (choice == 2) turnOffLight(&kitchen);
                else if (choice == 3) turnOffLight(&bedroom);
                else printf("Invalid selection. Please try again.\n\n");
                break;

            case 3:
                printf("Choose a light to set brightness:\n1. Living Room\n2. Kitchen\n3. Bedroom\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                printf("Enter brightness value (0-100): ");
                scanf("%d", &brightness);
                if (choice == 1) setBrightness(&livingRoom, brightness);
                else if (choice == 2) setBrightness(&kitchen, brightness);
                else if (choice == 3) setBrightness(&bedroom, brightness);
                else printf("Invalid selection. Please try again.\n\n");
                break;

            case 4:
                printLightStatus(&livingRoom);
                printLightStatus(&kitchen);
                printLightStatus(&bedroom);
                break;

            case 5:
                printf("Exiting Smart Light Control System. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please select a number between 1 and 5.\n\n");
        }
        sleep(1); // Short delay for user visibility
    }

    return 0;
}