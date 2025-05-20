//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_POINTS 100
#define RADIUS_EARTH 6371.0 // Radius of the Earth in kilometers

typedef struct {
    double latitude;
    double longitude;
} GPSPoint;

typedef struct {
    GPSPoint points[MAX_POINTS];
    int pointCount;
} Route;

void addPoint(Route* route, double latitude, double longitude) {
    if (route->pointCount < MAX_POINTS) {
        route->points[route->pointCount].latitude = latitude;
        route->points[route->pointCount].longitude = longitude;
        route->pointCount++;
    } else {
        printf("Route is full! Can't add more points.\n");
    }
}

double toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

double haversine(GPSPoint a, GPSPoint b) {
    double lat1 = toRadians(a.latitude);
    double lat2 = toRadians(b.latitude);
    double dLat = toRadians(b.latitude - a.latitude);
    double dLon = toRadians(b.longitude - a.longitude);

    double h = pow(sin(dLat / 2), 2) +
               cos(lat1) * cos(lat2) * pow(sin(dLon / 2), 2);

    double distance = 2 * RADIUS_EARTH * asin(sqrt(h));
    return distance;
}

void calculateRouteDistance(Route* route) {
    double totalDistance = 0.0;
    
    for (int i = 0; i < route->pointCount - 1; i++) {
        double dist = haversine(route->points[i], route->points[i+1]);
        totalDistance += dist;
        printf("Distance from Point %d to Point %d: %.2f km\n", i, i + 1, dist);
    }
    
    printf("Total route distance: %.2f km\n", totalDistance);
}

void displayRoute(Route* route) {
    printf("Route Details:\n");
    for (int i = 0; i < route->pointCount; i++) {
        printf("Point %d: Latitude: %.6f, Longitude: %.6f\n", 
                i, route->points[i].latitude, route->points[i].longitude);
    }
}

void getUserInput(Route* route) {
    char command[10];
    double latitude, longitude;

    while (1) {
        printf("Enter command (add/show/calibrate/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter Latitude and Longitude: ");
            scanf("%lf %lf", &latitude, &longitude);
            addPoint(route, latitude, longitude);
            printf("Point added! Wow!\n");
        } else if (strcmp(command, "show") == 0) {
            displayRoute(route);
        } else if (strcmp(command, "calibrate") == 0) {
            calculateRouteDistance(route);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program... Bye!\n");
            break;
        } else {
            printf("Unknown command! Please try again!\n");
        }
    }
}

int main() {
    printf("Welcome to the GPS Navigation Simulation! Hold on tight!\n");
    Route route;
    route.pointCount = 0;

    getUserInput(&route);
    
    return 0;
}