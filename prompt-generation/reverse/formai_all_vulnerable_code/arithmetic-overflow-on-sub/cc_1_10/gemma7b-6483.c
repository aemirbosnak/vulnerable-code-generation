//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WAYPOINTS 10

typedef struct Waypoint {
    int x;
    int y;
    char name[20];
} Waypoint;

int main() {
    time_t t;
    srand(time(NULL));

    // Create an array of waypoints
    Waypoint waypoints[MAX_WAYPOINTS];

    // Populate the waypoints
    waypoints[0].x = 10;
    waypoints[0].y = 10;
    strcpy(waypoints[0].name, "Home");

    waypoints[1].x = 20;
    waypoints[1].y = 20;
    strcpy(waypoints[1].name, "Work");

    waypoints[2].x = 30;
    waypoints[2].y = 30;
    strcpy(waypoints[2].name, "School");

    // Simulate GPS navigation
    int current_waypoint = 0;
    t = time(NULL);
    while (time(NULL) - t < 10) {
        // Calculate the next waypoint
        int next_waypoint = (current_waypoint + 1) % MAX_WAYPOINTS;

        // Update the current waypoint
        current_waypoint = next_waypoint;

        // Print the current waypoint
        printf("Current waypoint: %s (%d, %d)\n", waypoints[current_waypoint].name, waypoints[current_waypoint].x, waypoints[current_waypoint].y);

        // Sleep for a while
        sleep(1);
    }

    return 0;
}