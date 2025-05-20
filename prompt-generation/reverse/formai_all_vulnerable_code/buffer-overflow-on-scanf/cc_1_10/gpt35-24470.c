//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371000

// Function to convert degrees to radians
double deg2rad(double deg) {
    return deg * (PI / 180);
}

// Function to calculate the distance between two points on Earth
double distance(double lat1, double long1, double lat2, double long2) {
    double lat1_rad = deg2rad(lat1);
    double lat2_rad = deg2rad(lat2);
    double long1_rad = deg2rad(long1);
    double long2_rad = deg2rad(long2);
    
    double delta_lat = lat2_rad - lat1_rad;
    double delta_long = long2_rad - long1_rad;
    
    double a = pow(sin(delta_lat/2),2) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(delta_long/2),2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    
    double distance = EARTH_RADIUS * c;
    
    return distance;
}

int main() {
    printf("Welcome to GPS Navigation Simulation\n");
    printf("Please enter the starting location's latitude:");
    double start_lat;
    scanf("%lf", &start_lat);
    
    printf("Please enter the starting location's longitude:");
    double start_long;
    scanf("%lf", &start_long);
    
    printf("Please enter the destination location's latitude:");
    double dest_lat;
    scanf("%lf", &dest_lat);
    
    printf("Please enter the destination location's longitude:");
    double dest_long;
    scanf("%lf", &dest_long);
    
    double distance_km = distance(start_lat, start_long, dest_lat, dest_long) / 1000;
    printf("The distance between the starting location and destination is: %.2lf km\n", distance_km);
    
    printf("Please enter the driving speed in km/h:");
    int speed;
    scanf("%d", &speed);
    
    double time_h = distance_km / speed;
    int time_min = round(time_h * 60);
    printf("The estimated driving time is: %d minutes\n", time_min);
    
    bool want_nav = false;
    printf("Do you want the navigation directions?(True or False)");
    scanf("%d", &want_nav);
    
    if(want_nav) {
        printf("Starting Navigation Directions:\n");
        printf("Drive straight for %.2lf km\n", distance_km);
        printf("Turn left at the next intersection\n");
        printf("Drive straight for 500 meters and turn right at the next intersection\n");
        printf("Drive straight for 1.5 km and turn left at the next intersection\n");
        printf("Drive straight for 3 km and you have arrived at your destination!\n");
    }
    
    return 0;
}