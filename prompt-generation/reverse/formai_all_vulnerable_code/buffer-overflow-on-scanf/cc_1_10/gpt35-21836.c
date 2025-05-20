//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define DEFAULT_LATITUDE 37.7749
#define DEFAULT_LONGITUDE -122.4194
#define MAX_WAYPOINTS 10

// Structs
typedef struct {
    double latitude;
    double longitude;
} Coordinate;

typedef struct {
    Coordinate coordinates[MAX_WAYPOINTS];
    int numWaypoints;
} Route;

// Function Prototypes
void displayMainMenu();
void displayRouteMenu(Route *route);
void addWaypoint(Route *route);
void removeWaypoint(Route *route);
void generateRandomRoute(Route *route);
void simulateNavigation(Route *route);

int main() {
    srand(time(NULL));  // Seed random number generator with current time

    // Initialize route with default starting location
    Route route = {{DEFAULT_LATITUDE, DEFAULT_LONGITUDE}, 1};

    int choice;
    do {
        displayMainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWaypoint(&route);
                break;
            case 2:
                removeWaypoint(&route);
                break;
            case 3:
                generateRandomRoute(&route);
                break;
            case 4:
                simulateNavigation(&route);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

/**
 * Displays the main menu options to the user.
 */
void displayMainMenu() {
    printf("Main Menu\n");
    printf("1. Add waypoint\n");
    printf("2. Remove waypoint\n");
    printf("3. Generate random route\n");
    printf("4. Simulate navigation\n");
    printf("5. Quit\n");
}

/**
 * Displays the route menu options to the user.
 * @param route The route object containing the waypoints.
 */
void displayRouteMenu(Route *route) {
    printf("Route Menu\n");
    for (int i = 0; i < route->numWaypoints; i++) {
        printf("%d. (%f, %f)\n", i + 1, route->coordinates[i].latitude, route->coordinates[i].longitude);
    }
    printf("0. return to Main Menu\n");
}

/**
 * Adds a new waypoint to the route.
 * @param route The route object to add the waypoint to.
 */
void addWaypoint(Route *route) {
    if (route->numWaypoints == MAX_WAYPOINTS) {
        printf("Maximum number of waypoints reached.\n");
        return;
    }

    double lat, lon;
    printf("Enter latitude: ");
    scanf("%lf", &lat);
    printf("Enter longitude: ");
    scanf("%lf", &lon);

    route->coordinates[route->numWaypoints].latitude = lat;
    route->coordinates[route->numWaypoints].longitude = lon;
    route->numWaypoints++;

    printf("Waypoint added successfully.\n");
}

/**
 * Removes a waypoint from the route.
 * @param route The route object to remove the waypoint from.
 */
void removeWaypoint(Route *route) {
    displayRouteMenu(route);

    int choice;
    printf("Enter the number of the waypoint to remove: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > route->numWaypoints) {
        printf("Invalid choice, please try again.\n");
        return;
    }

    for (int i = choice - 1; i < route->numWaypoints - 1; i++) {
        route->coordinates[i] = route->coordinates[i + 1];
    }
    route->numWaypoints--;

    printf("Waypoint removed successfully.\n");
}

/**
 * Generates a random route with up to 10 waypoints.
 * @param route The route object to populate with waypoints.
 */
void generateRandomRoute(Route *route) {
    int numWaypoints = rand() % MAX_WAYPOINTS + 1;  // Random number from 1 to MAX_WAYPOINTS
    double lat, lon;
    for (int i = 0; i < numWaypoints; i++) {
        lat = (double)(rand() % 180 - 90) + (double)(rand() % 10000) / 10000;  // Random latitude within valid range
        lon = (double)(rand() % 360 - 180) + (double)(rand() % 10000) / 10000;  // Random longitude within valid range
        route->coordinates[i].latitude = lat;
        route->coordinates[i].longitude = lon;
    }
    route->numWaypoints = numWaypoints;

    printf("Random route generated with %d waypoints.\n", numWaypoints);
}

/**
 * Simulates the navigation process by displaying each waypoint in the route one at a time.
 * @param route The route object to navigate.
 */
void simulateNavigation(Route *route) {
    if (route->numWaypoints == 1) {
        printf("No waypoints in route, cannot navigate.\n");
        return;
    }

    Coordinate currentLocation = {DEFAULT_LATITUDE, DEFAULT_LONGITUDE};
    printf("Starting navigation from (%f, %f).\n", currentLocation.latitude, currentLocation.longitude);

    displayRouteMenu(route);

    int choice;
    printf("Enter the number of the waypoint to navigate to: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > route->numWaypoints) {
        printf("Invalid choice, navigation cancelled.\n");
        return;
    }

    for (int i = choice - 1; i < route->numWaypoints; i++) {
        Coordinate nextWaypoint = route->coordinates[i];

        printf("Next waypoint: (%f, %f)\n", nextWaypoint.latitude, nextWaypoint.longitude);

        // Calculate distance between current location and next waypoint in km
        double distance = acos(sin(currentLocation.latitude * 3.14159265 / 180) * sin(nextWaypoint.latitude * 3.14159265 / 180) + cos(currentLocation.latitude * 3.14159265 / 180) * cos(nextWaypoint.latitude * 3.14159265 / 180) * cos((nextWaypoint.longitude - currentLocation.longitude) * 3.14159265 / 180)) * 6371;

        printf("Distance to next waypoint: %.2f km\n", distance);

        // Update current location to next waypoint
        currentLocation = nextWaypoint;
    }

    printf("Navigation completed.\n");
}