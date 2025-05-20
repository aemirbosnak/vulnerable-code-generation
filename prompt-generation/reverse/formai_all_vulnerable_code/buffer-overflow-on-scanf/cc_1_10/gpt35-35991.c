//FormAI DATASET v1.0 Category: Smart home light control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to turn lights on or off
void lightSwitch(bool status) {
    if (status) {
        printf("Lights turned ON!\n");
    } else {
        printf("Lights turned OFF!\n");
    }
}

int main() {
    bool light_status = false; // initially lights are turned off
    int choice; // for user input

    printf("Welcome to Smart Home Light Control!\n");

    // Loop for menu options
    while (true) {
        printf("\nSelect an option:\n");
        printf("1. Turn lights ON\n");
        printf("2. Turn lights OFF\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (light_status == true) {
                    printf("Lights already turned ON!\n");
                } else {
                    light_status = true;
                    lightSwitch(light_status);
                }
                break;

            case 2:
                if (light_status == false) {
                    printf("Lights already turned OFF!\n");
                } else {
                    light_status = false;
                    lightSwitch(light_status);
                }
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please select again.\n");
                break;
        }
    }

    return 0;
}