//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359
#define RADIUS 6371.01

struct point {
    double latitude;
    double longitude;
};

double distance(struct point p1, struct point p2) {
    double dLat = p2.latitude - p1.latitude;
    double dLon = p2.longitude - p1.longitude;
    double a = sin(dLat/2) * sin(dLat/2) + cos(p1.latitude) * cos(p2.latitude) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return RADIUS * c;
}

int main() {
    int numLocations;
    printf("Enter the number of locations: ");
    scanf("%d", &numLocations);

    struct point locations[numLocations];

    for(int i=0; i<numLocations; i++) {
        printf("Enter the latitude and longitude for location %d: ", i+1);
        scanf("%lf %lf", &locations[i].latitude, &locations[i].longitude);
    }

    int numRoutes;
    printf("Enter the number of routes: ");
    scanf("%d", &numRoutes);

    for(int i=0; i<numRoutes; i++) {
        int numStops;
        printf("Enter the number of stops for route %d: ", i+1);
        scanf("%d", &numStops);

        struct point stops[numStops];

        for(int j=0; j<numStops; j++) {
            printf("Enter the latitude and longitude for stop %d: ", j+1);
            scanf("%lf %lf", &stops[j].latitude, &stops[j].longitude);
        }

        double totalDistance = 0;
        for(int j=0; j<numStops-1; j++) {
            totalDistance += distance(stops[j], stops[j+1]);
        }

        printf("The total distance for route %d is %.2lf km.\n", i+1, totalDistance);
    }

    return 0;
}