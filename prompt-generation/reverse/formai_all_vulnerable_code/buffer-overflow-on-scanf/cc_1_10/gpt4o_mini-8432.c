//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LOCATIONS 100

typedef struct {
    double latitude;
    double longitude;
    char name[50];
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int count;
} GPSNavigationSystem;

void initializeGPS(GPSNavigationSystem *gps) {
    gps->count = 0;
}

void addLocation(GPSNavigationSystem *gps, double latitude, double longitude, const char *name) {
    if (gps->count < MAX_LOCATIONS) {
        gps->locations[gps->count].latitude = latitude;
        gps->locations[gps->count].longitude = longitude;
        strncpy(gps->locations[gps->count].name, name, sizeof(gps->locations[gps->count].name) - 1);
        gps->locations[gps->count].name[sizeof(gps->locations[gps->count].name) - 1] = '\0'; // Null-terminate
        gps->count++;
    } else {
        printf("Cannot add more locations. Maximum limit reached!\n");
    }
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double R = 6371.0; // Earth radius in kilometers
    double dLat = (lat2 - lat1) * M_PI / 180.0; 
    double dLon = (lon2 - lon1) * M_PI / 180.0; 
    lat1 = lat1 * M_PI / 180.0; 
    lat2 = lat2 * M_PI / 180.0; 

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) * 
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a)); 
    return R * c; // Distance in kilometers
}

void showDirections(GPSNavigationSystem *gps, int start, int end) {
    if (start < 0 || end < 0 || start >= gps->count || end >= gps->count) {
        printf("Invalid location indexes!\n");
        return;
    }
    Location startLoc = gps->locations[start];
    Location endLoc = gps->locations[end];
    double distance = calculateDistance(startLoc.latitude, startLoc.longitude,
                                        endLoc.latitude, endLoc.longitude);
    
    printf("From %s to %s:\n", startLoc.name, endLoc.name);
    printf("Distance: %.2f km\n", distance);
    
    // Simple directional output (mockup)
    printf("To reach %s from %s, follow these instructions:\n", endLoc.name, startLoc.name);
    printf("1. Head North towards %.5f latitude.\n", endLoc.latitude);
    printf("2. Turn East towards %.5f longitude.\n", endLoc.longitude);
    printf("3. Keep going straight.\n");
    printf("4. You have arrived at %s.\n", endLoc.name);
}

void printMenu() {
    printf("\n=== GPS Navigation System ===\n");
    printf("1. Add Location\n");
    printf("2. Show Directions\n");
    printf("3. Exit\n");
}

int main() {
    GPSNavigationSystem gps;
    initializeGPS(&gps);
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                double lat, lon;
                char name[50];
                printf("Enter Latitude: ");
                scanf("%lf", &lat);
                printf("Enter Longitude: ");
                scanf("%lf", &lon);
                printf("Enter Location Name: ");
                scanf("%s", name);
                addLocation(&gps, lat, lon, name);
                break;
            }
            case 2: {
                int start, end;
                printf("Enter start location index (0 to %d): ", gps.count - 1);
                scanf("%d", &start);
                printf("Enter destination location index (0 to %d): ", gps.count - 1);
                scanf("%d", &end);
                showDirections(&gps, start, end);
                break;
            }
            case 3:
                printf("Exiting the GPS Navigation System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}