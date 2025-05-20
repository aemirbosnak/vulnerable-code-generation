//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

typedef struct {
    double lat;
    double lon;
} GPSCoordinate;

GPSCoordinate currentLocation;
GPSCoordinate destination;

void getUserInput() {
    printf("Enter current latitude: ");
    scanf("%lf", &currentLocation.lat);
    printf("Enter current longitude: ");
    scanf("%lf", &currentLocation.lon);

    printf("Enter destination latitude: ");
    scanf("%lf", &destination.lat);
    printf("Enter destination longitude: ");
    scanf("%lf", &destination.lon);
}

double distance(GPSCoordinate coord1, GPSCoordinate coord2) {
    double dLat = coord2.lat - coord1.lat;
    double dLon = coord2.lon - coord1.lon;

    double a = sin(dLat / 2) * sin(dLat / 2) + cos(coord1.lat) * cos(coord2.lat) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

void navigate() {
    double distanceInMeters = distance(currentLocation, destination);
    double angle = atan2(destination.lon - currentLocation.lon, destination.lat - currentLocation.lat);

    printf("Distance to destination: %.2f meters\n", distanceInMeters);
    printf("Angle to destination: %.2f degrees\n", angle * 180 / PI);

    if (distanceInMeters <= 0) {
        printf("You have reached your destination!\n");
    } else {
        double stepSize = 10.0; // 10 meters
        double stepsToDestination = distanceInMeters / stepSize;

        for (int i = 0; i < stepsToDestination; i++) {
            double progress = i * stepSize / distanceInMeters;

            double newLat = currentLocation.lat + stepSize * cos(angle * PI / 180);
            double newLon = currentLocation.lon + stepSize * sin(angle * PI / 180);

            printf("Step %d of %d\n", i + 1, stepsToDestination);
            printf("Progress: %.2f%%\n", progress * 100);
            printf("Current location: (%.2f, %.2f)\n", newLat, newLon);

            currentLocation.lat = newLat;
            currentLocation.lon = newLon;
        }
    }
}

int main() {
    getUserInput();
    navigate();

    return 0;
}