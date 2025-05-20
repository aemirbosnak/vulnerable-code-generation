//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// This structure holds GPS coordinate data
typedef struct {
    double latitude;
    double longitude;
} Coordinate;

// Function prototypes
void print_intro();
void get_current_location(Coordinate *my_location);
void calculate_distance(Coordinate source, Coordinate destination, double *distance);
void display_route(Coordinate destination, double distance);

int main() {
    print_intro();

    Coordinate my_location;
    get_current_location(&my_location);

    Coordinate destination;
    printf("Enter destination latitude: ");
    scanf("%lf", &destination.latitude);
    printf("Enter destination longitude: ");
    scanf("%lf", &destination.longitude);

    double distance;
    calculate_distance(my_location, destination, &distance);
    display_route(destination, distance);

    return 0;
}

// Function to print introduction and instructions
void print_intro() {
    printf("****************************************\n");
    printf("* Welcome to the C GPS Navigation App! *\n");
    printf("****************************************\n");
    printf("* This program will help you navigate   *\n");
    printf("* from your current location to your    *\n");
    printf("* destination based on GPS coordinates. *\n");
    printf("****************************************\n");
}

// Function to mock getting current location
void get_current_location(Coordinate *my_location) {
    // For simplicity, we will use fixed coordinates
    my_location->latitude = 37.7749;   // San Francisco
    my_location->longitude = -122.4194; // San Francisco
    printf("Current location: Latitude: %.4f, Longitude: %.4f\n", my_location->latitude, my_location->longitude);
}

// Function to calculate distance using Haversine formula
void calculate_distance(Coordinate source, Coordinate destination, double *distance) {
    double earth_radius = 6371.0; // Earth radius in kilometers
    double d_lat = (destination.latitude - source.latitude) * M_PI / 180.0;
    double d_lon = (destination.longitude - source.longitude) * M_PI / 180.0;

    double a = sin(d_lat / 2) * sin(d_lat / 2) +
               cos(source.latitude * M_PI / 180.0) * cos(destination.latitude * M_PI / 180.0) *
               sin(d_lon / 2) * sin(d_lon / 2);
    
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    *distance = earth_radius * c; // Distance in kilometers
}

// Function to display the route and distance
void display_route(Coordinate destination, double distance) {
    printf("Calculating route...\n");
    printf("Destination coordinates: Latitude: %.4f, Longitude: %.4f\n", 
            destination.latitude, destination.longitude);
    printf("Distance to destination: %.2f km\n", distance);
    
    if (distance < 1.0) {
        printf("You have arrived at your destination!\n");
    } else {
        printf("Safe travels! Follow the road signs to your destination.\n");
    }
}