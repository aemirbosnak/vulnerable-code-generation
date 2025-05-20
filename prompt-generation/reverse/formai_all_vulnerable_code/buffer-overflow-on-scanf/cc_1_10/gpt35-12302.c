//FormAI DATASET v1.0 Category: Smart home light control ; Style: introspective
#include <stdio.h>

// Light State enum
typedef enum {
    OFF,
    ON
} LightState;

// Light Switch function
void switchLight(LightState *state) {
    if (*state == OFF) {
        *state = ON;
    } else {
        *state = OFF;
    }
}

int main() {

    // Create light objects
    LightState livingRoomLight = OFF;
    LightState bedroomLight = OFF;
    LightState kitchenLight = OFF;
    LightState bathroomLight = OFF;
    LightState garageLight = OFF;

    // Loop until user exits
    int exit = 0;
    while (!exit) {

        // Display options to user
        printf("\nSelect an option:\n");
        printf("1. Turn living room light ");
        if (livingRoomLight == ON) {
            printf("off.\n");
        } else {
            printf("on.\n");
        }
        printf("2. Turn bedroom light ");
        if (bedroomLight == ON) {
            printf("off.\n");
        } else {
            printf("on.\n");
        }
        printf("3. Turn kitchen light ");
        if (kitchenLight == ON) {
            printf("off.\n");
        } else {
            printf("on.\n");
        }
        printf("4. Turn bathroom light ");
        if (bathroomLight == ON) {
            printf("off.\n");
        } else {
            printf("on.\n");
        }
        printf("5. Turn garage light ");
        if (garageLight == ON) {
            printf("off.\n");
        } else {
            printf("on.\n");
        }
        printf("6. Exit.\n");

        // Get user input
        int option = 0;
        printf("Enter option: ");
        scanf("%d", &option);

        // Switch light based on user input
        switch (option) {
            case 1:
                switchLight(&livingRoomLight);
                break;
            case 2:
                switchLight(&bedroomLight);
                break;
            case 3:
                switchLight(&kitchenLight);
                break;
            case 4:
                switchLight(&bathroomLight);
                break;
            case 5:
                switchLight(&garageLight);
                break;
            case 6:
                exit = 1;
                break;
            default:
                printf("Invalid option.\n");
                break;
        }

    }

    return 0;
}