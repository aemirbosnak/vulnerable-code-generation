//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define R 6371.0

typedef struct {
    double lat;
    double lon;
} Point;

Point get_position(double bearing, double distance) {
    Point result;
    double lat1, lon1, lat2, lon2, dlat, dlon, a, c, d;

    lat1 = 37.7749;
    lon1 = -122.4194;

    lat2 = asin(sin(lat1) * cos(distance / R) + cos(lat1) * sin(distance / R) * cos(bearing));
    lon2 = lon1 + atan2(sin(bearing) * sin(distance / R) * cos(lat1), cos(distance / R) - sin(lat1) * sin(lat2));

    result.lat = lat2;
    result.lon = lon2;

    return result;
}

void main() {
    double lat1, lon1, lat2, lon2, distance, bearing;
    Point start, end;

    printf("Enter starting latitude and longitude: ");
    scanf("%lf %lf", &lat1, &lon1);

    printf("Enter destination latitude and longitude: ");
    scanf("%lf %lf", &lat2, &lon2);

    printf("Enter distance in kilometers: ");
    scanf("%lf", &distance);

    bearing = atan2(sin(lon2 - lon1) * cos(lat2), cos(lat2) * sin(lat1) - sin(lat2) * cos(lat1) * cos(lon2 - lon1));

    start.lat = lat1;
    start.lon = lon1;

    end = get_position(bearing, distance);

    printf("Starting position: %.6lf°N %.6lf°E\n", start.lat, start.lon);
    printf("Destination: %.6lf°N %.6lf°E\n", end.lat, end.lon);
}