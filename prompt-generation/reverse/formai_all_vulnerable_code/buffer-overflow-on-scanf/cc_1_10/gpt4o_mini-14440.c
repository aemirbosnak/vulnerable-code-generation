//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

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
} Map;

void initMap(Map *map) {
    map->count = 0;
}

void addLocation(Map *map, const char *name, double latitude, double longitude) {
    if (map->count < MAX_LOCATIONS) {
        snprintf(map->locations[map->count].name, MAX_NAME_LENGTH, "%s", name);
        map->locations[map->count].latitude = latitude;
        map->locations[map->count].longitude = longitude;
        map->count++;
    } else {
        printf("Error: Max locations reached!\n");
    }
}

void displayLocations(const Map *map) {
    printf("\nAvailable Locations:\n");
    for (int i = 0; i < map->count; i++) {
        printf("%d: %s (%.6f, %.6f)\n", i + 1, map->locations[i].name,
               map->locations[i].latitude, map->locations[i].longitude);
    }
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double radlat1 = M_PI * lat1 / 180;
    double radlat2 = M_PI * lat2 / 180;
    double theta = lon1 - lon2;
    double radtheta = M_PI * theta / 180;

    double dist = sin(radlat1) * sin(radlat2) + cos(radlat1) * cos(radlat2) * cos(radtheta);
    dist = acos(dist);
    dist = dist * 180 / M_PI; // Convert from radians to degrees
    dist = dist * 60 * 1.1515; // Convert to miles
    return dist;
}

void findNearestLocation(const Map *map, double userLat, double userLon) {
    if (map->count == 0) {
        printf("No locations available to navigate to.\n");
        return;
    }

    double minDistance = calculateDistance(userLat, userLon,
                            map->locations[0].latitude, map->locations[0].longitude);
    int nearestIndex = 0;

    for (int i = 1; i < map->count; i++) {
        double distance = calculateDistance(userLat, userLon,
                            map->locations[i].latitude, map->locations[i].longitude);
        if (distance < minDistance) {
            minDistance = distance;
            nearestIndex = i;
        }
    }

    printf("The nearest location is: %s, Distance: %.2f miles\n", 
            map->locations[nearestIndex].name, minDistance);
}

void showMenu() {
    printf("\nGPS Navigation Simulation Menu:\n");
    printf("1. Add Location\n");
    printf("2. Display Locations\n");
    printf("3. Find Nearest Location\n");
    printf("4. Exit\n");
}

int main() {
    Map map;
    initMap(&map);
    int choice;
    char name[MAX_NAME_LENGTH];
    double latitude, longitude;
    double userLat, userLon;

    while (1) {
        showMenu();
        printf("Select an option (1-4): ");
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
                displayLocations(&map);
                break;

            case 3:
                printf("Enter your current latitude: ");
                scanf("%lf", &userLat);
                printf("Enter your current longitude: ");
                scanf("%lf", &userLon);
                findNearestLocation(&map, userLat, userLon);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}