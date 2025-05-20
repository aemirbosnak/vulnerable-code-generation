//FormAI DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    bool isLightOn = false;
    int lightIntensity = 0;

    printf("Welcome to the Smart Home Light Control System\n");

    while (true) {
        printf("\n");
        printf("Current light status: %s\n", isLightOn ? "ON" : "OFF");
        printf("Current light intensity: %d\n", lightIntensity);

        int choice;
        printf("\nAvailable actions:\n");
        printf("1. Turn %s the light\n", isLightOn ? "off" : "on");
        printf("2. Increase light intensity\n");
        printf("3. Decrease light intensity\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                isLightOn = !isLightOn;
                printf("Light turned %s\n", isLightOn ? "on" : "off");
                break;
            case 2:
                if (!isLightOn) {
                    printf("Error: Light is not turned on\n");
                } else if (lightIntensity == 100) {
                    printf("Error: Maximum light intensity reached\n");
                } else {
                    lightIntensity += 10;
                    printf("Light intensity increased to %d\n", lightIntensity);
                }
                break;
            case 3:
                if (!isLightOn) {
                    printf("Error: Light is not turned on\n");
                } else if (lightIntensity == 0) {
                    printf("Error: Minimum light intensity reached\n");
                } else {
                    lightIntensity -= 10;
                    printf("Light intensity decreased to %d\n", lightIntensity);
                }
                break;
            case 4:
                printf("Exiting Smart Home Light Control System\n");
                exit(0);
            default:
                printf("Error: Invalid choice\n");
                break;
        }
    }

    return 0;
}