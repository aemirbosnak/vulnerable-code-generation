//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void initialize_waypoint_list(WaypointList *list) {
    list->count = 0;
}

void add_waypoint(WaypointList *list) {
    if (list->count >= MAX_WAYPOINTS) {
        printf("Cannot add more waypoints!\n");
        return;
    }
    
    Waypoint new_waypoint;
    printf("Enter waypoint name: ");
    scanf("%s", new_waypoint.name);
    printf("Enter latitude: ");
    scanf("%f", &new_waypoint.latitude);
    printf("Enter longitude: ");
    scanf("%f", &new_waypoint.longitude);
    
    list->waypoints[list->count] = new_waypoint;
    list->count++;
    printf("Waypoint added!\n");
}

void display_waypoints(WaypointList *list) {
    printf("\nList of Waypoints:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s (Lat: %.2f, Lon: %.2f)\n", i + 1,
               list->waypoints[i].name,
               list->waypoints[i].latitude,
               list->waypoints[i].longitude);
    }
}

float calculate_distance(float lat1, float lon1, float lat2, float lon2) {
    // Haversine formula for distance calculation
    const float R = 6371.0; // Earth radius in kilometers
    float dlat = (lat2 - lat1) * M_PI / 180.0;
    float dlon = (lon2 - lon1) * M_PI / 180.0;

    float a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) * sin(dlon / 2) * sin(dlon / 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

void navigate(WaypointList *list) {
    if (list->count < 2) {
        printf("Need at least 2 waypoints to navigate.\n");
        return;
    }
    
    int start_index, end_index;
    display_waypoints(list);
    
    printf("Select starting waypoint (1 - %d): ", list->count);
    scanf("%d", &start_index);
    printf("Select destination waypoint (1 - %d): ", list->count);
    scanf("%d", &end_index);
    
    if (start_index < 1 || start_index > list->count ||
        end_index < 1 || end_index > list->count) {
        printf("Invalid selection!\n");
        return;
    }

    float distance = calculate_distance(
        list->waypoints[start_index - 1].latitude,
        list->waypoints[start_index - 1].longitude,
        list->waypoints[end_index - 1].latitude,
        list->waypoints[end_index - 1].longitude
    );

    printf("Distance from %s to %s is %.2f km.\n",
           list->waypoints[start_index - 1].name,
           list->waypoints[end_index - 1].name,
           distance);
}

int main() {
    WaypointList waypoint_list;
    initialize_waypoint_list(&waypoint_list);
    
    while (1) {
        printf("\nGPS Navigation System\n");
        printf("1. Add Waypoint\n");
        printf("2. Display Waypoints\n");
        printf("3. Navigate\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        int option;
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_waypoint(&waypoint_list);
                break;
            case 2:
                display_waypoints(&waypoint_list);
                break;
            case 3:
                navigate(&waypoint_list);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}