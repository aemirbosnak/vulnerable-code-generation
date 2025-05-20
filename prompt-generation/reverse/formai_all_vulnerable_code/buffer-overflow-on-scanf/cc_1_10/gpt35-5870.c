//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize Drone
void initializeDrone() {
    printf("Drone initialized!\n");
}

// Start Flight
void startFlight() {
    printf("Starting flight...\n");
}

// Hover in Air
void hoverInAir() {
    printf("Hovering in the air...\n");
}

// Land Drone
void landDrone() {
    printf("Landing drone...\n");
}

// Change Altitude
void changeAltitude(int altitude) {
    printf("Changing altitude to %d meters...\n", altitude);
}

int main() {
    int batteryLevel = 100; // Battery level in percentage
    int altitude = 0; // Altitude in meters

    // Initialize drone
    initializeDrone();

    // Get user input for altitude
    printf("Enter desired altitude (in meters): ");
    scanf("%d", &altitude);

    // Check if altitude is valid
    if (altitude < 0 || altitude > 500) {
        printf("Invalid altitude! Altitude should be between 0 and 500 meters.\n");
        exit(0);
    }

    // Start flight
    startFlight();

    // Change altitude
    changeAltitude(altitude);

    // Hover in air
    hoverInAir();

    // Land drone
    landDrone();

    // Display battery level
    srand(time(0)); // Generate random number for battery level simulation
    batteryLevel -= rand() % 20; // Simulate battery drain during flight
    printf("Battery level: %d%%\n", batteryLevel);

    return 0;
}