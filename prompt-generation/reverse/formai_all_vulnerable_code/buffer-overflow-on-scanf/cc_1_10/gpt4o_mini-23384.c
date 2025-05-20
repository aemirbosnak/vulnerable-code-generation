//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WAYPOINTS 10

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Waypoint;

void displayWaypoints(Waypoint waypoints[], int count) {
    printf("\nYour Waypoints:\n");
    for (int i = 0; i < count; i++) {
        printf("Waypoint %d: %s (Lat: %.6f, Long: %.6f)\n", i + 1, waypoints[i].name, waypoints[i].latitude, waypoints[i].longitude);
    }
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    // Haversine formula to calculate the distance
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double r = 6371.0; // Radius of Earth in kilometers
    return r * c; // Distance in kilometers
}

void inputWaypoint(Waypoint *waypoint) {
    printf("Enter the name of the waypoint: ");
    scanf("%s", waypoint->name);
    printf("Enter latitude (in decimal degrees): ");
    scanf("%lf", &waypoint->latitude);
    printf("Enter longitude (in decimal degrees): ");
    scanf("%lf", &waypoint->longitude);
}

int main() {
    Waypoint waypoints[MAX_WAYPOINTS];
    int count = 0;

    printf("Welcome to the GPS Navigation Simulation!\n");
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Waypoint\n");
        printf("2. View Waypoints\n");
        printf("3. Calculate Distance Between Waypoints\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < MAX_WAYPOINTS) {
                    inputWaypoint(&waypoints[count]);
                    count++;
                    printf("Waypoint added successfully!\n");
                } else {
                    printf("Maximum number of waypoints reached!\n");
                }
                break;
            case 2:
                displayWaypoints(waypoints, count);
                break;
            case 3:
                if (count < 2) {
                    printf("You need at least 2 waypoints to calculate distance!\n");
                } else {
                    int wp1, wp2;
                    printf("Enter the first waypoint number (1-%d): ", count);
                    scanf("%d", &wp1);
                    printf("Enter the second waypoint number (1-%d): ", count);
                    scanf("%d", &wp2);
                    
                    if (wp1 < 1 || wp1 > count || wp2 < 1 || wp2 > count) {
                        printf("Invalid waypoint numbers!\n");
                    } else {
                        double distance = calculateDistance(
                            waypoints[wp1 - 1].latitude,
                            waypoints[wp1 - 1].longitude,
                            waypoints[wp2 - 1].latitude,
                            waypoints[wp2 - 1].longitude
                        );
                        printf("Distance between %s and %s: %.2f km\n",
                               waypoints[wp1 - 1].name, waypoints[wp2 - 1].name, distance);
                    }
                }
                break;
            case 4:
                printf("Exiting the simulation! Safe travels!\n");
                return 0;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }

    return 0;
}