//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define R 6371.0 // Radius of the Earth in kilometers

// Structure to hold GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} Coordinate;

// Function to convert degrees to radians
double degreesToRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

// Function to calculate distance between two coordinates using Haversine formula
double haversineDistance(Coordinate coord1, Coordinate coord2) {
    double lat1 = degreesToRadians(coord1.latitude);
    double lon1 = degreesToRadians(coord1.longitude);
    double lat2 = degreesToRadians(coord2.latitude);
    double lon2 = degreesToRadians(coord2.longitude);
    
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return R * c; // Distance in kilometers
}

// Function to determine the direction to the destination
void getDirection(Coordinate current, Coordinate destination) {
    if (destination.latitude > current.latitude) {
        if (destination.longitude > current.longitude) {
            printf("Head Northeast towards your destination.\n");
        } else {
            printf("Head Northwest towards your destination.\n");
        }
    } else {
        if (destination.longitude > current.longitude) {
            printf("Head Southeast towards your destination.\n");
        } else {
            printf("Head Southwest towards your destination.\n");
        }
    }
}

// Main function
int main() {
    Coordinate start, destination;

    // User input for starting point
    printf("Enter your starting latitude: ");
    scanf("%lf", &start.latitude);
    printf("Enter your starting longitude: ");
    scanf("%lf", &start.longitude);

    // User input for destination
    printf("Enter your destination latitude: ");
    scanf("%lf", &destination.latitude);
    printf("Enter your destination longitude: ");
    scanf("%lf", &destination.longitude);

    // Calculate the distance
    double distance = haversineDistance(start, destination);
    printf("Distance to destination: %.2f km\n", distance);

    // Get the direction to the destination
    getDirection(start, destination);

    return 0;
}