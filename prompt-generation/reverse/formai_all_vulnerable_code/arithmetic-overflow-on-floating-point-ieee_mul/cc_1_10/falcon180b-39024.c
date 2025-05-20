//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define PI 3.14159265358979323846

// Define the Earth's radius in kilometers
#define EARTH_RADIUS 6371.01

typedef struct {
    double lat;
    double lon;
    double alt;
} location;

// Function to calculate the distance between two points on the Earth's surface
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

// Function to convert degrees to radians
double deg2rad(double deg) {
    return deg * PI / 180.0;
}

int main() {
    location start, end;
    char input[100];
    double distance_km, distance_mi;

    // Get starting location from user
    printf("Enter starting location (latitude, longitude, altitude): ");
    scanf("%lf,%lf,%lf", &start.lat, &start.lon, &start.alt);

    // Get ending location from user
    printf("Enter ending location (latitude, longitude, altitude): ");
    scanf("%lf,%lf,%lf", &end.lat, &end.lon, &end.alt);

    // Calculate distance between locations
    distance_km = distance(start.lat, start.lon, end.lat, end.lon);
    distance_mi = distance_km * 0.621371;

    // Display results
    printf("Distance between locations: %.2lf km or %.2lf mi\n", distance_km, distance_mi);

    return 0;
}