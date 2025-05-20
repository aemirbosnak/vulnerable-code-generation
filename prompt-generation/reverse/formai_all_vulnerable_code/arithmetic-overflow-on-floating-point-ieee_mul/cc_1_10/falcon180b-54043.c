//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371.01 // Earth's radius in km
#define PI 3.14159265358979323846

struct Point {
    double latitude;
    double longitude;
};

struct Point get_current_location() {
    struct Point location;
    printf("Enter your current latitude: ");
    scanf("%lf", &location.latitude);
    printf("Enter your current longitude: ");
    scanf("%lf", &location.longitude);

    return location;
}

double distance(struct Point p1, struct Point p2) {
    double lat1 = p1.latitude * PI / 180;
    double lat2 = p2.latitude * PI / 180;
    double dLat = lat2 - lat1;
    double dLon = p2.longitude * PI / 180 - p1.longitude * PI / 180;
    double a =
        pow(sin(dLat / 2), 2) +
        cos(lat1) * cos(lat2) * pow(sin(dLon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

struct Point get_destination() {
    struct Point destination;
    printf("Enter your destination latitude: ");
    scanf("%lf", &destination.latitude);
    printf("Enter your destination longitude: ");
    scanf("%lf", &destination.longitude);

    return destination;
}

void get_route(struct Point current_location, struct Point destination) {
    printf("Calculating route...\n");
    double distance_km = distance(current_location, destination) / 1000;
    printf("Distance: %.2f km\n", distance_km);
}

int main() {
    struct Point current_location = get_current_location();
    struct Point destination = get_destination();

    get_route(current_location, destination);

    return 0;
}