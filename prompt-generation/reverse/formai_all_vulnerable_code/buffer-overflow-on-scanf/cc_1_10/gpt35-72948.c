//FormAI DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>

float roomTemp = 23.5;    // default room temperature
char lightStatus = 'N';   // light status turned off by default
int lightIntensity = 0;   // light intensity at 0 by default

void turnOnLight() {
   lightStatus = 'Y';
   printf("The light has been turned on.\n");
}

void turnOffLight() {
    lightStatus = 'N';
    printf("The light has been turned off.\n");
}

void changeLightIntensity(int newIntensity) {
    lightIntensity = newIntensity;
    printf("The light intensity has been set to %d.\n", lightIntensity);
}

void adjustRoomTemp(float newTemp) {
    roomTemp = newTemp;
    printf("The new room temperature is %.1f.\n", roomTemp);
}

int main() {
    int selection;

    printf("*** Smart Home Light Control ***\n");
    printf("1. Turn Light on\n");
    printf("2. Turn Light off\n");
    printf("3. Change Light Intensity\n");
    printf("4. Adjust Room Temperature\n");
    printf("0. Exit\n");

    do {
        printf("Enter selection: ");
        scanf("%d", &selection);

        switch(selection) {
            case 1:
                if (lightStatus == 'N') {
                    turnOnLight();
                } else {
                    printf("The light is already on.\n");
                }
                break;

            case 2:
                if (lightStatus == 'Y') {
                    turnOffLight();
                } else {
                    printf("The light is already off.\n");
                }
                break;

            case 3:
                printf("Enter new light intensity (0 to 100): ");
                scanf("%d", &lightIntensity);
                if (lightIntensity < 0 || lightIntensity > 100) {
                    printf("Invalid light intensity!\n");
                } else {
                    changeLightIntensity(lightIntensity);
                }
                break;

            case 4:
                printf("Enter new room temperature: ");
                scanf("%f", &roomTemp);
                adjustRoomTemp(roomTemp);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid selection.\n");
                break;
        }
    } while(selection != 0);

    return 0;
}