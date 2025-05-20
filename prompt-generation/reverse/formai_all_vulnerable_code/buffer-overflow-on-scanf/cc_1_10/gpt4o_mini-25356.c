//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESTINATIONS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float latitude;
    float longitude;
} Destination;

typedef struct {
    Destination destinations[MAX_DESTINATIONS];
    int count;
    int currentDestinationIndex;
} GPSNavigator;

void initializeNavigator(GPSNavigator* navigator) {
    navigator->count = 0;
    navigator->currentDestinationIndex = -1;
}

void addDestination(GPSNavigator* navigator, const char* name, float lat, float lon) {
    if (navigator->count < MAX_DESTINATIONS) {
        strncpy(navigator->destinations[navigator->count].name, name, NAME_LENGTH);
        navigator->destinations[navigator->count].latitude = lat;
        navigator->destinations[navigator->count].longitude = lon;
        navigator->count++;
        printf("Destination '%s' added successfully.\n", name);
    } else {
        printf("Cannot add more destinations. Limit reached.\n");
    }
}

void setCurrentDestination(GPSNavigator* navigator, int index) {
    if (index >= 0 && index < navigator->count) {
        navigator->currentDestinationIndex = index;
        printf("Current destination set to: %s\n", navigator->destinations[index].name);
    } else {
        printf("Invalid destination index.\n");
    }
}

void printDestinations(GPSNavigator* navigator) {
    printf("Available Destinations:\n");
    for (int i = 0; i < navigator->count; i++) {
        printf("%d: %s (Lat: %.6f, Lon: %.6f)\n", i, navigator->destinations[i].name,
               navigator->destinations[i].latitude, navigator->destinations[i].longitude);
    }
}

void navigate(GPSNavigator* navigator) {
    if (navigator->currentDestinationIndex != -1) {
        printf("Navigating to %s...\n", navigator->destinations[navigator->currentDestinationIndex].name);
        // Here we can implement more complex navigation logic.
        printf("Arrived at %s!\n", navigator->destinations[navigator->currentDestinationIndex].name);
    } else {
        printf("No destination selected. Please select a destination first.\n");
    }
}

void clearNavigator(GPSNavigator* navigator) {
    initializeNavigator(navigator);
    printf("All destinations cleared.\n");
}

int main() {
    GPSNavigator navigator;
    initializeNavigator(&navigator);
    int choice, index;
    char name[NAME_LENGTH];
    float lat, lon;

    while (1) {
        printf("\nGPS Navigation System\n");
        printf("1. Add Destination\n");
        printf("2. List Destinations\n");
        printf("3. Set Current Destination\n");
        printf("4. Navigate to Current Destination\n");
        printf("5. Clear All Destinations\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter destination name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%f", &lat);
                printf("Enter longitude: ");
                scanf("%f", &lon);
                addDestination(&navigator, name, lat, lon);
                break;
            case 2:
                printDestinations(&navigator);
                break;
            case 3:
                printf("Select destination index: ");
                scanf("%d", &index);
                setCurrentDestination(&navigator, index);
                break;
            case 4:
                navigate(&navigator);
                break;
            case 5:
                clearNavigator(&navigator);
                break;
            case 6:
                printf("Exiting GPS Navigation System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}