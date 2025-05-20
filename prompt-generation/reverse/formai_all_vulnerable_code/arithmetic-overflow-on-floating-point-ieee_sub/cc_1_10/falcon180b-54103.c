//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371

typedef struct {
    double latitude;
    double longitude;
} Coordinate;

Coordinate get_current_location() {
    Coordinate current_location;
    printf("Enter your current latitude and longitude (in degrees):\n");
    scanf("%lf %lf", &current_location.latitude, &current_location.longitude);
    return current_location;
}

Coordinate get_destination() {
    Coordinate destination;
    printf("Enter your destination latitude and longitude (in degrees):\n");
    scanf("%lf %lf", &destination.latitude, &destination.longitude);
    return destination;
}

double calculate_distance(Coordinate start, Coordinate end) {
    double dLat = end.latitude - start.latitude;
    double dLon = end.longitude - start.longitude;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(start.latitude * PI / 180) * cos(end.latitude * PI / 180) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;
    return distance;
}

void display_route(Coordinate start, Coordinate end) {
    printf("The distance between the starting point and the destination is %.2lf kilometers.\n", calculate_distance(start, end));
    printf("You can reach your destination by following these directions:\n");
    if (start.latitude > end.latitude) {
        printf("Head south.\n");
    } else if (start.latitude < end.latitude) {
        printf("Head north.\n");
    }
    if (start.longitude > end.longitude) {
        printf("Head west.\n");
    } else if (start.longitude < end.longitude) {
        printf("Head east.\n");
    }
}

int main() {
    Coordinate current_location = get_current_location();
    Coordinate destination = get_destination();
    display_route(current_location, destination);
    return 0;
}