//FormAI DATASET v1.0 Category: Smart home light control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "smartHomePassword" // Define the smart home password
#define MAX_ATTEMPTS 3 // Define the maximum login attempts

int main() {
    int attempts = 0; // Keep track of login attempts
    int lightStatus = 0; // Initialize light status to off

    printf("Welcome to the Smart Home Light Control System\n");

    while (attempts < MAX_ATTEMPTS) { // Loop until maximum attempts is reached
        char password[20]; // Initialize password variable
        printf("Please enter the system password: ");
        scanf("%s", password);

        if(strcmp(password, PASSWORD) == 0) { // Compare passwords
            printf("You have successfully logged in!\n");

            // Light control loop
            while (1) {
                printf("Enter 1 to turn the light ON and 0 to turn it OFF: ");
                int choice;
                scanf("%d", &choice);

                if (choice == 0) {
                    // Turn off the light
                    lightStatus = 0;
                    printf("The light is now OFF.\n");
                } else if (choice == 1) {
                    // Turn on the light
                    lightStatus = 1;
                    printf("The light is now ON.\n");
                } else {
                    printf("Invalid input. Please try again.\n");
                }

                // Ask user if they want to continue or exit
                printf("Enter 1 to continue or 0 to exit: ");
                int continueChoice;
                scanf("%d", &continueChoice);

                if (continueChoice == 0) {
                    printf("Exiting the Smart Home Light Control System...\n");
                    break;
                }
            }

            break;
        } else {
            printf("Incorrect password. Please try again.\n");
            attempts++;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Max login attempts exceeded. Exiting the Smart Home Light Control System...\n");
    }

    return 0;
}