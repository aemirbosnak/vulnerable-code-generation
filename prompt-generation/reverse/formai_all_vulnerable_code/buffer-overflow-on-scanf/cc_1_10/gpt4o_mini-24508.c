//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESTINATIONS 10
#define MAX_NAME_LENGTH 50
#define MAX_COORDINATES_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char coordinates[MAX_COORDINATES_LENGTH];
} Destination;

typedef struct {
    Destination destinations[MAX_DESTINATIONS];
    int count;
} NavigationSystem;

void initNavigationSystem(NavigationSystem *nav) {
    nav->count = 0;
}

void addDestination(NavigationSystem *nav, const char *name, const char *coords) {
    if (nav->count < MAX_DESTINATIONS) {
        strncpy(nav->destinations[nav->count].name, name, MAX_NAME_LENGTH);
        strncpy(nav->destinations[nav->count].coordinates, coords, MAX_COORDINATES_LENGTH);
        nav->count++;
        printf("Destination '%s' at coordinates %s added.\n", name, coords);
    } else {
        printf("Error: Maximum number of destinations reached.\n");
    }
}

void listDestinations(const NavigationSystem *nav) {
    if (nav->count == 0) {
        printf("No destinations available.\n");
        return;
    }
    printf("Available Destinations:\n");
    for (int i = 0; i < nav->count; i++) {
        printf("%d. %s - %s\n", i + 1, nav->destinations[i].name, nav->destinations[i].coordinates);
    }
}

void navigateToDestination(const NavigationSystem *nav, int index) {
    if (index < 0 || index >= nav->count) {
        printf("Error: Invalid destination index.\n");
        return;
    }
    printf("Navigating to %s located at %s...\n", nav->destinations[index].name, nav->destinations[index].coordinates);
}

int main() {
    NavigationSystem navSystem;
    initNavigationSystem(&navSystem);

    int choice, index;
    char name[MAX_NAME_LENGTH], coords[MAX_COORDINATES_LENGTH];

    do {
        printf("\nGPS Navigation Simulation\n");
        printf("1. Add Destination\n");
        printf("2. List Destinations\n");
        printf("3. Navigate to Destination\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter destination name: ");
                scanf("%s", name);
                printf("Enter destination coordinates: ");
                scanf("%s", coords);
                addDestination(&navSystem, name, coords);
                break;

            case 2:
                listDestinations(&navSystem);
                break;

            case 3:
                printf("Enter destination index to navigate (1-%d): ", navSystem.count);
                scanf("%d", &index);
                navigateToDestination(&navSystem, index - 1); // Adjust for 0-indexing
                break;

            case 4:
                printf("Exiting GPS Navigation Simulation.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}