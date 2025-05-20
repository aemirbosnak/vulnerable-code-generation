//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAYPOINTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float latitude;
    float longitude;
} Waypoint;

typedef struct {
    Waypoint waypoints[MAX_WAYPOINTS];
    int count;
} WaypointList;

// Function prototypes
void addWaypoint(WaypointList* list);
void displayWaypoints(const WaypointList* list);
void navigateToWaypoint(const WaypointList* list);
float calculateDistance(float lat1, float lon1, float lat2, float lon2);

int main() {
    WaypointList waypointList = { .count = 0 };
    int choice;

    do {
        printf("\n==== GPS Navigation Menu ====\n");
        printf("1. Add Waypoint\n");
        printf("2. Display Waypoints\n");
        printf("3. Navigate to Waypoint\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWaypoint(&waypointList);
                break;
            case 2:
                displayWaypoints(&waypointList);
                break;
            case 3:
                navigateToWaypoint(&waypointList);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addWaypoint(WaypointList* list) {
    if (list->count >= MAX_WAYPOINTS) {
        printf("Waypoint list is full.\n");
        return;
    }

    Waypoint newWaypoint;

    printf("Enter waypoint name: ");
    scanf("%s", newWaypoint.name);
    printf("Enter latitude: ");
    scanf("%f", &newWaypoint.latitude);
    printf("Enter longitude: ");
    scanf("%f", &newWaypoint.longitude);

    list->waypoints[list->count++] = newWaypoint;
    printf("Waypoint added successfully.\n");
}

void displayWaypoints(const WaypointList* list) {
    if (list->count == 0) {
        printf("No waypoints to display.\n");
        return;
    }

    printf("\n=== Waypoints ===\n");
    for (int i = 0; i < list->count; ++i) {
        printf("Waypoint %d: %s (Lat: %.6f, Lon: %.6f)\n", 
               i + 1, list->waypoints[i].name, 
               list->waypoints[i].latitude, 
               list->waypoints[i].longitude);
    }
}

void navigateToWaypoint(const WaypointList* list) {
    if (list->count == 0) {
        printf("No waypoints available for navigation.\n");
        return;
    }

    int index;
    printf("Select the waypoint number to navigate to (1 - %d): ", list->count);
    scanf("%d", &index);

    if (index < 1 || index > list->count) {
        printf("Invalid waypoint number.\n");
        return;
    }

    Waypoint destination = list->waypoints[index - 1];
    float currentLat, currentLon;

    printf("Enter current location (Latitude and Longitude): ");
    scanf("%f %f", &currentLat, &currentLon);

    float distance = calculateDistance(currentLat, currentLon, destination.latitude, destination.longitude);
    
    printf("Navigating to %s...\n", destination.name);
    printf("Distance to %s: %.2f km\n", destination.name, distance);
}

float calculateDistance(float lat1, float lon1, float lat2, float lon2) {
    // Using Haversine formula could be an improvement for actual GPS systems.
    const float R = 6371.0; // Radius of Earth in kilometers
    float dLat = (lat2 - lat1) * (3.141592653589793 / 180);
    float dLon = (lon2 - lon1) * (3.141592653589793 / 180);
    
    lat1 = lat1 * (3.141592653589793 / 180);
    lat2 = lat2 * (3.141592653589793 / 180);

    float a = sin(dLat / 2) * sin(dLat / 2) +
              cos(lat1) * cos(lat2) *
              sin(dLon / 2) * sin(dLon / 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c; // Distance in kilometers
}