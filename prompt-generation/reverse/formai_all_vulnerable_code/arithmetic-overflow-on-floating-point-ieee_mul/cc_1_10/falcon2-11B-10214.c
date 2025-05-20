//Falcon2-11B DATASET v1.0 Category: GPS Navigation Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for Earth's radius and other parameters
#define EARTH_RADIUS 6371 // km
#define LATITUDE_MIN -90 // Degrees
#define LATITUDE_MAX 90
#define LONGITUDE_MIN -180
#define LONGITUDE_MAX 180

// Function to convert latitude and longitude to radians
float degToRad(float deg) {
    return (deg * M_PI / 180);
}

// Function to convert radians to degrees
float radToDeg(float rad) {
    return (rad * 180 / M_PI);
}

// Function to calculate the distance between two points on the Earth's surface
float calculateDistance(float lat1, float lon1, float lat2, float lon2) {
    // Convert latitude and longitude to radians
    float lat1Rad = degToRad(lat1);
    float lat2Rad = degToRad(lat2);
    float lon1Rad = degToRad(lon1);
    float lon2Rad = degToRad(lon2);

    // Calculate the differences in latitude and longitude
    float diffLat = lat2Rad - lat1Rad;
    float diffLon = lon2Rad - lon1Rad;

    // Calculate the square of the differences in latitude and longitude
    float diffLatSq = diffLat * diffLat;
    float diffLonSq = diffLon * diffLon;

    // Calculate the combined difference in latitude and longitude
    float diff = sqrt(diffLatSq + diffLonSq);

    // Calculate the distance using the Earth's radius
    float distance = EARTH_RADIUS * diff;

    return distance;
}

int main() {
    // Get input for latitude and longitude
    printf("Enter latitude: ");
    float lat;
    scanf("%f", &lat);
    printf("Enter longitude: ");
    float lon;
    scanf("%f", &lon);

    // Convert latitude and longitude to radians
    float latRad = degToRad(lat);
    float lonRad = degToRad(lon);

    // Calculate the distance to a reference point
    float distance = calculateDistance(LATITUDE_MIN, LONGITUDE_MIN, latRad, lonRad);

    // Print the distance
    printf("Distance: %f km\n", distance);

    return 0;
}