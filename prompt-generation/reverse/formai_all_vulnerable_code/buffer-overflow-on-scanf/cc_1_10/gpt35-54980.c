//FormAI DATASET v1.0 Category: Smart home light control ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>

struct Light {
    int id;
    bool isOn;
    int brightness;
};

typedef struct Light Light;

void turnOn(Light* light) {
    light->isOn = true;
    printf("Light %d turned on.\n", light->id);
}

void turnOff(Light* light) {
    light->isOn = false;
    printf("Light %d turned off.\n", light->id);
}

void changeBrightness(Light* light, int brightness) {
    light->brightness = brightness;
    printf("Brightness of light %d changed to %d.\n", light->id, brightness);
}

int main() {
    // initialize lights
    Light livingRoom = {1, false, 0};
    Light kitchen = {2, false, 0};
    Light bedroom = {3, false, 0};

    char userChoice;
    int lightId;
    int brightness;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Turn on light\n");
        printf("2. Turn off light\n");
        printf("3. Change brightness of light\n");
        printf("4. Quit\n");

        scanf(" %c", &userChoice);

        switch (userChoice) {
            case '1':
                printf("Enter the id of the light you want to turn on: ");
                scanf("%d", &lightId);
                if (lightId == 1) {
                    turnOn(&livingRoom);
                } else if (lightId == 2) {
                    turnOn(&kitchen);
                } else if (lightId == 3) {
                    turnOn(&bedroom);
                } else {
                    printf("Invalid light id.\n");
                }
                break;
            case '2':
                printf("Enter the id of the light you want to turn off: ");
                scanf("%d", &lightId);
                if (lightId == 1) {
                    turnOff(&livingRoom);
                } else if (lightId == 2) {
                    turnOff(&kitchen);
                } else if (lightId == 3) {
                    turnOff(&bedroom);
                } else {
                    printf("Invalid light id.\n");
                }
                break;
            case '3':
                printf("Enter the id of the light you want to change brightness: ");
                scanf("%d", &lightId);
                if (lightId == 1) {
                    printf("Enter the brightness level (0-100): ");
                    scanf("%d", &brightness);
                    changeBrightness(&livingRoom, brightness);
                } else if (lightId == 2) {
                    printf("Enter the brightness level (0-100): ");
                    scanf("%d", &brightness);
                    changeBrightness(&kitchen, brightness);
                } else if (lightId == 3) {
                    printf("Enter the brightness level (0-100): ");
                    scanf("%d", &brightness);
                    changeBrightness(&bedroom, brightness);
                } else {
                    printf("Invalid light id.\n");
                }
                break;
            case '4':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid entry. Try again\n");
                break;
        }
    } while (userChoice != '4');

    return 0;
}