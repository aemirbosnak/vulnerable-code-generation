//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int size;
} GPSMap;

void initializeMap(GPSMap* map) {
    map->size = 0;
}

void addLocation(GPSMap* map, const char* name, double latitude, double longitude) {
    if (map->size < MAX_LOCATIONS) {
        strncpy(map->locations[map->size].name, name, MAX_NAME_LENGTH);
        map->locations[map->size].latitude = latitude;
        map->locations[map->size].longitude = longitude;
        map->size++;
    } else {
        printf("Map is full, cannot add more locations.\n");
    }
}

void displayMap(GPSMap* map) {
    printf("Current Locations in GPS Map:\n");
    for (int i = 0; i < map->size; i++) {
        printf("%d: %s (Lat: %.6f, Lon: %.6f)\n", i + 1, map->locations[i].name,
               map->locations[i].latitude, map->locations[i].longitude);
    }
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    // Haversine formula to calculate distance
    const double R = 6371.0; // Radius of the Earth in km
    double dLat = (lat2 - lat1) * (3.141592653589793 / 180.0);
    double dLon = (lon2 - lon1) * (3.141592653589793 / 180.0);
    lat1 = lat1 * (3.141592653589793 / 180.0);
    lat2 = lat2 * (3.141592653589793 / 180.0);
    
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c; // Distance in km
}

void findClosestLocation(GPSMap* map, double userLat, double userLon) {
    if (map->size == 0) {
        printf("No locations available to search.\n");
        return;
    }

    double closestDistance = -1;
    int closestIndex = -1;

    for (int i = 0; i < map->size; i++) {
        double distance = calculateDistance(userLat, userLon,
                                             map->locations[i].latitude,
                                             map->locations[i].longitude);
        if (closestDistance == -1 || distance < closestDistance) {
            closestDistance = distance;
            closestIndex = i;
        }
    }
    if (closestIndex != -1) {
        printf("Closest location is %s - Distance: %.2f km\n",
               map->locations[closestIndex].name, closestDistance);
    }
}

void displayMenu() {
    printf("\nGPS Navigation Simulation\n");
    printf("1. Add Location\n");
    printf("2. Display Map\n");
    printf("3. Find Closest Location\n");
    printf("4. Exit\n");
}

int main() {
    GPSMap map;
    initializeMap(&map);
    
    int choice;
    char name[MAX_NAME_LENGTH];
    double latitude, longitude, userLat, userLon;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter location name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%lf", &latitude);
                printf("Enter longitude: ");
                scanf("%lf", &longitude);
                addLocation(&map, name, latitude, longitude);
                break;
            case 2:
                displayMap(&map);
                break;
            case 3:
                printf("Enter your current latitude: ");
                scanf("%lf", &userLat);
                printf("Enter your current longitude: ");
                scanf("%lf", &userLon);
                findClosestLocation(&map, userLat, userLon);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}