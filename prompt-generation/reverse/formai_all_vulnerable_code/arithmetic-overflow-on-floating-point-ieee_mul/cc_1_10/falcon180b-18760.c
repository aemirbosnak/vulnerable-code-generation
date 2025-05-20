//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6378137.0 // Earth's radius in meters

// Define GPS coordinate structure
typedef struct {
    double latitude;
    double longitude;
} GPSCoordinate;

// Function to calculate distance between two GPS coordinates
double calculateDistance(GPSCoordinate coord1, GPSCoordinate coord2) {
    double lat1 = coord1.latitude * PI / 180.0;
    double lat2 = coord2.latitude * PI / 180.0;
    double dLat = lat2 - lat1;
    double dLon = (coord2.longitude - coord1.longitude) * PI / 180.0;
    double a = sin(dLat / 2.0) * sin(dLat / 2.0) + cos(lat1) * cos(lat2) * sin(dLon / 2.0) * sin(dLon / 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    double distance = RADIUS * c;
    return distance;
}

// Function to prompt user for GPS coordinates
void getGPSCoordinate(GPSCoordinate* coord) {
    printf("Enter latitude: ");
    scanf("%lf", &coord->latitude);
    printf("Enter longitude: ");
    scanf("%lf", &coord->longitude);
}

// Function to prompt user for destination coordinates
void getDestinationCoordinate(GPSCoordinate* dest) {
    printf("Enter destination latitude: ");
    scanf("%lf", &dest->latitude);
    printf("Enter destination longitude: ");
    scanf("%lf", &dest->longitude);
}

// Function to simulate GPS navigation
void simulateGPSNavigation(GPSCoordinate start, GPSCoordinate dest) {
    printf("Simulating GPS navigation from (%lf, %lf) to (%lf, %lf)\n", start.latitude, start.longitude, dest.latitude, dest.longitude);
    double distance = calculateDistance(start, dest);
    printf("Distance: %.2lf meters\n", distance);
}

int main() {
    GPSCoordinate start, dest;
    getGPSCoordinate(&start);
    getDestinationCoordinate(&dest);
    simulateGPSNavigation(start, dest);
    return 0;
}