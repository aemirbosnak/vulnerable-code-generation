//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WAYPOINTS 10
#define EARTH_RADIUS 6371.0 // in kilometers

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Waypoint;

typedef struct {
    Waypoint waypoints[MAX_WAYPOINTS];
    int count;
} NavigationSystem;

// Function prototypes
void init_navigation_system(NavigationSystem *nav);
void add_waypoint(NavigationSystem *nav);
void display_waypoints(NavigationSystem *nav);
double calculate_distance(double lat1, double lon1, double lat2, double lon2);
void navigate(NavigationSystem *nav);

int main() {
    NavigationSystem nav;
    init_navigation_system(&nav);
    
    int choice;
    do {
        printf("\nGPS Navigation Simulation Menu\n");
        printf("1. Add Waypoint\n");
        printf("2. Display Waypoints\n");
        printf("3. Navigate\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_waypoint(&nav);
                break;
            case 2:
                display_waypoints(&nav);
                break;
            case 3:
                navigate(&nav);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void init_navigation_system(NavigationSystem *nav) {
    nav->count = 0;
}

void add_waypoint(NavigationSystem *nav) {
    if (nav->count >= MAX_WAYPOINTS) {
        printf("Maximum number of waypoints reached!\n");
        return;
    }
    Waypoint w;
    printf("Enter waypoint name: ");
    scanf("%s", w.name);
    printf("Enter latitude: ");
    scanf("%lf", &w.latitude);
    printf("Enter longitude: ");
    scanf("%lf", &w.longitude);
    nav->waypoints[nav->count++] = w;
    printf("Waypoint '%s' added successfully.\n", w.name);
}

void display_waypoints(NavigationSystem *nav) {
    if (nav->count == 0) {
        printf("No waypoints available.\n");
        return;
    }
    printf("Waypoints:\n");
    for (int i = 0; i < nav->count; i++) {
        printf("%d. %s (Lat: %.6f, Long: %.6f)\n", i + 1, nav->waypoints[i].name, nav->waypoints[i].latitude, nav->waypoints[i].longitude);
    }
}

double to_radians(double degree) {
    return degree * (M_PI / 180.0);
}

double calculate_distance(double lat1, double lon1, double lat2, double lon2) {
    // Haversine formula
    double dlat = to_radians(lat2 - lat1);
    double dlon = to_radians(lon2 - lon1);
    lat1 = to_radians(lat1);
    lat2 = to_radians(lat2);

    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c; // returns the distance in kilometers
}

void navigate(NavigationSystem *nav) {
    if (nav->count < 2) {
        printf("You need at least 2 waypoints to navigate.\n");
        return;
    }
    printf("Choose start waypoint:\n");
    display_waypoints(nav);
    
    int startIndex, endIndex;
    printf("Select start (1 - %d): ", nav->count);
    scanf("%d", &startIndex);
    startIndex--; // Adjust for 0-based index

    printf("Choose destination waypoint:\n");
    display_waypoints(nav);
    printf("Select destination (1 - %d): ", nav->count);
    scanf("%d", &endIndex);
    endIndex--; // Adjust for 0-based index

    if (startIndex < 0 || startIndex >= nav->count || endIndex < 0 || endIndex >= nav->count) {
        printf("Invalid selection.\n");
        return;
    }

    double distance = calculate_distance(nav->waypoints[startIndex].latitude, nav->waypoints[startIndex].longitude,
                                         nav->waypoints[endIndex].latitude, nav->waypoints[endIndex].longitude);
    
    printf("Distance from %s to %s is %.2f km.\n", nav->waypoints[startIndex].name, nav->waypoints[endIndex].name, distance);
}