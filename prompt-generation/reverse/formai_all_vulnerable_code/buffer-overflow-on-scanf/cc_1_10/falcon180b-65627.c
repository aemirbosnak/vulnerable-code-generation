//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0 // in km

typedef struct {
    double lat;
    double lon;
} Coordinates;

typedef struct {
    Coordinates current;
    Coordinates destination;
} GPS;

void init_gps(GPS* gps) {
    gps->current.lat = 0;
    gps->current.lon = 0;
    gps->destination.lat = 0;
    gps->destination.lon = 0;
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void get_current_location(GPS* gps) {
    printf("Enter current latitude: ");
    scanf("%lf", &gps->current.lat);
    printf("Enter current longitude: ");
    scanf("%lf", &gps->current.lon);
}

void get_destination(GPS* gps) {
    printf("Enter destination latitude: ");
    scanf("%lf", &gps->destination.lat);
    printf("Enter destination longitude: ");
    scanf("%lf", &gps->destination.lon);
}

void calculate_route(GPS* gps) {
    double distance_km = distance(gps->current.lat, gps->current.lon, gps->destination.lat, gps->destination.lon);
    printf("Distance to destination: %.2lf km\n", distance_km);
}

int main() {
    GPS gps;
    init_gps(&gps);
    get_current_location(&gps);
    get_destination(&gps);
    calculate_route(&gps);
    return 0;
}