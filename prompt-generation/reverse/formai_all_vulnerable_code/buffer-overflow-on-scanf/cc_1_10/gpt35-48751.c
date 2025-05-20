//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOCATIONS 100
#define MAX_NAME_LENGTH 50

// Function to generate a random GPS Coordinate
void generateGPS(int *latitude, int *longitude) {
    *latitude = rand() % 180 - 90;
    *longitude = rand() % 360 - 180;
}

// Structure to hold location information
struct location {
    char name[MAX_NAME_LENGTH];
    int latitude;
    int longitude;
} locations[MAX_LOCATIONS];

int main() {
    srand((unsigned)time(NULL)); // Seed the random number generator

    int numLocations, currentLocation, destination, choice;

    // Get the number of locations from the user
    printf("Enter the number of locations: ");
    scanf("%d", &numLocations);

    // Get information for each location
    for (int i = 0; i < numLocations; i++) {
        // Get the name
        printf("Enter name for Location %d: ", i + 1);
        scanf(" %[^\n]%*c", locations[i].name);

        // Generate a random GPS coordinate
        generateGPS(&locations[i].latitude, &locations[i].longitude);
    }

    // Display the list of locations
    printf("\nLocation List:\n");
    for (int i = 0; i < numLocations; i++) {
        printf("%d. %s: (%d,%d)\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }

    // Get the starting location from the user
    printf("\nEnter your current location (1-%d): ", numLocations);
    scanf("%d", &currentLocation);
    printf("You are currently at %s.\n", locations[currentLocation - 1].name);

    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Enter destination\n");
        printf("2. Get directions\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enter destination
                printf("\nEnter destination (1-%d): ", numLocations);
                scanf("%d", &destination);
                printf("Destination set to %s.\n", locations[destination - 1].name);
                break;
            case 2: // Get directions
                if (destination == 0) {
                    printf("\nError: Destination has not been set.\n");
                } else {
                    // Calculate the distance and bearing to the destination
                    int distance = rand() % 5000 + 1000;
                    double bearing = (rand() % 360) / 180.0 * 3.14159265358979323846;

                    // Calculate the new GPS coordinate
                    double latitude = locations[currentLocation - 1].latitude + distance * cos(bearing);
                    double longitude = locations[currentLocation - 1].longitude + distance * sin(bearing);

                    // Find the closest location to the new GPS coordinate
                    double closestDistance = 1000000000.0;
                    int closestLocation = -1;
                    for (int i = 0; i < numLocations; i++) {
                        double d = sqrt((latitude - locations[i].latitude) * (latitude - locations[i].latitude)
                            + (longitude - locations[i].longitude) * (longitude - locations[i].longitude));
                        if (d < closestDistance) {
                            closestDistance = d;
                            closestLocation = i;
                        }
                    }

                    // Display the directions
                    printf("\nDirections to %s:\n", locations[destination - 1].name);
                    printf("1. Start at %s.\n", locations[currentLocation - 1].name);
                    if (closestLocation == destination - 1) {
                        printf("2. You have arrived at %s.\n", locations[destination - 1].name);
                    } else {
                        printf("2. Go to %s (%d,%d).\n", locations[closestLocation].name, locations[closestLocation].latitude, locations[closestLocation].longitude);
                        printf("3. Follow the road to %s.\n", locations[destination - 1].name);
                        printf("4. You have arrived at %s.\n", locations[destination - 1].name);
                    }

                    // Update the current location
                    currentLocation = closestLocation + 1;
                }
                break;
            case 3: // Exit
                printf("\nThank you for using the GPS Navigation Simulation!\n");
                break;
            default: // Invalid choice
                printf("\nError: Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}