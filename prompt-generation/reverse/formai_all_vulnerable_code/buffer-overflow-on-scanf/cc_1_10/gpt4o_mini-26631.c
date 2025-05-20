//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOCATIONS 100
#define EARTH_RADIUS 6371.0 // Radius of the Earth in kilometers

// Structure to store location information
typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

// Function to calculate the distance between two locations using Haversine formula
double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dlat = (lat2 - lat1) * M_PI / 180.0;
    double dlon = (lon2 - lon1) * M_PI / 180.0;
    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c; // Distance in kilometers
}

// Function to input locations
void inputLocation(Location *loc) {
    printf("Enter location name: ");
    scanf(" %[^\n]", loc->name);
    printf("Enter latitude: ");
    scanf("%lf", &loc->latitude);
    printf("Enter longitude: ");
    scanf("%lf", &loc->longitude);
}

// Function to display a location
void displayLocation(const Location *loc) {
    printf("Location: %s\n", loc->name);
    printf("Coordinates: Latitude %.6f, Longitude %.6f\n", loc->latitude, loc->longitude);
}

// Function to find the nearest location from a given point
void findNearestLocation(const Location *locations, int count, double lat, double lon) {
    double minDistance = -1;
    int nearestIndex = -1;

    for (int i = 0; i < count; i++) {
        double distance = haversine(lat, lon, locations[i].latitude, locations[i].longitude);
        if (minDistance == -1 || distance < minDistance) {
            minDistance = distance;
            nearestIndex = i;
        }
    }

    if (nearestIndex != -1) {
        printf("The nearest location is:\n");
        displayLocation(&locations[nearestIndex]);
        printf("Distance: %.2f km\n", minDistance);
    } else {
        printf("No locations available.\n");
    }
}

int main() {
    Location locations[MAX_LOCATIONS];
    int count = 0;
    char choice;

    do {
        printf("GPS Navigation Simulation\n");
        printf("1. Input a new location\n");
        printf("2. Find nearest location\n");
        printf("3. Display all locations\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (count < MAX_LOCATIONS) {
                    inputLocation(&locations[count]);
                    count++;
                } else {
                    printf("Location storage is full!\n");
                }
                break;

            case '2':
                if (count > 0) {
                    double userLat, userLon;
                    printf("Enter your current latitude: ");
                    scanf("%lf", &userLat);
                    printf("Enter your current longitude: ");
                    scanf("%lf", &userLon);
                    findNearestLocation(locations, count, userLat, userLon);
                } else {
                    printf("No locations available to find nearest.\n");
                }
                break;

            case '3':
                if (count > 0) {
                    printf("All Locations:\n");
                    for (int i = 0; i < count; i++) {
                        displayLocation(&locations[i]);
                    }
                } else {
                    printf("No locations stored yet.\n");
                }
                break;

            case '4':
                printf("Exiting the simulation. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }

        printf("\n");

    } while (choice != '4');

    return 0;
}