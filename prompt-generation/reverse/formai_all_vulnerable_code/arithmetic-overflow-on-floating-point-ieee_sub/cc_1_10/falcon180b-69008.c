//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

typedef struct {
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location start;
    Location end;
} Route;

Location get_current_location() {
    Location current_location;

    printf("Enter your current location (latitude and longitude):\n");
    scanf("%lf %lf", &current_location.latitude, &current_location.longitude);

    return current_location;
}

Location get_destination() {
    Location destination;

    printf("Enter your destination (latitude and longitude):\n");
    scanf("%lf %lf", &destination.latitude, &destination.longitude);

    return destination;
}

double calculate_distance(Location location1, Location location2) {
    double dLat = location2.latitude - location1.latitude;
    double dLon = location2.longitude - location1.longitude;

    double a = sin(dLat/2) * sin(dLat/2) + cos(location1.latitude) * cos(location2.latitude) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return EARTH_RADIUS * c;
}

void print_route(Route route) {
    printf("Route:\n");
    printf("Start: %.2lf, %.2lf\n", route.start.latitude, route.start.longitude);
    printf("End: %.2lf, %.2lf\n", route.end.latitude, route.end.longitude);
    printf("Distance: %.2lf km\n", calculate_distance(route.start, route.end));
}

int main() {
    srand(time(NULL));

    Location current_location = get_current_location();
    Location destination = get_destination();

    Route route;
    route.start = current_location;
    route.end = destination;

    print_route(route);

    return 0;
}