//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

// Define GPS coordinates structure
struct GPSCoordinate {
    double latitude;
    double longitude;
};

// Define GPS location function
void GPSLocation(struct GPSCoordinate *location, double distance, double bearing) {
    double dLat = distance * sin(bearing * PI / 180);
    double dLon = distance * cos(bearing * PI / 180);
    location->latitude += dLat;
    location->longitude += dLon;
}

// Define GPS simulation function
void GPSSimulation(struct GPSCoordinate *startLocation, struct GPSCoordinate *endLocation, double *distance, double *bearing) {
    double dLat = endLocation->latitude - startLocation->latitude;
    double dLon = endLocation->longitude - startLocation->longitude;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(startLocation->latitude * PI / 180) * cos(endLocation->latitude * PI / 180) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distanceInMeters = 6371 * c;
    *distance = distanceInMeters;
    *bearing = (endLocation->longitude - startLocation->longitude) * 180 / PI;
}

// Define main function
int main() {
    struct GPSCoordinate startLocation, endLocation;
    double distance, bearing;

    // Get starting location from user
    printf("Enter starting location in decimal degrees (latitude longitude): ");
    scanf("%lf %lf", &startLocation.latitude, &startLocation.longitude);

    // Get ending location from user
    printf("Enter ending location in decimal degrees (latitude longitude): ");
    scanf("%lf %lf", &endLocation.latitude, &endLocation.longitude);

    // Simulate GPS navigation
    GPSSimulation(&startLocation, &endLocation, &distance, &bearing);

    // Output results
    printf("Distance between locations: %.2lf meters\n", distance);
    printf("Bearing from start to end location: %.2lf degrees\n", bearing);

    return 0;
}