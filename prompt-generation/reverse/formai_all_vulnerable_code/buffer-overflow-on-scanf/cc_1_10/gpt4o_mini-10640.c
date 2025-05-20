//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float latitude;
    float longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int count;
} Map;

void initialize_map(Map* map) {
    map->count = 0;
}

void add_location(Map* map, const char* name, float latitude, float longitude) {
    if (map->count < MAX_LOCATIONS) {
        strcpy(map->locations[map->count].name, name);
        map->locations[map->count].latitude = latitude;
        map->locations[map->count].longitude = longitude;
        map->count++;
    } else {
        printf("Cannot add more locations. Maximum limit reached.\n");
    }
}

void display_locations(const Map* map) {
    printf("Available Locations:\n");
    for (int i = 0; i < map->count; i++) {
        printf("%d: %s (Lat: %.2f, Long: %.2f)\n", i + 1, map->locations[i].name, map->locations[i].latitude, map->locations[i].longitude);
    }
}

void calculate_distance(float lat1, float lon1, float lat2, float lon2, float* distance) {
    // Using a simple Euclidean distance formula for demonstration purposes
    *distance = sqrt((lat2 - lat1) * (lat2 - lat1) + (lon2 - lon1) * (lon2 - lon1));
}

void navigate(const Map* map, int start_index, int end_index) {
    if (start_index < 0 || start_index >= map->count || end_index < 0 || end_index >= map->count) {
        printf("Invalid locations selected for navigation.\n");
        return;
    }

    float distance;
    calculate_distance(map->locations[start_index].latitude, map->locations[start_index].longitude,
                      map->locations[end_index].latitude, map->locations[end_index].longitude,
                      &distance);

    printf("Navigating from %s to %s...\n", map->locations[start_index].name, map->locations[end_index].name);
    printf("Distance: %.2f units.\n", distance);
}

int main() {
    Map map;
    initialize_map(&map);
    
    add_location(&map, "Home", 40.7128, -74.0060);
    add_location(&map, "Work", 40.7580, -73.9855);
    add_location(&map, "Park", 40.7851, -73.9683);
    
    int start_loc, end_loc;

    while (1) {
        display_locations(&map);
        printf("Select the starting location (1 to %d, 0 to exit): ", map.count);
        scanf("%d", &start_loc);
        
        if (start_loc == 0)
            break;

        printf("Select the ending location (1 to %d): ", map.count);
        scanf("%d", &end_loc);
        
        // Adjust for 0-based index
        navigate(&map, start_loc - 1, end_loc - 1);
    }
    
    printf("Exiting Navigation System...\n");
    return 0;
}