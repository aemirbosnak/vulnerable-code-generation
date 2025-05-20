//FormAI DATASET v1.0 Category: Smart home light control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int mainLights = 0;
int bedroomLights = 0;
int kitchenLights = 0;

// Function to turn on/off main lights
void mainLightControl(int status) {
    if (status == 1) {
        mainLights = 1;
        printf("Main lights turned on.\n");
    } else {
        mainLights = 0;
        printf("Main lights turned off.\n");
    }
}

// Function to turn on/off bedroom lights
void bedroomLightControl(int status) {
    if (status == 1) {
        bedroomLights = 1;
        printf("Bedroom lights turned on.\n");
    } else {
        bedroomLights = 0;
        printf("Bedroom lights turned off.\n");
    }
}

// Function to turn on/off kitchen lights
void kitchenLightControl(int status) {
    if (status == 1) {
        kitchenLights = 1;
        printf("Kitchen lights turned on.\n");
    } else {
        kitchenLights = 0;
        printf("Kitchen lights turned off.\n");
    }
}

// Main function
int main() {
    int choice, status;

    // Loop until user chooses to exit
    while (1) {
        printf("\nEnter your choice:\n1. Turn main lights on/off\n2. Turn bedroom lights on/off\n3. Turn kitchen lights on/off\n4. Exit program\n");
        scanf("%d", &choice);

        // Switch case depending on user choice
        switch(choice) {
            case 1:
                printf("\nEnter 1 to turn on main lights or 0 to turn off: ");
                scanf("%d", &status);
                mainLightControl(status);
                break;

            case 2:
                printf("\nEnter 1 to turn on bedroom lights or 0 to turn off: ");
                scanf("%d", &status);
                bedroomLightControl(status);
                break;

            case 3:
                printf("\nEnter 1 to turn on kitchen lights or 0 to turn off: ");
                scanf("%d", &status);
                kitchenLightControl(status);
                break;

            case 4:
                printf("\nExiting program.\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}