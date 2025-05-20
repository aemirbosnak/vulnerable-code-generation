//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: relaxed
#include <stdio.h>

int main() {
    int batteryLevel = 100;
    int altitude = 0;
    int droneSpeed = 0;
    int heading = 0;
    int pitch = 0;
    int roll = 0;
    int yaw = 0;
    int landed = 1;
    char command;

    printf("Welcome to C Drone Remote Control\n");

    while (1) {
        printf("Enter command (t=takeoff, l=land, u=climb, d=descend, f=forward, b=backward, r=right, "
               "e=left, q=quit): ");
        scanf(" %c", &command);

        // Handle command
        switch (command) {
            case 't':
                if (landed) {
                    printf("Taking off\n");
                    altitude = 50; // Change altitude to 50 feet
                    landed = 0;
                } else {
                    printf("Drone is already in the air\n");
                }
                break;
            case 'l':
                if (!landed) {
                    printf("Landing\n");
                    altitude = 0; // Change altitude to ground level
                    landed = 1;
                } else {
                    printf("Drone has already landed\n");
                }
                break;
            case 'u':
                if (!landed) {
                    if (altitude < 100) {
                        printf("Climbing\n");
                        altitude += 10; // Increase altitude by 10 feet
                    } else {
                        printf("Drone is already at maximum altitude\n");
                    }
                } else {
                    printf("Drone is not in the air\n");
                }
                break;
            case 'd':
                if (!landed) {
                    if (altitude > 0) {
                        printf("Descending\n");
                        altitude -= 10; // Decrease altitude by 10 feet
                    } else {
                        printf("Drone is already on the ground\n");
                    }
                } else {
                    printf("Drone is not in the air\n");
                }
                break;
            case 'f':
                if (!landed) {
                    printf("Moving forward\n");
                    pitch += 10; // Increase pitch by 10 degrees
                } else {
                    printf("Drone is not in the air\n");
                }
                break;
            case 'b':
                if (!landed) {
                    printf("Moving backward\n");
                    pitch -= 10; // Decrease pitch by 10 degrees
                } else {
                    printf("Drone is not in the air\n");
                }
                break;
            case 'r':
                if (!landed) {
                    printf("Moving right\n");
                    roll += 10; // Increase roll by 10 degrees
                } else {
                    printf("Drone is not in the air\n");
                }
                break;
            case 'e':
                if (!landed) {
                    printf("Moving left\n");
                    roll -= 10; // Decrease roll by 10 degrees
                } else {
                    printf("Drone is not in the air\n");
                }
                break;
            case 'q':
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid command\n");
                break;
        }

        // Update drone status
        if (!landed) {
            droneSpeed += 5; // Increase speed by 5 mph every second
            if (droneSpeed > 50) droneSpeed = 50; // Cap max speed at 50 mph
            heading += yaw;
            if (heading >= 360) heading -= 360; // Keep heading within 0-359 degrees
            if (heading < 0) heading += 360;
            printf("Battery level: %d%%\n", batteryLevel);
            printf("Altitude: %d feet\n", altitude);
            printf("Speed: %d mph\n", droneSpeed);
            printf("Heading: %d degrees\n", heading);
            printf("Pitch: %d degrees\n", pitch);
            printf("Roll: %d degrees\n", roll);
            printf("Yaw: %d degrees per second\n\n", yaw);
            batteryLevel--; // Drain battery every second
        } else {
            printf("Drone is on the ground\n\n");
        }

        // Check if battery is depleted
        if (batteryLevel == 0) {
            printf("Battery depleted. Returning drone to base\n");
            altitude = 0;
            droneSpeed = 0;
            heading = 0;
            pitch = 0;
            roll = 0;
            yaw = 0;
            landed = 1;
            batteryLevel = 100;
        }
    }
}