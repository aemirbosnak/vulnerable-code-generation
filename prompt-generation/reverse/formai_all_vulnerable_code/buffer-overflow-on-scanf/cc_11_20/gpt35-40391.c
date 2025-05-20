//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C Drone Remote Control program!\n");

    // Initialize the drone state
    int droneState = 0;

    // Main loop
    while (1) {
        // Print current drone state
        printf("Current drone state: %d\n", droneState);

        // Ask for user input
        printf("What command would you like to send to the drone?\n");
        printf("1. Take off\n");
        printf("2. Land\n");
        printf("3. Move forward\n");
        printf("4. Move backward\n");
        printf("5. Move left\n");
        printf("6. Move right\n");
        printf("7. Ascend\n");
        printf("8. Descend\n");
        printf("9. Quit\n");

        int userCommand;
        scanf("%d", &userCommand);

        // Process user input
        switch(userCommand) {
            case 1: // Take off
                if (droneState == 0) { // Drone is on the ground
                    droneState = 1; // Drone is in the air
                    printf("Drone takes off!\n");
                } else {
                    printf("Drone is already in the air!\n");
                }
                break;
            case 2: // Land
                if (droneState == 1) { // Drone is in the air
                    droneState = 0; // Drone is on the ground
                    printf("Drone lands!\n");
                } else {
                    printf("Drone is already on the ground!\n");
                }
                break;
            case 3: // Move forward
                if (droneState == 1) { // Drone is in the air
                    printf("Drone moves forward!\n");
                } else {
                    printf("Drone is not in the air!\n");
                }
                break;
             case 4: // Move backward
                if (droneState == 1) { // Drone is in the air
                    printf("Drone moves backward!\n");
                } else {
                    printf("Drone is not in the air!\n");
                }
                break;
            case 5: // Move left
                if (droneState == 1) { // Drone is in the air
                    printf("Drone moves left!\n");
                } else {
                    printf("Drone is not in the air!\n");
                }
                break;
             case 6: // Move right
                if (droneState == 1) { // Drone is in the air
                    printf("Drone moves right!\n");
                } else {
                    printf("Drone is not in the air!\n");
                }
                break;
            case 7: // Ascend
                if (droneState == 1) { // Drone is in the air
                    printf("Drone ascends!\n");
                } else {
                    printf("Drone is not in the air!\n");
                }
                break;
            case 8: // Descend
                if (droneState == 1) { // Drone is in the air
                    printf("Drone descends!\n");
                } else {
                    printf("Drone is not in the air!\n");
                }
                break;
            case 9: // Quit
                printf("Thank you for using the C Drone Remote Control program! Goodbye!\n");
                exit(0);
            default: // Invalid command
                printf("Invalid command! Please try again.\n");
                break;
        }
    }

    return 0;
}