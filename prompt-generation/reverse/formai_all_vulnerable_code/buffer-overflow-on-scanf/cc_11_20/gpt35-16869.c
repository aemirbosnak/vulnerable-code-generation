//FormAI DATASET v1.0 Category: Smart home light control ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

int main() {
    int livingRoomLight = 0, bedroomLight = 0, kitchenLight = 0;
    bool isLivingRoomOn = false, isBedroomOn = false, isKitchenOn = false;
    char input;

    while (true) {
        printf("Which room would you like to control? (L)iving Room, (B)edroom, (K)itchen, (E)xit\n");
        scanf(" %c", &input);

        switch(input) {
            case 'L':
            case 'l':
                printf("Living Room Lights: %d\n1. Turn On\n2. Turn Off\n", livingRoomLight);
                scanf(" %d", &input);
                if (input == 1) {
                    isLivingRoomOn = true;
                    livingRoomLight = 100;
                    printf("Turning on Living Room Lights.\n");
                } else if (input == 2) {
                    isLivingRoomOn = false;
                    livingRoomLight = 0;
                    printf("Turning off Living Room Lights.\n");
                } else {
                    printf("Invalid input, please try again.\n");
                }
                break;
            case 'B':
            case 'b':
                printf("Bedroom Lights: %d\n1. Turn On\n2. Turn Off\n", bedroomLight);
                scanf(" %d", &input);
                if (input == 1) {
                    isBedroomOn = true;
                    bedroomLight = 75;
                    printf("Turning on Bedroom Lights.\n");
                } else if (input == 2) {
                    isBedroomOn = false;
                    bedroomLight = 0;
                    printf("Turning off Bedroom Lights.\n");
                } else {
                    printf("Invalid input, please try again.\n");
                }
                break;
            case 'K':
            case 'k':
                printf("Kitchen Lights: %d\n1. Turn On\n2. Turn Off\n", kitchenLight);
                scanf(" %d", &input);
                if (input == 1) {
                    isKitchenOn = true;
                    kitchenLight = 50;
                    printf("Turning on Kitchen Lights.\n");
                } else if (input == 2) {
                    isKitchenOn = false;
                    kitchenLight = 0;
                    printf("Turning off Kitchen Lights.\n");
                } else {
                    printf("Invalid input, please try again.\n");
                }
                break;
            case 'E':
            case 'e':
                printf("Exiting Light Control.\n");
                return 0;
            default:
                printf("Invalid input, please try again.\n");
                break;
        }
    }
}