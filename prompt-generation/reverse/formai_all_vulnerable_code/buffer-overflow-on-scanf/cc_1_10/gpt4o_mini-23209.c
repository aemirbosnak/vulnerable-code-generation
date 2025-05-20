//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOCATIONS 100
#define EARTH_RADIUS 6371.0 // In kilometers

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

Location locations[MAX_LOCATIONS];
int locationCount = 0;

void addLocation(const char* name, double latitude, double longitude) {
    if (locationCount < MAX_LOCATIONS) {
        strncpy(locations[locationCount].name, name, sizeof(locations[locationCount].name) - 1);
        locations[locationCount].latitude = latitude;
        locations[locationCount].longitude = longitude;
        locationCount++;
        printf("Location '%s' added successfully!\n", name);
    } else {
        printf("Location limit reached! Cannot add more locations.\n");
    }
}

double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c; // Distance in kilometers
}

int findLocation(const char* name) {
    for (int i = 0; i < locationCount; i++) {
        if (strcmp(locations[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

void displayMenu() {
    printf("\n--- GPS Navigation Simulation Menu ---\n");
    printf("1. Add Location\n");
    printf("2. Calculate Distance\n");
    printf("3. List Locations\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char name[50];
    double lat1, lon1, lat2, lon2;

    printf("Welcome to the GPS Navigation Simulation!\n");
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter location name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%lf", &lat1);
                printf("Enter longitude: ");
                scanf("%lf", &lon1);
                addLocation(name, lat1, lon1);
                break;

            case 2:
                printf("Enter the first location name: ");
                scanf("%s", name);
                int index1 = findLocation(name);
                if (index1 == -1) {
                    printf("Location '%s' not found!\n", name);
                    break;
                }
                printf("Enter the second location name: ");
                scanf("%s", name);
                int index2 = findLocation(name);
                if (index2 == -1) {
                    printf("Location '%s' not found!\n", name);
                    break;
                }
                double distance = calculateDistance(locations[index1].latitude, locations[index1].longitude,
                                                    locations[index2].latitude, locations[index2].longitude);
                printf("Distance between '%s' and '%s': %.2f km\n", locations[index1].name, locations[index2].name, distance);
                break;

            case 3:
                printf("List of Locations:\n");
                for (int i = 0; i < locationCount; i++) {
                    printf("%s: (%.6f, %.6f)\n", locations[i].name, locations[i].latitude, locations[i].longitude);
                }
                break;

            case 4:
                printf("Exiting the GPS Navigation Simulation. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}