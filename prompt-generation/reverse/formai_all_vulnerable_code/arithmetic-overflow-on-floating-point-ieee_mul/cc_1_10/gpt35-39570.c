//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define R 6371 // Earth's radius in km

// Function to convert degree to radian
double deg2rad(double deg) {
    return (deg * PI / 180);
}

// Function to calculate the distance between two points
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat, dlon, a, c, d;
    dlat = deg2rad(lat2-lat1);
    dlon = deg2rad(lon2-lon1);
    a = sin(dlat/2) * sin(dlat/2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dlon/2) * sin(dlon/2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    d = R * c;
    return d;
}

int main() {
    double lat, lon, distance_travelled, total_distance = 0;
    char direction;
    
    // Start location
    printf("Enter starting location (latitude longitude): ");
    scanf("%lf %lf", &lat, &lon);
    
    // Navigation directions
    printf("Enter navigation directions (enter 'X' to exit):\n");
    printf("> ");
    scanf(" %c", &direction);
    while (direction != 'X') {
        double new_lat, new_lon;
        printf("> ");
        scanf(" %lf %lf", &new_lat, &new_lon);
        
        // Calculate distance travelled between two points
        distance_travelled = distance(lat, lon, new_lat, new_lon);
        total_distance += distance_travelled;
        
        printf("Distance travelled: %.2f km\n", distance_travelled);
        
        // Update current location
        lat = new_lat;
        lon = new_lon;
    }
    
    printf("Total distance travelled: %.2f km\n", total_distance);
    
    return 0;
}