//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

// Structure to hold coordinates
typedef struct {
    double latitude;
    double longitude;
} Coordinates;

// Structure for waypoints
typedef struct {
    char name[50];
    Coordinates coords;
} Waypoint;

// Function to calculate distance between two coordinates (Haversine formula)
double calculate_distance(Coordinates pos1, Coordinates pos2) {
    const double R = 6371.0; // Earth's radius in km
    double lat1_rad = pos1.latitude * M_PI / 180.0;
    double lat2_rad = pos2.latitude * M_PI / 180.0;
    double delta_lat = (pos2.latitude - pos1.latitude) * M_PI / 180.0;
    double delta_lon = (pos2.longitude - pos1.longitude) * M_PI / 180.0;

    double a = sin(delta_lat / 2) * sin(delta_lat / 2) +
               cos(lat1_rad) * cos(lat2_rad) *
               sin(delta_lon / 2) * sin(delta_lon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c; // Distance in kilometers
}

// Function to simulate navigation
void navigate(Waypoint waypoints[], int count, Coordinates current_pos) {
    printf("Initiating navigation...\n");
    for (int i = 0; i < count; i++) {
        printf("Heading to %s at (%.6f, %.6f)\n", waypoints[i].name, 
               waypoints[i].coords.latitude, waypoints[i].coords.longitude);
        double distance = calculate_distance(current_pos, waypoints[i].coords);
        printf("Distance to %s: %.2f km\n", waypoints[i].name, distance);

        // Simulate travel
        for (int j = 0; j < 5; ++j) {
            printf("Traveling to %s...\n", waypoints[i].name);
            sleep(1);
        }
        
        // Update current position to next waypoint
        current_pos = waypoints[i].coords;
        printf("Arrived at %s!\n\n", waypoints[i].name);
    }
    printf("Navigation complete!\n");
}

// Function to display the menu and manage user input
void display_menu() {
    printf("Futuristic GPS Navigation System\n");
    printf("===================================\n");
    printf("1. Initialize Waypoints\n");
    printf("2. Start Navigation\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int choice;
    Coordinates current_pos = {37.7749, -122.4194}; // Starting point: San Francisco, CA
    Waypoint waypoints[3] = {
        {"Point A", {34.0522, -118.2437}}, // Los Angeles, CA
        {"Point B", {36.1699, -115.1398}}, // Las Vegas, NV
        {"Point C", {40.7128, -74.0060}}   // New York, NY
    };

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Waypoints initialized!\n");
                break;
            case 2:
                navigate(waypoints, 3, current_pos);
                break;
            case 3:
                printf("Exiting the navigation system. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }
    
    return 0;
}