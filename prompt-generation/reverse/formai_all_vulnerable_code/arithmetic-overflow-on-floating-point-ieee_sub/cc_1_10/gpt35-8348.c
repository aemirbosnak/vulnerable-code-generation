//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <string.h>

#define MAX_LOCATIONS 50
#define MAX_STEPS 100

// Define a structure for storing a GPS location
typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

// Define a structure for storing a set of GPS locations and the steps between them
typedef struct {
    Location locations[MAX_LOCATIONS];
    int num_locations;
    int steps[MAX_STEPS];
    int num_steps;
} Route;

// Function to add a new location to the route
void add_location(Route *route, char* name, double latitude, double longitude) {
    Location new_location;
    strcpy(new_location.name, name);
    new_location.latitude = latitude;
    new_location.longitude = longitude;
    route->locations[route->num_locations] = new_location;
    route->num_locations++;
}

// Function to add a new step to the route
void add_step(Route *route, int steps) {
    route->steps[route->num_steps] = steps;
    route->num_steps++;
}

// Function to get the distance between two locations
double distance(Location loc1, Location loc2) {
    double lat_dist = (loc2.latitude - loc1.latitude) * 69;
    double long_dist = (loc2.longitude - loc1.longitude) * 69;
    return sqrt(lat_dist * lat_dist + long_dist * long_dist);
}

// Function to get the total distance of the route
double total_distance(Route route) {
    double total = 0;
    for (int i = 1; i < route.num_locations; i++) {
        total += distance(route.locations[i-1], route.locations[i]);
    }
    return total;
}

// Function to print the route instructions
void print_instructions(Route route) {
    printf("INSTRUCTIONS:\n");
    for (int i = 0; i < route.num_steps; i++) {
        printf("%d. Go %d steps from %s to %s\n", i+1, route.steps[i], route.locations[i].name, route.locations[i+1].name);
    }
}

// Example usage
int main() {
    Route my_route;
    my_route.num_locations = 0;
    my_route.num_steps = 0;
    
    // Add some locations to the route
    add_location(&my_route, "Start", 42.35641, -71.05778);
    add_location(&my_route, "Park", 42.35872, -71.06795);
    add_location(&my_route, "Museum", 42.35816, -71.06460);
    add_location(&my_route, "End", 42.35522, -71.06256);
    
    // Add some steps to the route
    add_step(&my_route, 200);
    add_step(&my_route, 500);
    add_step(&my_route, 400);
    
    // Print the total distance of the route and the route instructions
    printf("TOTAL DISTANCE: %.2f miles\n", total_distance(my_route));
    print_instructions(my_route);
    
    return 0;
}