//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WAYPOINTS 10

typedef struct waypoint {
    int x;
    int y;
    char name[20];
} waypoint;

waypoint waypoints[MAX_WAYPOINTS] = {
    {10, 10, "The Mill"},
    {20, 20, "The Castle"},
    {30, 30, "The Fountain"},
    {40, 40, "The Bridge"},
    {50, 50, "The Tower"}
};

int main() {
    int current_waypoint = 0;
    char destination[20];

    printf("Welcome to the grand navigation system of the Middle Ages!\n");
    printf("Please enter your desired destination: ");
    scanf("%s", destination);

    for (int i = 0; i < MAX_WAYPOINTS; i++) {
        if (strcmp(destination, waypoints[i].name) == 0) {
            current_waypoint = i;
            break;
        }
    }

    if (current_waypoint == -1) {
        printf("Error: Destination not found.\n");
    } else {
        printf("Your current position is: (%d, %d).\n", waypoints[current_waypoint].x, waypoints[current_waypoint].y);
        printf("Your destination is: %s.\n", waypoints[current_waypoint].name);

        int direction = rand() % 4;
        switch (direction) {
            case 0:
                printf("Travel north.\n");
                waypoints[current_waypoint].y++;
                break;
            case 1:
                printf("Travel south.\n");
                waypoints[current_waypoint].y--;
                break;
            case 2:
                printf("Travel east.\n");
                waypoints[current_waypoint].x++;
                break;
            case 3:
                printf("Travel west.\n");
                waypoints[current_waypoint].x--;
                break;
        }

        printf("Continue your journey...!\n");
    }

    return 0;
}