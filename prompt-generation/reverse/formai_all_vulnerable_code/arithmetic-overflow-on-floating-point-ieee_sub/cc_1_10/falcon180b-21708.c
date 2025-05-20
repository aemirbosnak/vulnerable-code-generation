//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

// Function to calculate distance between two coordinates
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * PI / 180;
    double dLon = (lon2 - lon1) * PI / 180;
    double a =
        sin(dLat / 2) * sin(dLat / 2) +
        cos(lat1 * PI / 180) * cos(lat2 * PI / 180) *
        sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void main() {
    int choice;
    double lat1, lon1, lat2, lon2;
    double distance_km, distance_mi;

    // Get starting coordinates from user
    printf("Enter starting latitude: ");
    scanf("%lf", &lat1);
    printf("Enter starting longitude: ");
    scanf("%lf", &lon1);

    // Get destination coordinates from user
    printf("Enter destination latitude: ");
    scanf("%lf", &lat2);
    printf("Enter destination longitude: ");
    scanf("%lf", &lon2);

    // Calculate distance between coordinates
    distance_km = distance(lat1, lon1, lat2, lon2) / 1000;
    distance_mi = distance(lat1, lon1, lat2, lon2) / 1609.34;

    // Display distance in kilometers and miles
    printf("Distance between coordinates: %.2lf km or %.2lf mi\n", distance_km, distance_mi);

    // Ask user if they want to calculate another route
    printf("Do you want to calculate another route? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Exiting program...\n");
        exit(0);
    }
}