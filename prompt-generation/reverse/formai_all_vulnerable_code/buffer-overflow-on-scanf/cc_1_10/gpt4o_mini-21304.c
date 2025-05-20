//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 10
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int count;
} Route;

void addLocation(Route *route, const char *name, double latitude, double longitude) {
    if (route->count < MAX_LOCATIONS) {
        strncpy(route->locations[route->count].name, name, MAX_NAME_LENGTH);
        route->locations[route->count].latitude = latitude;
        route->locations[route->count].longitude = longitude;
        route->count++;
    } else {
        printf("Maximum number of locations reached!\n");
    }
}

void displayRoute(const Route *route) {
    printf("Current Route:\n");
    for (int i = 0; i < route->count; i++) {
        printf("%d: %s (Lat: %.6f, Lon: %.6f)\n", 
                i + 1, route->locations[i].name, 
                route->locations[i].latitude, 
                route->locations[i].longitude);
    }
}

void simulateNavigation(const Route *route) {
    for (int i = 0; i < route->count; i++) {
        printf("Navigating to %s...\n", route->locations[i].name);
        // Simulate some time delay for navigation
        usleep(1000000);
        printf("You have arrived at %s!\n", route->locations[i].name);
    }
}

void clearRoute(Route *route) {
    route->count = 0;
}

int main() {
    Route myRoute;
    myRoute.count = 0;
    
    int choice;
    char name[MAX_NAME_LENGTH];
    double latitude, longitude;

    do {
        printf("\nGPS Navigation Simulation\n");
        printf("1. Add Location\n");
        printf("2. Display Route\n");
        printf("3. Start Navigation\n");
        printf("4. Clear Route\n");
        printf("5. Exit\n");
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
                addLocation(&myRoute, name, latitude, longitude);
                break;
            case 2:
                displayRoute(&myRoute);
                break;
            case 3:
                if (myRoute.count == 0) {
                    printf("No locations in the route. Please add locations first.\n");
                } else {
                    simulateNavigation(&myRoute);
                }
                break;
            case 4:
                clearRoute(&myRoute);
                printf("Route cleared!\n");
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}