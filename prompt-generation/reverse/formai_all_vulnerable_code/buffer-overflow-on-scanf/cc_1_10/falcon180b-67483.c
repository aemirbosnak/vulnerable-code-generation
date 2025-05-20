//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359
#define EARTH_RADIUS 6371.01

typedef struct {
    double lat;
    double lon;
} Coordinates;

void calculateDistance(Coordinates c1, Coordinates c2, double *distance) {
    double dLat = c2.lat - c1.lat;
    double dLon = c2.lon - c1.lon;
    double a = sin(dLat/2) * sin(dLat/2) + cos(c1.lat) * cos(c2.lat) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    *distance = EARTH_RADIUS * c;
}

void calculateBearing(Coordinates c1, Coordinates c2, double *bearing) {
    double y = sin(c2.lon - c1.lon) * cos(c2.lat);
    double x = cos(c1.lat) * sin(c2.lat) - sin(c1.lat) * cos(c2.lat) * cos(c2.lon - c1.lon);
    double bearingDegrees = atan2(y, x);
    if (bearingDegrees < 0) {
        bearingDegrees += 2 * PI;
    }
    *bearing = bearingDegrees * 180 / PI;
}

int main() {
    Coordinates currentLocation;
    Coordinates destination;
    char input[100];
    double distance, bearing;

    printf("Enter your current location in the format of latitude,longitude: ");
    scanf("%lf,%lf", &currentLocation.lat, &currentLocation.lon);

    printf("Enter your destination in the format of latitude,longitude: ");
    scanf("%s", input);
    sscanf(input, "%lf,%lf", &destination.lat, &destination.lon);

    calculateDistance(currentLocation, destination, &distance);
    calculateBearing(currentLocation, destination, &bearing);

    printf("Distance to destination: %.2lf km\n", distance);
    printf("Bearing to destination: %.2lf degrees\n", bearing);

    return 0;
}