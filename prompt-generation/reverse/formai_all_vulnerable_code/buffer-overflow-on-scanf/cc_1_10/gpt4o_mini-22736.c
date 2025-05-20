//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

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
} GPSNavigator;

void addLocation(GPSNavigator *navigator, const char *name, double latitude, double longitude) {
    if (navigator->count < MAX_LOCATIONS) {
        strncpy(navigator->locations[navigator->count].name, name, MAX_NAME_LENGTH);
        navigator->locations[navigator->count].latitude = latitude;
        navigator->locations[navigator->count].longitude = longitude;
        navigator->count++;
        printf("Location '%s' added successfully!\n", name);
    } else {
        printf("Error: Location database full, cannot add '%s'.\n", name);
    }
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371; // Radius of the Earth in kilometers
    double dLat = (lat2 - lat1) * (M_PI / 180);
    double dLon = (lon2 - lon1) * (M_PI / 180);
    lat1 = lat1 * (M_PI / 180);
    lat2 = lat2 * (M_PI / 180);

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
  
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c; // Distance in kilometers
}

void findNearestLocation(GPSNavigator *navigator, double currentLat, double currentLon) {
    if (navigator->count == 0) {
        printf("Error: No locations available to search.\n");
        return;
    }
    
    double minDistance = -1;
    char nearestLocation[MAX_NAME_LENGTH];

    for (int i = 0; i < navigator->count; i++) {
        double distance = calculateDistance(currentLat, currentLon,
                                             navigator->locations[i].latitude,
                                             navigator->locations[i].longitude);
        if (minDistance == -1 || distance < minDistance) {
            minDistance = distance;
            strncpy(nearestLocation, navigator->locations[i].name, MAX_NAME_LENGTH);
        }
    }

    printf("Nearest location is '%s' at a distance of %.2f km.\n", nearestLocation, minDistance);
}

void displayLocations(GPSNavigator *navigator) {
    if (navigator->count == 0) {
        printf("No locations to display.\n");
        return;
    }
    
    printf("Locations:\n");
    for (int i = 0; i < navigator->count; i++) {
        printf("%d: %s (Lat: %.6f, Lon: %.6f)\n", 
               i + 1, 
               navigator->locations[i].name, 
               navigator->locations[i].latitude, 
               navigator->locations[i].longitude);
    }
}

void interactiveMenu() {
    GPSNavigator navigator = {.count = 0};
    int choice;

    do {
        printf("\n=== GPS Navigation System ===\n");
        printf("1. Add Location\n");
        printf("2. Display Locations\n");
        printf("3. Find Nearest Location\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char name[MAX_NAME_LENGTH];
            double latitude, longitude;

            printf("Enter location name: ");
            scanf("%s", name);
            printf("Enter latitude: ");
            scanf("%lf", &latitude);
            printf("Enter longitude: ");
            scanf("%lf", &longitude);
            addLocation(&navigator, name, latitude, longitude);
        } else if (choice == 2) {
            displayLocations(&navigator);
        } else if (choice == 3) {
            double currentLat, currentLon;
            printf("Enter your current latitude: ");
            scanf("%lf", &currentLat);
            printf("Enter your current longitude: ");
            scanf("%lf", &currentLon);
            findNearestLocation(&navigator, currentLat, currentLon);
        } else if (choice == 4) {
            printf("Exiting the GPS Navigation System. Goodbye!\n");
        } else {
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    interactiveMenu();
    return 0;
}