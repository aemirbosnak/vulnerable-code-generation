//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// function that simulates GPS navigation
void navigate(double lat_origin, double long_origin,
              double lat_dest, double long_dest) {

    // convert degrees to radians
    double lat1 = lat_origin * PI / 180;
    double long1 = long_origin * PI / 180;
    double lat2 = lat_dest * PI / 180;
    double long2 = long_dest * PI / 180;

    // calculate differences
    double delta_lat = lat2 - lat1;
    double delta_long = long2 - long1;

    // calculate distance
    double R = 6371; // Earth's radius in km
    double a = sin(delta_lat / 2) * sin(delta_lat / 2) +
               cos(lat1) * cos(lat2) *
               sin(delta_long / 2) * sin(delta_long / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c;

    // calculate bearing
    double y = sin(delta_long) * cos(lat2);
    double x = cos(lat1) * sin(lat2) -
               sin(lat1) * cos(lat2) * cos(delta_long);
    double bearing = atan2(y, x) * 180 / PI;

    // print results
    printf("Starting point: (%f,%f)\n", lat_origin, long_origin);
    printf("Destination point: (%f,%f)\n", lat_dest, long_dest);
    printf("Distance between points: %f km\n", distance);
    printf("Bearing from starting point to destination: %f degrees\n", bearing);
}

int main() {
    double lat1, long1, lat2, long2;

    // prompt user for input
    printf("Enter starting point (latitude,longitude): ");
    scanf("%lf,%lf", &lat1, &long1);
    printf("Enter destination point (latitude,longitude): ");
    scanf("%lf,%lf", &lat2, &long2);

    // simulate navigation
    navigate(lat1, long1, lat2, long2);

    return 0;
}