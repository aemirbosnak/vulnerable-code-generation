//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int count;
} GPS;

void initializeGPS(GPS *gps) {
    gps->count = 0;
}

void addLocation(GPS *gps, const char *name, double latitude, double longitude) {
    if (gps->count < MAX_LOCATIONS) {
        strncpy(gps->locations[gps->count].name, name, MAX_NAME_LENGTH);
        gps->locations[gps->count].latitude = latitude;
        gps->locations[gps->count].longitude = longitude;
        gps->count++;
    } else {
        printf("GPS location memory full. Cannot add more locations.\n");
    }
}

void displayLocations(const GPS *gps) {
    for (int i = 0; i < gps->count; i++) {
        printf("Location %d: %s (%.6f, %.6f)\n", i + 1, gps->locations[i].name,
               gps->locations[i].latitude, gps->locations[i].longitude);
    }
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    // Haversine formula implementation
    const double R = 6371.0; // Earth's radius in kilometers
    double dlat = (lat2 - lat1) * (3.141592653589793 / 180.0);
    double dlon = (lon2 - lon1) * (3.141592653589793 / 180.0);
    lat1 = lat1 * (3.141592653589793 / 180.0);
    lat2 = lat2 * (3.141592653589793 / 180.0);

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c; // Distance in kilometers
}

void findNearestLocation(const GPS *gps, double currentLat, double currentLon) {
    double minDistance = -1.0;
    int nearestIndex = -1;

    for (int i = 0; i < gps->count; i++) {
        double distance = calculateDistance(currentLat, currentLon,
                                             gps->locations[i].latitude,
                                             gps->locations[i].longitude);
        if (minDistance == -1.0 || distance < minDistance) {
            minDistance = distance;
            nearestIndex = i;
        }
    }

    if (nearestIndex != -1) {
        printf("Nearest Location: %s (%.6f, %.6f) - Distance: %.2f km\n",
               gps->locations[nearestIndex].name,
               gps->locations[nearestIndex].latitude,
               gps->locations[nearestIndex].longitude,
               minDistance);
    } else {
        printf("No locations available to find the nearest one.\n");
    }
}

void displayMenu() {
    printf("\nGPS Navigation Simulation\n");
    printf("1. Add Location\n");
    printf("2. Display Locations\n");
    printf("3. Find Nearest Location\n");
    printf("4. Exit\n");
}

int main() {
    GPS gps;
    initializeGPS(&gps);

    int choice;
    char locationName[MAX_NAME_LENGTH];
    double latitude, longitude;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter location name: ");
                scanf("%s", locationName);
                printf("Enter latitude: ");
                scanf("%lf", &latitude);
                printf("Enter longitude: ");
                scanf("%lf", &longitude);
                addLocation(&gps, locationName, latitude, longitude);
                break;
            case 2:
                displayLocations(&gps);
                break;
            case 3:
                printf("Enter your current latitude: ");
                scanf("%lf", &latitude);
                printf("Enter your current longitude: ");
                scanf("%lf", &longitude);
                findNearestLocation(&gps, latitude, longitude);
                break;
            case 4:
                printf("Exiting GPS simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}