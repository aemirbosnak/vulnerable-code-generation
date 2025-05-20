//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define EARTH_RADIUS 6371e3 // Radius of Earth in meters
#define MAX_LOCATIONS 100

typedef struct {
    char name[50];
    double latitude;  // in degrees
    double longitude; // in degrees
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int count;
} NavigationSystem;

// Function prototypes
void addLocation(NavigationSystem *system, const char *name, double latitude, double longitude);
void displayLocations(NavigationSystem *system);
double toRadians(double degree);
double calculateDistance(double lat1, double lon1, double lat2, double lon2);
void findNearestLocation(NavigationSystem *system, double userLat, double userLon);
void clearInputBuffer();

int main() {
    NavigationSystem navSystem = { .count = 0 };
    int choice;
    char name[50];
    double latitude, longitude;

    while (1) {
        printf("=== GPS Navigation System ===\n");
        printf("1. Add Location\n");
        printf("2. Display Locations\n");
        printf("3. Find Nearest Location\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        while (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please choose again: ");
        }

        switch (choice) {
            case 1:
                if (navSystem.count >= MAX_LOCATIONS) {
                    printf("Error: Maximum number of locations reached.\n");
                    break;
                }
                printf("Enter location name: ");
                scanf("%s", name);
                printf("Enter latitude (degrees): ");
                scanf("%lf", &latitude);
                printf("Enter longitude (degrees): ");
                scanf("%lf", &longitude);
                addLocation(&navSystem, name, latitude, longitude);
                printf("Location added successfully!\n");
                break;
            case 2:
                displayLocations(&navSystem);
                break;
            case 3:
                printf("Enter your current latitude: ");
                scanf("%lf", &latitude);
                printf("Enter your current longitude: ");
                scanf("%lf", &longitude);
                findNearestLocation(&navSystem, latitude, longitude);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}

void addLocation(NavigationSystem *system, const char *name, double latitude, double longitude) {
    strncpy(system->locations[system->count].name, name, sizeof(system->locations[system->count].name));
    system->locations[system->count].latitude = latitude;
    system->locations[system->count].longitude = longitude;
    system->count++;
}

void displayLocations(NavigationSystem *system) {
    if (system->count == 0) {
        printf("No locations added.\n");
        return;
    }
    printf("Locations:\n");
    for (int i = 0; i < system->count; i++) {
        printf("%d: %s (%.6f, %.6f)\n", i + 1, system->locations[i].name,
               system->locations[i].latitude, system->locations[i].longitude);
    }
}

double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(toRadians(lat1)) * cos(toRadians(lat2)) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return EARTH_RADIUS * c; // distance in meters
}

void findNearestLocation(NavigationSystem *system, double userLat, double userLon) {
    if (system->count == 0) {
        printf("No locations available to find the nearest one.\n");
        return;
    }

    double minDistance = -1;
    int nearestIndex = -1;

    for (int i = 0; i < system->count; i++) {
        double distance = calculateDistance(userLat, userLon, system->locations[i].latitude, system->locations[i].longitude);
        if (minDistance < 0 || distance < minDistance) {
            minDistance = distance;
            nearestIndex = i;
        }
    }

    printf("The nearest location is: %s, which is %.2f meters away.\n",
           system->locations[nearestIndex].name, minDistance);
}

void clearInputBuffer() {
    while (getchar() != '\n');
}