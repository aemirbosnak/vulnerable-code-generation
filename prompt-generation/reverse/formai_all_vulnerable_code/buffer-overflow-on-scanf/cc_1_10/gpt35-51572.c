//FormAI DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>

// Define constants for light status
#define LIGHT_ON true
#define LIGHT_OFF false

// Initialize the light status to off
bool light_status = LIGHT_OFF;

// Function to toggle the light status
void toggle_light() {
    light_status = !light_status;
}

int main() {
    printf("Welcome to Smart Home Light Control\n\n");

    // Loop to continuously ask user for input
    while (true) {
        printf("Press 1 to turn the light on\n");
        printf("Press 2 to turn the light off\n");
        printf("Press 3 to toggle the light\n");
        printf("Press 4 to exit\n\n");

        int user_input;
        scanf("%d", &user_input);

        // Use a switch statement to handle user input
        switch(user_input) {
            case 1:
                light_status = LIGHT_ON;
                printf("Light turned on\n\n");
                break;
            case 2:
                light_status = LIGHT_OFF;
                printf("Light turned off\n\n");
                break;
            case 3:
                toggle_light();
                if (light_status == LIGHT_ON) {
                    printf("Light turned on\n\n");
                } else {
                    printf("Light turned off\n\n");
                }
                break;
            case 4:
                printf("Thank you for using Smart Home Light Control!\n");
                return 0; // Exit the program
            default:
                printf("Invalid input\n\n");
        }
    }
    return 0;
}