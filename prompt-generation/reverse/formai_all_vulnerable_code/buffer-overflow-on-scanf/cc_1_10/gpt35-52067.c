//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Struct to hold GPS coordinates
typedef struct {
    double lat;
    double lon;
} GPS_Coord;

// Function to calculate the distance between two GPS coordinates
double calc_distance(GPS_Coord coord1, GPS_Coord coord2) {
    double lat_diff = coord2.lat - coord1.lat;
    double lon_diff = coord2.lon - coord1.lon;
    double distance = sqrt(lat_diff*lat_diff + lon_diff*lon_diff);
    return distance;
}

// Function to simulate navigation
void navigation_simulation(GPS_Coord start, GPS_Coord destination) {
    double total_dist = calc_distance(start, destination);
    double remaining_dist = total_dist;
    GPS_Coord current_loc = start;

    // Print initial message
    printf("Starting navigation from (%f, %f) to (%f, %f).\n", start.lat, start.lon, destination.lat, destination.lon);

    // Loop until destination is reached
    while (remaining_dist > 0) {
        // Get user input
        printf("Enter distance to travel (in meters): ");
        double travel_dist;
        scanf("%lf", &travel_dist);

        // Check if input is valid
        if (travel_dist < 0) {
            printf("Invalid input. Distance must be non-negative.\n");
            continue;
        }
        if (travel_dist > remaining_dist) {
            printf("Invalid input. Distance cannot be greater than remaining distance to destination.\n");
            continue;
        }

        // Update current location and remaining distance
        GPS_Coord prev_loc = current_loc;
        double lat_diff = (destination.lat - start.lat) * (1 - (remaining_dist - travel_dist) / total_dist);
        double lon_diff = (destination.lon - start.lon) * (1 - (remaining_dist - travel_dist) / total_dist);
        current_loc.lat += lat_diff;
        current_loc.lon += lon_diff;
        remaining_dist -= travel_dist;

        // Calculate distance traveled and print message
        double dist_traveled = calc_distance(prev_loc, current_loc);
        printf("Traveled %f meters. Remaining distance to destination: %f meters.\n", dist_traveled, remaining_dist);
    }

    // Print final message
    printf("Destination reached!\n");
}

// Driver program to test navigation simulation
int main() {
    GPS_Coord start = {51.5074, -0.1278};
    GPS_Coord destination = {48.8566, 2.3522};
    navigation_simulation(start, destination);
    return 0;
}