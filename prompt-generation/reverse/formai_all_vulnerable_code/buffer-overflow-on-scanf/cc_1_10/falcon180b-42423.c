//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define NUM_LIGHTS 5

void turnOnLight(int lightIndex) {
    printf("Turning on light %d\n", lightIndex);
}

void turnOffLight(int lightIndex) {
    printf("Turning off light %d\n", lightIndex);
}

void toggleLight(int lightIndex) {
    printf("Toggling light %d\n", lightIndex);
}

void setLightBrightness(int lightIndex, int brightness) {
    printf("Setting light %d brightness to %d\n", lightIndex, brightness);
}

int main() {
    int choice;
    int lightIndex;
    int brightness;

    do {
        printf("Smart Home Light Control\n");
        printf("1. Turn on light\n");
        printf("2. Turn off light\n");
        printf("3. Toggle light\n");
        printf("4. Set light brightness\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light index (1 to %d): ", NUM_LIGHTS);
                scanf("%d", &lightIndex);
                turnOnLight(lightIndex);
                break;
            case 2:
                printf("Enter light index (1 to %d): ", NUM_LIGHTS);
                scanf("%d", &lightIndex);
                turnOffLight(lightIndex);
                break;
            case 3:
                printf("Enter light index (1 to %d): ", NUM_LIGHTS);
                scanf("%d", &lightIndex);
                toggleLight(lightIndex);
                break;
            case 4:
                printf("Enter light index (1 to %d): ", NUM_LIGHTS);
                scanf("%d", &lightIndex);
                printf("Enter brightness (1 to 100): ");
                scanf("%d", &brightness);
                setLightBrightness(lightIndex, brightness);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}