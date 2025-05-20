//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

// Define the GPS coordinate structure
typedef struct {
    double latitude;
    double longitude;
} GPSCoordinate;

// Function to calculate the distance between two GPS coordinates
double calculateDistance(GPSCoordinate coordinate1, GPSCoordinate coordinate2) {
    double dLat = coordinate2.latitude - coordinate1.latitude;
    double dLon = coordinate2.longitude - coordinate1.longitude;

    double a = sin(dLat / 2) * sin(dLat / 2) + cos(coordinate1.latitude) * cos(coordinate2.latitude) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

// Function to print the current date and time
void printDateTime() {
    time_t now = time(NULL);
    struct tm *timeInfo = localtime(&now);

    printf("Current date and time: %s", asctime(timeInfo));
}

// Function to get user input for GPS coordinates
void getGPSCoordinates(GPSCoordinate *coordinate) {
    printf("Enter latitude: ");
    scanf("%lf", &coordinate->latitude);

    printf("Enter longitude: ");
    scanf("%lf", &coordinate->longitude);
}

// Function to get user input for destination coordinates
void getDestinationCoordinates(GPSCoordinate *destination) {
    printf("Enter destination latitude: ");
    scanf("%lf", &destination->latitude);

    printf("Enter destination longitude: ");
    scanf("%lf", &destination->longitude);
}

// Function to simulate GPS navigation
void simulateNavigation(GPSCoordinate currentPosition, GPSCoordinate destination) {
    double distance = calculateDistance(currentPosition, destination);

    printf("Starting navigation from current position:\n");
    printf("Latitude: %.6lf\n", currentPosition.latitude);
    printf("Longitude: %.6lf\n", currentPosition.longitude);

    printf("Destination:\n");
    printf("Latitude: %.6lf\n", destination.latitude);
    printf("Longitude: %.6lf\n", destination.longitude);

    printf("Distance to destination: %.2lf km\n", distance / 1000.0);
}

int main() {
    srand(time(NULL));

    printDateTime();

    GPSCoordinate currentPosition, destination;

    getGPSCoordinates(&currentPosition);
    getDestinationCoordinates(&destination);

    simulateNavigation(currentPosition, destination);

    return 0;
}