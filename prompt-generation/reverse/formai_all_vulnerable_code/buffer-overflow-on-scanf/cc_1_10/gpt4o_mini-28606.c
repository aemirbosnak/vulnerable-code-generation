//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 100
#define LOCATION_NAME_LENGTH 50

typedef struct {
    char name[LOCATION_NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int count;
} GPSNavigation;

void addLocation(GPSNavigation *gps, const char *name, double latitude, double longitude) {
    if (gps->count < MAX_LOCATIONS) {
        strcpy(gps->locations[gps->count].name, name);
        gps->locations[gps->count].latitude = latitude;
        gps->locations[gps->count].longitude = longitude;
        gps->count++;
        printf("Location '%s' added successfully!\n", name);
    } else {
        printf("Maximum number of locations reached.\n");
    }
}

void listLocations(const GPSNavigation *gps) {
    for (int i = 0; i < gps->count; i++) {
        printf("Location %d: %s (Lat: %.6f, Long: %.6f)\n", i + 1,
               gps->locations[i].name, gps->locations[i].latitude, gps->locations[i].longitude);
    }
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0; // Radius of the Earth in kilometers
    double dlat = (lat2 - lat1) * (3.14159265 / 180.0);
    double dlon = (lon2 - lon1) * (3.14159265 / 180.0);
    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1 * (3.14159265 / 180.0)) * cos(lat2 * (3.14159265 / 180.0)) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c; // Distance in kilometers
}

void findNearestLocation(const GPSNavigation *gps, double currentLat, double currentLon) {
    if (gps->count == 0) {
        printf("No locations available.\n");
        return;
    }

    double minDistance = -1;
    int nearestIndex = -1;

    for (int i = 0; i < gps->count; i++) {
        double distance = calculateDistance(currentLat, currentLon,
                                             gps->locations[i].latitude,
                                             gps->locations[i].longitude);
        if (minDistance < 0 || distance < minDistance) {
            minDistance = distance;
            nearestIndex = i;
        }
    }

    printf("Nearest location is '%s' at a distance of %.2f km.\n",
           gps->locations[nearestIndex].name, minDistance);
}

int main() {
    GPSNavigation gps = { .count = 0 };
    int choice;
    double currentLat, currentLon;

    while (1) {
        printf("\nGPS Navigation System\n");
        printf("1. Add Location\n");
        printf("2. List Locations\n");
        printf("3. Set Current Location\n");
        printf("4. Find Nearest Location\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[LOCATION_NAME_LENGTH];
                double latitude, longitude;
                printf("Enter location name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%lf", &latitude);
                printf("Enter longitude: ");
                scanf("%lf", &longitude);
                addLocation(&gps, name, latitude, longitude);
                break;
            }
            case 2:
                listLocations(&gps);
                break;
            case 3: {
                printf("Enter current latitude: ");
                scanf("%lf", &currentLat);
                printf("Enter current longitude: ");
                scanf("%lf", &currentLon);
                break;
            }
            case 4:
                findNearestLocation(&gps, currentLat, currentLon);
                break;
            case 5:
                printf("Exiting the GPS Navigation System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}