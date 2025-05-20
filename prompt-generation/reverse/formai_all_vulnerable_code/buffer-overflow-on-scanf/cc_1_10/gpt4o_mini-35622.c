//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WAYPOINTS 10
#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
    char name[50];
} Waypoint;

void addWaypoint(Waypoint* waypoints, int* count) {
    if (*count >= MAX_WAYPOINTS) {
        printf("Maximum waypoints reached!\n");
        return;
    }
    
    printf("Enter waypoint name: ");
    scanf("%s", waypoints[*count].name);

    printf("Enter X coordinate (0 to %d): ", GRID_SIZE - 1);
    scanf("%d", &waypoints[*count].x);
    printf("Enter Y coordinate (0 to %d): ", GRID_SIZE - 1);
    scanf("%d", &waypoints[*count].y);
    
    (*count)++;
    printf("Waypoint added successfully!\n");
}

void displayWaypoints(Waypoint* waypoints, int count) {
    printf("Waypoints:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s (%d, %d)\n", i + 1, waypoints[i].name, waypoints[i].x, waypoints[i].y);
    }
}

void calculateRoute(Waypoint* waypoints, int count) {
    if (count < 2) {
        printf("At least two waypoints are needed to calculate a route!\n");
        return;
    }

    printf("Calculating route from %s to %s...\n", waypoints[0].name, waypoints[1].name);
    int x_diff = waypoints[1].x - waypoints[0].x;
    int y_diff = waypoints[1].y - waypoints[0].y;
    int steps = (int) sqrt(x_diff * x_diff + y_diff * y_diff);

    printf("Route:\n");
    for (int i = 0; i <= steps; i++) {
        int step_x = waypoints[0].x + (i * x_diff) / steps;
        int step_y = waypoints[0].y + (i * y_diff) / steps;
        printf("Step %d: Move to (%d, %d)\n", i + 1, step_x, step_y);
    }
    
    printf("Arrived at %s!\n", waypoints[1].name);
}

int main() {
    Waypoint waypoints[MAX_WAYPOINTS];
    int waypoint_count = 0;
    int choice;

    while (1) {
        printf("\nGPS Navigation System\n");
        printf("1. Add Waypoint\n");
        printf("2. Display Waypoints\n");
        printf("3. Calculate Route\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addWaypoint(waypoints, &waypoint_count);
                break;
            case 2:
                displayWaypoints(waypoints, waypoint_count);
                break;
            case 3:
                calculateRoute(waypoints, waypoint_count);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}