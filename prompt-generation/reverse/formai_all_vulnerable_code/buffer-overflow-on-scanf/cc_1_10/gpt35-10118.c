//FormAI DATASET v1.0 Category: Smart home light control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to turn the light on
void turn_on() {
    printf("Turning on the light...\n");
    // Code to turn on the light goes here
}

// Function to turn the light off
void turn_off() {
    printf("Turning off the light...\n");
    // Code to turn off the light goes here
}

// Function to check the current state of the light
bool is_on() {
    // Code to check the current state of the light goes here
    return true; // Assuming light is always on for the purpose of this example
}

// Main function to control the light
int main() {
    char input;
    printf("Welcome to the Smart Home Light Control Program!\n");
    while (true) {
        printf("Enter '1' to turn on the light\n");
        printf("Enter '2' to turn off the light\n");
        printf("Enter '3' to check the current state of the light\n");
        printf("Enter '0' to exit the program\n");
        printf("Enter your choice: ");
        scanf(" %c", &input);
        switch (input) {
            case '1':
                turn_on();
                break;
            case '2':
                turn_off();
                break;
            case '3':
                if (is_on()) {
                    printf("The light is currently on.\n");
                } else {
                    printf("The light is currently off.\n");
                }
                break;
            case '0':
                printf("Thank you for using the Smart Home Light Control Program!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}