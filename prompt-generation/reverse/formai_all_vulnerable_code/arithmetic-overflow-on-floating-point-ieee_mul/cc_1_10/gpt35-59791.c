//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359
#define EARTH_RADIUS 6371000

// Function to convert degrees to radians
double toRadians(double degrees) {
    return degrees * (PI / 180);
}

// Function to calculate the bearing between two GPS coordinates
double calculateBearing(double lat1, double lon1, double lat2, double lon2) {
    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);
    double y = sin(dLon) * cos(toRadians(lat2));
    double x = cos(toRadians(lat1)) * sin(toRadians(lat2)) - sin(toRadians(lat1)) * cos(toRadians(lat2)) * cos(dLon);
    double bearing = atan2(y, x);
    return fmod((bearing + 2 * PI), (2 * PI));
}

// Function to calculate the distance between two GPS coordinates
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);
    double a = sin(dLat / 2) * sin(dLat / 2) +
        cos(toRadians(lat1)) * cos(toRadians(lat2)) *
        sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;
    return distance;
}

int main() {
    // Set the GPS coordinates for a destination location
    double destinationLat = 37.7749;
    double destinationLon = -122.4194;

    // Ask the user for their current GPS location
    printf("Enter your current GPS location in degrees:\n");
    double currentLat, currentLon;
    scanf("%lf %lf", &currentLat, &currentLon);

    // Calculate the bearing and distance to the destination location
    double bearing = calculateBearing(currentLat, currentLon, destinationLat, destinationLon);
    double distance = calculateDistance(currentLat, currentLon, destinationLat, destinationLon);

    // Display the results to the user
    printf("You are %.2f meters away from the destination\n", distance);
    printf("The bearing to the destination is %.2f degrees\n", bearing * 180 / PI);

    return 0;
}