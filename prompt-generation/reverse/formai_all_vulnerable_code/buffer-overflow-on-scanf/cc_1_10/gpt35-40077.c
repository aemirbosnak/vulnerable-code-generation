//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOCATIONS 100 // Maximum number of locations that can be added to the GPS
#define RADIUS_OF_EARTH 6371 // Radius of Earth in km

// Struct to store location coordinates
struct Location {
    char name[20];
    double lat;
    double lon;
};

// Function to calculate distance between two points using Haversine formula
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = (lat2 - lat1) * M_PI / 180;
    double dlon = (lon2 - lon1) * M_PI / 180;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return RADIUS_OF_EARTH * c;
}

int main() {
    struct Location locations[MAX_LOCATIONS]; // Array to store all added locations
    int numLocations = 0; // Keeps track of number of locations added
    int choice; // Choice variable for user menu
    int i, j; // Iteration variables for loops

    do {
        printf("GPS Navigation Simulation\n");
        printf("1. Add location\n");
        printf("2. View all locations\n");
        printf("3. Navigate from current location\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numLocations < MAX_LOCATIONS) {
                    printf("Enter location name: ");
                    scanf("%s", locations[numLocations].name);
                    printf("Enter latitude: ");
                    scanf("%lf", &locations[numLocations].lat);
                    printf("Enter longitude: ");
                    scanf("%lf", &locations[numLocations].lon);
                    numLocations++;
                    printf("Location added successfully!\n");
                } else {
                    printf("Maximum locations have already been added!\n");
                }
                break;
            case 2:
                if (numLocations > 0) {
                    printf("List of all locations:\n");
                    for (i = 0; i < numLocations; i++) {
                        printf("%d. %s (%lf, %lf)\n", i+1, locations[i].name, locations[i].lat, locations[i].lon);
                    }
                } else {
                    printf("No locations have been added!\n");
                }
                break;
            case 3:
                if (numLocations > 0) {
                    double currLat, currLon;
                    printf("Enter your current latitude: ");
                    scanf("%lf", &currLat);
                    printf("Enter your current longitude: ");
                    scanf("%lf", &currLon);
                    double closestDistance = calculateDistance(currLat, currLon, locations[0].lat, locations[0].lon);
                    int closestIndex = 0;
                    for (i = 1; i < numLocations; i++) {
                        double distance = calculateDistance(currLat, currLon, locations[i].lat, locations[i].lon);
                        if (distance < closestDistance) {
                            closestDistance = distance;
                            closestIndex = i;
                        }
                    }
                    printf("Closest location to you is: %s (%lf km away)\n", locations[closestIndex].name, closestDistance);
                } else {
                    printf("No locations have been added!\n");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
        printf("\n");

    } while (choice != 4);

    return 0;
}