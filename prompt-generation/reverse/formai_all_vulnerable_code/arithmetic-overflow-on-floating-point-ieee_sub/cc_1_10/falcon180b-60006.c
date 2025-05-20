//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.009

typedef struct {
    double lat1;
    double lon1;
    double lat2;
    double lon2;
    double distance;
} location;

void calculate_distance(location* loc) {
    double dlat = loc->lat2 - loc->lat1;
    double dlon = loc->lon2 - loc->lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(loc->lat1 * PI / 180) * cos(loc->lat2 * PI / 180) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;
    loc->distance = distance;
}

int main() {
    location gps1, gps2;
    double distance;

    // User inputs GPS coordinates for location 1
    printf("Enter GPS coordinates for location 1 (in degrees):\n");
    printf("Latitude: ");
    scanf("%lf", &gps1.lat1);
    printf("Longitude: ");
    scanf("%lf", &gps1.lon1);

    // User inputs GPS coordinates for location 2
    printf("Enter GPS coordinates for location 2 (in degrees):\n");
    printf("Latitude: ");
    scanf("%lf", &gps2.lat2);
    printf("Longitude: ");
    scanf("%lf", &gps2.lon2);

    // Calculate distance between two locations
    calculate_distance(&gps1);
    calculate_distance(&gps2);

    // Display distance between two locations
    printf("Distance between location 1 and location 2: %.2lf km\n", gps1.distance);

    return 0;
}