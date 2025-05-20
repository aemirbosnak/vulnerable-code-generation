//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Global variables
int drone_status = 0; // 0 = landed, 1 = flying
float drone_altitude = 0.0;
float drone_x = 0.0;
float drone_y = 0.0;
float drone_z = 0.0;

// Function to control the drone
void control_drone(int command, float value) {
    switch (command) {
        case 0: // Takeoff
            drone_status = 1;
            printf("Taking off...\n");
            break;
        case 1: // Landing
            drone_status = 0;
            printf("Landing...\n");
            break;
        case 2: // Move forward
            drone_x += value;
            printf("Moving forward by %f m\n", value);
            break;
        case 3: // Move backward
            drone_x -= value;
            printf("Moving backward by %f m\n", value);
            break;
        case 4: // Move left
            drone_y -= value;
            printf("Moving left by %f m\n", value);
            break;
        case 5: // Move right
            drone_y += value;
            printf("Moving right by %f m\n", value);
            break;
        case 6: // Move up
            drone_z += value;
            printf("Moving up by %f m\n", value);
            break;
        case 7: // Move down
            drone_z -= value;
            printf("Moving down by %f m\n", value);
            break;
        default:
            printf("Invalid command\n");
            break;
    }
}

// Main function
int main() {
    printf("Welcome to the Drone Remote Control!\n");
    while (1) {
        printf("Enter command (0-7): ");
        int command;
        scanf("%d", &command);
        float value;
        printf("Enter value: ");
        scanf("%f", &value);
        control_drone(command, value);
    }
    return 0;
}