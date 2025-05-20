//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WAYPOINTS 50
#define MAX_CMD_LENGTH 100

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Waypoint;

typedef struct {
    Waypoint waypoints[MAX_WAYPOINTS];
    int waypoint_count;
} GPSNavigator;

void add_waypoint(GPSNavigator *navigator, const char *name, double latitude, double longitude) {
    if (navigator->waypoint_count < MAX_WAYPOINTS) {
        strncpy(navigator->waypoints[navigator->waypoint_count].name, name, 50);
        navigator->waypoints[navigator->waypoint_count].latitude = latitude;
        navigator->waypoints[navigator->waypoint_count].longitude = longitude;
        navigator->waypoint_count++;
        printf("Waypoint added: %s (%f, %f)\n", name, latitude, longitude);
    } else {
        printf("Waypoint limit reached. Cannot add more.\n");
    }
}

void list_waypoints(GPSNavigator *navigator) {
    if (navigator->waypoint_count == 0) {
        printf("No waypoints available.\n");
        return;
    }
    printf("Waypoints:\n");
    for (int i = 0; i < navigator->waypoint_count; i++) {
        printf("%d: %s (%f, %f)\n", i + 1, navigator->waypoints[i].name, navigator->waypoints[i].latitude, navigator->waypoints[i].longitude);
    }
}

double calculate_distance(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0; // Earth's radius in kilometers
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c; // Distance in kilometers
}

void navigate_to(GPSNavigator *navigator, const char *waypoint_name) {
    for (int i = 0; i < navigator->waypoint_count; i++) {
        if (strcmp(navigator->waypoints[i].name, waypoint_name) == 0) {
            printf("Navigating to %s (%f, %f)\n", navigator->waypoints[i].name, navigator->waypoints[i].latitude, navigator->waypoints[i].longitude);
            // Let's assume the user's current location is (0, 0) for the purpose of this example.
            double distance = calculate_distance(0.0, 0.0, navigator->waypoints[i].latitude, navigator->waypoints[i].longitude);
            printf("Distance to %s: %.2f km\n", waypoint_name, distance);
            return;
        }
    }
    printf("Waypoint %s not found.\n", waypoint_name);
}

void show_menu() {
    printf("\nGPS Navigation System\n");
    printf("1. Add Waypoint\n");
    printf("2. List Waypoints\n");
    printf("3. Navigate to Waypoint\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    GPSNavigator navigator;
    navigator.waypoint_count = 0;

    int choice;
    char cmd[MAX_CMD_LENGTH];
    char name[50];
    double latitude, longitude;

    while (1) {
        show_menu();
        fgets(cmd, MAX_CMD_LENGTH, stdin);
        sscanf(cmd, "%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter waypoint name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove the newline character
                printf("Enter latitude: ");
                fscanf(stdin, "%lf", &latitude);
                printf("Enter longitude: ");
                fscanf(stdin, "%lf", &longitude);
                add_waypoint(&navigator, name, latitude, longitude);
                break;
                
            case 2:
                list_waypoints(&navigator);
                break;

            case 3:
                printf("Enter waypoint name to navigate to: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove the newline character
                navigate_to(&navigator, name);
                break;
                
            case 4:
                printf("Exiting navigation system.\n");
                exit(0);
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}