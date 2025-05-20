//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

// GPS coordinates struct
typedef struct {
    double lat;
    double lon;
} GPSCoords;

// Function to calculate distance between two GPS coordinates
double calculateDistance(GPSCoords coord1, GPSCoords coord2) {
    double dLat = coord2.lat - coord1.lat;
    double dLon = coord2.lon - coord1.lon;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(coord1.lat) * cos(coord2.lat) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

// Function to convert GPS coordinates from degrees to radians
void convertToRadians(GPSCoords *coord) {
    coord->lat = coord->lat * PI / 180;
    coord->lon = coord->lon * PI / 180;
}

// Function to get user input for GPS coordinates
void getGPSInput(GPSCoords *coord) {
    printf("Enter latitude: ");
    scanf("%lf", &coord->lat);
    printf("Enter longitude: ");
    scanf("%lf", &coord->lon);
}

int main() {
    // Initialize GPS coordinates for starting point and destination
    GPSCoords start, dest;
    getGPSInput(&start);
    getGPSInput(&dest);

    // Convert GPS coordinates from degrees to radians
    convertToRadians(&start);
    convertToRadians(&dest);

    // Calculate distance between starting point and destination
    double distance = calculateDistance(start, dest);

    // Print results
    printf("Distance between (%lf, %lf) and (%lf, %lf): %lf km\n", start.lat, start.lon, dest.lat, dest.lon, distance);

    return 0;
}