//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define EARTH_RADIUS 6371.01

//struct for GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} GPS_Coordinate;

//function to calculate distance between two GPS coordinates
double calculateDistance(GPS_Coordinate coordinate1, GPS_Coordinate coordinate2) {
    double dLat = coordinate2.latitude - coordinate1.latitude;
    double dLon = coordinate2.longitude - coordinate1.longitude;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(coordinate1.latitude) * cos(coordinate2.latitude) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

//function to print GPS coordinates
void printCoordinate(GPS_Coordinate coordinate) {
    printf("Latitude: %lf\n", coordinate.latitude);
    printf("Longitude: %lf\n", coordinate.longitude);
}

//function to generate random GPS coordinates
GPS_Coordinate generateRandomCoordinate() {
    GPS_Coordinate coordinate;
    coordinate.latitude = rand() % 180 - 90;
    coordinate.longitude = rand() % 360 - 180;
    return coordinate;
}

//function to simulate GPS navigation
void simulateGPSNavigation(int numOfPoints) {
    srand(time(NULL));
    GPS_Coordinate currentCoordinate = generateRandomCoordinate();
    GPS_Coordinate destinationCoordinate = generateRandomCoordinate();

    printf("Starting location: ");
    printCoordinate(currentCoordinate);
    printf("Destination: ");
    printCoordinate(destinationCoordinate);

    double totalDistance = calculateDistance(currentCoordinate, destinationCoordinate);
    double distanceTravelled = 0;

    int i;
    for (i = 0; i < numOfPoints; i++) {
        double distanceToNextPoint = totalDistance / numOfPoints;
        distanceTravelled += distanceToNextPoint;
        GPS_Coordinate nextCoordinate = generateRandomCoordinate();
        printf("Travelled %.2lf km, current location: ", distanceTravelled);
        printCoordinate(nextCoordinate);
    }

    printf("Reached destination after travelling %.2lf km.\n", distanceTravelled);
}

//main function
int main() {
    int numOfPoints;
    printf("Enter the number of points to simulate: ");
    scanf("%d", &numOfPoints);

    simulateGPSNavigation(numOfPoints);

    return 0;
}