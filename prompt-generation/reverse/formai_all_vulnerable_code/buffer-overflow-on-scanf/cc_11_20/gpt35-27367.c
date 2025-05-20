//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: detailed
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Drone status variables
    bool isOn = false;
    bool isFlying = false;
    bool isLanded = true;

    // Remote control input variables
    char input;

    printf("Welcome to the Drone Remote Control App!\n");

    // Main program loop
    while (true) {
        // Print out current drone status
        printf("Status:\n");
        printf("  Power: %s\n", isOn ? "ON" : "OFF");
        printf("  Flying: %s\n", isFlying ? "YES" : "NO");
        printf("  Landed: %s\n", isLanded ? "YES" : "NO");

        // Prompt user for input
        printf("\nEnter command (o) on/(f) fly/(l) land/(q) quit: ");
        scanf(" %c", &input);

        switch (input) {
            case 'o':
                // Turn on the drone if it's currently off
                if (!isOn) {
                    isOn = true;
                    printf("Drone is now powered ON.\n");
                } else {
                    printf("Drone is already powered ON.\n");
                }
                break;

            case 'f':
                // Check if the drone is powered on and landed
                if (!isOn) {
                    printf("Drone is not powered ON.\n");
                } else if (!isLanded) {
                    printf("Drone must land before taking off.\n");
                } else {
                    isFlying = true;
                    isLanded = false;
                    printf("Drone is now FLYING.\n");
                }
                break;

            case 'l':
                // Check if the drone is currently flying
                if (!isFlying) {
                    printf("Drone is not currently FLYING.\n");
                } else {
                    isFlying = false;
                    isLanded = true;
                    printf("Drone is now LANDED.\n");
                }
                break;

            case 'q':
                // Quit the program
                printf("Exiting Drone Remote Control App...\n");
                exit(0);

            default:
                // Invalid input
                printf("Invalid Input! Try again.\n");
        }
    }

    return 0;
}