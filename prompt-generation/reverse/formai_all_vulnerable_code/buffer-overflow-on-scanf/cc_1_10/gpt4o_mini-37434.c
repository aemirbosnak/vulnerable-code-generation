//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOCATIONS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

Location locations[MAX_LOCATIONS];
int location_count = 0;

void add_location(const char* name, double lat, double lon) {
    if (location_count < MAX_LOCATIONS) {
        strncpy(locations[location_count].name, name, NAME_LENGTH);
        locations[location_count].latitude = lat;
        locations[location_count].longitude = lon;
        location_count++;
    } else {
        printf("Location limit reached!\n");
    }
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    double R = 6371.0; // Radius of Earth in kilometers
    double dlat = (lat2 - lat1) * M_PI / 180.0;
    double dlon = (lon2 - lon1) * M_PI / 180.0;
    
    double a = sin(dlat / 2) * sin(dlat / 2) + 
               cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) * 
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return R * c; // Distance in kilometers
}

void find_nearest(double lat, double lon) {
    double min_distance = -1;
    int nearest_index = -1;

    for (int i = 0; i < location_count; i++) {
        double distance = haversine(lat, lon, locations[i].latitude, locations[i].longitude);
        if (min_distance < 0 || distance < min_distance) {
            min_distance = distance;
            nearest_index = i;
        }
    }

    if (nearest_index >= 0) {
        printf("Nearest Location: %s, Distance: %.2f km\n", 
               locations[nearest_index].name, min_distance);
    } else {
        printf("No locations available.\n");
    }
}

void show_locations() {
    if (location_count == 0) {
        printf("No locations stored.\n");
        return;
    }
    printf("Stored Locations:\n");
    for (int i = 0; i < location_count; i++) {
        printf("%d) %s (Lat: %.6f, Lon: %.6f)\n", 
               i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    double lat, lon;

    while (1) {
        printf("\n=== GPS Navigation Simulation ===\n");
        printf("1. Add Location\n");
        printf("2. Show Locations\n");
        printf("3. Find Nearest Location\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter location name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%lf", &lat);
                printf("Enter longitude: ");
                scanf("%lf", &lon);
                add_location(name, lat, lon);
                break;

            case 2:
                show_locations();
                break;

            case 3:
                printf("Enter your current latitude: ");
                scanf("%lf", &lat);
                printf("Enter your current longitude: ");
                scanf("%lf", &lon);
                find_nearest(lat, lon);
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}