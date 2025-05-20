//FormAI DATASET v1.0 Category: Smart home light control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    bool isLightOn = false; // initialize the light state to off
    int choice = 0; // initialize choice to 0

    // prompt user for input
    printf("Welcome to the Smart Home Light Control system!\n");
    printf("Please select an option:\n");
    printf("1. Turn on the light\n");
    printf("2. Turn off the light\n");
    printf("3. Exit\n");

    // loop until user chooses to exit
    while (choice != 3) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isLightOn) {
                    printf("The light is already on!\n");
                } else {
                    printf("Turning on the light...\n");
                    isLightOn = true;
                }
                break;

            case 2:
                if (!isLightOn) {
                    printf("The light is already off!\n");
                } else {
                    printf("Turning off the light...\n");
                    isLightOn = false;
                }
                break;

            case 3:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}