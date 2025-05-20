//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define constants
#define EARTH_RADIUS 6371.0 // in kilometers
#define PI 3.14159265359

// define function to convert degrees to radians
double deg2rad(double deg) {
    return deg * PI / 180.0;
}

// define function to calculate distance between two coordinates
double distance(double lat1, double lon1, double lat2, double lon2) {
    double lat1_rad = deg2rad(lat1);
    double lon1_rad = deg2rad(lon1);
    double lat2_rad = deg2rad(lat2);
    double lon2_rad = deg2rad(lon2);

    double dlat = lat2_rad - lat1_rad;
    double dlon = lon2_rad - lon1_rad;

    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1_rad) * cos(lat2_rad) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return EARTH_RADIUS * c;
}

int main() {
    double start_lat, start_lon, end_lat, end_lon;

    printf("Enter starting latitude: ");
    scanf("%lf", &start_lat);

    printf("Enter starting longitude: ");
    scanf("%lf", &start_lon);

    printf("Enter ending latitude: ");
    scanf("%lf", &end_lat);

    printf("Enter ending longitude: ");
    scanf("%lf", &end_lon);

    double d = distance(start_lat, start_lon, end_lat, end_lon);

    printf("The distance between the two coordinates is %lf kilometers", d);

    return 0;
}