//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define constants
#define MAX_WAYPOINTS 100
#define PI 3.14159265358979323846

// Structure for a waypoint
typedef struct {
    char name[30];
    double latitude;
    double longitude;
} Waypoint;

// Function prototypes
void addWaypoint(Waypoint waypoints[], int *count);
void listWaypoints(Waypoint waypoints[], int count);
void calculateDistance(double lat1, double lon1, double lat2, double lon2);
double toRadians(double degree);
void navigate(Waypoint waypoints[], int count);

int main() {
    Waypoint waypoints[MAX_WAYPOINTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nGPS Navigation Simulation\n");
        printf("1. Add Waypoint\n");
        printf("2. List Waypoints\n");
        printf("3. Calculate Distance\n");
        printf("4. Navigate to Waypoint\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWaypoint(waypoints, &count);
                break;
            case 2:
                listWaypoints(waypoints, count);
                break;
            case 3:
                if (count >= 2) {
                    double lat1, lon1, lat2, lon2;
                    printf("Enter latitude and longitude for first point (lat lon): ");
                    scanf("%lf %lf", &lat1, &lon1);
                    printf("Enter latitude and longitude for second point (lat lon): ");
                    scanf("%lf %lf", &lat2, &lon2);
                    calculateDistance(lat1, lon1, lat2, lon2);
                } else {
                    printf("Need at least two points for distance calculation.\n");
                }
                break;
            case 4:
                if (count > 0) {
                    navigate(waypoints, count);
                } else {
                    printf("No waypoints available to navigate.\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void addWaypoint(Waypoint waypoints[], int *count) {
    if (*count >= MAX_WAYPOINTS) {
        printf("Maximum number of waypoints reached.\n");
        return;
    }
    Waypoint w;
    printf("Enter waypoint name: ");
    scanf("%s", w.name);
    printf("Enter latitude: ");
    scanf("%lf", &w.latitude);
    printf("Enter longitude: ");
    scanf("%lf", &w.longitude);
    waypoints[*count] = w;
    (*count)++;
    printf("Waypoint %s added successfully.\n", w.name);
}

void listWaypoints(Waypoint waypoints[], int count) {
    printf("\nList of Waypoints:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Lat: %.6f, Lon: %.6f)\n", i + 1, waypoints[i].name, waypoints[i].latitude, waypoints[i].longitude);
    }
}

void calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double d_lat = toRadians(lat2 - lat1);
    double d_lon = toRadians(lon2 - lon1);
    lat1 = toRadians(lat1);
    lat2 = toRadians(lat2);

    // Haversine formula
    double a = sin(d_lat / 2) * sin(d_lat / 2) +
               cos(lat1) * cos(lat2) *
               sin(d_lon / 2) * sin(d_lon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double radius = 6371.0; // Radius of Earth in kilometers
    double distance = radius * c;

    printf("Distance: %.2f km\n", distance);
}

double toRadians(double degree) {
    return degree * (PI / 180.0);
}

void navigate(Waypoint waypoints[], int count) {
    int index;
    printf("Choose a waypoint to navigate to (1-%d): ", count);
    scanf("%d", &index);
    if (index < 1 || index > count) {
        printf("Invalid waypoint number.\n");
        return;
    }

    Waypoint w = waypoints[index - 1];
    printf("Navigating to %s...\n", w.name);
    printf("Current coordinates: (Lat: %.6f, Lon: %.6f)\n", w.latitude, w.longitude);
    printf("Destination: %s (Lat: %.6f, Lon: %.6f)\n", w.name, w.latitude, w.longitude);
    printf("Routing...\n");
    printf("You have arrived at %s!\n", w.name);
}