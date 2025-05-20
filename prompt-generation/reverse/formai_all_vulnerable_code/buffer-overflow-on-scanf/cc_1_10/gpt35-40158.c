//FormAI DATASET v1.0 Category: Smart home light control ; Style: complete
#include <stdio.h>
#include <stdlib.h>

/* Define light control variables */
int livingRoomLight = 0;
int bedroomLight = 0;
int kitchenLight = 0;

/* Define function to turn off all lights */
void turnOffAllLights(void) {
    livingRoomLight = 0;
    bedroomLight = 0;
    kitchenLight = 0;
    printf("All lights turned off.\n");
}

/* Define function to toggle living room light */
void toggleLivingRoomLight(void) {
    if(livingRoomLight == 0) {
        livingRoomLight = 1;
        printf("Living room light turned on.\n");
    } else {
        livingRoomLight = 0;
        printf("Living room light turned off.\n");
    }
}

/* Define function to toggle bedroom light */
void toggleBedroomLight(void) {
    if(bedroomLight == 0) {
        bedroomLight = 1;
        printf("Bedroom light turned on.\n");
    } else {
        bedroomLight = 0;
        printf("Bedroom light turned off.\n");
    }
}

/* Define function to toggle kitchen light */
void toggleKitchenLight(void) {
    if(kitchenLight == 0) {
        kitchenLight = 1;
        printf("Kitchen light turned on.\n");
    } else {
        kitchenLight = 0;
        printf("Kitchen light turned off.\n");
    }
}

/* Define main function */
int main() {
    int option;
    printf("Welcome to Smart Home Light Control Panel!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Turn off all lights\n");
        printf("2. Toggle living room light\n");
        printf("3. Toggle bedroom light\n");
        printf("4. Toggle kitchen light\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                turnOffAllLights();
                break;
            case 2:
                toggleLivingRoomLight();
                break;
            case 3:
                toggleBedroomLight();
                break;
            case 4:
                toggleKitchenLight();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0); /* Terminate program */
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }

    } while (option != 5);

    return 0;
}