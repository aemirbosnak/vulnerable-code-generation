//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

// GPS coordinate structure
typedef struct {
    double latitude;
    double longitude;
} GPSCoordinate;

// Function to calculate distance between two GPS coordinates
double calculateDistance(GPSCoordinate* coordinate1, GPSCoordinate* coordinate2) {
    double dLat = coordinate2->latitude - coordinate1->latitude;
    double dLon = coordinate2->longitude - coordinate1->longitude;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(coordinate1->latitude) * cos(coordinate2->latitude) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

// Function to convert decimal degrees to radians
double decimalToRadians(double decimal) {
    return decimal * (PI / 180);
}

int main() {
    GPSCoordinate currentLocation;
    GPSCoordinate destination;

    // Get current location from user input
    printf("Enter your current latitude: ");
    scanf("%lf", &currentLocation.latitude);
    printf("Enter your current longitude: ");
    scanf("%lf", &currentLocation.longitude);

    // Get destination from user input
    printf("Enter your destination latitude: ");
    scanf("%lf", &destination.latitude);
    printf("Enter your destination longitude: ");
    scanf("%lf", &destination.longitude);

    // Calculate distance between current location and destination
    double distance = calculateDistance(&currentLocation, &destination);

    // Convert distance to miles
    distance /= 1609.34;

    // Print distance between current location and destination
    printf("The distance between your current location and destination is %.2lf miles.\n", distance);

    return 0;
}