//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Drone specifications
    int maxAltitude = 100; // meters
    int maxRange = 500; // meters
    int maxSpeed = 50; // km/hour

    // Remote control specifications
    bool batteryConnected = true;
    int signalStrength = 80; // percentage
    int displayBrightness = 60; // percentage

    // Connect to drone
    printf("Connecting to drone...\n");
    bool isDroneConnected = true;
    while (isDroneConnected) {
        // Check battery
        if (!batteryConnected) {
            printf("Battery disconnected! Connection lost.\n");
            isDroneConnected = false;
            break;
        }

        // Check signal strength
        if (signalStrength < 50) {
            printf("Signal strength too weak! Connection lost.\n");
            isDroneConnected = false;
            break;
        }

        // Display remote control settings
        printf("Display brightness: %d%%\n", displayBrightness);
        printf("Signal strength: %d%%\n", signalStrength);

        // Get user input
        int altitude = 0;
        int range = 0;
        int speed = 0;
        printf("Enter altitude (meters): ");
        scanf("%d", &altitude);
        printf("Enter range (meters): ");
        scanf("%d", &range);
        printf("Enter speed (km/hour): ");
        scanf("%d", &speed);

        // Check if drone is capable of settings
        if (altitude > maxAltitude) {
            printf("Drone cannot fly at that altitude!");
            continue;
        }
        if (range > maxRange) {
            printf("Drone cannot fly that far!");
            continue;
        }
        if (speed > maxSpeed) {
            printf("Drone cannot fly that fast!");
            continue;
        }

        // Set drone settings
        printf("Setting drone to altitude %d meters, range %d meters, speed %d km/hour...\n", altitude, range, speed);

        // Fly drone
        printf("Flying drone...\n");
        printf("Drone has reached altitude of %d meters, range of %d meters, and speed of %d km/hour.\n", altitude, range, speed);

        // Disconnect drone
        printf("Disconnecting from drone...\n");
        isDroneConnected = false;
    }

    return 0;
}