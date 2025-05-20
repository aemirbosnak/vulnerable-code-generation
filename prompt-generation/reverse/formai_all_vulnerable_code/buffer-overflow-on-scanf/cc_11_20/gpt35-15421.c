//FormAI DATASET v1.0 Category: Smart home light control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool isLightOn = false;

    printf("Welcome to Shape Shifting Smart Home Light Control!\n");
    printf("To turn on the light, say 'on'. To turn off the light, say 'off'.\n");
    printf("To change the color of the light, say 'color'. To exit, say 'exit'.\n");

    while (true) {
        char input[10];

        printf("Enter command: ");
        scanf("%s", input);

        if (strcmp(input, "on") == 0) {
            if (!isLightOn) {
                isLightOn = true;
                printf("Light is now on!\n");
            } else {
                printf("Light is already on!\n");
            }
        } else if (strcmp(input, "off") == 0) {
            if (isLightOn) {
                isLightOn = false;
                printf("Light is now off!\n");
            } else {
                printf("Light is already off!\n");
            }
        } else if (strcmp(input, "color") == 0) {
            char color[10];
            printf("Enter color (red, green, blue): ");
            scanf("%s", color);
            if (strcmp(color, "red") == 0) {
                printf("Light is now red!\n");
            } else if (strcmp(color, "green") == 0) {
                printf("Light is now green!\n");
            } else if (strcmp(color, "blue") == 0) {
                printf("Light is now blue!\n");
            } else {
                printf("Invalid color!\n");
            }
        } else if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}