//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAYPOINTS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float latitude;
    float longitude;
} Waypoint;

typedef struct {
    Waypoint waypoints[MAX_WAYPOINTS];
    int count;
} GPSTracker;

void initTracker(GPSTracker* tracker) {
    tracker->count = 0;
}

int addWaypoint(GPSTracker* tracker, const char* name, float latitude, float longitude) {
    if (tracker->count >= MAX_WAYPOINTS) {
        printf("Error: Maximum waypoint limit reached.\n");
        return -1;
    }
    strncpy(tracker->waypoints[tracker->count].name, name, MAX_NAME_LENGTH);
    tracker->waypoints[tracker->count].latitude = latitude;
    tracker->waypoints[tracker->count].longitude = longitude;
    tracker->count++;
    return 0;
}

void displayWaypoints(const GPSTracker* tracker) {
    printf("Current Waypoints:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Waypoint %d: %s (Lat: %.6f, Lon: %.6f)\n", 
               i + 1, tracker->waypoints[i].name, 
               tracker->waypoints[i].latitude, 
               tracker->waypoints[i].longitude);
    }
}

void navigateToWaypoint(const GPSTracker* tracker, int index) {
    if (index < 0 || index >= tracker->count) {
        printf("Error: Invalid waypoint index.\n");
        return;
    }
    printf("Navigating to %s (Lat: %.6f, Lon: %.6f)...\n", 
           tracker->waypoints[index].name, 
           tracker->waypoints[index].latitude, 
           tracker->waypoints[index].longitude);
    // Simple simulation of navigation
    printf("Arrived at %s!\n", tracker->waypoints[index].name);
}

void saveWaypointsToFile(const GPSTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%.6f,%.6f\n", 
                tracker->waypoints[i].name, 
                tracker->waypoints[i].latitude, 
                tracker->waypoints[i].longitude);
    }
    fclose(file);
    printf("Waypoints saved to %s successfully!\n", filename);
}

void loadWaypointsFromFile(GPSTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file for reading.\n");
        return;
    }
    while (!feof(file) && tracker->count < MAX_WAYPOINTS) {
        Waypoint wp;
        if (fscanf(file, "%49[^,],%f,%f\n", wp.name, &wp.latitude, &wp.longitude) == 3) {
            addWaypoint(tracker, wp.name, wp.latitude, wp.longitude);
        }
    }
    fclose(file);
    printf("Waypoints loaded from %s successfully!\n", filename);
}

int main() {
    GPSTracker tracker;
    initTracker(&tracker);

    int choice;
    do {
        printf("\nGPS Navigation System\n");
        printf("1. Add Waypoint\n");
        printf("2. Display Waypoints\n");
        printf("3. Navigate to Waypoint\n");
        printf("4. Save Waypoints\n");
        printf("5. Load Waypoints\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                float latitude, longitude;
                printf("Enter waypoint name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%f", &latitude);
                printf("Enter longitude: ");
                scanf("%f", &longitude);
                addWaypoint(&tracker, name, latitude, longitude);
                break;
            }
            case 2:
                displayWaypoints(&tracker);
                break;
            case 3: {
                int index;
                printf("Enter waypoint index to navigate to: ");
                scanf("%d", &index);
                navigateToWaypoint(&tracker, index - 1);
                break;
            }
            case 4: {
                char filename[100];
                printf("Enter filename to save waypoints: ");
                scanf("%s", filename);
                saveWaypointsToFile(&tracker, filename);
                break;
            }
            case 5: {
                char filename[100];
                printf("Enter filename to load waypoints: ");
                scanf("%s", filename);
                loadWaypointsFromFile(&tracker, filename);
                break;
            }
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}