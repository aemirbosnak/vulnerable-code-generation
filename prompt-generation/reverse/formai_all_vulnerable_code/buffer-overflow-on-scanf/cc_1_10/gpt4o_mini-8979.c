//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOCATIONS 100
#define EARTH_RADIUS 6371.0 // Earth radius in kilometers

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

Location locations[MAX_LOCATIONS];
int locationCount = 0;

void addLocation(char *name, double latitude, double longitude) {
    if (locationCount < MAX_LOCATIONS) {
        strcpy(locations[locationCount].name, name);
        locations[locationCount].latitude = latitude;
        locations[locationCount].longitude = longitude;
        locationCount++;
    } else {
        printf("Location limit reached!\n");
    }
}

double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

double haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);
    
    lat1 = toRadians(lat1);
    lat2 = toRadians(lat2);

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c; // Distance in kilometers
}

void findNearestLocation(double userLat, double userLon) {
    double minDistance = -1;
    char nearestLocation[50];
    
    for (int i = 0; i < locationCount; i++) {
        double distance = haversineDistance(userLat, userLon, locations[i].latitude, locations[i].longitude);
        if (minDistance == -1 || distance < minDistance) {
            minDistance = distance;
            strcpy(nearestLocation, locations[i].name);
        }
    }
    
    if (minDistance != -1) {
        printf("Nearest location: %s, Distance: %.2f km\n", nearestLocation, minDistance);
    } else {
        printf("No locations available!\n");
    }
}

void displayLocations() {
    printf("List of Locations:\n");
    for (int i = 0; i < locationCount; i++) {
        printf("%d: %s (Lat: %.6f, Lon: %.6f)\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

int main() {
    int choice;
    double userLat, userLon;
    char name[50];
    double latitude, longitude;

    while (1) {
        printf("\nGPS Navigation Simulation:\n");
        printf("1. Add Location\n");
        printf("2. Find Nearest Location\n");
        printf("3. Display All Locations\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter location name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%lf", &latitude);
                printf("Enter longitude: ");
                scanf("%lf", &longitude);
                addLocation(name, latitude, longitude);
                break;

            case 2:
                printf("Enter your latitude: ");
                scanf("%lf", &userLat);
                printf("Enter your longitude: ");
                scanf("%lf", &userLon);
                findNearestLocation(userLat, userLon);
                break;

            case 3:
                displayLocations();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}