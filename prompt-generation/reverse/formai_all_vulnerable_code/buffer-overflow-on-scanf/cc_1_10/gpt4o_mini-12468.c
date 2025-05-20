//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining max number of locations
#define MAX_LOCATIONS 100

// Struct to hold location data
typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

// Function to calculate the distance between two coordinates
double haversine(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0; // Radius of the Earth in km
    double dlat = (lat2 - lat1) * (3.14159265358979323846 / 180.0);
    double dlon = (lon2 - lon1) * (3.14159265358979323846 / 180.0);
  
    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1 * (3.14159265358979323846 / 180.0)) *
               cos(lat2 * (3.14159265358979323846 / 180.0)) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  
    return R * c; // Distance in kilometers
}

// Function to add a location
void add_location(Location *locations, int *count) {
    if (*count >= MAX_LOCATIONS) {
        printf("Location list is full!\n");
        return;
    }
    
    printf("Enter location name: ");
    scanf("%s", locations[*count].name);
    printf("Enter latitude: ");
    scanf("%lf", &locations[*count].latitude);
    printf("Enter longitude: ");
    scanf("%lf", &locations[*count].longitude);
    
    (*count)++;
    printf("Location added successfully.\n");
}

// Function to display all locations
void display_locations(Location *locations, int count) {
    printf("\nList of Locations:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s (%.6f, %.6f)\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

// Function to find the nearest location from the current position
void find_nearest(Location *locations, int count, double current_lat, double current_lon) {
    if (count == 0) {
        printf("No locations to compare with!\n");
        return;
    }

    double min_distance = -1;
    int nearest_index = -1;

    for (int i = 0; i < count; i++) {
        double distance = haversine(current_lat, current_lon, locations[i].latitude, locations[i].longitude);
        if (min_distance == -1 || distance < min_distance) {
            min_distance = distance;
            nearest_index = i;
        }
    }

    if (nearest_index != -1) {
        printf("Nearest location: %s, Distance: %.2f km\n", 
               locations[nearest_index].name, min_distance);
    }
}

// Main function
int main() {
    Location locations[MAX_LOCATIONS];
    int count = 0;
    int choice;
    double current_lat, current_lon;

    printf("Welcome to the GPS Navigation Simulation!\n");
    
    // Input current location
    printf("Enter your current latitude: ");
    scanf("%lf", &current_lat);
    printf("Enter your current longitude: ");
    scanf("%lf", &current_lon);
    
    do {
        printf("\nMenu:\n");
        printf("1. Add Location\n");
        printf("2. Display Locations\n");
        printf("3. Find Nearest Location\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_location(locations, &count);
                break;
            case 2:
                display_locations(locations, count);
                break;
            case 3:
                find_nearest(locations, count, current_lat, current_lon);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}