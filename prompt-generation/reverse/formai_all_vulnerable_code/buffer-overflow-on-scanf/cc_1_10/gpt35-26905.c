//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // setting the seed for random number generation
    
    int distance = rand() % 1000; // generating a random distance between 0 and 999 km
    double lat = rand() % 181 - 90; // generating a random latitude between -90 and 90 degrees
    double lon = rand() % 361 - 180; // generating a random longitude between -180 and 180 degrees
    
    printf("You need to travel %d kilometers to reach your destination.\n", distance);
    printf("Your current location is (%lf, %lf).\n", lat, lon);
    
    double dest_lat, dest_lon;
    printf("Please enter the latitude and longitude of your destination, separated by a space:");
    scanf("%lf %lf", &dest_lat, &dest_lon);
    printf("Destination set to (%lf, %lf).\n", dest_lat, dest_lon);
    
    double dist_lat = lat - dest_lat;
    double dist_lon = lon - dest_lon;
    double dist = sqrt(dist_lat * dist_lat + dist_lon * dist_lon); // calculating the straight-line distance between current location and destination
    
    if (dist > distance) {
        printf("You are currently %lf kilometers away from your destination. Unfortunately, there is no direct path to your destination.\n", dist);
        return 0;
    }
    
    double remaining_distance = distance - dist; // calculating the remaining distance to travel
    printf("You are currently %lf kilometers away from your destination. You have %lf kilometers to go.\n", dist, remaining_distance);
    
    while (remaining_distance > 0) {
        double lat_step = (dest_lat - lat) / remaining_distance; // calculating the latitude step size
        double lon_step = (dest_lon - lon) / remaining_distance; // calculating the longitude step size
        
        double new_lat = lat + lat_step; // calculating the new latitude
        double new_lon = lon + lon_step; // calculating the new longitude
        
        printf("You have traveled to (%lf, %lf).\n", new_lat, new_lon);
        
        double dist_to_dest_lat = new_lat - dest_lat;
        double dist_to_dest_lon = new_lon - dest_lon;
        double dist_to_dest = sqrt(dist_to_dest_lat * dist_to_dest_lat + dist_to_dest_lon * dist_to_dest_lon); // calculating distance to destination
        
        remaining_distance = remaining_distance - dist_to_dest; // updating the remaining distance
        
        if (remaining_distance <= 0) {
            printf("You have reached your destination!\n");
            return 0;
        }
        
        lat = new_lat; // updating the latitude
        lon = new_lon; // updating the longitude
        
        printf("You have %lf kilometers to go.\n", remaining_distance);
    }
    
    return 0;
}