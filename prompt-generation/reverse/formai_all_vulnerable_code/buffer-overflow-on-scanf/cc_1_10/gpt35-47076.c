//FormAI DATASET v1.0 Category: Smart home light control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Smart Home Light Control Program

int main() {

    bool isLightOn = false; // Light off by default

    printf("Welcome to the Smart Home Light Control Program!\n");

    while(true) {

        printf("\nWhat would you like to do?\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Check if the light is on\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice); // Taking input from user

        switch(choice) {

            case 1:
                if (isLightOn == true) { // If light is already on
                    printf("The light is already on!\n");
                } else {
                    printf("Turning on the light...\n");
                    isLightOn = true;
                }
                break;

            case 2:
                if (isLightOn == false) { // If light is already off
                    printf("The light is already off!\n");
                } else {
                    printf("Turning off the light...\n");
                    isLightOn = false;
                }
                break;

            case 3:
                if (isLightOn == true) {
                    printf("The light is on!\n");
                } else {
                    printf("The light is off!\n");
                }
                break;

            case 4:
                printf("Thank you for using the Smart Home Light Control Program!\n");
                exit(0); // Exiting the program

            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}