//FormAI DATASET v1.0 Category: Smart home light control ; Style: introspective
#include <stdio.h>
#include <stdbool.h>

// Define the state of the lights
bool living_room_lights = false;
bool kitchen_lights = false;

// Define functions to toggle the state of the lights
void toggle_living_room() {
    living_room_lights = !living_room_lights;
}
void toggle_kitchen() {
    kitchen_lights = !kitchen_lights;
}

// Define the main function
int main() {
    // Print a welcome message to the user
    printf("Welcome to the Smart Home Light Control System\n");

    // Define a variable to store the user's input
    int choice;

    // Start an infinite loop to keep the program running
    while (true) {
        // Print a menu of options for the user
        printf("\nPlease select an option:\n");
        printf("1. Toggle Living Room Lights\n");
        printf("2. Toggle Kitchen Lights\n");
        printf("3. Quit\n");

        // Get the user's choice
        scanf("%d", &choice);

        // Use a switch statement to toggle the lights or quit the program
        switch (choice) {
            case 1:
                toggle_living_room();
                printf("Living Room Lights toggled %s\n", living_room_lights ? "on" : "off");
                break;
            case 2:
                toggle_kitchen();
                printf("Kitchen Lights toggled %s\n", kitchen_lights ? "on" : "off");
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}