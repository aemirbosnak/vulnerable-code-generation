//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 100
#define MAX_ROUTES 100

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

typedef struct {
    int num_locations;
    Location locations[MAX_LOCATIONS];
} Route;

int main() {
    // Initialize the GPS simulation
    int num_locations = 0;
    int num_routes = 0;
    Location locations[MAX_LOCATIONS];
    Route routes[MAX_ROUTES];

    // Load the locations from a file
    FILE *locations_file = fopen("locations.txt", "r");
    if (locations_file == NULL) {
        printf("Error opening locations file\n");
        return EXIT_FAILURE;
    }

    while (fscanf(locations_file, "%s %lf %lf", locations[num_locations].name, &locations[num_locations].latitude, &locations[num_locations].longitude) != EOF) {
        num_locations++;
    }

    fclose(locations_file);

    // Load the routes from a file
    FILE *routes_file = fopen("routes.txt", "r");
    if (routes_file == NULL) {
        printf("Error opening routes file\n");
        return EXIT_FAILURE;
    }

    while (fscanf(routes_file, "%d", &routes[num_routes].num_locations) != EOF) {
        for (int i = 0; i < routes[num_routes].num_locations; i++) {
            fscanf(routes_file, "%s", routes[num_routes].locations[i].name);
        }
        num_routes++;
    }

    fclose(routes_file);

    // Start the GPS simulation
    while (1) {
        // Get the user's current location
        char current_location[50];
        printf("Enter your current location: ");
        scanf("%s", current_location);

        // Find the closest location in the database
        int closest_location_index = -1;
        double closest_distance = -1;
        for (int i = 0; i < num_locations; i++) {
            double distance = sqrt(pow(locations[i].latitude - atof(current_location), 2) + pow(locations[i].longitude - atof(current_location), 2));
            if (distance < closest_distance || closest_distance == -1) {
                closest_distance = distance;
                closest_location_index = i;
            }
        }

        // Get the user's destination
        char destination[50];
        printf("Enter your destination: ");
        scanf("%s", destination);

        // Find the closest route to the destination
        int closest_route_index = -1;
        double closest_route_distance = -1;
        for (int i = 0; i < num_routes; i++) {
            double distance = 0;
            for (int j = 0; j < routes[i].num_locations; j++) {
                if (strcmp(routes[i].locations[j].name, destination) == 0) {
                    distance = sqrt(pow(routes[i].locations[j].latitude - atof(current_location), 2) + pow(routes[i].locations[j].longitude - atof(current_location), 2));
                    break;
                }
            }
            if (distance < closest_route_distance || closest_route_distance == -1) {
                closest_route_distance = distance;
                closest_route_index = i;
            }
        }

        // Get the directions to the destination
        char directions[1000];
        sprintf(directions, "From %s, head towards %s.\n", locations[closest_location_index].name, routes[closest_route_index].locations[0].name);
        for (int i = 1; i < routes[closest_route_index].num_locations; i++) {
            sprintf(directions, "%s Turn left onto %s.\n", directions, routes[closest_route_index].locations[i].name);
        }

        // Print the directions to the user
        printf("Directions to %s:\n\n%s\n", destination, directions);
    }

    return EXIT_SUCCESS;
}