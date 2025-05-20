//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 5
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int brightness; // Range from 0 to 100
    char color[NAME_LENGTH];
    int is_on; // 1 for ON, 0 for OFF
} SmartLight;

SmartLight lights[MAX_LIGHTS];

void initializeLights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, NAME_LENGTH, "Light %d", i + 1);
        lights[i].brightness = 100; // Default brightness
        strcpy(lights[i].color, "White"); // Default color
        lights[i].is_on = 1; // Lights are ON by default
    }
}

void displayLightStatus() {
    printf("\nCurrent Status of Smart Lights:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].is_on ? "ON" : "OFF");
        printf("Brightness: %d%%\n", lights[i].brightness);
        printf("Color: %s\n", lights[i].color);
        printf("-------------------------\n");
    }
}

void turnOnLight(int index) {
    if (index >= 0 && index < MAX_LIGHTS) {
        lights[index].is_on = 1;
        printf("%s is now ON!\n", lights[index].name);
    } else {
        printf("Invalid light index!\n");
    }
}

void turnOffLight(int index) {
    if (index >= 0 && index < MAX_LIGHTS) {
        lights[index].is_on = 0;
        printf("%s is now OFF!\n", lights[index].name);
    } else {
        printf("Invalid light index!\n");
    }
}

void setBrightness(int index, int brightness) {
    if (index >= 0 && index < MAX_LIGHTS) {
        if (brightness >= 0 && brightness <= 100) {
            lights[index].brightness = brightness;
            printf("Brightness of %s set to %d%%.\n", lights[index].name, brightness);
        } else {
            printf("Brightness must be between 0 and 100!\n");
        }
    } else {
        printf("Invalid light index!\n");
    }
}

void setColor(int index, const char* color) {
    if (index >= 0 && index < MAX_LIGHTS) {
        strncpy(lights[index].color, color, NAME_LENGTH);
        printf("Color of %s set to %s.\n", lights[index].name, lights[index].color);
    } else {
        printf("Invalid light index!\n");
    }
}

void controlLights() {
    int choice, index, brightness;
    char color[NAME_LENGTH];

    do {
        printf("\nSmart Light Control Menu:\n");
        printf("1. Display Light Status\n");
        printf("2. Turn On a Light\n");
        printf("3. Turn Off a Light\n");
        printf("4. Set Brightness\n");
        printf("5. Change Color\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayLightStatus();
                break;
            case 2:
                printf("Enter light index (0 to %d): ", MAX_LIGHTS - 1);
                scanf("%d", &index);
                turnOnLight(index);
                break;
            case 3:
                printf("Enter light index (0 to %d): ", MAX_LIGHTS - 1);
                scanf("%d", &index);
                turnOffLight(index);
                break;
            case 4:
                printf("Enter light index (0 to %d): ", MAX_LIGHTS - 1);
                scanf("%d", &index);
                printf("Enter brightness (0 to 100): ");
                scanf("%d", &brightness);
                setBrightness(index, brightness);
                break;
            case 5:
                printf("Enter light index (0 to %d): ", MAX_LIGHTS - 1);
                scanf("%d", &index);
                printf("Enter color: ");
                scanf("%s", color);
                setColor(index, color);
                break;
            case 6:
                printf("Exiting Smart Light Control. Bye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);
}

int main() {
    initializeLights();
    controlLights();
    return 0;
}