//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 10

typedef struct {
    char name[100];
    double latitude;
    double longitude;
} Location;

void print_locations(Location locations[], int count) {
    printf("Available Locations:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s (Lat: %.6f, Lon: %.6f)\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    // Simple Euclidean distance calculation for simulation purposes
    return sqrt((lat2 - lat1) * (lat2 - lat1) + (lon2 - lon1) * (lon2 - lon1));
}

void find_nearest_location(Location locations[], int count, double user_latitude, double user_longitude) {
    int nearest_index = -1;
    double min_distance = -1;

    for (int i = 0; i < count; i++) {
        double dist = distance(user_latitude, user_longitude, locations[i].latitude, locations[i].longitude);
        
        if (nearest_index == -1 || dist < min_distance) {
            min_distance = dist;
            nearest_index = i;
        }
    }

    if (nearest_index != -1) {
        printf("Nearest Location: %s (Lat: %.6f, Lon: %.6f) at a distance of %.6f\n", 
               locations[nearest_index].name, 
               locations[nearest_index].latitude, 
               locations[nearest_index].longitude, 
               min_distance);
    }
}

int main() {
    Location locations[MAX_LOCATIONS] = {
        {"Park", 34.0522, -118.2437},
        {"Museum", 34.0622, -118.2537},
        {"Restaurant", 34.0722, -118.2637},
        {"Library", 34.0822, -118.2737},
        {"Mall", 34.0922, -118.2837},
        {"Airport", 33.9425, -118.4083},
        {"School", 34.0625, -118.2875},
        {"Theater", 34.0575, -118.2515},
        {"Hospital", 34.0450, -118.2490},
        {"Cafe", 34.0511, -118.2446}
    };

    double user_latitude, user_longitude;

    printf("GPS Navigation Simulation\n");
    print_locations(locations, MAX_LOCATIONS);
    
    printf("Enter your current latitude: ");
    scanf("%lf", &user_latitude);
    printf("Enter your current longitude: ");
    scanf("%lf", &user_longitude);

    find_nearest_location(locations, MAX_LOCATIONS, user_latitude, user_longitude);

    return 0;
}