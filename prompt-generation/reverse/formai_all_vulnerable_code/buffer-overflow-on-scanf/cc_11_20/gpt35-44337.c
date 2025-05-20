//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Initialize drone status variables
    bool isArmed = false;
    bool isFlying = false;
    int batteryLevel = 100;
    
    while (true) {
        // Display menu options
        printf("\nDrone Remote Control Menu:\n");
        printf("1. Arm the drone\n");
        printf("2. Take off\n");
        printf("3. Land\n");
        printf("4. Increase altitude\n");
        printf("5. Decrease altitude\n");
        printf("6. Disarm the drone\n");
        printf("7. Check battery level\n");
        printf("8. Exit program\n");
        printf("Please enter a menu option number: ");
        
        // Get user input for menu option
        int option;
        scanf("%d", &option);
        printf("\n");
        
        // Check selected menu option and perform corresponding action
        switch (option) {
            case 1:
                if (isArmed) {
                    printf("Drone is already armed.\n");
                } else {
                    isArmed = true;
                    printf("Drone is armed.\n");
                }
                break;
            case 2:
                if (isArmed) {
                    if (isFlying) {
                        printf("Drone is already flying.\n");
                    } else {
                        isFlying = true;
                        printf("Drone has taken off.\n");
                    }
                } else {
                    printf("Drone must be armed before takeoff.\n");
                }
                break;
            case 3:
                if (isFlying) {
                    isFlying = false;
                    printf("Drone has landed.\n");
                } else {
                    printf("Drone is not flying.\n");
                }
                break;
            case 4:
                if (isFlying) {
                    printf("Increase altitude by how much (in meters)? ");
                    int increase;
                    scanf("%d", &increase);
                    printf("\n");
                    printf("Drone altitude increased by %d meters.\n", increase);
                } else {
                    printf("Drone must be flying to adjust altitude.\n");
                }
                break;
            case 5:
                if (isFlying) {
                    printf("Decrease altitude by how much (in meters)? ");
                    int decrease;
                    scanf("%d", &decrease);
                    printf("\n");
                    printf("Drone altitude decreased by %d meters.\n", decrease);
                } else {
                    printf("Drone must be flying to adjust altitude.\n");
                }
                break;
            case 6:
                if (isArmed) {
                    if (isFlying) {
                        printf("Drone must land before disarming.\n");
                    } else {
                        isArmed = false;
                        printf("Drone is disarmed.\n");
                    }
                } else {
                    printf("Drone is already disarmed.\n");
                }
                break;
            case 7:
                printf("Battery level: %d%%\n", batteryLevel);
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid menu option.\n");
                break;
        }
        
        // Check battery level and give warning if low
        if (batteryLevel <= 10) {
            printf("WARNING: Low battery level!\n");
        }
        
        // Decrease battery level with each iteration of loop
        batteryLevel--;
    }
    
    return 0;
}