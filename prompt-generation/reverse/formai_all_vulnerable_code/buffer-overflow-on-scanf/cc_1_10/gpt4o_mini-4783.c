//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOCATIONS 100

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int count;
} LocationList;

void addLocation(LocationList *list, const char *name, double lat, double lon) {
    if (list->count < MAX_LOCATIONS) {
        strcpy(list->locations[list->count].name, name);
        list->locations[list->count].latitude = lat;
        list->locations[list->count].longitude = lon;
        list->count++;
    } else {
        printf("Location list is full!\n");
    }
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    // Haversine formula to calculate distance between two points on Earth
    const double R = 6371.0; // Earth radius in kilometers
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) * 
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c; // Distance in kilometers
}

void findNearestLocation(LocationList *list, double currentLat, double currentLon) {
    double minDistance = -1;
    int nearestIndex = -1;

    for (int i = 0; i < list->count; i++) {
        double distance = calculateDistance(currentLat, currentLon, 
                                             list->locations[i].latitude, 
                                             list->locations[i].longitude);
        if (minDistance == -1 || distance < minDistance) {
            minDistance = distance;
            nearestIndex = i;
        }
    }

    if (nearestIndex != -1) {
        printf("Nearest location is: %s, Distance: %.2f km\n", 
               list->locations[nearestIndex].name, minDistance);
    } else {
        printf("No locations available to search.\n");
    }
}

void displayLocations(LocationList *list) {
    printf("Locations:\n");
    for (int i = 0; i < list->count; i++) {
        printf(" %d: %s (Lat: %.6f, Lon: %.6f)\n", 
               i + 1, list->locations[i].name, 
               list->locations[i].latitude, 
               list->locations[i].longitude);
    }
}

int main() {
    LocationList locations = { .count = 0 };
    int choice;
    char name[50];
    double lat, lon;

    while (1) {
        printf("\nGPS Navigation Simulation Menu:\n");
        printf("1. Add Location\n");
        printf("2. Display Locations\n");
        printf("3. Find Nearest Location\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter location name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%lf", &lat);
                printf("Enter longitude: ");
                scanf("%lf", &lon);
                addLocation(&locations, name, lat, lon);
                break;
                
            case 2:
                displayLocations(&locations);
                break;

            case 3:
                printf("Enter your current latitude: ");
                scanf("%lf", &lat);
                printf("Enter your current longitude: ");
                scanf("%lf", &lon);
                findNearestLocation(&locations, lat, lon);
                break;
                
            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}