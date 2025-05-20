//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0 // in kilometers

struct Point {
    double latitude;
    double longitude;
    double altitude;
};

struct Point get_current_location(void) {
    struct Point location;
    printf("Enter your current latitude: ");
    scanf("%lf", &location.latitude);
    printf("Enter your current longitude: ");
    scanf("%lf", &location.longitude);
    printf("Enter your current altitude (in meters): ");
    scanf("%lf", &location.altitude);
    return location;
}

struct Point get_destination(void) {
    struct Point destination;
    printf("Enter your destination latitude: ");
    scanf("%lf", &destination.latitude);
    printf("Enter your destination longitude: ");
    scanf("%lf", &destination.longitude);
    printf("Enter your destination altitude (in meters): ");
    scanf("%lf", &destination.altitude);
    return destination;
}

double haversine_distance(struct Point p1, struct Point p2) {
    double dlat = p2.latitude - p1.latitude;
    double dlon = p2.longitude - p1.longitude;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(p1.latitude) * cos(p2.latitude) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

int main(void) {
    struct Point current_location = get_current_location();
    struct Point destination = get_destination();

    double distance = haversine_distance(current_location, destination);

    printf("The distance between your current location and your destination is %.2lf kilometers.\n", distance);

    return 0;
}