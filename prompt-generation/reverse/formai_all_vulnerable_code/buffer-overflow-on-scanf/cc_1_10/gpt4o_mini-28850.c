//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOCATIONS 100
#define MAX_NAME_LENGTH 50
#define PI 3.14159265358979323846

typedef struct {
    char name[MAX_NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int count;
} LocationList;

void addLocation(LocationList *list, const char *name, double latitude, double longitude) {
    if (list->count < MAX_LOCATIONS) {
        strcpy(list->locations[list->count].name, name);
        list->locations[list->count].latitude = latitude;
        list->locations[list->count].longitude = longitude;
        list->count++;
    } else {
        printf("Location list is full!\n");
    }
}

double toRadians(double degrees) {
    return degrees * (PI / 180.0);
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);
    lat1 = toRadians(lat1);
    lat2 = toRadians(lat2);

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double radius = 6371.0; // Earth's radius in kilometers
    return radius * c; // returns the distance in kilometers
}

void findNearestLocation(LocationList *list, double latitude, double longitude) {
    if (list->count == 0) {
        printf("No locations available.\n");
        return;
    }

    double minDistance = haversine(latitude, longitude, list->locations[0].latitude, list->locations[0].longitude);
    Location nearestLocation = list->locations[0];

    for (int i = 1; i < list->count; i++) {
        double distance = haversine(latitude, longitude, list->locations[i].latitude, list->locations[i].longitude);
        if (distance < minDistance) {
            minDistance = distance;
            nearestLocation = list->locations[i];
        }
    }

    printf("Nearest location: %s at %.2f km\n", nearestLocation.name, minDistance);
}

void printLocationList(const LocationList *list) {
    if (list->count == 0) {
        printf("No locations in the list.\n");
        return;
    }

    for (int i = 0; i < list->count; i++) {
        printf("%d: %s (Latitude: %.6f, Longitude: %.6f)\n", 
                i + 1, 
                list->locations[i].name, 
                list->locations[i].latitude, 
                list->locations[i].longitude);
    }
}

int main() {
    LocationList locationList = {{0}, 0};
    char command[20];
    char name[MAX_NAME_LENGTH];
    double latitude, longitude;

    while (1) {
        printf("\nGPS Navigation Simulation Menu:\n");
        printf("1. Add Location\n");
        printf("2. Find Nearest Location\n");
        printf("3. Print All Locations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", command);

        if (strcmp(command, "1") == 0) {
            printf("Enter location name: ");
            scanf("%s", name);
            printf("Enter latitude: ");
            scanf("%lf", &latitude);
            printf("Enter longitude: ");
            scanf("%lf", &longitude);
            addLocation(&locationList, name, latitude, longitude);
        } else if (strcmp(command, "2") == 0) {
            printf("Enter your current latitude: ");
            scanf("%lf", &latitude);
            printf("Enter your current longitude: ");
            scanf("%lf", &longitude);
            findNearestLocation(&locationList, latitude, longitude);
        } else if (strcmp(command, "3") == 0) {
            printLocationList(&locationList);
        } else if (strcmp(command, "4") == 0) {
            printf("Exiting the GPS Navigation Simulation.\n");
            break;
        } else {
            printf("Invalid command! Please enter a valid option.\n");
        }
    }

    return 0;
}