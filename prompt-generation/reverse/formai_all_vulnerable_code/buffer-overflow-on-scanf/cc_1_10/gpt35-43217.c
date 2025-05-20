//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R 6371 // radius of the Earth in km

typedef struct Location {
    double lat;
    double lng;
} Location;

double toRadians(double degrees) {
    return degrees * M_PI / 180;
}

double distance(Location loc1, Location loc2) {
    double lat1 = toRadians(loc1.lat);
    double lat2 = toRadians(loc2.lat);
    double lng1 = toRadians(loc1.lng);
    double lng2 = toRadians(loc2.lng);
    double deltaLat = lat2 - lat1;
    double deltaLng = lng2 - lng1;
    double a = sin(deltaLat/2) * sin(deltaLat/2) + cos(lat1) * cos(lat2) * sin(deltaLng/2) * sin(deltaLng/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = R * c;
    return d;
}

int main() {
    Location destination;
    printf("Enter destination latitude: ");
    scanf("%lf", &destination.lat);
    printf("Enter destination longitude: ");
    scanf("%lf", &destination.lng);

    Location current_location;
    printf("Enter current latitude: ");
    scanf("%lf", &current_location.lat);
    printf("Enter current longitude: ");
    scanf("%lf", &current_location.lng);

    double dist = distance(destination, current_location);
    printf("Distance to destination: %.2f km\n", dist);

    // get direction
    double y = sin(toRadians(destination.lng - current_location.lng)) * cos(toRadians(destination.lat));
    double x = cos(toRadians(current_location.lat)) * sin(toRadians(destination.lat)) - sin(toRadians(current_location.lat)) * cos(toRadians(destination.lat)) * cos(toRadians(destination.lng - current_location.lng));
    double direction = atan2(y, x);
    direction = direction * 180 / M_PI;
    direction = fmod(direction + 360, 360);

    printf("Direction to destination: %.2f degrees\n", direction);

    return 0;
}