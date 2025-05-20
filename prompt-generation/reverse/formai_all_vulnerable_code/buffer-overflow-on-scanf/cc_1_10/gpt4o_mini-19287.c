//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float latitude;
    float longitude;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int count;
} GPSNavigator;

void add_location(GPSNavigator *gps, const char *name, float latitude, float longitude) {
    if (gps->count < MAX_LOCATIONS) {
        strncpy(gps->locations[gps->count].name, name, MAX_NAME_LENGTH);
        gps->locations[gps->count].latitude = latitude;
        gps->locations[gps->count].longitude = longitude;
        gps->count++;
        printf("Location '%s' added successfully!\n", name);
    } else {
        printf("Oops! Maximum location limit reached!\n");
    }
}

void show_locations(const GPSNavigator *gps) {
    if (gps->count == 0) {
        printf("No locations to display! Looks like we need to add some!\n");
        return;
    }
    printf("Here are your saved locations:\n");
    for (int i = 0; i < gps->count; i++) {
        printf("%d: %s (Lat: %.6f, Long: %.6f)\n", i + 1, gps->locations[i].name, gps->locations[i].latitude, gps->locations[i].longitude);
    }
}

void calculate_distance(float lat1, float lon1, float lat2, float lon2, float *distance) {
    // Haversine formula to calculate distance between two points on the Earth
    const float R = 6371; // Radius of the Earth in kilometers
    float dlat = (lat2 - lat1) * (3.14159 / 180.0);
    float dlon = (lon2 - lon1) * (3.14159 / 180.0);
    
    float a = sin(dlat / 2) * sin(dlat / 2) +
              cos(lat1 * (3.14159 / 180.0)) * cos(lat2 * (3.14159 / 180.0)) *
              sin(dlon / 2) * sin(dlon / 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    *distance = R * c;
}

void navigate(const GPSNavigator *gps) {
    if (gps->count < 2) {
        printf("Whoa! We need at least two locations to navigate!\n");
        return;
    }
    
    int start_index, end_index;
    printf("Please select the start location (1 to %d): ", gps->count);
    scanf("%d", &start_index);
    printf("Please select the destination location (1 to %d): ", gps->count);
    scanf("%d", &end_index);

    if (start_index < 1 || start_index > gps->count || end_index < 1 || end_index > gps->count) {
        printf("Yikes! Invalid selection. Please try again!\n");
        return;
    }

    float distance;
    calculate_distance(gps->locations[start_index - 1].latitude, gps->locations[start_index - 1].longitude,
                      gps->locations[end_index - 1].latitude, gps->locations[end_index - 1].longitude, &distance);
    
    printf("Navigating from %s to %s...\n", gps->locations[start_index - 1].name, gps->locations[end_index - 1].name);
    printf("Whoa! The distance is approximately %.2f km!\n", distance);
    printf("Let's go!\n");
}

int main() {
    GPSNavigator gps = {0};
    int choice;

    do {
        printf("\nGPS Navigation Simulator\n");
        printf("1. Add Location\n");
        printf("2. Show Locations\n");
        printf("3. Navigate\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                float latitude, longitude;

                printf("Enter location name: ");
                scanf(" %[^\n]", name);
                printf("Enter latitude: ");
                scanf("%f", &latitude);
                printf("Enter longitude: ");
                scanf("%f", &longitude);
                
                add_location(&gps, name, latitude, longitude);
                break;
            }
            case 2:
                show_locations(&gps);
                break;
            case 3:
                navigate(&gps);
                break;
            case 4:
                printf("Exiting... Adios, navigator!\n");
                break;
            default:
                printf("Wait, what? Invalid choice! Try again!\n");
        }
    } while (choice != 4);

    return 0;
}