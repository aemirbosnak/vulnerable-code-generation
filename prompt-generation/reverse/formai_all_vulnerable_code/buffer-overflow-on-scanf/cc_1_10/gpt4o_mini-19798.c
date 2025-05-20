//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAYPOINTS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float latitude;
    float longitude;
} Waypoint;

typedef struct {
    Waypoint waypoints[MAX_WAYPOINTS];
    int count;
} Map;

void add_waypoint(Map *map, const char *name, float latitude, float longitude) {
    if (map->count < MAX_WAYPOINTS) {
        strncpy(map->waypoints[map->count].name, name, MAX_NAME_LENGTH);
        map->waypoints[map->count].latitude = latitude;
        map->waypoints[map->count].longitude = longitude;
        map->count++;
        printf("Waypoint '%s' added at (%f, %f).\n", name, latitude, longitude);
    } else {
        printf("Cannot add more waypoints. Max limit reached.\n");
    }
}

void display_waypoints(const Map *map) {
    printf("Current Waypoints:\n");
    for (int i = 0; i < map->count; i++) {
        printf("[%d] %s: (%f, %f)\n", i + 1, map->waypoints[i].name,
               map->waypoints[i].latitude, map->waypoints[i].longitude);
    }
}

void navigate(const Map *map, const char *start, const char *end) {
    int start_index = -1;
    int end_index = -1;

    for (int i = 0; i < map->count; i++) {
        if (strcmp(map->waypoints[i].name, start) == 0) {
            start_index = i;
        }
        if (strcmp(map->waypoints[i].name, end) == 0) {
            end_index = i;
        }
    }

    if (start_index == -1 || end_index == -1) {
        printf("Start or end waypoint not found.\n");
        return;
    }

    printf("Navigating from '%s' to '%s'.\n", map->waypoints[start_index].name, map->waypoints[end_index].name);
    // Here you could implement more navigation logic
    printf("Distance: (mocked) 5km\n");  // Placeholder for actual distance calculation
}

void user_menu() {
    printf("\n=== GPS Navigation Simulation ===\n");
    printf("1. Add Waypoint\n");
    printf("2. Display Waypoints\n");
    printf("3. Navigate\n");
    printf("4. Exit\n");
    printf("==================================\n");
}

int main() {
    Map map = { .count = 0 };
    int choice;
    char name[MAX_NAME_LENGTH], start[MAX_NAME_LENGTH], end[MAX_NAME_LENGTH];
    float latitude, longitude;

    while (1) {
        user_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter waypoint name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%f", &latitude);
                printf("Enter longitude: ");
                scanf("%f", &longitude);
                add_waypoint(&map, name, latitude, longitude);
                break;
            case 2:
                display_waypoints(&map);
                break;
            case 3:
                printf("Enter start waypoint name: ");
                scanf("%s", start);
                printf("Enter end waypoint name: ");
                scanf("%s", end);
                navigate(&map, start, end);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}