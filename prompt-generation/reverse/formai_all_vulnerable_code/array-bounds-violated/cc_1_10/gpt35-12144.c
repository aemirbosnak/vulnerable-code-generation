//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
/*
* GPS Navigation Simulation in C
* Calculates optimal routes based on the user's destination and current location
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define MAX_LOCATIONS 100
#define EARTH_RADIUS 6371.0 // km

// Define functions
void get_user_location(double* current_latitude, double* current_longitude);
void get_destination(double* dest_latitude, double* dest_longitude);
double calculate_distance(double current_latitude, double current_longitude, double dest_latitude, double dest_longitude);
void calculate_optimal_route(int num_locations, double* location_latitudes, double* location_longitudes, double current_latitude, double current_longitude, double dest_latitude, double dest_longitude);

// Main function
int main() {
    // Initialize variables
    double current_latitude, current_longitude, dest_latitude, dest_longitude;
    double location_latitudes[MAX_LOCATIONS], location_longitudes[MAX_LOCATIONS];
    int num_locations;

    // Get user input
    get_user_location(&current_latitude, &current_longitude);
    get_destination(&dest_latitude, &dest_longitude);
    printf("Enter the number of locations: ");
    scanf("%d", &num_locations);
    printf("Enter the latitude and longitude of each location:\n");
    for (int i = 0; i < num_locations; i++) {
        printf("Location %d: ", i+1);
        scanf("%lf %lf", &location_latitudes[i], &location_longitudes[i]);
    }

    // Calculate optimal route
    calculate_optimal_route(num_locations, location_latitudes, location_longitudes, current_latitude, current_longitude, dest_latitude, dest_longitude);

    return 0;
}

// Function to get the user's current location
void get_user_location(double* current_latitude, double* current_longitude) {
    printf("Enter your current location:\n");
    printf("Latitude: ");
    scanf("%lf", current_latitude);
    printf("Longitude: ");
    scanf("%lf", current_longitude);
}

// Function to get the destination
void get_destination(double* dest_latitude, double* dest_longitude) {
    printf("Enter your destination:\n");
    printf("Latitude: ");
    scanf("%lf", dest_latitude);
    printf("Longitude: ");
    scanf("%lf", dest_longitude);
}

// Function to calculate the distance between two coordinates using the Haversine formula
double calculate_distance(double current_latitude, double current_longitude, double dest_latitude, double dest_longitude) {
    double d_latitude = dest_latitude - current_latitude;
    double d_longitude = dest_longitude - current_longitude;

    double a = pow(sin(d_latitude/2), 2) + cos(current_latitude) * cos(dest_latitude) * pow(sin(d_longitude/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return EARTH_RADIUS * c;
}

// Function to calculate the optimal route based on the user's current location, destination, and a list of locations to visit
void calculate_optimal_route(int num_locations, double* location_latitudes, double* location_longitudes, double current_latitude, double current_longitude, double dest_latitude, double dest_longitude) {
    // Initialize variables
    int route[MAX_LOCATIONS];
    double distances[MAX_LOCATIONS+1], total_distance = 0.0;

    // Calculate distances between current location and each location to visit
    for (int i = 0; i < num_locations; i++) {
        distances[i] = calculate_distance(current_latitude, current_longitude, location_latitudes[i], location_longitudes[i]);
        current_latitude = location_latitudes[i];
        current_longitude = location_longitudes[i];
    }

    // Calculate distance from last location to destination
    distances[num_locations] = calculate_distance(current_latitude, current_longitude, dest_latitude, dest_longitude);

    // Find optimal route by selecting the location with the shortest distance from the current location
    int current_location = -1;
    while (current_location != num_locations) {
        int next_location = -1;
        double shortest_distance = INFINITY;
        for (int i = 0; i <= num_locations; i++) {
            if (distances[i] < shortest_distance && i != current_location) {
                shortest_distance = distances[i];
                next_location = i;
            }
        }
        current_location = next_location;
        route[current_location] = 1; // Mark location as visited
        total_distance += shortest_distance;
    }

    // Print optimal route
    printf("Optimal route:\n");
    printf("Current location -> ");
    for (int i = 0; i < num_locations; i++) {
        if (route[i]) {
            printf("Location %d -> ", i+1);
        }
    }
    printf("Destination\n");
    printf("Total distance: %lf km", total_distance);
}