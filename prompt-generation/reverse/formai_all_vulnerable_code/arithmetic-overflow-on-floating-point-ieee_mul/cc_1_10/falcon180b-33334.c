//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

struct point {
    double latitude;
    double longitude;
};

struct point get_current_location(void) {
    struct point location;
    double latitude, longitude;

    // Get current latitude and longitude from GPS
    latitude = 37.7749;
    longitude = -122.4194;

    location.latitude = latitude;
    location.longitude = longitude;

    return location;
}

struct point get_destination(void) {
    struct point destination;
    double latitude, longitude;

    // Get destination latitude and longitude from user input
    printf("Enter destination latitude: ");
    scanf("%lf", &latitude);
    printf("Enter destination longitude: ");
    scanf("%lf", &longitude);

    destination.latitude = latitude;
    destination.longitude = longitude;

    return destination;
}

double distance(struct point p1, struct point p2) {
    double dlat = p2.latitude - p1.latitude;
    double dlon = p2.longitude - p1.longitude;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(p1.latitude * PI / 180) * cos(p2.latitude * PI / 180) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

int main(void) {
    struct point current_location, destination;
    double distance_to_destination;

    // Get current location from GPS
    current_location = get_current_location();

    // Get destination from user input
    destination = get_destination();

    // Calculate distance between current location and destination
    distance_to_destination = distance(current_location, destination);

    // Print the distance to the destination
    printf("The distance to the destination is %.2lf km.\n", distance_to_destination);

    return 0;
}