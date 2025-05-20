//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOCATIONS 100
#define MIN_DISTANCE 100

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

void generateRandomLocation(Location* location) {
    srand(time(NULL));
    location->latitude = rand() % 90 + 1;
    location->longitude = rand() % 180 + 1;
}

int main() {
    // Initialize locations
    Location locations[MAX_LOCATIONS];
    int numLocations = 0;

    // Add some initial locations
    generateRandomLocation(&locations[numLocations++]);
    generateRandomLocation(&locations[numLocations++]);

    // Simulate GPS navigation
    double userLatitude = locations[0].latitude;
    double userLongitude = locations[0].longitude;

    while (1) {
        printf("Current location: %.2f, %.2f\n", userLatitude, userLongitude);
        printf("Nearby locations:\n");

        int numNearbyLocations = 0;
        for (int i = 0; i < numLocations; i++) {
            double distance = hypot(userLatitude - locations[i].latitude, userLongitude - locations[i].longitude);
            if (distance < MIN_DISTANCE) {
                printf("- %s\n", locations[i].name);
                numNearbyLocations++;
            }
        }

        if (numNearbyLocations == 0) {
            printf("No nearby locations found.\n");
        }

        char choice;
        printf("Enter your choice (n/s/e/w/q): ");
        scanf("%c", &choice);

        switch (choice) {
            case 'n':
                userLatitude += 0.0001;
                break;
            case's':
                userLatitude -= 0.0001;
                break;
            case 'e':
                userLongitude += 0.0001;
                break;
            case 'w':
                userLongitude -= 0.0001;
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}