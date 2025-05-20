//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LOCATIONS 100

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int size;
} LocationList;

// Function prototypes
void addLocation(LocationList *list, const char *name, double lat, double lon);
void displayLocations(const LocationList *list);
double calculateDistance(double lat1, double lon1, double lat2, double lon2);
void navigateTo(LocationList *list, const char *destinationName);

int main() {
    LocationList myLocations = {{0}, 0};
    int choice;
    char name[50];
    double latitude, longitude;

    while (1) {
        printf("\n=== GPS Navigation System ===\n");
        printf("1. Add Location\n");
        printf("2. View Locations\n");
        printf("3. Navigate to Location\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter location name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%lf", &latitude);
                printf("Enter longitude: ");
                scanf("%lf", &longitude);
                addLocation(&myLocations, name, latitude, longitude);
                break;

            case 2:
                displayLocations(&myLocations);
                break;

            case 3:
                printf("Enter destination name: ");
                scanf("%s", name);
                navigateTo(&myLocations, name);
                break;

            case 4:
                printf("Exiting the application. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
}

void addLocation(LocationList *list, const char *name, double lat, double lon) {
    if (list->size < MAX_LOCATIONS) {
        strcpy(list->locations[list->size].name, name);
        list->locations[list->size].latitude = lat;
        list->locations[list->size].longitude = lon;
        list->size++;
        printf("Location '%s' added successfully!\n", name);
    } else {
        printf("Location list is full! Cannot add more locations.\n");
    }
}

void displayLocations(const LocationList *list) {
    if (list->size == 0) {
        printf("No locations available.\n");
        return;
    }
    printf("\nStored Locations:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d. %s (Lat: %.6f, Lon: %.6f)\n", i + 1, list->locations[i].name, list->locations[i].latitude, list->locations[i].longitude);
    }
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double EARTH_RADIUS = 6371.0; // Radius in kilometers
    double dlat = (lat2 - lat1) * M_PI / 180.0;
    double dlon = (lon2 - lon1) * M_PI / 180.0;
    
    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return EARTH_RADIUS * c; // Distance in kilometers
}

void navigateTo(LocationList *list, const char *destinationName) {
    double currentLat, currentLon;
    printf("Enter your current latitude: ");
    scanf("%lf", &currentLat);
    printf("Enter your current longitude: ");
    scanf("%lf", &currentLon);

    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->locations[i].name, destinationName) == 0) {
            double distance = calculateDistance(currentLat, currentLon, list->locations[i].latitude, list->locations[i].longitude);
            printf("Distance to %s: %.2f km\n", list->locations[i].name, distance);
            return;
        }
    }
    printf("Location '%s' not found!\n", destinationName);
}