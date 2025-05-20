//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_WAYPOINTS 10

typedef struct waypoint {
    double lat;
    double lng;
    char name[25];
} waypoint;

waypoint waypoints[MAX_WAYPOINTS] = {
    {43.65323, -79.38321, "Central Park"},
    {40.71280, -74.00602, "Empire State Building"},
    {34.05223, -118.24363, "Grand Canyon"},
    {37.73323, -122.41948, "Golden Gate Bridge"},
    {39.90128, -82.41722, "Statue of Liberty"},
    {41.88112, -87.62816, "Will Rogers Memorial"},
    {36.11216, -122.08361, "Hollywood Sign"},
    {28.53012, -81.31621, "Golden Gate Bridge"},
    {32.33628, -116.68111, "Las Vegas Sign"},
    {46.81188, -122.23262, "Golden Gate Bridge"}
};

int main() {
    int i, current_waypoint = 0;
    double x, y, distance, time_elapsed = 0.0;
    char current_waypoint_name[25];

    // Seed the random number generator
    srand(time(NULL));

    // Display the current waypoint information
    printf("Current Waypoint: %s\n", waypoints[current_waypoint].name);
    printf("Lat: %.6f, LNG: %.6f\n", waypoints[current_waypoint].lat, waypoints[current_waypoint].lng);

    // Simulate driving to the next waypoint
    for (i = current_waypoint + 1; i < MAX_WAYPOINTS; i++) {
        // Calculate the distance to the next waypoint
        distance = sqrt(pow(waypoints[i].lat - waypoints[current_waypoint].lat, 2) + pow(waypoints[i].lng - waypoints[current_waypoint].lng, 2));

        // Simulate time elapsed
        time_elapsed += distance / 10.0;

        // Update the current waypoint
        current_waypoint++;

        // Display the new waypoint information
        printf("Current Waypoint: %s\n", waypoints[current_waypoint].name);
        printf("Lat: %.6f, LNG: %.6f\n", waypoints[current_waypoint].lat, waypoints[current_waypoint].lng);

        // Pause for a random amount of time
        sleep(rand() % 5);
    }

    // Display the time elapsed
    printf("Total Time Elapsed: %.2f minutes\n", time_elapsed);

    return 0;
}