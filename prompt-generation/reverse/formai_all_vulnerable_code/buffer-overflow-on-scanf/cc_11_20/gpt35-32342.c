//FormAI DATASET v1.0 Category: Smart home light control ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Define macros for light control */
#define LIGHT_ON 1
#define LIGHT_OFF 0
#define BRIGHTNESS_HIGH 100
#define BRIGHTNESS_MEDIUM 50
#define BRIGHTNESS_LOW 10

int main() {
    int lightStatus = LIGHT_OFF;
    int brightnessLevel = BRIGHTNESS_MEDIUM;
    char input[10];

    printf("Welcome to your Smart Home Light Control\n");

    while (1) {
        printf("Enter 'on' to turn on the lights, 'off' to turn off the lights, or 'brightness' to change the brightness level\n");
        scanf("%s", input);

        if (strcmp(input, "on") == 0) {
            if (lightStatus == LIGHT_ON) {
                printf("Lights are already on!\n");
            } else {
                lightStatus = LIGHT_ON;
                printf("Turning on the lights...\n");
            }
        } else if (strcmp(input, "off") == 0) {
            if (lightStatus == LIGHT_OFF) {
                printf("Lights are already off!\n");
            } else {
                lightStatus = LIGHT_OFF;
                printf("Turning off the lights...\n");
            }
        } else if (strcmp(input, "brightness") == 0) {
            printf("Enter 'high' to set brightness to high, 'medium' to set brightness to medium, or 'low' to set brightness to low\n");
            scanf("%s", input);

            if (strcmp(input, "high") == 0) {
                brightnessLevel = BRIGHTNESS_HIGH;
                printf("Brightness level set to high\n");
            } else if (strcmp(input, "medium") == 0) {
                brightnessLevel = BRIGHTNESS_MEDIUM;
                printf("Brightness level set to medium\n");
            } else if (strcmp(input, "low") == 0) {
                brightnessLevel = BRIGHTNESS_LOW;
                printf("Brightness level set to low\n");
            } else {
                printf("Invalid input. Try again.\n");
            }
        } else {
            printf("Invalid input. Try again.\n");
        }

        // Simulate light transition
        if (lightStatus == LIGHT_ON) {
            printf("Lights are now on with a brightness level of %d%%\n", brightnessLevel);
        } else {
            printf("Lights are now off.\n");
        }

        // Sleep for 3 seconds
        sleep(3);
    }

    return 0;
}