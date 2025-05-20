//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DRONE_BATTERY 100

int main() {
    int droneBattery = MAX_DRONE_BATTERY;
    bool isDroneOn = false;
    char userInput;
    
    do {
        // Display Drone's Battery Level
        printf("Drone Battery Level: %d%%", droneBattery);
        
        // Display Drone's On/Off Status
        if (isDroneOn) {
            printf("\nDrone is On");
        } else {
            printf("\nDrone is Off");
        }
        
        // Display Remote Control Menu
        printf("\n\n===== DRONE REMOTE CONTROL =====\n");
        printf("1. Turn On/Off Drone\n");
        printf("2. Fly Drone Up\n");
        printf("3. Fly Drone Down\n");
        printf("4. Land Drone\n");
        printf("5. Exit\n");
        printf("===============================\n");
        
        // Get User Input
        printf("\nSelect an option: ");
        scanf(" %c", &userInput);
        
        // Perform action based on user input
        switch(userInput) {
            case '1':
                // Turn On/Off Drone
                if (isDroneOn) {
                    isDroneOn = false;
                } else {
                    isDroneOn = true;
                }
                break;
            case '2':
                // Fly Drone Up
                if (!isDroneOn) {
                    printf("\nPlease turn on the Drone first!\n");
                } else {
                    droneBattery -= 5;
                    printf("\nFlying Drone Up...\n");
                }
                break;
            case '3':
                // Fly Drone Down
                if (!isDroneOn) {
                    printf("\nPlease turn on the Drone first!\n");
                } else {
                    droneBattery -= 5;
                    printf("\nFlying Drone Down...\n");
                }
                break;
            case '4':
                // Land Drone
                if (!isDroneOn) {
                    printf("\nPlease turn on the Drone first!\n");
                } else {
                    droneBattery -= 10;
                    printf("\nLanding Drone...\n");
                }
                break;
            case '5':
                // Exit
                printf("\nExiting Drone Remote Control...\n");
                break;
            default:
                printf("\nInvalid input! Please try again.\n");
        }
        
        // Check Drone Battery Level and Turn Off if Battery is low
        if (droneBattery <= 20 && isDroneOn) {
            printf("\nDrone Battery is low. Turning off Drone...\n");
            isDroneOn = false;
        }
        
        // Check if Drone Battery has Died
        if (droneBattery <= 0) {
            printf("\nDrone Battery has died. Exiting Drone Remote Control...\n");
            break;
        }
    } while (userInput != '5');
    
    return 0;
}