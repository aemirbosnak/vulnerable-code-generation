//FormAI DATASET v1.0 Category: Smart home automation ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>

int main() {

    bool kitchenLight = false;
    bool livingRoomTV = true;
    bool bedroomLight = false;

    printf("Welcome to your Smart Home!\n");

    while (1) { // infinite loop

        printf("\nPlease select an option: \n\n");
        printf("1. Turn on/off Kitchen Light\n");
        printf("2. Turn on/off Living Room TV\n");
        printf("3. Turn on/off Bedroom Light\n");
        printf("4. Quit the program\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                kitchenLight = !kitchenLight; // toggle kitchen light
                if (kitchenLight) {
                    printf("Kitchen Light has been turned on.\n");
                } else {
                    printf("Kitchen Light has been turned off.\n");
                }
                break;
            case 2:
                livingRoomTV = !livingRoomTV; // toggle living room TV
                if (livingRoomTV) {
                    printf("Living Room TV has been turned on.\n");
                } else {
                    printf("Living Room TV has been turned off.\n");
                }
                break;
            case 3:
                bedroomLight = !bedroomLight; // toggle bedroom light
                if (bedroomLight) {
                    printf("Bedroom Light has been turned on.\n");
                } else {
                    printf("Bedroom Light has been turned off.\n");
                }
                break;
            case 4:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid option, try again.\n");
        }
    }
    return 0;
}