//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.009 // in kilometers

struct point {
    double latitude;
    double longitude;
};

struct point get_current_location() {
    struct point location;
    printf("Enter your current location (latitude and longitude separated by a comma): ");
    scanf("%lf,%lf", &location.latitude, &location.longitude);
    return location;
}

struct point get_destination() {
    struct point destination;
    printf("Enter your destination (latitude and longitude separated by a comma): ");
    scanf("%lf,%lf", &destination.latitude, &destination.longitude);
    return destination;
}

double calculate_distance(struct point p1, struct point p2) {
    double dlat = p2.latitude - p1.latitude;
    double dlon = p2.longitude - p1.longitude;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(p1.latitude) * cos(p2.latitude) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c; // distance in kilometers
}

double calculate_bearing(struct point p1, struct point p2) {
    double y = sin(p2.latitude - p1.latitude) * cos(p2.longitude);
    double x = cos(p1.latitude) * sin(p2.latitude) - sin(p1.latitude) * cos(p2.latitude) * cos(p2.longitude - p1.longitude);
    double bearing = atan2(y, x);
    return bearing;
}

void main() {
    struct point current_location = get_current_location();
    struct point destination = get_destination();

    double distance = calculate_distance(current_location, destination);
    double bearing = calculate_bearing(current_location, destination);

    printf("Distance to destination: %.2f km\n", distance);
    printf("Bearing to destination: %.2f degrees\n", bearing * 180 / PI);
}