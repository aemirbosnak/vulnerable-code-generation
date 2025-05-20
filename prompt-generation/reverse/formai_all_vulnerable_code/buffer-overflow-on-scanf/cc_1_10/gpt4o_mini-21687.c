//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOCATIONS 10

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int count;
} GPSNavigator;

void initializeNavigator(GPSNavigator *navigator) {
    navigator->count = 0;
}

void addLocation(GPSNavigator *navigator, const char *name, double latitude, double longitude) {
    if (navigator->count < MAX_LOCATIONS) {
        strncpy(navigator->locations[navigator->count].name, name, 50);
        navigator->locations[navigator->count].latitude = latitude;
        navigator->locations[navigator->count].longitude = longitude;
        navigator->count++;
    } else {
        printf("Location limit reached!\n");
    }
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0; // Earth radius in kilometers
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c; // Distance in kilometers
}

void displayLocations(GPSNavigator *navigator) {
    printf("Available Locations:\n");
    for (int i = 0; i < navigator->count; i++) {
        printf("%d. %s (Lat: %.6f, Lon: %.6f)\n", 
               i + 1, navigator->locations[i].name, 
               navigator->locations[i].latitude, 
               navigator->locations[i].longitude);
    }
}

void findNearestLocation(GPSNavigator *navigator, double userLat, double userLon) {
    if (navigator->count == 0) {
        printf("No locations available!\n");
        return;
    }

    double minDistance = INFINITY;
    int nearestIndex = -1;

    for (int i = 0; i < navigator->count; i++) {
        double distance = calculateDistance(userLat, userLon, 
                                             navigator->locations[i].latitude, 
                                             navigator->locations[i].longitude);
        if (distance < minDistance) {
            minDistance = distance;
            nearestIndex = i;
        }
    }

    printf("Nearest Location: %s (Distance: %.2f km)\n", 
           navigator->locations[nearestIndex].name, 
           minDistance);
}

int main() {
    GPSNavigator navigator;
    initializeNavigator(&navigator);

    int choice;
    double userLat, userLon;

    while (1) {
        printf("\nGPS Navigation Simulation Menu:\n");
        printf("1. Add Location\n");
        printf("2. Display Locations\n");
        printf("3. Find Nearest Location\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                double latitude, longitude;

                printf("Enter Location Name: ");
                scanf("%s", name);
                printf("Enter Latitude: ");
                scanf("%lf", &latitude);
                printf("Enter Longitude: ");
                scanf("%lf", &longitude);

                addLocation(&navigator, name, latitude, longitude);
                printf("Location added successfully!\n");
                break;
            }
            case 2:
                displayLocations(&navigator);
                break;
            case 3:
                printf("Enter your Latitude: ");
                scanf("%lf", &userLat);
                printf("Enter your Longitude: ");
                scanf("%lf", &userLon);

                findNearestLocation(&navigator, userLat, userLon);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}