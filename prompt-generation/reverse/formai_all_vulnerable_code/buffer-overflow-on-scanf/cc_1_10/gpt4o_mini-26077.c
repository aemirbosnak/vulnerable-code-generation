//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WAYPOINTS 10
#define EARTH_RADIUS 6371.0 // Earth radius in kilometers

typedef struct {
    char name[50];
    double latitude; // In degrees
    double longitude; // In degrees
} Waypoint;

Waypoint waypoints[MAX_WAYPOINTS];
int waypoint_count = 0;

double deg_to_rad(double degree) {
    return degree * (M_PI / 180);
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    // Convert from degrees to radians
    lat1 = deg_to_rad(lat1);
    lon1 = deg_to_rad(lon1);
    lat2 = deg_to_rad(lat2);
    lon2 = deg_to_rad(lon2);

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c; // Distance in kilometers
}

void add_waypoint() {
    if (waypoint_count >= MAX_WAYPOINTS) {
        printf("Max waypoint limit reached.\n");
        return;
    }
    printf("Enter waypoint name: ");
    scanf("%s", waypoints[waypoint_count].name);
    printf("Enter latitude of %s: ", waypoints[waypoint_count].name);
    scanf("%lf", &waypoints[waypoint_count].latitude);
    printf("Enter longitude of %s: ", waypoints[waypoint_count].name);
    scanf("%lf", &waypoints[waypoint_count].longitude);
    waypoint_count++;
    printf("Waypoint added!\n");
}

void calculate_distances() {
    if (waypoint_count < 2) {
        printf("Not enough waypoints to calculate distance.\n");
        return;
    }

    for (int i = 0; i < waypoint_count - 1; i++) {
        for (int j = i + 1; j < waypoint_count; j++) {
            double distance = haversine(waypoints[i].latitude, waypoints[i].longitude,
                                         waypoints[j].latitude, waypoints[j].longitude);
            printf("Distance from %s to %s: %.2f km\n", waypoints[i].name, waypoints[j].name, distance);
        }
    }
}

void display_waypoints() {
    printf("Waypoints:\n");
    for (int i = 0; i < waypoint_count; i++) {
        printf("%d: %s (%lf, %lf)\n", i + 1, waypoints[i].name, waypoints[i].latitude, waypoints[i].longitude);
    }
}

int main() {
    int choice;
    do {
        printf("\nGPS Navigation Simulation\n");
        printf("1. Add Waypoint\n");
        printf("2. Calculate Distances\n");
        printf("3. Display Waypoints\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_waypoint();
                break;
            case 2:
                calculate_distances();
                break;
            case 3:
                display_waypoints();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}