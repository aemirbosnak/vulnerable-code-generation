//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Function to control drone and its movements
void droneControl(char action, int distance, int speed) {
    printf("Performing %c movement for %d meters at %d kph.\n", action, distance, speed);
}

int main() {
    // Display menu to select drone action
    printf("Welcome to C Drone Remote Control Program!\n");
    printf("Please select an action:\n");
    printf("1. Takeoff\n");
    printf("2. Land\n");
    printf("3. Forward\n");
    printf("4. Backward\n");
    printf("5. Right\n");
    printf("6. Left\n");

    // Get user input for drone action
    int choice;
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    // Perform selected drone action
    switch(choice) {
        case 1:
            printf("Performing takeoff sequence.\n");
            droneControl('T', 0, 0);
            printf("Drone is now in the air!\n");
            break;
        case 2:
            printf("Initiating landing sequence.\n");
            droneControl('L', 0, 0);
            printf("Drone has landed safely.\n");
            break;
        case 3:
            printf("Performing forward movement.\n");
            printf("Enter distance (meters): ");
            int distanceF;
            scanf("%d", &distanceF);
            printf("Enter speed (kph): ");
            int speedF;
            scanf("%d", &speedF);
            droneControl('F', distanceF, speedF);
            break;
        case 4:
            printf("Performing backward movement.\n");
            printf("Enter distance (meters): ");
            int distanceB;
            scanf("%d", &distanceB);
            printf("Enter speed (kph): ");
            int speedB;
            scanf("%d", &speedB);
            droneControl('B', distanceB, speedB);
            break;
        case 5:
            printf("Performing right movement.\n");
            printf("Enter distance (meters): ");
            int distanceR;
            scanf("%d", &distanceR);
            printf("Enter speed (kph): ");
            int speedR;
            scanf("%d", &speedR);
            droneControl('R', distanceR, speedR);
            break;
        case 6:
            printf("Performing left movement.\n");
            printf("Enter distance (meters): ");
            int distanceL;
            scanf("%d", &distanceL);
            printf("Enter speed (kph): ");
            int speedL;
            scanf("%d", &speedL);
            droneControl('L', distanceL, speedL);
            break;
        default:
            printf("Invalid choice, please select an action (1-6).\n");
            break;
    }

    return 0;
}