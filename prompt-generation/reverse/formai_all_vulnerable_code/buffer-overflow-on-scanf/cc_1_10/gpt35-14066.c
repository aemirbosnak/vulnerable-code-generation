//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define coordinates of current location and destination
double currentLat, currentLong;
double destLat, destLong;

// Define function to calculate distance between two coordinates using Haversine formula
double haversine(double lat1, double lon1, double lat2, double lon2) {
    const int R = 6371; // Earth's radius in km
    double dLat = (lat2 - lat1) * M_PI / 180; // Convert degrees to radians
    double dLon = (lon2 - lon1) * M_PI / 180;

    lat1 *= M_PI / 180; // Convert degrees to radians
    lat2 *= M_PI / 180;

    double a = sin(dLat/2) * sin(dLat/2) + sin(dLon/2) * sin(dLon/2) * cos(lat1) * cos(lat2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = R * c; // Distance in km
    return d;
}

int main() {
    // Input current location and destination coordinates
    printf("Enter your current latitude: ");
    scanf("%lf", &currentLat);
    printf("Enter your current longitude: ");
    scanf("%lf", &currentLong);

    printf("Enter your destination latitude: ");
    scanf("%lf", &destLat);
    printf("Enter your destination longitude: ");
    scanf("%lf", &destLong);

    // Calculate distance between current location and destination
    double distance = haversine(currentLat, currentLong, destLat, destLong);
    printf("Distance to destination: %.2f km\n", distance);

    // Simulate movement towards destination
    while (distance > 0.05) { // Stop when within 50 meters of the destination
        // Calculate bearing from current location to destination
        double y = sin(destLong - currentLong) * cos(destLat);
        double x = cos(currentLat) * sin(destLat) - sin(currentLat) * cos(destLat) * cos(destLong - currentLong);
        double bearing = atan2(y, x) * 180 / M_PI;

        // Calculate new coordinates based on bearing and distance travelled
        double newLat = asin(sin(currentLat) * cos(distance / 6371) + cos(currentLat) * sin(distance / 6371) * cos(bearing * M_PI / 180));
        double newLong = currentLong + atan2(sin(bearing * M_PI / 180) * sin(distance / 6371) * cos(currentLat), cos(distance / 6371) - sin(currentLat) * sin(newLat));

        // Update current location and calculate new distance to the destination
        currentLat = newLat * 180 / M_PI;
        currentLong = newLong * 180 / M_PI;
        distance = haversine(currentLat, currentLong, destLat, destLong);
        printf("Current location: %.6f, %.6f\n", currentLat, currentLong);
    }

    printf("You have reached your destination!\n");
    return 0;
}