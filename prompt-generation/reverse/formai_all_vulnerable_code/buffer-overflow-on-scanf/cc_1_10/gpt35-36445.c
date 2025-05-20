//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define RADIUS 6371 // Earth's radius in km

typedef struct {
    double latitude;
    double longitude;
} Coordinate;

double degreesToRadians(double degrees) {
    return degrees * (M_PI / 180);
}

double calcDistance(Coordinate p1, Coordinate p2) {
    double lat1 = degreesToRadians(p1.latitude);
    double lon1 = degreesToRadians(p1.longitude);
    double lat2 = degreesToRadians(p2.latitude);
    double lon2 = degreesToRadians(p2.longitude);
    
    double deltaLat = lat2 - lat1;
    double deltaLon = lon2 - lon1;
    
    double a = pow(sin(deltaLat/2),2) + cos(lat1) * cos(lat2) * pow(sin(deltaLon/2),2);
    
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    
    return RADIUS * c;
}

Coordinate promptCoordinates() {
    Coordinate point;
    printf("Enter latitude in degrees (-90 to 90): ");
    scanf("%lf", &point.latitude);
    printf("Enter longitude in degrees (-180 to 180): ");
    scanf("%lf", &point.longitude);
    return point;
}

void simulation() {
    int distance;
    Coordinate currentLocation = promptCoordinates();
    Coordinate destination = promptCoordinates();
    
    printf("Calculating route...\n");
    distance = (int) round(calcDistance(currentLocation, destination));
    
    printf("Estimated distance to destination: %d km\n", distance);
    printf("Begin Navigation (press any key to continue)...\n");
    
    srand(time(NULL)); // seed random number generator
    while(distance > 0) {
        int randomDistance = rand() % 10 + 1; // generate random distance between 1 and 10 km
        
        if(distance < randomDistance) { // check if remaining distance is less than randomly generated distance
            randomDistance = distance; // set the remaining distance
        }
        
        printf("Go %d km \n", randomDistance);
        distance -= randomDistance; // decrement the distance remaining
        double bearing = atan2(sin(destination.longitude-currentLocation.longitude)*cos(destination.latitude), cos(currentLocation.latitude)*sin(destination.latitude)-sin(currentLocation.latitude)*cos(destination.latitude)*cos(destination.longitude-currentLocation.longitude));
        
        currentLocation.latitude += (180/M_PI)*((double)randomDistance/RADIUS)*cos(bearing);
        currentLocation.longitude += (180/M_PI)*((double)randomDistance/RADIUS)*sin(bearing) / cos(currentLocation.latitude);
    }
    
    printf("You have reached your destination!\n");
}

int main() {
    simulation();
    return 0;
}