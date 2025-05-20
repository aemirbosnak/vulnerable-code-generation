//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01 // in km
#define MINUTES_PER_DEGREE 60
#define DEGREES_PER_RADIAN (180/PI)

// Define the structure for a GPS coordinate
typedef struct {
    double latitude;
    double longitude;
} GPSCoordinate;

GPSCoordinate currentLocation; // The user's current location
GPSCoordinate destination; // The user's destination

void getCurrentLocation() {
    printf("Enter your current latitude: ");
    scanf("%lf", &currentLocation.latitude);
    printf("Enter your current longitude: ");
    scanf("%lf", &currentLocation.longitude);
}

void getDestination() {
    printf("Enter your destination latitude: ");
    scanf("%lf", &destination.latitude);
    printf("Enter your destination longitude: ");
    scanf("%lf", &destination.longitude);
}

double calculateDistance(GPSCoordinate location1, GPSCoordinate location2) {
    double lat1 = location1.latitude * PI / 180;
    double lat2 = location2.latitude * PI / 180;
    double dLat = lat2 - lat1;
    double dLon = location2.longitude * PI / 180 - location1.longitude * PI / 180;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;
    return distance;
}

void calculateRoute() {
    double distance = calculateDistance(currentLocation, destination);
    double minutes = distance / (currentLocation.latitude * MINUTES_PER_DEGREE);
    double degrees = minutes * DEGREES_PER_RADIAN;
    printf("The distance between your current location and your destination is %.2f km.\n", distance);
    printf("You need to travel %.2f degrees north and %.2f degrees east.\n", degrees, 0);
}

int main() {
    getCurrentLocation();
    getDestination();
    calculateRoute();
    return 0;
}