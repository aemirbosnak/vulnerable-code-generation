//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS_EARTH 6371.0  // Kilometers

// Degree-to-radian conversion factor
#define DEG_TO_RAD (M_PI / 180.0)

// Distance formula using haversine formula
double haversine_distance(double lat1, double lon1, double lat2, double lon2) {
    // Convert to radians
    lat1 *= DEG_TO_RAD;
    lon1 *= DEG_TO_RAD;
    lat2 *= DEG_TO_RAD;
    lon2 *= DEG_TO_RAD;

    // Calculate difference between latitudes and longitudes
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    // Calculate square of half the chord length
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);

    // Calculate central angle
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    // Return distance in kilometers
    return RADIUS_EARTH * c;
}

int main() {
    // Prompt for user input
    printf("Enter the coordinates of two points:\n");
    printf("Latitude of point 1 (in degrees): ");
    double lat1;
    scanf("%lf", &lat1);
    printf("Longitude of point 1 (in degrees): ");
    double lon1;
    scanf("%lf", &lon1);
    printf("Latitude of point 2 (in degrees): ");
    double lat2;
    scanf("%lf", &lat2);
    printf("Longitude of point 2 (in degrees): ");
    double lon2;
    scanf("%lf", &lon2);

    // Calculate distance
    double distance = haversine_distance(lat1, lon1, lat2, lon2);

    // Print result
    printf("\nThe distance between the two points is: %.2f kilometers\n", distance);

    return 0;
}