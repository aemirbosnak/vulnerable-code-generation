//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to C Drone Remote Control!\n");
    printf("Initializing connection...\n");

    // Connect to the drone
    int connected = 1;

    if (connected) {
        printf("Drone connected successfully!\n");
    } else {
        printf("Failed to connect to the drone.\n");
        return 1;
    }

    // Control the drone with the remote
    int battery = 100;
    int altitude = 0;

    while (1) {
        // Read user inputs
        char input;

        printf("Battery: %d%% | Altitude: %d m | Enter command (F - forward, B - back, L - left, R - right, U - up, D - down): ", battery, altitude);
        scanf(" %c", &input);

        // Process command
        switch (input) {
            case 'F':
                printf("Moving drone forward.\n");
                break;
            case 'B':
                printf("Moving drone back.\n");
                break;
            case 'L':
                printf("Moving drone left.\n");
                break;
            case 'R':
                printf("Moving drone right.\n");
                break;
            case 'U':
                altitude++;
                printf("Increasing altitude to %d m.\n", altitude);
                break;
            case 'D':
                if (altitude == 0) {
                    printf("Drone cannot go any lower.\n");
                } else {
                    altitude--;
                    printf("Decreasing altitude to %d m.\n", altitude);
                }
                break;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }

        // Check battery level
        battery -= 10;

        if (battery <= 0) {
            printf("Drone battery low. Returning to base.\n");
            break;
        }
    }

    printf("Shutting down drone.\n");
    printf("Closing connection.\n");

    return 0;
}