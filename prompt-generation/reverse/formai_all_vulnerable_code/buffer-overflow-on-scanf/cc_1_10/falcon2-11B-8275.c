//Falcon2-11B DATASET v1.0 Category: GPS Navigation Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Global variables
int gps_latitude = 0;
int gps_longitude = 0;
int gps_altitude = 0;
int destination_latitude = 0;
int destination_longitude = 0;
int destination_altitude = 0;

// Function to convert degrees to radians
double degToRad(double degrees) {
    return degrees * M_PI / 180.0;
}

// Function to calculate distance between two points
double distance(double latitude1, double longitude1, double latitude2, double longitude2) {
    double lat1 = degToRad(latitude1);
    double lat2 = degToRad(latitude2);
    double lon1 = degToRad(longitude1);
    double lon2 = degToRad(longitude2);

    double deltaLat = lat2 - lat1;
    double deltaLon = lon2 - lon1;

    double a = sin(deltaLat / 2) * sin(deltaLat / 2) +
           cos(lat1) * cos(lat2) * sin(deltaLon / 2) * sin(deltaLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return 6371 * c; // in kilometers
}

// Function to calculate bearing between two points
double bearing(double latitude1, double longitude1, double latitude2, double longitude2) {
    double lat1 = degToRad(latitude1);
    double lat2 = degToRad(latitude2);
    double lon1 = degToRad(longitude1);
    double lon2 = degToRad(longitude2);

    double deltaLat = lat2 - lat1;
    double deltaLon = lon2 - lon1;

    double sinBearing = sin(deltaLat / 2) * cos(lat1) * cos(lat2);

    double bearingRadians = atan2(sinBearing, sin(deltaLon / 2));

    return (bearingRadians * 180 / M_PI);
}

// Function to calculate heading based on current latitude, longitude, and destination latitude, longitude
double calculateHeading(double currentLatitude, double currentLongitude, double destinationLatitude, double destinationLongitude) {
    double headingRadians = atan2(destinationLongitude - currentLongitude, destinationLatitude - currentLatitude);
    return (headingRadians * 180 / M_PI);
}

// Main function
int main() {
    // Initialize GPS latitude, longitude, and altitude
    printf("Enter latitude: ");
    scanf("%d", &gps_latitude);
    printf("Enter longitude: ");
    scanf("%d", &gps_longitude);
    printf("Enter altitude: ");
    scanf("%d", &gps_altitude);

    // Calculate current distance and bearing to destination
    double currentDistance = distance(gps_latitude, gps_longitude, destination_latitude, destination_longitude);
    double currentBearing = bearing(gps_latitude, gps_longitude, destination_latitude, destination_longitude);

    // Calculate current heading based on current latitude, longitude, and destination latitude, longitude
    double currentHeading = calculateHeading(gps_latitude, gps_longitude, destination_latitude, destination_longitude);

    // Print out current GPS information and calculated distance, bearing, and heading
    printf("Current GPS latitude: %d\n", gps_latitude);
    printf("Current GPS longitude: %d\n", gps_longitude);
    printf("Current GPS altitude: %d\n", gps_altitude);
    printf("Distance to destination: %.2f km\n", currentDistance);
    printf("Bearing to destination: %.2f degrees\n", currentBearing);
    printf("Heading: %.2f degrees\n", currentHeading);

    // Continue to calculate distance, bearing, and heading as the GPS moves closer to the destination
    double distanceDiff = currentDistance - destination_altitude;
    double bearingDiff = currentBearing - destination_longitude;
    double headingDiff = currentHeading - destination_latitude;

    // Check if GPS is within 10 meters of the destination
    if (distanceDiff < 10) {
        printf("GPS is within 10 meters of the destination\n");
    } else {
        printf("GPS is %.2f meters from the destination\n", distanceDiff);
    }

    return 0;
}