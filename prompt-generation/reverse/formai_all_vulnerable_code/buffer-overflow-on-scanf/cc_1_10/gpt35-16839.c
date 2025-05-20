//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_LIGHTS 3

struct Light {
    int id;
    int status; // 0 = off, 1 = on
    int brightness; // 0 (minimum) to 10 (maximum)
};

void printWelcomeMessage() {
    printf("Welcome to Smart Home Light Control System!\n\n");
}

void printUserOptions() {
    printf("Please select your desired option:\n");
    printf("1. Turn on a light\n");
    printf("2. Turn off a light\n");
    printf("3. Adjust brightness of a light\n");
    printf("4. Show status of all lights\n");
    printf("5. Exit\n");
}

void printLightStatus(struct Light light) {
    printf("Light %d is currently %s, with brightness level %d.\n", light.id, light.status == 1 ? "on" : "off", light.brightness);
}

void printAllLightStatus(struct Light lights[NUM_LIGHTS]) {
    printf("Current status of all lights:\n\n");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printLightStatus(lights[i]);
    }
}

int getInput(int min, int max) {
    int input;
    do {
        printf("Please enter your choice (%d-%d): ", min, max);
        scanf("%d", &input);
    } while (input < min || input > max);
    return input;
}

void turnLightOn(struct Light *light) {
    light->status = 1;
    printf("Light %d has been turned on.\n", light->id);
}

void turnLightOff(struct Light *light) {
    light->status = 0;
    printf("Light %d has been turned off.\n", light->id);
}

void adjustBrightness(struct Light *light, int brightness) {
    light->brightness = brightness;
    printf("Brightness of light %d has been adjusted to %d.\n", light->id, light->brightness);
}

int main() {
    srand(time(0));
    struct Light lights[NUM_LIGHTS];
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i].id = i + 1;
        lights[i].status = rand() % 2; // randomly assign on/off status
        lights[i].brightness = rand() % 11; // randomly assign brightness level
    }

    printWelcomeMessage();

    int choice;
    do {
        printUserOptions();
        choice = getInput(1, 5);

        switch (choice) {
            case 1:
                printf("\n");
                printAllLightStatus(lights);
                int lightOn;
                do {
                    printf("\nPlease enter the ID of the light you want to turn on (1-%d): ", NUM_LIGHTS);
                    scanf("%d", &lightOn);
                } while (lightOn < 1 || lightOn > NUM_LIGHTS);
                turnLightOn(&lights[lightOn - 1]);
                break;
            case 2:
                printf("\n");
                printAllLightStatus(lights);
                int lightOff;
                do {
                    printf("\nPlease enter the ID of the light you want to turn off (1-%d): ", NUM_LIGHTS);
                    scanf("%d", &lightOff);
                } while (lightOff < 1 || lightOff > NUM_LIGHTS);
                turnLightOff(&lights[lightOff - 1]);
                break;
            case 3:
                printf("\n");
                printAllLightStatus(lights);
                int lightBrightness;
                int brightness;
                do {
                    printf("\nPlease enter the ID of the light you want to adjust the brightness (1-%d): ", NUM_LIGHTS);
                    scanf("%d", &lightBrightness);
                } while (lightBrightness < 1 || lightBrightness > NUM_LIGHTS);
                printf("Please enter the new brightness level (0-10): ");
                scanf("%d", &brightness);
                while (brightness < 0 || brightness > 10) {
                    printf("Invalid input. Please enter a number between 0 and 10: ");
                    scanf("%d", &brightness);
                }
                adjustBrightness(&lights[lightBrightness - 1], brightness);
                break;
            case 4:
                printf("\n");
                printAllLightStatus(lights);
                break;
            default:
                break;
        }
        printf("\n");
    } while (choice != 5);

    printf("Thank you for using Smart Home Light Control System.\n");

    return 0;
}