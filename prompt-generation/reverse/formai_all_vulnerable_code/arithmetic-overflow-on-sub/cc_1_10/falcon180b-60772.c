//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371

// Function prototypes
double haversine(double lat1, double lon1, double lat2, double lon2);
void generate_random_route(int num_points);
void print_route(double* route, int num_points);

int main() {
    int num_points;
    double* route;

    // Get number of points for the route from user input
    printf("Enter the number of points for the route: ");
    scanf("%d", &num_points);

    // Allocate memory for the route
    route = (double*)malloc(num_points * sizeof(double));

    // Generate random route
    generate_random_route(num_points);

    // Print the generated route
    printf("Generated route:\n");
    print_route(route, num_points);

    // Free memory allocated for the route
    free(route);

    return 0;
}

// Function to calculate the distance between two points on Earth using the Haversine formula
double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_RADIUS * c;
}

// Function to generate a random route with the specified number of points
void generate_random_route(int num_points) {
    double* route = (double*)malloc(num_points * sizeof(double));
    srand(time(NULL));

    for (int i = 0; i < num_points; i++) {
        double lat = rand() % 180 - 90;
        double lon = rand() % 360 - 180;
        route[i] = haversine(0, 0, lat, lon);
    }

    // Set the first and last points to be the same to create a closed loop
    route[0] = route[num_points-1];
}

// Function to print the generated route
void print_route(double* route, int num_points) {
    for (int i = 0; i < num_points; i++) {
        printf("%.2f ", route[i]);
    }
    printf("\n");
}