//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOCATIONS 100
#define EARTH_RADIUS 6371.0 // Earth's radius in kilometers

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

Location locations[MAX_LOCATIONS];
int location_count = 0;

void addLocation(const char *name, double lat, double lon) {
    if (location_count < MAX_LOCATIONS) {
        strncpy(locations[location_count].name, name, sizeof(locations[location_count].name) - 1);
        locations[location_count].latitude = lat;
        locations[location_count].longitude = lon;
        location_count++;
    } else {
        printf("Location limit reached. Cannot add more locations.\n");
    }
}

double toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);
    lat1 = toRadians(lat1);
    lat2 = toRadians(lat2);

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c; // returns distance in kilometers
}

void displayLocations() {
    printf("Saved Locations:\n");
    for (int i = 0; i < location_count; i++) {
        printf("%d: %s (Lat: %.6f, Lon: %.6f)\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
    printf("\n");
}

void findNearestLocation(double currentLat, double currentLon) {
    if (location_count == 0) {
        printf("No locations to compare to.\n");
        return;
    }
    
    double min_distance = -1.0;
    int nearest_index = -1;

    for (int i = 0; i < location_count; i++) {
        double distance = calculateDistance(currentLat, currentLon, locations[i].latitude, locations[i].longitude);
        if (min_distance < 0 || distance < min_distance) {
            min_distance = distance;
            nearest_index = i;
        }
    }
    
    printf("Nearest Location: %s, Distance: %.2f km\n", locations[nearest_index].name, min_distance);
}

int main() {
    int choice;
    double currentLat, currentLon;

    while (1) {
        printf("GPS Navigation Simulation\n");
        printf("1. Add Location\n");
        printf("2. Display Locations\n");
        printf("3. Find Nearest Location\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    char name[50];
                    double lat, lon;
                    printf("Enter location name: ");
                    scanf("%s", name);
                    printf("Enter latitude: ");
                    scanf("%lf", &lat);
                    printf("Enter longitude: ");
                    scanf("%lf", &lon);
                    addLocation(name, lat, lon);
                }
                break;
            case 2:
                displayLocations();
                break;
            case 3:
                printf("Enter current latitude: ");
                scanf("%lf", &currentLat);
                printf("Enter current longitude: ");
                scanf("%lf", &currentLon);
                findNearestLocation(currentLat, currentLon);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}