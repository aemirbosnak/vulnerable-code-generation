//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

struct Point {
    double lat;
    double lon;
};

struct Point GPS_get_current_location() {
    struct Point location;

    printf("Enter current latitude: ");
    scanf("%lf", &location.lat);

    printf("Enter current longitude: ");
    scanf("%lf", &location.lon);

    return location;
}

struct Point GPS_get_destination() {
    struct Point destination;

    printf("Enter destination latitude: ");
    scanf("%lf", &destination.lat);

    printf("Enter destination longitude: ");
    scanf("%lf", &destination.lon);

    return destination;
}

double GPS_calculate_distance(struct Point point1, struct Point point2) {
    double dLat = point2.lat - point1.lat;
    double dLon = point2.lon - point1.lon;

    double a = sin(dLat / 2) * sin(dLat / 2) + cos(point1.lat * PI / 180) * cos(point2.lat * PI / 180) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

void GPS_navigate(struct Point current_location, struct Point destination) {
    double distance = GPS_calculate_distance(current_location, destination);

    printf("The distance between your current location and the destination is %.2lf kilometers.\n", distance);
}

int main() {
    struct Point current_location = GPS_get_current_location();
    struct Point destination = GPS_get_destination();

    GPS_navigate(current_location, destination);

    return 0;
}