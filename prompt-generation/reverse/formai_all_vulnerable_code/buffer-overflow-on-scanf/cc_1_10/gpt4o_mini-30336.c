//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define MAX_WAYPOINTS 100
#define EARTH_RADIUS 6371.0  // Average radius of earth in kilometers

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Waypoint;

void clear_screen() {
    printf("\033[H\033[J");  // ANSI escape code to clear the screen
}

void wait_for_user_input() {
    printf("Press Enter to continue...");
    while (getchar() != '\n');
}

double to_radians(double degrees) {
    return degrees * (M_PI / 180.0);
}

double distance_between(double lat1, double lon1, double lat2, double lon2) {
    double dlat = to_radians(lat2 - lat1);
    double dlon = to_radians(lon2 - lon1);
    lat1 = to_radians(lat1);
    lat2 = to_radians(lat2);

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;  // Distance in kilometers
}

void display_menu() {
    clear_screen();
    printf("=== GPS Navigation Simulation ===\n");
    printf("1. Add Waypoint\n");
    printf("2. Calculate Distance\n");
    printf("3. Display Waypoints\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void add_waypoint(Waypoint waypoints[], int *count) {
    if (*count >= MAX_WAYPOINTS) {
        printf("Max waypoints reached!\n");
        wait_for_user_input();
        return;
    }
    printf("Enter waypoint name: ");
    scanf("%s", waypoints[*count].name);
    printf("Enter latitude: ");
    scanf("%lf", &waypoints[*count].latitude);
    printf("Enter longitude: ");
    scanf("%lf", &waypoints[*count].longitude);
    (*count)++;
    printf("Waypoint added successfully!\n");
    wait_for_user_input();
}

void calculate_distance(Waypoint waypoints[], int count) {
    if (count < 2) {
        printf("Need at least 2 waypoints to calculate distance!\n");
        wait_for_user_input();
        return;
    }
    int from, to;
    printf("Select starting waypoint (0 to %d): ", count - 1);
    scanf("%d", &from);
    printf("Select destination waypoint (0 to %d): ", count - 1);
    scanf("%d", &to);
    
    if (from < 0 || from >= count || to < 0 || to >= count) {
        printf("Invalid selection!\n");
        wait_for_user_input();
        return;
    }

    double distance = distance_between(
        waypoints[from].latitude,
        waypoints[from].longitude,
        waypoints[to].latitude,
        waypoints[to].longitude
    );

    printf("Distance from '%s' to '%s' is: %.2f km\n", 
            waypoints[from].name, 
            waypoints[to].name, 
            distance);
    wait_for_user_input();
}

void display_waypoints(Waypoint waypoints[], int count) {
    clear_screen();
    printf("=== List of Waypoints ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Lat: %.6f, Lon: %.6f)\n", i, 
            waypoints[i].name, 
            waypoints[i].latitude, 
            waypoints[i].longitude);
    }
    wait_for_user_input();
}

int main() {
    Waypoint waypoints[MAX_WAYPOINTS];
    int count = 0;
    
    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_waypoint(waypoints, &count);
                break;
            case 2:
                calculate_distance(waypoints, count);
                break;
            case 3:
                display_waypoints(waypoints, count);
                break;
            case 4:
                printf("Exiting the GPS Navigation Simulation. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
                wait_for_user_input();
                break;
        }
    }
    return 0;
}