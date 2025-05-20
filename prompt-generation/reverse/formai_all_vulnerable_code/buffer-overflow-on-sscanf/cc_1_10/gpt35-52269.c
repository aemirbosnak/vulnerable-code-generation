//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants
#define MAX_LOCATIONS 100
#define MAX_NAME_LEN 50

// Structures
struct Location {
    char name[MAX_NAME_LEN];
    double latitude;
    double longitude;
};

// Prototypes
void load_locations(struct Location locations[], int *num_locations);
void get_destination(char destination[]);
double calculate_distance(double lat1, double long1, double lat2, double long2);

int main() {

    // Declare variables
    struct Location locations[MAX_LOCATIONS];
    int num_locations = 0;
    char destination[MAX_NAME_LEN];
    double current_latitude = 0.0;
    double current_longitude = 0.0;
    double total_distance = 0.0;

    // Load locations from file
    load_locations(locations, &num_locations);

    // Get destination from user
    get_destination(destination);

    // Search for destination in locations
    int found = 0;
    double dest_latitude = 0.0;
    double dest_longitude = 0.0;
    for (int i = 0; i < num_locations; i++) {
        if (strcmp(locations[i].name, destination) == 0) {
            found = 1;
            dest_latitude = locations[i].latitude;
            dest_longitude = locations[i].longitude;
            break;
        }
    }

    // Print error message if destination not found
    if (!found) {
        printf("Destination not found\n");
        return 1;
    }

    // Set current location to starting location
    current_latitude = locations[0].latitude;
    current_longitude = locations[0].longitude;

    // Calculate distance to destination
    total_distance = calculate_distance(current_latitude, current_longitude, dest_latitude, dest_longitude);

    // Print navigation instructions
    printf("Starting at %s\n", locations[0].name);
    printf("Heading towards %s\n", destination);
    printf("Total distance: %.2lf km\n", total_distance);

    return 0;
}

// Load locations from file
void load_locations(struct Location locations[], int *num_locations) {
    FILE *f = fopen("locations.txt", "r");
    if (f == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, f) != NULL) {
        sscanf(line, "%lf,%lf,%[^\n]", &locations[*num_locations].latitude, &locations[*num_locations].longitude, locations[*num_locations].name);
        (*num_locations)++;
    }

    fclose(f);
}

// Get destination from user
void get_destination(char destination[]) {
    printf("Enter destination: ");
    fgets(destination, MAX_NAME_LEN, stdin);
    destination[strlen(destination) - 1] = '\0'; // Remove newline character
}

// Calculate distance between two points on earth
double calculate_distance(double lat1, double long1, double lat2, double long2) {
    const double R = 6371; // radius of earth in km
    double lat1_rad = M_PI * lat1 / 180;
    double long1_rad = M_PI * long1 / 180;
    double lat2_rad = M_PI * lat2 / 180;
    double long2_rad = M_PI * long2 / 180;

    double dlat = lat2_rad - lat1_rad;
    double dlong = long2_rad - long1_rad;

    double a = pow(sin(dlat/2), 2) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(dlong/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c;
}