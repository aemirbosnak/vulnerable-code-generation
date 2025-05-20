//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOCATIONS 10
#define EARTH_RADIUS 6371.0  // Earth's radius in kilometers

typedef struct {
    char name[30];
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int locationCount;
} GPSNavigation;

// Function to calculate the distance between two points using the Haversine formula
double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    
    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return EARTH_RADIUS * c;  // Distance in kilometers
}

// Function to get user input for locations
void getLocationInput(GPSNavigation *nav) {
    printf("Enter the number of locations (max %d): ", MAX_LOCATIONS);
    scanf("%d", &nav->locationCount);

    if (nav->locationCount > MAX_LOCATIONS) {
        printf("The maximum number of locations is %d.\n", MAX_LOCATIONS);
        nav->locationCount = MAX_LOCATIONS;
    }

    for (int i = 0; i < nav->locationCount; i++) {
        printf("Enter name for location %d: ", i + 1);
        scanf("%s", nav->locations[i].name);
        printf("Enter latitude for %s: ", nav->locations[i].name);
        scanf("%lf", &nav->locations[i].latitude);
        printf("Enter longitude for %s: ", nav->locations[i].name);
        scanf("%lf", &nav->locations[i].longitude);
    }
}

// Function to find the closest location
int findClosestLocation(GPSNavigation *nav, double currentLat, double currentLon) {
    double minDistance = -1;
    int closestIndex = -1;

    for (int i = 0; i < nav->locationCount; i++) {
        double distance = haversine(currentLat, currentLon,
                                    nav->locations[i].latitude,
                                    nav->locations[i].longitude);
        printf("Distance to %s: %.2f km\n", nav->locations[i].name, distance);
        
        if (minDistance == -1 || distance < minDistance) {
            minDistance = distance;
            closestIndex = i;
        }
    }

    return closestIndex;
}

// Function to simulate GPS navigation
void simulateGPS(GPSNavigation *nav) {
    double currentLat, currentLon;

    printf("Enter your current location latitude: ");
    scanf("%lf", &currentLat);
    printf("Enter your current location longitude: ");
    scanf("%lf", &currentLon);

    printf("\nFinding closest location...\n");
    int closestIndex = findClosestLocation(nav, currentLat, currentLon);

    if (closestIndex != -1) {
        printf("The closest location is %s at (%.6f, %.6f).\n",
               nav->locations[closestIndex].name,
               nav->locations[closestIndex].latitude,
               nav->locations[closestIndex].longitude);
    } else {
        printf("No locations available.\n");
    }
}

int main() {
    GPSNavigation nav;
    nav.locationCount = 0;

    getLocationInput(&nav);
    simulateGPS(&nav);

    return 0;
}