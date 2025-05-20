//FormAI DATASET v1.0 Category: Smart home light control ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to turn on the light
void turn_on_light() {
    printf("Light turned on!\n");
}

// Function to turn off the light
void turn_off_light() {
    printf("Light turned off!\n");
}

int main() {
    bool light_status = false; // Assume light is turned off initially

    printf("Welcome to smart home light control program!\n\n");

    // Loop until user chooses to exit
    while (true) {
        int choice;

        // Display menu options
        printf("Enter your choice:\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Exit the program\n");

        // Get user's choice
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (light_status) {
                    printf("Light is already turned on!\n");
                } else {
                    turn_on_light();
                    light_status = true;
                }
                break;

            case 2:
                if (!light_status) {
                    printf("Light is already turned off!\n");
                } else {
                    turn_off_light();
                    light_status = false;
                }
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice, please try again!\n\n");
                break;
        }

        printf("\n");
    }

    return 0;
}