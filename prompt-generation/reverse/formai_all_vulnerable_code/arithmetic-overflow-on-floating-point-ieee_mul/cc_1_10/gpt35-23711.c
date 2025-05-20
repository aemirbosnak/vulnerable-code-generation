//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS_OF_EARTH 6371 // radius of earth in km
#define MAX_LOCATIONS 10 // maximum number of locations
#define PI 3.14159265358979323846 // value of pi

// function to calculate distance between two points using longitude and latitude
double calculateDistance(double currLat, double currLong, double destLat, double destLong) {
    currLat = currLat * PI / 180; // convert latitude to radians
    currLong = currLong * PI / 180; // convert longitude to radians
    destLat = destLat * PI / 180; // convert latitude to radians
    destLong = destLong * PI / 180; // convert longitude to radians

    double dlon = destLong - currLong;
    double dlat = destLat - currLat;

    double a = pow(sin(dlat / 2), 2) + cos(currLat) * cos(destLat) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = RADIUS_OF_EARTH * c;

    return distance;
}

// function to find and display nearest location
void findNearestLocation(double currLat, double currLong, double locations[MAX_LOCATIONS][2], int num) {
    double shortestDistance = calculateDistance(currLat, currLong, locations[0][0], locations[0][1]); // assume first location as nearest
    int nearestIndex = 0;

    for(int i = 1; i < num; i++) {
        double currDistance = calculateDistance(currLat, currLong, locations[i][0], locations[i][1]);
        if(currDistance < shortestDistance) {
            shortestDistance = currDistance;
            nearestIndex = i;
        }
    }

    printf("Nearest location is at latitude %lf and longitude %lf, which is %.2lf km away from current location.\n", locations[nearestIndex][0], locations[nearestIndex][1], shortestDistance);
}

int main() {
    double currentLatitude, currentLongitude;
    int numOfLocations;

    printf("Enter your current location (latitude and longitude separated by space): ");
    scanf("%lf %lf", &currentLatitude, &currentLongitude);

    printf("Enter the number of locations: ");
    scanf("%d", &numOfLocations);

    double locations[MAX_LOCATIONS][2];

    for(int i = 1; i <= numOfLocations; i++) {
        printf("Enter location %d (latitude and longitude separated by space): ", i);
        scanf("%lf %lf", &locations[i-1][0], &locations[i-1][1]);
    }

    findNearestLocation(currentLatitude, currentLongitude, locations, numOfLocations);

    return 0;
}