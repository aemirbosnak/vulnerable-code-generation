//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//the constants can be changed according to the requirements
#define MAX_WAYPOINTS 10
#define MAX_DISTANCE 1000
#define RADIUS_OF_EARTH 6371

//structure to hold the waypoint information
typedef struct {
    float latitude;
    float longitude;
} waypoint_t;

//function to calculate the distance between two waypoints
float distance_between_waypoints(waypoint_t wp1, waypoint_t wp2) {
    float lat1_rad, lat2_rad, long1_rad, long2_rad, delta_lat, delta_long, a, c, distance;
    lat1_rad = wp1.latitude * M_PI / 180;
    lat2_rad = wp2.latitude * M_PI / 180;
    long1_rad = wp1.longitude * M_PI / 180;
    long2_rad = wp2.longitude * M_PI / 180;
    delta_lat = lat2_rad - lat1_rad;
    delta_long = long2_rad - long1_rad;
    a = sin(delta_lat / 2) * sin(delta_lat / 2) + cos(lat1_rad) * cos(lat2_rad) * sin(delta_long / 2) * sin(delta_long / 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    distance = RADIUS_OF_EARTH * c;
    return distance;
}

int main() {
    int num_waypoints, i, j;
    float current_lat, current_long, total_distance = 0;
    waypoint_t waypoints[MAX_WAYPOINTS];

    //get the number of waypoints
    printf("Enter the number of waypoints (maximum %d): ", MAX_WAYPOINTS);
    scanf("%d", &num_waypoints);

    //get the waypoints
    for (i = 0; i < num_waypoints; i++) {
        printf("Enter latitude for waypoint %d (between -90 and 90): ", i + 1);
        scanf("%f", &waypoints[i].latitude);
        printf("Enter longitude for waypoint %d (between -180 and 180): ", i + 1);
        scanf("%f", &waypoints[i].longitude);
    }

    //loop through the waypoints to calculate the distances and the total distance
    for (i = 0; i < num_waypoints - 1; i++) {
        total_distance += distance_between_waypoints(waypoints[i], waypoints[i + 1]);
    }

    //get the current location
    printf("Enter current latitude (between -90 and 90): ");
    scanf("%f", &current_lat);
    printf("Enter current longitude (between -180 and 180): ");
    scanf("%f", &current_long);

    //calculate the nearest waypoint by distance
    float min_distance = MAX_DISTANCE;
    int nearest_waypoint_index = -1;
    for (j = 0; j < num_waypoints; j++) {
        float distance = distance_between_waypoints(waypoints[j], (waypoint_t) {current_lat, current_long});
        if (distance < min_distance) {
            min_distance = distance;
            nearest_waypoint_index = j;
        }
    }

    //output the results
    printf("\nNearest waypoint is waypoint %d\n", nearest_waypoint_index + 1);
    printf("Total distance is %.2f km\n", total_distance);
    return 0;
}