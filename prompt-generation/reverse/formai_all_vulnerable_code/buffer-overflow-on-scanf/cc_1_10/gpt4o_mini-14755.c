//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a location
typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

// Function to calculate distance between two coordinates
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    // Haversine formula to calculate distance
    const double R = 6371.0; // Radius of the Earth in km
    double dLat = (lat2 - lat1) * (3.141592653589793 / 180.0);
    double dLon = (lon2 - lon1) * (3.141592653589793 / 180.0);
    lat1 = lat1 * (3.141592653589793 / 180.0);
    lat2 = lat2 * (3.141592653589793 / 180.0);

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c; // Distance in km
}

// Function to display menu options
void displayMenu() {
    printf("----- GPS Navigation System -----\n");
    printf("1. Add Location\n");
    printf("2. Calculate Distance\n");
    printf("3. Exit\n");
}

// Function to add a new location
void addLocation(Location *locations, int *count) {
    if (*count >= 10) {
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
    printf("Location added successfully!\n");
}

// Function to calculate distance between two locations
void calculateDistanceBetweenLocations(Location *locations, int count) {
    char name1[50], name2[50];
    printf("Enter first location name: ");
    scanf("%s", name1);
    printf("Enter second location name: ");
    scanf("%s", name2);

    Location loc1, loc2;
    int found1 = 0, found2 = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(locations[i].name, name1) == 0) {
            loc1 = locations[i];
            found1 = 1;
        }
        if (strcmp(locations[i].name, name2) == 0) {
            loc2 = locations[i];
            found2 = 1;
        }
    }

    if (found1 && found2) {
        double distance = calculateDistance(loc1.latitude, loc1.longitude, loc2.latitude, loc2.longitude);
        printf("Distance between %s and %s: %.2f km\n", loc1.name, loc2.name, distance);
    } else {
        if (!found1) printf("Location '%s' not found!\n", name1);
        if (!found2) printf("Location '%s' not found!\n", name2);
    }
}

int main() {
    Location locations[10]; // Array to store up to 10 locations
    int count = 0; // Count of added locations
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addLocation(locations, &count);
                break;
            case 2:
                calculateDistanceBetweenLocations(locations, count);
                break;
            case 3:
                printf("Exiting GPS Navigation System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}