//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WAYPOINTS 10
#define EARTH_RADIUS 6371.0 // Earth radius in kilometers

typedef struct {
    char name[50];
    double latitude; // in decimal degrees
    double longitude; // in decimal degrees
} Waypoint;

double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

double haversineDistance(Waypoint w1, Waypoint w2) {
    double lat1 = toRadians(w1.latitude);
    double lat2 = toRadians(w2.latitude);
    double dlat = toRadians(w2.latitude - w1.latitude);
    double dlon = toRadians(w2.longitude - w1.longitude);
    
    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return EARTH_RADIUS * c; // Distance in kilometers
}

void printDirections(Waypoint from, Waypoint to) {
    printf("From %s to %s: ", from.name, to.name);
    double distance = haversineDistance(from, to);
    printf("Distance: %.2f km\n", distance);
}

int main() {
    Waypoint waypoints[MAX_WAYPOINTS];
    int waypointCount = 0;
    char command[50];

    printf("Simple GPS Navigation Simulation\n");
    printf("Enter waypoints in the format: 'name latitude longitude'\n");
    printf("Type 'done' to finish entering waypoints.\n");

    while (waypointCount < MAX_WAYPOINTS) {
        printf("Enter waypoint: ");
        fgets(command, sizeof(command), stdin);
        
        if (strcmp(command, "done\n") == 0) {
            break;
        }

        sscanf(command, "%49s %lf %lf", waypoints[waypointCount].name, 
               &waypoints[waypointCount].latitude, 
               &waypoints[waypointCount].longitude);
        waypointCount++;
    }

    printf("\nNavigating between waypoints:\n");
    for (int i = 0; i < waypointCount - 1; i++) {
        printDirections(waypoints[i], waypoints[i + 1]);
    }

    printf("All waypoints entered successfully!\n");
    return 0;
}