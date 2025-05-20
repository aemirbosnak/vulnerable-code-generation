//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
/*
 * GPS Navigation Simulation Example Program
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define PI 3.14159265359
#define EARTH_RADIUS 6371.01

typedef struct {
    double lat;
    double lon;
} GPSCoordinate;

void initialize_gps(GPSCoordinate *gps) {
    gps->lat = 0;
    gps->lon = 0;
}

void print_gps(GPSCoordinate gps) {
    printf("Latitude: %.6f\n", gps.lat);
    printf("Longitude: %.6f\n", gps.lon);
}

void calculate_distance(GPSCoordinate start, GPSCoordinate end, double *distance) {
    double lat1, lat2, lon1, lon2;
    double dlat, dlon;
    double a, c, d;

    lat1 = start.lat * PI / 180;
    lon1 = start.lon * PI / 180;
    lat2 = end.lat * PI / 180;
    lon2 = end.lon * PI / 180;

    dlat = lat2 - lat1;
    dlon = lon2 - lon1;

    a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));

    d = EARTH_RADIUS * c;

    *distance = d;
}

int main() {
    GPSCoordinate start, end;
    double distance;

    initialize_gps(&start);
    initialize_gps(&end);

    printf("Enter starting latitude: ");
    scanf("%lf", &start.lat);
    printf("Enter starting longitude: ");
    scanf("%lf", &start.lon);

    printf("Enter destination latitude: ");
    scanf("%lf", &end.lat);
    printf("Enter destination longitude: ");
    scanf("%lf", &end.lon);

    calculate_distance(start, end, &distance);

    printf("Distance between the two locations is %.2f km\n", distance);

    return 0;
}