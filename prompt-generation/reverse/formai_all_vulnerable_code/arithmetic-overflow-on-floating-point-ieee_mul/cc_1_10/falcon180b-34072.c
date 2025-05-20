//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double latitude;
    double longitude;
} GPSLocation;

GPSLocation currentLocation;
GPSLocation destinationLocation;

void initializeGPS(GPSLocation* location) {
    location->latitude = rand() % 180 - 90;
    location->longitude = rand() % 360 - 180;
}

double calculateDistance(GPSLocation* location1, GPSLocation* location2) {
    double lat1 = location1->latitude * PI / 180;
    double lat2 = location2->latitude * PI / 180;
    double dLat = lat2 - lat1;
    double dLon = location2->longitude * PI / 180 - location1->longitude * PI / 180;

    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return 6371 * c; // Earth's radius in km
}

void printLocation(GPSLocation* location) {
    printf("Latitude: %.2f\nLongitude: %.2f\n", location->latitude, location->longitude);
}

int main() {
    srand(time(NULL));

    initializeGPS(&currentLocation);
    initializeGPS(&destinationLocation);

    printf("Current location:\n");
    printLocation(&currentLocation);

    printf("Enter destination latitude: ");
    scanf("%lf", &destinationLocation.latitude);

    printf("Enter destination longitude: ");
    scanf("%lf", &destinationLocation.longitude);

    double distance = calculateDistance(&currentLocation, &destinationLocation);

    printf("Distance to destination: %.2f km\n", distance);

    return 0;
}