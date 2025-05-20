//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
#include <stdio.h>
#include <math.h>

#define MAX_WAYPOINTS 10
#define EARTH_RADIUS 6371.0 // Earth's radius in kilometers

typedef struct {
    char name[50];
    double latitude;  // Latitude in degrees
    double longitude; // Longitude in degrees
} Waypoint;

double toRadians(double degree) {
    return degree * (M_PI / 180.0);
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
    return EARTH_RADIUS * c; // Distance in km
}

void printMenu() {
    printf("\nGPS Navigation Simulation\n");
    printf("1. Add Waypoint\n");
    printf("2. Calculate Distance\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void addWaypoint(Waypoint waypoints[], int *count) {
    if (*count >= MAX_WAYPOINTS) {
        printf("Error: Maximum number of waypoints reached.\n");
        return;
    }
    
    Waypoint wp;
    printf("Enter waypoint name: ");
    scanf("%s", wp.name);
    printf("Enter latitude: ");
    scanf("%lf", &wp.latitude);
    printf("Enter longitude: ");
    scanf("%lf", &wp.longitude);

    waypoints[*count] = wp;
    (*count)++;
    printf("Waypoint added: %s (%lf, %lf)\n", wp.name, wp.latitude, wp.longitude);
}

void calculateDistance(Waypoint waypoints[], int count) {
    if (count < 2) {
        printf("Error: At least two waypoints are needed to calculate distance.\n");
        return;
    }
    
    char name1[50], name2[50];
    printf("Enter first waypoint name: ");
    scanf("%s", name1);
    printf("Enter second waypoint name: ");
    scanf("%s", name2);

    Waypoint *wp1 = NULL;
    Waypoint *wp2 = NULL;

    for (int i = 0; i < count; i++) {
        if (strcmp(waypoints[i].name, name1) == 0) {
            wp1 = &waypoints[i];
        }
        if (strcmp(waypoints[i].name, name2) == 0) {
            wp2 = &waypoints[i];
        }
    }

    if (wp1 == NULL || wp2 == NULL) {
        printf("Error: One or both waypoints not found.\n");
        return;
    }

    double distance = haversine(wp1->latitude, wp1->longitude, wp2->latitude, wp2->longitude);
    printf("Distance between %s and %s is: %.2f km\n", wp1->name, wp2->name, distance);
}

int main() {
    Waypoint waypoints[MAX_WAYPOINTS];
    int count = 0;
    int option;

    while (1) {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addWaypoint(waypoints, &count);
                break;
            case 2:
                calculateDistance(waypoints, count);
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}