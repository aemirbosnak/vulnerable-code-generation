//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROUTES 10
#define MAX_WAYPOINTS 50

typedef struct {
    double lat;
    double lon;
} waypoint_t;

typedef struct {
    char name[50];
    waypoint_t waypoints[MAX_WAYPOINTS];
    int num_waypoints;
} route_t;

typedef struct {
    char name[50];
    waypoint_t current_location;
    route_t *current_route;
    int current_waypoint_index;
} vehicle_t;

int read_routes(route_t *routes, int max_routes);
int read_waypoints(FILE *file, waypoint_t *waypoints, int max_waypoints);
double distance_between(waypoint_t p1, waypoint_t p2);
int navigate_to_next_waypoint(vehicle_t *vehicle);
void print_vehicle_status(vehicle_t vehicle);

int main(int argc, char *argv[]) {
    route_t routes[MAX_ROUTES];
    int num_routes = read_routes(routes, MAX_ROUTES);

    if (num_routes == 0) {
        fprintf(stderr, "No routes found!\n");
        exit(EXIT_FAILURE);
    }

    vehicle_t vehicle;

    // Set default vehicle state
    strcpy(vehicle.name, "My Vehicle");
    vehicle.current_location.lat = 0.0;
    vehicle.current_location.lon = 0.0;
    vehicle.current_route = &routes[0];
    vehicle.current_waypoint_index = 0;

    int result = navigate_to_next_waypoint(&vehicle);

    while (result == 0) {
        print_vehicle_status(vehicle);
        result = navigate_to_next_waypoint(&vehicle);
    }

    if (result == 1) {
        printf("You have reached your destination!\n");
    } else {
        printf("Error navigating to next waypoint!\n");
    }

    return 0;
}

int read_routes(route_t *routes, int max_routes) {
    int num_routes = 0;

    FILE *file = fopen("routes.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening routes file!\n");
        return 0;
    }

    while (!feof(file) && num_routes < max_routes) {
        route_t route;
        int result = fscanf(file, "%49s", route.name);

        if (result != 1) {
            continue;
        }

        route.num_waypoints = read_waypoints(file, route.waypoints, MAX_WAYPOINTS);

        if (route.num_waypoints > 1) {
            routes[num_routes++] = route;
        }
    }

    fclose(file);

    return num_routes;
}

int read_waypoints(FILE *file, waypoint_t *waypoints, int max_waypoints) {
    int num_waypoints = 0;

    while (!feof(file) && num_waypoints < max_waypoints) {
        int result = fscanf(file, "%lf %lf", &waypoints[num_waypoints].lat, &waypoints[num_waypoints].lon);

        if (result == 2) {
            num_waypoints++;
        } else {
            break;
        }
    }

    return num_waypoints;
}

double distance_between(waypoint_t p1, waypoint_t p2) {
    double R = 6371e3; // metres
    double phi1 = p1.lat * (M_PI / 180);
    double phi2 = p2.lat * (M_PI / 180);
    double delta_phi = (p2.lat - p1.lat) * (M_PI / 180);
    double delta_lambda = (p2.lon - p1.lon) * (M_PI / 180);

    double a = sin(delta_phi / 2) * sin(delta_phi / 2) +
              cos(phi1) * cos(phi2) *
              sin(delta_lambda / 2) * sin(delta_lambda / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = R * c;

    return distance;
}

int navigate_to_next_waypoint(vehicle_t *vehicle) {
    route_t *route = vehicle->current_route;
    waypoint_t *current_waypoint = &route->waypoints[vehicle->current_waypoint_index];
    int next_waypoint_index = vehicle->current_waypoint_index + 1;

    if (next_waypoint_index >= route->num_waypoints) {
        return 1; // reached destination
    }

    waypoint_t *next_waypoint = &route->waypoints[next_waypoint_index];

    double distance = distance_between(vehicle->current_location, *next_waypoint);

    if (distance <= 10.0) { // within 10 meters of next waypoint
        vehicle->current_location = *next_waypoint;
        vehicle->current_waypoint_index = next_waypoint_index;
    } else {
        double bearing = atan2(next_waypoint->lon - current_waypoint->lon, next_waypoint->lat - current_waypoint->lat) * (180 / M_PI);
        printf("Bearing: %lf\n", bearing);
        printf("Distance to next waypoint: %lf meters\n", distance);
        printf("Vehicle is currently at: (%lf, %lf)\n", vehicle->current_location.lat, vehicle->current_location.lon);

        double delta_lat = sin(bearing * (M_PI / 180)) * (distance / 6371e3);
        double delta_lon = cos((vehicle->current_location.lat) * (M_PI / 180)) * cos((bearing) * (M_PI / 180)) * (distance / 6371e3);

        double new_lat = vehicle->current_location.lat + (delta_lat * (180 / M_PI));
        double new_lon = vehicle->current_location.lon + (delta_lon * (180 / M_PI));

        vehicle->current_location.lat = new_lat;
        vehicle->current_location.lon = new_lon;
    }

    return 0; // success
}

void print_vehicle_status(vehicle_t vehicle) {
    printf("-------------\n");
    printf("Vehicle Name: %s\n", vehicle.name);
    printf("Current Location: (%lf, %lf)\n", vehicle.current_location.lat, vehicle.current_location.lon);
    printf("Waypoint: %d of %d\n", vehicle.current_waypoint_index + 1, vehicle.current_route->num_waypoints);
    printf("Current Route: %s\n", vehicle.current_route->name);
    printf("-------------\n");
}