//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01
#define MINUTES_PER_DEGREE 60.0
#define DEGREES_PER_RADIAN 57.2957795

struct Coordinate {
    double latitude;
    double longitude;
};

struct Waypoint {
    char name[50];
    struct Coordinate coordinate;
};

void print_coordinate(struct Coordinate coordinate) {
    printf("Latitude: %.6f, Longitude: %.6f\n", coordinate.latitude, coordinate.longitude);
}

void calculate_distance(struct Coordinate start, struct Coordinate end, double *distance) {
    double dLat = end.latitude - start.latitude;
    double dLon = end.longitude - start.longitude;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(start.latitude) * cos(end.latitude) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    *distance = EARTH_RADIUS * c;
}

int main() {
    int num_waypoints;
    printf("Enter the number of waypoints: ");
    scanf("%d", &num_waypoints);

    struct Waypoint waypoints[num_waypoints];

    for (int i = 0; i < num_waypoints; i++) {
        printf("Enter the name of waypoint %d: ", i + 1);
        scanf("%s", waypoints[i].name);

        printf("Enter the latitude of waypoint %d: ", i + 1);
        scanf("%lf", &waypoints[i].coordinate.latitude);

        printf("Enter the longitude of waypoint %d: ", i + 1);
        scanf("%lf", &waypoints[i].coordinate.longitude);
    }

    int start_index, end_index;
    printf("Enter the starting waypoint index: ");
    scanf("%d", &start_index);
    printf("Enter the ending waypoint index: ");
    scanf("%d", &end_index);

    double distance;
    calculate_distance(waypoints[start_index - 1].coordinate, waypoints[end_index - 1].coordinate, &distance);

    printf("The distance between waypoints %s and %s is %.2f km.\n", waypoints[start_index - 1].name, waypoints[end_index - 1].name, distance);

    return 0;
}