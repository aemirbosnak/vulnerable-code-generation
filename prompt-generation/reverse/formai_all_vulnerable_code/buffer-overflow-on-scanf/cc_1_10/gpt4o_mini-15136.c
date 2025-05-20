//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAYPOINTS 10

typedef struct {
    char name[50];
    float latitude;
    float longitude;
} Waypoint;

typedef struct {
    Waypoint waypoints[MAX_WAYPOINTS];
    int count;
} Route;

void addWaypoint(Route *route) {
    if (route->count >= MAX_WAYPOINTS) {
        printf("Oops! Maximum waypoints reached.\n");
        return;
    }
    
    Waypoint wp;
    printf("Enter name of waypoint: ");
    scanf("%s", wp.name);
    printf("Enter latitude of %s: ", wp.name);
    scanf("%f", &wp.latitude);
    printf("Enter longitude of %s: ", wp.name);
    scanf("%f", &wp.longitude);

    route->waypoints[route->count] = wp;
    route->count++;
    printf("Waypoint %s added! Total waypoints: %d\n", wp.name, route->count);
}

void displayRoute(const Route *route) {
    printf("\nYour Navigation Route:\n");
    if (route->count == 0) {
        printf("No waypoints to display!\n");
        return;
    }

    for (int i = 0; i < route->count; i++) {
        printf("Waypoint %d: Name: %s, Latitude: %.6f, Longitude: %.6f\n", 
                i + 1, route->waypoints[i].name, route->waypoints[i].latitude, route->waypoints[i].longitude);
    }
}

void navigate(Route *route) {
    if (route->count == 0) {
        printf("Navigate? But there are no waypoints added!\n");
        return;
    }

    printf("Starting navigation...\n");
    for (int i = 0; i < route->count; i++) {
        printf("Now approaching: %s (Lat: %.6f, Lon: %.6f)\n", 
                route->waypoints[i].name, route->waypoints[i].latitude, route->waypoints[i].longitude);
        
        // Simulating travel time with a surprise
        printf("Traveling to %s...\n", route->waypoints[i].name);
        for (int j = 0; j < 3; j++) {
            printf("...still going...\n");
            sleep(1);
        }
    }
    printf("You've arrived at your final destination! What a journey!\n");
}

int main() {
    Route route;
    route.count = 0;
    
    int choice;
    do {
        printf("\nGPS Navigation System\n");
        printf("1. Add Waypoint\n");
        printf("2. Display Route\n");
        printf("3. Start Navigation\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addWaypoint(&route);
                break;
            case 2:
                displayRoute(&route);
                break;
            case 3:
                navigate(&route);
                break;
            case 4:
                printf("Exiting the GPS Navigation System. Safe travels!\n");
                break;
            default:
                printf("Hmm, that option is not valid. Try again!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}