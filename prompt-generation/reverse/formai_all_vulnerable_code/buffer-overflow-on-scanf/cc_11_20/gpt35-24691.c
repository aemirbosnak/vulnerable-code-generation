//FormAI DATASET v1.0 Category: Smart home light control ; Style: irregular
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isLightOn = false;
    int lightIntensity = 0;
    char userChoice;

    printf("Welcome to Smart Home Light Control System\n");

    while (true) {
        if (isLightOn) {
            printf("The light is currently on with %d intensity level.\n", lightIntensity);
        } else {
            printf("The light is currently off.\n");
        }

        printf("Please enter your choice:\n");
        printf("1. Turn the light on\n");
        printf("2. Turn the light off\n");
        printf("3. Increase light intensity\n");
        printf("4. Decrease light intensity\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf(" %c", &userChoice);

        switch(userChoice) {
            case '1':
                isLightOn = true;
                printf("The light has been turned on.\n");
                break;
            case '2':
                isLightOn = false;
                printf("The light has been turned off.\n");
                break;
            case '3':
                if (isLightOn && lightIntensity < 10) {
                    lightIntensity++;
                    printf("The light intensity has been increased to %d.\n", lightIntensity);
                } else if (lightIntensity >= 10) {
                    printf("The light intensity is already at maximum level.\n");
                } else {
                    printf("The light is currently off, please turn it on first.\n");
                }
                break;
            case '4':
                if (isLightOn && lightIntensity > 0) {
                    lightIntensity--;
                    printf("The light intensity has been decreased to %d.\n", lightIntensity);
                } else if (lightIntensity <= 0) {
                    printf("The light intensity is already at minimum level.\n");
                } else {
                    printf("The light is currently off, please turn it on first.\n");
                }
                break;
            case '5':
                printf("Thank you for using Smart Home Light Control System.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}