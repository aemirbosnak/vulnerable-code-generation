//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_POINTS 100
#define EARTH_RADIUS 6371.0 // in kilometers

typedef struct {
    double latitude;
    double longitude;
    char name[50];
} Location;

Location locations[MAX_POINTS];
int location_count = 0;

void add_location(double latitude, double longitude, const char *name) {
    if (location_count < MAX_POINTS) {
        locations[location_count].latitude = latitude;
        locations[location_count].longitude = longitude;
        strncpy(locations[location_count].name, name, sizeof(locations[location_count].name) - 1);
        locations[location_count].name[sizeof(locations[location_count].name) - 1] = '\0'; // Ensure null-termination
        location_count++;
        printf("Location '%s' added!\n", name);
    } else {
        printf("Location array is full. Cannot add more locations.\n");
    }
}

double to_radians(double degree) {
    return degree * (M_PI / 180.0);
}

double haversine_distance(Location loc1, Location loc2) {
    double lat1_rad = to_radians(loc1.latitude);
    double lat2_rad = to_radians(loc2.latitude);
    double delta_lat_rad = to_radians(loc2.latitude - loc1.latitude);
    double delta_lon_rad = to_radians(loc2.longitude - loc1.longitude);

    double a = sin(delta_lat_rad / 2) * sin(delta_lat_rad / 2) +
               cos(lat1_rad) * cos(lat2_rad) *
               sin(delta_lon_rad / 2) * sin(delta_lon_rad / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c; // Distance in kilometers
}

void find_nearest_location(double user_lat, double user_lon) {
    Location nearest;
    double min_distance = INFINITY;

    for (int i = 0; i < location_count; i++) {
        double distance = haversine_distance(locations[i], (Location){user_lat, user_lon});
        if (distance < min_distance) {
            min_distance = distance;
            nearest = locations[i];
        }
    }

    if (min_distance < INFINITY) {
        printf("Nearest location is '%s' at a distance of %.2f km.\n", nearest.name, min_distance);
    } else {
        printf("No locations found.\n");
    }
}

void display_locations() {
    printf("Stored locations:\n");
    for (int i = 0; i < location_count; i++) {
        printf("%d: %s (%.6f, %.6f)\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

int main() {
    while (1) {
        int choice;
        printf("\nGPS Navigation Simulation\n");
        printf("1. Add Location\n");
        printf("2. Find Nearest Location\n");
        printf("3. Display All Locations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            double lat, lon;
            char name[50];
            printf("Enter latitude: ");
            scanf("%lf", &lat);
            printf("Enter longitude: ");
            scanf("%lf", &lon);
            printf("Enter location name: ");
            scanf("%s", name);
            add_location(lat, lon, name);
        } else if (choice == 2) {
            double user_lat, user_lon;
            printf("Enter your latitude: ");
            scanf("%lf", &user_lat);
            printf("Enter your longitude: ");
            scanf("%lf", &user_lon);
            find_nearest_location(user_lat, user_lon);
        } else if (choice == 3) {
            display_locations();
        } else if (choice == 4) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}