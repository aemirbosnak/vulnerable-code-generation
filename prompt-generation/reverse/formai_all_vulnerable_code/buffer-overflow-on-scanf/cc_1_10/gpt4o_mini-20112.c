//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#define MAX_LOCATIONS 100
#define MAX_NAME_LENGTH 30
#define EARTH_RADIUS 6371.0 // Earth radius in kilometers

typedef struct {
    char name[MAX_NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

Location locations[MAX_LOCATIONS];
int location_count = 0;

void add_location(const char *name, double latitude, double longitude) {
    if (location_count < MAX_LOCATIONS) {
        strncpy(locations[location_count].name, name, MAX_NAME_LENGTH);
        locations[location_count].latitude = latitude;
        locations[location_count].longitude = longitude;
        location_count++;
    } else {
        printf("Location limit reached!\n");
    }
}

double to_radians(double degree) {
    return degree * (M_PI / 180.0);
}

double calculate_distance(Location a, Location b) {
    double lat1 = to_radians(a.latitude);
    double lat2 = to_radians(b.latitude);
    double lon1 = to_radians(a.longitude);
    double lon2 = to_radians(b.longitude);
    
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    
    double a_value = sin(dlat / 2) * sin(dlat / 2) +
                     cos(lat1) * cos(lat2) *
                     sin(dlon / 2) * sin(dlon / 2);
                     
    double c = 2 * atan2(sqrt(a_value), sqrt(1 - a_value));
    return EARTH_RADIUS * c;
}

void find_nearest_location(double latitude, double longitude) {
    Location user_location = {"User", latitude, longitude};
    double nearest_distance = -1;
    Location nearest_location;

    for (int i = 0; i < location_count; i++) {
        double distance = calculate_distance(user_location, locations[i]);
        
        if (nearest_distance < 0 || distance < nearest_distance) {
            nearest_distance = distance;
            nearest_location = locations[i];
        }
    }

    if (nearest_distance >= 0) {
        printf("Nearest Location: %s, Distance: %.2f km\n", 
               nearest_location.name, nearest_distance);
    } else {
        printf("No locations available.\n");
    }
}

void display_locations() {
    printf("Saved Locations:\n");
    for (int i = 0; i < location_count; i++) {
        printf("%d: %s (Lat: %.6f, Lon: %.6f)\n", 
               i + 1, locations[i].name, 
               locations[i].latitude, locations[i].longitude);
    }
}

int main() {
    int choice;
    double latitude, longitude;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\nGPS Navigation Simulation\n");
        printf("1. Add Location\n");
        printf("2. Display Locations\n");
        printf("3. Find Nearest Location\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter location name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%lf", &latitude);
                printf("Enter longitude: ");
                scanf("%lf", &longitude);
                add_location(name, latitude, longitude);
                break;
            case 2:
                display_locations();
                break;
            case 3:
                printf("Enter your latitude: ");
                scanf("%lf", &latitude);
                printf("Enter your longitude: ");
                scanf("%lf", &longitude);
                find_nearest_location(latitude, longitude);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        sleep(1); // To slow down the loop slightly for readability
    }
    return 0;
}