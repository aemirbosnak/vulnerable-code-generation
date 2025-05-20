//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

#define NUM_WAYPOINTS 5

typedef struct Waypoint
{
    int x;
    int y;
    char name[20];
} Waypoint;

Waypoint waypoints[NUM_WAYPOINTS] =
{
    {5, 5, "Start"},
    {10, 10, "Intersection A"},
    {15, 15, "Intersection B"},
    {20, 20, "End"},
    {10, 20, "Detour"}
};

int main()
{
    int current_x = waypoints[0].x;
    int current_y = waypoints[0].y;

    char current_waypoint_name[20];
    strcpy(current_waypoint_name, waypoints[0].name);

    int target_x = waypoints[NUM_WAYPOINTS - 1].x;
    int target_y = waypoints[NUM_WAYPOINTS - 1].y;

    char target_waypoint_name[20];
    strcpy(target_waypoint_name, waypoints[NUM_WAYPOINTS - 1].name);

    char map[MAP_HEIGHT][MAP_WIDTH];

    for (int h = 0; h < MAP_HEIGHT; h++)
    {
        for (int w = 0; w < MAP_WIDTH; w++)
        {
            map[h][w] = '-';
        }
    }

    map[current_x][current_y] = 'o';
    map[target_x][target_y] = 'T';

    for (int i = 0; i < NUM_WAYPOINTS - 1; i++)
    {
        map[waypoints[i].x][waypoints[i].y] = 'x';
    }

    printf("Current Position: %s (%d, %d)\n", current_waypoint_name, current_x, current_y);
    printf("Target Position: %s (%d, %d)\n", target_waypoint_name, target_x, target_y);

    printf("Map:\n");

    for (int h = 0; h < MAP_HEIGHT; h++)
    {
        for (int w = 0; w < MAP_WIDTH; w++)
        {
            printf("%c ", map[h][w]);
        }
        printf("\n");
    }

    return 0;
}