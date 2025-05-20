//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: careful
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

void printDirections(Location start, Location destination) {
    printf("Starting navigation from: %s (%.2f, %.2f)\n", start.name, start.latitude, start.longitude);
    printf("Navigating to: %s (%.2f, %.2f)\n", destination.name, destination.latitude, destination.longitude);
    printf("Estimated route:\n");

    printf("1. Head %s for approximately %.2f km.\n", (destination.latitude > start.latitude) ? "North" : "South", fabs(destination.latitude - start.latitude) * 111);
    printf("2. Turn %s at the next intersection.\n", (destination.longitude > start.longitude) ? "East" : "West");
    printf("3. Continue until you reach %s.\n", destination.name);
    printf("You have reached your destination: %s\n", destination.name);
}

int main() {
    Location locations[MAX_LOCATIONS];
    int locationCount = 0;
    char choice[5];

    // Sample locations
    strcpy(locations[0].name, "Home");
    locations[0].latitude = 37.7749;
    locations[0].longitude = -122.4194;

    strcpy(locations[1].name, "Office");
    locations[1].latitude = 37.7849;
    locations[1].longitude = -122.4094;

    strcpy(locations[2].name, "Park");
    locations[2].latitude = 37.7649;
    locations[2].longitude = -122.4294;

    strcpy(locations[3].name, "Mall");
    locations[3].latitude = 37.7549;
    locations[3].longitude = -122.4394;

    locationCount = 4;

    printf("Welcome to Simple GPS Navigation Simulation!\n");

    while (1) {
        printf("\nAvailable locations:\n");
        for (int i = 0; i < locationCount; i++) {
            printf("%d. %s\n", i + 1, locations[i].name);
        }

        int startIdx, destIdx;
        printf("Select starting location (1-%d): ", locationCount);
        scanf("%d", &startIdx);
        printf("Select destination location (1-%d): ", locationCount);
        scanf("%d", &destIdx);

        if (startIdx < 1 || startIdx > locationCount || destIdx < 1 || destIdx > locationCount) {
            printf("Invalid selection! Please try again.\n");
            continue;
        }

        Location startLocation = locations[startIdx - 1];
        Location destinationLocation = locations[destIdx - 1];

        printDirections(startLocation, destinationLocation);

        printf("Do you want to navigate again? (yes/no): ");
        scanf("%s", choice);
        if (strcmp(choice, "no") == 0) {
            break;
        }
    }

    printf("Thank you for using the GPS Navigation Simulation!\n");
    return 0;
}