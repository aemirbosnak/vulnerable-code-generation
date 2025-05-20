//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 5
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int isOn;
    int brightness; // 0 to 100 percent
} Light;

Light lights[MAX_LIGHTS];

void initLights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, NAME_LENGTH, "Light %d", i + 1);
        lights[i].isOn = 0;  // start as off
        lights[i].brightness = 0; // start at 0% brightness
    }
}

void displayMenu() {
    printf("\n----- Smart Home Light Control -----\n");
    printf("1. Turn On a Light\n");
    printf("2. Turn Off a Light\n");
    printf("3. Check Light Status\n");
    printf("4. Set Brightness\n");
    printf("5. View All Lights\n");
    printf("6. Exit\n");
    printf("------------------------------------\n");
    printf("Choose an option: ");
}

void turnOnLight(int index) {
    lights[index].isOn = 1;
    lights[index].brightness = 100; // default to 100% when turned on
    printf("%s is now ON with brightness set to %d%%.\n", lights[index].name, lights[index].brightness);
}

void turnOffLight(int index) {
    lights[index].isOn = 0;
    lights[index].brightness = 0;
    printf("%s is now OFF.\n", lights[index].name);
}

void checkLightStatus(int index) {
    if (lights[index].isOn) {
        printf("%s is ON with brightness at %d%%.\n", lights[index].name, lights[index].brightness);
    } else {
        printf("%s is OFF.\n", lights[index].name);
    }
}

void setBrightness(int index, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Brightness should be between 0 and 100.\n");
    } else {
        lights[index].brightness = brightness;
        printf("Brightness of %s set to %d%%.\n", lights[index].name, brightness);
    }
}

void viewAllLights() {
    printf("\n----- Current Light Status -----\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        checkLightStatus(i);
    }
    printf("--------------------------------\n");
}

int main() {
    initLights();
    int choice, lightNumber, brightness;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the light number to turn ON (1-%d): ", MAX_LIGHTS);
                scanf("%d", &lightNumber);
                if (lightNumber >= 1 && lightNumber <= MAX_LIGHTS) {
                    turnOnLight(lightNumber - 1);
                } else {
                    printf("Invalid light number.\n");
                }
                break;

            case 2:
                printf("Enter the light number to turn OFF (1-%d): ", MAX_LIGHTS);
                scanf("%d", &lightNumber);
                if (lightNumber >= 1 && lightNumber <= MAX_LIGHTS) {
                    turnOffLight(lightNumber - 1);
                } else {
                    printf("Invalid light number.\n");
                }
                break;

            case 3:
                printf("Enter the light number to check status (1-%d): ", MAX_LIGHTS);
                scanf("%d", &lightNumber);
                if (lightNumber >= 1 && lightNumber <= MAX_LIGHTS) {
                    checkLightStatus(lightNumber - 1);
                } else {
                    printf("Invalid light number.\n");
                }
                break;

            case 4:
                printf("Enter the light number to set brightness (1-%d): ", MAX_LIGHTS);
                scanf("%d", &lightNumber);
                if (lightNumber >= 1 && lightNumber <= MAX_LIGHTS) {
                    printf("Enter brightness (0-100): ");
                    scanf("%d", &brightness);
                    setBrightness(lightNumber - 1, brightness);
                } else {
                    printf("Invalid light number.\n");
                }
                break;

            case 5:
                viewAllLights();
                break;

            case 6:
                printf("Exiting Smart Home Light Control...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}