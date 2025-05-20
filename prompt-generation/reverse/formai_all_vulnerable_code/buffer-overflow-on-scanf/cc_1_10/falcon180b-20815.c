//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init() {
    printf("Smart Home Light Control\n");
    printf("-------------------------\n");
    printf("1. Turn on light\n");
    printf("2. Turn off light\n");
    printf("3. Set light brightness\n");
    printf("4. Exit\n");
}

void turnOnLight() {
    printf("Light turned on\n");
}

void turnOffLight() {
    printf("Light turned off\n");
}

void setLightBrightness() {
    int brightness;
    printf("Enter brightness level (0-100): ");
    scanf("%d", &brightness);
    printf("Light brightness set to %d\n", brightness);
}

int main() {
    int choice;
    bool exit = false;

    init();

    while (!exit) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                turnOnLight();
                break;
            case 2:
                turnOffLight();
                break;
            case 3:
                setLightBrightness();
                break;
            case 4:
                exit = true;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}