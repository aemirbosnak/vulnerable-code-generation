//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare the light switch status
bool light_switch = false;

// Define the main function
int main() {
    // Greet the user
    printf("Howdy, human!\n");
    printf("Welcome to my not-so-smart home light control system.\n");

    // Create a loop to keep the program running
    while (true) {

        // Display the current light switch status
        printf("The light switch is currently %s.\n", light_switch ? "on" : "off");

        // Get the user's input
        char input;
        printf("What would you like to do?\n");
        printf("Type 'o' to turn the light on, 'f' to turn it off, or 'e' to exit.\n");
        scanf(" %c", &input);

        // Process the user's input
        switch (input) {
            case 'o':
                // Turn the light on
                light_switch = true;
                printf("Voilà! The light is now on.\n");
                break;
            case 'f':
                // Turn the light off
                light_switch = false;
                printf("Poof! The light is now off.\n");
                break;
            case 'e':
                // Exit the program
                printf("Farewell, human! May your light switch always be in your control.\n");
                return 0;
            default:
                // Handle invalid input
                printf("Sorry, I didn't understand that. Please try again.\n");
                break;
        }
    }

    return 0;
}