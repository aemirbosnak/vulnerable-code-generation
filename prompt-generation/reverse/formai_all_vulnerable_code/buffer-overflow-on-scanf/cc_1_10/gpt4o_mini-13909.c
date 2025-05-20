//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WAYPOINTS 10
#define MAP_SIZE 5

typedef struct {
    char name[20];
    int x, y;
} Waypoint;

Waypoint waypoints[MAX_WAYPOINTS];
int waypoint_count = 0;

double heuristic(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void addWaypoint(char* name, int x, int y) {
    if (waypoint_count < MAX_WAYPOINTS) {
        strcpy(waypoints[waypoint_count].name, name);
        waypoints[waypoint_count].x = x;
        waypoints[waypoint_count].y = y;
        waypoint_count++;
    } else {
        printf("Max waypoints limit reached!\n");
    }
}

void displayMap() {
    char map[MAP_SIZE][MAP_SIZE] = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };

    for (int i = 0; i < waypoint_count; i++) {
        map[waypoints[i].y][waypoints[i].x] = waypoints[i].name[0];
    }

    printf("\nMap:\n");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void findRoute(int start_idx, int end_idx) {
    int start_x = waypoints[start_idx].x;
    int start_y = waypoints[start_idx].y;
    int end_x = waypoints[end_idx].x;
    int end_y = waypoints[end_idx].y;

    printf("Finding route from %s to %s...\n", waypoints[start_idx].name, waypoints[end_idx].name);

    while (start_x != end_x || start_y != end_y) {
        if (start_x < end_x) start_x++;
        else if (start_x > end_x) start_x--;

        if (start_y < end_y) start_y++;
        else if (start_y > end_y) start_y--;

        printf("Current position: (%d, %d)\n", start_x, start_y);
    }

    printf("Arrived at %s!\n", waypoints[end_idx].name);
}

int main() {
    addWaypoint("Start", 0, 0);
    addWaypoint("A", 1, 1);
    addWaypoint("B", 4, 1);
    addWaypoint("C", 4, 4);
    addWaypoint("End", 0, 4);

    displayMap();

    int start_idx, end_idx;
    printf("Enter the start waypoint index (0 - %d): ", waypoint_count - 1);
    scanf("%d", &start_idx);
    printf("Enter the end waypoint index (0 - %d): ", waypoint_count - 1);
    scanf("%d", &end_idx);

    if (start_idx >= 0 && start_idx < waypoint_count && end_idx >= 0 && end_idx < waypoint_count) {
        findRoute(start_idx, end_idx);
    } else {
        printf("Invalid waypoint indices!\n");
    }

    return 0;
}