//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Location {
    double Latitude;
    double Longitude;
} Location;

double degreeToRadian(double degree) {
    return degree * M_PI / 180.0;
}

double distanceBetweenLocations(Location location1, Location location2) {
    double lat1 = degreeToRadian(location1.Latitude);
    double lat2 = degreeToRadian(location2.Latitude);
    double lon1 = degreeToRadian(location1.Longitude);
    double lon2 = degreeToRadian(location2.Longitude);

    double deltaLat = lat2 - lat1;
    double deltaLon = lon2 - lon1;

    double a = pow(sin(deltaLat / 2.0), 2) + cos(lat1) * cos(lat2) * pow(sin(deltaLon / 2.0), 2);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

    return 6371e3 * c;
}

Location randomLocation() {
    Location location;

    location.Latitude = ((double) rand() / (RAND_MAX / 180.0)) - 90.0;
    location.Longitude = ((double) rand() / (RAND_MAX / 360.0)) - 180.0;

    return location;
}

int main() {
    Location origin, destination;
    double distance;

    printf("Enter your current latitude: ");
    scanf("%lf", &origin.Latitude);

    printf("Enter your current longitude: ");
    scanf("%lf", &origin.Longitude);

    printf("Enter your destination latitude: ");
    scanf("%lf", &destination.Latitude);

    printf("Enter your destination longitude: ");
    scanf("%lf", &destination.Longitude);

    distance = distanceBetweenLocations(origin, destination);

    printf("The distance between your current location and your destination is %lf meters.\n", distance);

    return 0;
}