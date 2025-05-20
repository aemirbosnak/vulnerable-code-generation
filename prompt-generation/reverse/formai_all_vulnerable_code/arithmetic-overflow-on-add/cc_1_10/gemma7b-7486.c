//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WAYPOINTS 10

typedef struct waypoint {
    int x;
    int y;
    char name[20];
} waypoint;

 waypoint waypoints[MAX_WAYPOINTS];

void initializeWaypoints() {
    waypoints[0].x = 10;
    waypoints[0].y = 20;
    strcpy(waypoints[0].name, "Home");

    waypoints[1].x = 20;
    waypoints[1].y = 30;
    strcpy(waypoints[1].name, "Work");

    waypoints[2].x = 30;
    waypoints[2].y = 40;
    strcpy(waypoints[2].name, "School");
}

int main() {
    initializeWaypoints();

    // Simulate GPS navigation
    int currentX = waypoints[0].x;
    int currentY = waypoints[0].y;

    time_t startTime = time(NULL);
    time_t currentTime = startTime;

    while (currentX != waypoints[2].x || currentY != waypoints[2].y) {
        // Calculate direction and distance to next waypoint
        int direction = calculateDirection(currentX, currentY, waypoints[1].x, waypoints[1].y);
        int distance = calculateDistance(currentX, currentY, waypoints[1].x, waypoints[1].y);

        // Display current location and heading
        printf("Current position: (%d, %d)\n", currentX, currentY);
        printf("Heading: %d degrees\n", direction);
        printf("Distance: %d miles\n", distance);

        // Update current position
        currentX += direction * distance;
        currentY += distance;

        // Sleep for 1 second
        time_t sleepTime = time(NULL) + 1;
        while (time(NULL) < sleepTime) {}
    }

    // Display final destination
    printf("Congratulations! You have reached your destination!\n");

    return 0;
}

int calculateDirection(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int direction = (dx * 180) / dy;

    if (dy == 0) {
        direction = 90;
    } else if (dx == 0) {
        direction = 0;
    }

    return direction;
}

int calculateDistance(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int distance = (dx * dx + dy * dy) / 2 + 0.5;

    return distance;
}