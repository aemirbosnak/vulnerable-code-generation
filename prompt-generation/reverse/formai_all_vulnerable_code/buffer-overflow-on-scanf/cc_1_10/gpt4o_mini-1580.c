//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_POINTS 10

typedef struct {
    float latitude;
    float longitude;
    char name[50];
} Location;

typedef struct {
    Location points[MAX_POINTS];
    int count;
} Route;

// Function to initialize a route
void initializeRoute(Route *route) {
    route->count = 0;
}

// Function to add a location to the route
void addLocation(Route *route, float latitude, float longitude, const char *name) {
    if (route->count < MAX_POINTS) {
        route->points[route->count].latitude = latitude;
        route->points[route->count].longitude = longitude;
        strcpy(route->points[route->count].name, name);
        route->count++;
        printf("Location '%s' added successfully!\n", name);
    } else {
        printf("Route is full! Can't add more locations.\n");
    }
}

// Function to display the route
void displayRoute(Route *route) {
    printf("\nCurrent Route:\n");
    for (int i = 0; i < route->count; i++) {
        printf("[%d] %s: (%.6f, %.6f)\n", i + 1, route->points[i].name, route->points[i].latitude, route->points[i].longitude);
    }
}

// Function to simulate navigation to each point
void navigate(Route *route) {
    printf("Starting navigation...\n");
    for (int i = 0; i < route->count; i++) {
        printf("Navigating to '%s' at (%.6f, %.6f)...\n", route->points[i].name, route->points[i].latitude, route->points[i].longitude);
        sleep(2);  // Simulating travel time
        printf("Arrived at '%s'!\n", route->points[i].name);
    }
    printf("Navigation completed! Safe travels!\n");
}

int main() {
    Route myRoute;
    initializeRoute(&myRoute);
    
    printf("Welcome to the GPS Navigation Simulation!\n");

    while (1) {
        int choice;
        float lat, lon;
        char name[50];

        printf("\nMenu:\n");
        printf("1. Add Location\n");
        printf("2. View Route\n");
        printf("3. Navigate\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the location: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%f", &lat);
                printf("Enter longitude: ");
                scanf("%f", &lon);
                addLocation(&myRoute, lat, lon, name);
                break;
            case 2:
                displayRoute(&myRoute);
                break;
            case 3:
                navigate(&myRoute);
                break;
            case 4:
                printf("Thank you for using the GPS Navigation Simulation! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }

    return 0;
}