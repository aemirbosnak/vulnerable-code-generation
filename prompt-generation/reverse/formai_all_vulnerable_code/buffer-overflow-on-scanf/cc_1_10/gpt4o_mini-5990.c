//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_LOCATIONS 100
#define EARTH_RADIUS 6371.0 // in kilometers

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int count;
} LocationList;

void add_location(LocationList *list, const char *name, double latitude, double longitude) {
    if (list->count < MAX_LOCATIONS) {
        strncpy(list->locations[list->count].name, name, sizeof(list->locations[list->count].name) - 1);
        list->locations[list->count].latitude = latitude;
        list->locations[list->count].longitude = longitude;
        list->count++;
    } else {
        printf("Location list is full!\n");
    }
}

double to_radians(double degree) {
    return degree * (M_PI / 180.0);
}

double calculate_distance(Location loc1, Location loc2) {
    double lat1 = to_radians(loc1.latitude);
    double lat2 = to_radians(loc2.latitude);
    double diff_lat = to_radians(loc2.latitude - loc1.latitude);
    double diff_lon = to_radians(loc2.longitude - loc1.longitude);

    double a = sin(diff_lat / 2) * sin(diff_lat / 2) +
               cos(lat1) * cos(lat2) *
               sin(diff_lon / 2) * sin(diff_lon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c; // Distance in kilometers
}

void find_nearby_locations(LocationList *list, Location current_location, double radius) {
    printf("Nearby locations within %.2f km of %s:\n", radius, current_location.name);
    for (int i = 0; i < list->count; i++) {
        double distance = calculate_distance(current_location, list->locations[i]);
        if (distance <= radius) {
            printf("  - %s: %.2f km away\n", list->locations[i].name, distance);
        }
    }
}

void display_menu() {
    printf("\nGPS Navigation Simulation:\n");
    printf("1. Add Location\n");
    printf("2. Find Nearby Locations\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void clear_input_buffer() {
    while (getchar() != '\n');
}

int main() {
    LocationList location_list = {.count = 0};
    int choice;
    char name[50];
    double latitude, longitude, search_radius;

    while (true) {
        display_menu();
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:  // Add Location
                printf("Enter location name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character

                printf("Enter latitude: ");
                scanf("%lf", &latitude);
                
                printf("Enter longitude: ");
                scanf("%lf", &longitude);

                add_location(&location_list, name, latitude, longitude);
                printf("Location '%s' added successfully!\n", name);
                break;

            case 2:  // Find Nearby Locations
                printf("Enter your current location name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character

                printf("Enter your current latitude: ");
                scanf("%lf", &latitude);
                
                printf("Enter your current longitude: ");
                scanf("%lf", &longitude);

                Location current_location;
                strncpy(current_location.name, name, sizeof(current_location.name) - 1);
                current_location.latitude = latitude;
                current_location.longitude = longitude;

                printf("Enter search radius in km: ");
                scanf("%lf", &search_radius);

                find_nearby_locations(&location_list, current_location, search_radius);
                break;

            case 3: // Exit
                printf("Exiting the simulation. Safe travels!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}