//FormAI DATASET v1.0 Category: Smart home light control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdbool.h>

bool isLightOn = false;

void turnOnLight() {
    printf("Turning on the lights!\n");
    isLightOn = true;
}

void turnOffLight() {
    printf("Turning off the lights!\n");
    isLightOn = false;
}

int main() {
    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Press 1 to turn on the lights.\n");
    printf("Press 2 to turn off the lights.\n");
    printf("Press 0 to exit.\n");

    int userInput;

    while (true) {
        printf("Enter your choice: ");
        scanf("%d", &userInput);

        switch (userInput) {
            case 0:
                printf("Exiting the program...\n");
                return 0;

            case 1:
                if (!isLightOn) {
                    turnOnLight();
                } else {
                    printf("The lights are already on.\n");
                }
                break;

            case 2:
                if (isLightOn) {
                    turnOffLight();
                } else {
                    printf("The lights are already off.\n");
                }
                break;

            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}