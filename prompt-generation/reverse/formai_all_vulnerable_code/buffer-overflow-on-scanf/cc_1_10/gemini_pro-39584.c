//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Earth's radius in kilometers
#define EARTH_RADIUS 6371

// Structure to represent a GPS coordinate
typedef struct {
    double latitude;
    double longitude;
} GPSCoordinate;

// Function to calculate the distance between two GPS coordinates
double calculateDistance(GPSCoordinate coord1, GPSCoordinate coord2) {
    // Convert latitudes and longitudes to radians
    double lat1 = coord1.latitude * M_PI / 180;
    double lon1 = coord1.longitude * M_PI / 180;
    double lat2 = coord2.latitude * M_PI / 180;
    double lon2 = coord2.longitude * M_PI / 180;

    // Calculate the difference in latitudes and longitudes
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    // Calculate the square of the distance between the two points
    double a = pow(sin(dLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dLon / 2), 2);

    // Calculate the distance between the two points
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

// Function to simulate GPS navigation
void simulateGPSNavigation() {
    // Initialize the current GPS coordinate
    GPSCoordinate currentCoord = {0, 0};

    // Get the destination GPS coordinate from the user
    printf("Enter the destination latitude: ");
    scanf("%lf", &currentCoord.latitude);
    printf("Enter the destination longitude: ");
    scanf("%lf", &currentCoord.longitude);

    // Initialize the distance traveled to 0
    double distanceTraveled = 0;

    // Simulate the GPS navigation loop
    while (distanceTraveled < 100) {
        // Get the next GPS coordinate from the user
        printf("Enter the next GPS coordinate (latitude, longitude): ");
        scanf("%lf %lf", &currentCoord.latitude, &currentCoord.longitude);

        // Calculate the distance traveled since the last GPS coordinate
        double distance = calculateDistance(currentCoord, currentCoord);

        // Add the distance traveled to the total distance traveled
        distanceTraveled += distance;

        // Print the current GPS coordinate and the distance traveled
        printf("Current GPS coordinate: (%lf, %lf)\n", currentCoord.latitude, currentCoord.longitude);
        printf("Distance traveled: %lf km\n", distanceTraveled);
    }

    // Print the final destination reached
    printf("Destination reached!\n");
}

int main() {
    simulateGPSNavigation();
    return 0;
}