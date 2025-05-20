//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

typedef struct {
    double latitude;
    double longitude;
    double altitude;
} GPSLocation;

typedef struct {
    GPSLocation current;
    GPSLocation destination;
    int route_type;
} GPSRoute;

void GPSInit(GPSLocation *location) {
    srand(time(NULL));
    location->latitude = rand() % 90 - 45;
    location->longitude = rand() % 180 - 90;
    location->altitude = rand() % 1000;
}

double GPSCalculateDistance(GPSLocation location1, GPSLocation location2) {
    double dLat = location2.latitude - location1.latitude;
    double dLon = location2.longitude - location1.longitude;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(location1.latitude) * cos(location2.latitude) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

int GPSNavigate(GPSRoute *route) {
    double distance = GPSCalculateDistance(route->current, route->destination);
    if(distance <= 10) {
        printf("You have reached your destination!\n");
        return 1;
    } else {
        printf("Current location: %.2f, %.2f\n", route->current.latitude, route->current.longitude);
        printf("Destination: %.2f, %.2f\n", route->destination.latitude, route->destination.longitude);
        printf("Distance to destination: %.2f km\n", distance);
    }
    return 0;
}

int main() {
    GPSLocation current;
    GPSLocation destination;
    GPSRoute route;
    int choice;

    do {
        printf("GPS Navigation System\n");
        printf("1. Enter current location\n");
        printf("2. Enter destination\n");
        printf("3. Navigate\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                GPSInit(&current);
                printf("Current location set to: %.2f, %.2f\n", current.latitude, current.longitude);
                break;
            case 2:
                GPSInit(&destination);
                printf("Destination set to: %.2f, %.2f\n", destination.latitude, destination.longitude);
                break;
            case 3:
                route.current = current;
                route.destination = destination;
                GPSNavigate(&route);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);

    return 0;
}