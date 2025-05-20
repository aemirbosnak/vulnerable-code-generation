//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define EARTH_RADIUS 6371.01 // in km
#define PI 3.14159265359

// GPS coordinate structure
typedef struct {
    double latitude;
    double longitude;
} GPSCoordinate;

// GPS simulation functions
GPSCoordinate getGPSLocation(double speed, double direction, double time) {
    GPSCoordinate location;
    double distance = speed * time;
    double angle = direction * PI / 180;
    location.latitude = sin(angle) * distance * EARTH_RADIUS;
    location.longitude = cos(angle) * distance * EARTH_RADIUS;
    return location;
}

void printGPSLocation(GPSCoordinate location) {
    printf("Latitude: %.2f\n", location.latitude);
    printf("Longitude: %.2f\n", location.longitude);
}

// Main function
int main() {
    double speed, direction, time;
    GPSCoordinate currentLocation, destination;

    // Get user input for speed, direction, and time
    printf("Enter speed in km/h: ");
    scanf("%lf", &speed);
    printf("Enter direction in degrees: ");
    scanf("%lf", &direction);
    printf("Enter time in seconds: ");
    scanf("%lf", &time);

    // Calculate current location based on speed and direction
    currentLocation = getGPSLocation(speed, direction, time);
    printf("Current location:\n");
    printGPSLocation(currentLocation);

    // Calculate destination based on current location
    destination = getGPSLocation(speed, direction + 180, time);
    printf("Destination:\n");
    printGPSLocation(destination);

    return 0;
}