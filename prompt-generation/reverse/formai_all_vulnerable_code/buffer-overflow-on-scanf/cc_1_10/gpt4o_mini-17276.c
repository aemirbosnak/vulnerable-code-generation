//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DESTINATIONS 10
#define EARTH_RADIUS 6371.0 // Radius of Earth in kilometers

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Destination;

typedef struct {
    Destination destinations[MAX_DESTINATIONS];
    int count;
} DestinationList;

void addDestination(DestinationList *list, const char *name, double lat, double lon) {
    if (list->count < MAX_DESTINATIONS) {
        strcpy(list->destinations[list->count].name, name);
        list->destinations[list->count].latitude = lat;
        list->destinations[list->count].longitude = lon;
        list->count++;
    } else {
        printf("Destination list is full!\n");
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

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c; // Distance in kilometers
}

void findClosestDestination(DestinationList *list, double latitude, double longitude) {
    if (list->count == 0) {
        printf("No destinations to choose from.\n");
        return;
    }

    double minDistance = calculateDistance(latitude, longitude, list->destinations[0].latitude, list->destinations[0].longitude);
    char *closestDestination = list->destinations[0].name;

    for (int i = 1; i < list->count; i++) {
        double distance = calculateDistance(latitude, longitude, list->destinations[i].latitude, list->destinations[i].longitude);
        if (distance < minDistance) {
            minDistance = distance;
            closestDestination = list->destinations[i].name;
        }
    }
    
    printf("Closest destination: %s (Distance: %.2f km)\n", closestDestination, minDistance);
}

void displayDestinations(DestinationList *list) {
    printf("Destinations:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s - Latitude: %.6f, Longitude: %.6f\n", i + 1,
               list->destinations[i].name,
               list->destinations[i].latitude,
               list->destinations[i].longitude);
    }
}

int main() {
    DestinationList list = { .count = 0 };
    int choice;

    while (1) {
        printf("\nGPS Navigation Simulation Menu:\n");
        printf("1. Add Destination\n");
        printf("2. Find Closest Destination\n");
        printf("3. Display Destinations\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                double lat, lon;
                printf("Enter destination name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%lf", &lat);
                printf("Enter longitude: ");
                scanf("%lf", &lon);
                addDestination(&list, name, lat, lon);
                break;
            }
            case 2: {
                double userLat, userLon;
                printf("Enter your current latitude: ");
                scanf("%lf", &userLat);
                printf("Enter your current longitude: ");
                scanf("%lf", &userLon);
                findClosestDestination(&list, userLat, userLon);
                break;
            }
            case 3:
                displayDestinations(&list);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}