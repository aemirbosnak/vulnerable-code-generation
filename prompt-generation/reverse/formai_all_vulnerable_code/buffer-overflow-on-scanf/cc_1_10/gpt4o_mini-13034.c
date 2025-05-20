//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: ephemeral
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAYPOINTS 10

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Waypoint;

void displayWaypoints(Waypoint waypoints[], int count) {
    printf("Waypoints:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s (Lat: %.6f, Lon: %.6f)\n", i + 1, waypoints[i].name, waypoints[i].latitude, waypoints[i].longitude);
    }
}

double toRadians(double degree) {
    return degree * (M_PI / 180);
}

double calculateDistance(Waypoint a, Waypoint b) {
    const double EARTH_RADIUS = 6371.0; // km
    double latDiff = toRadians(b.latitude - a.latitude);
    double lonDiff = toRadians(b.longitude - a.longitude);

    double a_hav = sin(latDiff / 2) * sin(latDiff / 2) +
                   cos(toRadians(a.latitude)) * cos(toRadians(b.latitude)) *
                   sin(lonDiff / 2) * sin(lonDiff / 2);
    double c = 2 * atan2(sqrt(a_hav), sqrt(1 - a_hav));

    return EARTH_RADIUS * c;
}

int main() {
    Waypoint waypoints[MAX_WAYPOINTS];
    int count = 0;
    char continueInput;

    printf("Welcome to the GPS Navigation Simulation!\n");

    do {
        if (count >= MAX_WAYPOINTS) {
            printf("Maximum waypoints reached. Cannot add more.\n");
            break;
        }

        printf("Enter waypoint name: ");
        scanf("%s", waypoints[count].name);
        printf("Enter latitude: ");
        scanf("%lf", &waypoints[count].latitude);
        printf("Enter longitude: ");
        scanf("%lf", &waypoints[count].longitude);
        count++;

        printf("Do you want to add another waypoint? (y/n): ");
        scanf(" %c", &continueInput);
    } while (continueInput == 'y' || continueInput == 'Y');

    displayWaypoints(waypoints, count);

    int startIndex, endIndex;
    printf("Select start waypoint index (1-%d): ", count);
    scanf("%d", &startIndex);
    printf("Select end waypoint index (1-%d): ", count);
    scanf("%d", &endIndex);

    if (startIndex < 1 || startIndex > count || endIndex < 1 || endIndex > count) {
        printf("Invalid indices selected.\n");
        return 1;
    }

    double distance = calculateDistance(waypoints[startIndex - 1], waypoints[endIndex - 1]);
    printf("Distance from '%s' to '%s': %.2f km\n", waypoints[startIndex - 1].name, waypoints[endIndex - 1].name, distance);

    return 0;
}