//Code Llama-13B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Linus Torvalds
/*
 * Linus Torvalds' GPS Navigation Simulation
 *
 * This program simulates a GPS navigation system, where the user can input
 * their current location and destination, and the program will calculate
 * the shortest route to get there.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371000
#define PI 3.14159265359

// Struct to store the coordinates of a location
struct Location {
    double latitude;
    double longitude;
};

// Function to calculate the distance between two locations
double distance(struct Location loc1, struct Location loc2) {
    double d_lat = loc2.latitude - loc1.latitude;
    double d_lon = loc2.longitude - loc1.longitude;
    double a = pow(sin(d_lat / 2), 2) + cos(loc1.latitude) * cos(loc2.latitude) * pow(sin(d_lon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

// Function to calculate the shortest route between two locations
void shortest_route(struct Location loc1, struct Location loc2) {
    double d_lat = loc2.latitude - loc1.latitude;
    double d_lon = loc2.longitude - loc1.longitude;
    double y = sin(d_lon) * cos(loc2.latitude);
    double x = cos(loc1.latitude) * sin(loc2.latitude) - sin(loc1.latitude) * cos(loc2.latitude) * cos(d_lon);
    double brng = atan2(y, x);
    printf("Shortest route is %.2f degrees\n", brng);
}

int main() {
    struct Location loc1;
    struct Location loc2;

    printf("Enter current location (latitude, longitude): ");
    scanf("%lf %lf", &loc1.latitude, &loc1.longitude);

    printf("Enter destination location (latitude, longitude): ");
    scanf("%lf %lf", &loc2.latitude, &loc2.longitude);

    double dist = distance(loc1, loc2);
    printf("Distance between current and destination locations is %.2f meters\n", dist);

    shortest_route(loc1, loc2);

    return 0;
}