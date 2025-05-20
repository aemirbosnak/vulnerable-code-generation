//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371000.0
#define MINUTES_IN_DEGREE 60.0
#define DEGREES_IN_RADIAN PI/180.0

typedef struct {
    double latitude;
    double longitude;
} Location;

Location currentLocation, destinationLocation;
double distance, bearing;

void initialize() {
    printf("Initializing GPS...\n");
    printf("Enter your current location (latitude, longitude): ");
    scanf("%lf %lf", &currentLocation.latitude, &currentLocation.longitude);
    printf("Enter your destination location (latitude, longitude): ");
    scanf("%lf %lf", &destinationLocation.latitude, &destinationLocation.longitude);
}

void calculateDistance() {
    double dLat = destinationLocation.latitude - currentLocation.latitude;
    double dLon = destinationLocation.longitude - currentLocation.longitude;
    double a = pow(sin(dLat/2), 2) + cos(currentLocation.latitude*DEGREES_IN_RADIAN) * cos(destinationLocation.latitude*DEGREES_IN_RADIAN) * pow(sin(dLon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    distance = EARTH_RADIUS * c;
}

void calculateBearing() {
    double y = sin(destinationLocation.latitude*DEGREES_IN_RADIAN) * cos(currentLocation.latitude*DEGREES_IN_RADIAN);
    double x = cos(destinationLocation.latitude*DEGREES_IN_RADIAN) * sin(currentLocation.latitude*DEGREES_IN_RADIAN) - sin(destinationLocation.latitude*DEGREES_IN_RADIAN) * cos(currentLocation.latitude*DEGREES_IN_RADIAN) * cos(destinationLocation.longitude*DEGREES_IN_RADIAN - currentLocation.longitude*DEGREES_IN_RADIAN);
    bearing = atan2(y, x) * MINUTES_IN_DEGREE;
    if (bearing < 0) {
        bearing += 360;
    }
}

void displayDirections() {
    printf("Distance to destination: %.2lf km\n", distance);
    printf("Bearing to destination: %.2lf degrees\n", bearing);
    if (bearing >= 0 && bearing < 45) {
        printf("Head north.\n");
    } else if (bearing >= 45 && bearing < 135) {
        printf("Head northeast.\n");
    } else if (bearing >= 135 && bearing < 225) {
        printf("Head southeast.\n");
    } else if (bearing >= 225 && bearing < 315) {
        printf("Head southwest.\n");
    } else {
        printf("Head northwest.\n");
    }
}

int main() {
    initialize();
    calculateDistance();
    calculateBearing();
    displayDirections();
    return 0;
}