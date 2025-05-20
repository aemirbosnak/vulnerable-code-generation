//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float latitude;
    float longitude;
} Location;

Location locations[MAX_LOCATIONS];
int locationCount = 0;

void addLocation(char *name, float latitude, float longitude) {
    if (locationCount >= MAX_LOCATIONS) {
        printf("Whoa! Location limit reached!\n");
        return;
    }
    strncpy(locations[locationCount].name, name, MAX_NAME_LENGTH);
    locations[locationCount].latitude = latitude;
    locations[locationCount].longitude = longitude;
    locationCount++;
    printf("🎉 Added location: %s\n", name);
}

void listLocations() {
    if (locationCount == 0) {
        printf("📍 No locations tracked yet!\n");
        return;
    }
    printf("🌍 Locations available:\n");
    for (int i = 0; i < locationCount; i++) {
        printf("%d: %s (Lat: %.6f, Long: %.6f)\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

float calculateDistance(Location *loc1, Location *loc2) {
    // Simple formula for distance, not accurate but serves the purpose for this simulation
    return sqrt(pow(loc2->latitude - loc1->latitude, 2) + pow(loc2->longitude - loc1->longitude, 2));
}

void navigate(char *startName, char *endName) {
    Location *start = NULL;
    Location *end = NULL;

    for (int i = 0; i < locationCount; i++) {
        if (strcmp(startName, locations[i].name) == 0) {
            start = &locations[i];
        }
        if (strcmp(endName, locations[i].name) == 0) {
            end = &locations[i];
        }
    }

    if (!start || !end) {
        printf("🚫 One or more locations not found! Make sure to add them first!\n");
        return;
    }

    float distance = calculateDistance(start, end);
    printf("🚗 Navigating from %s to %s...\n", start->name, end->name);
    printf("🗺️ Distance: %.2f units (not real-world accurate)\n", distance);
    printf("🎶 Playing navigation sounds... 🎶\n");
    printf("You have arrived at %s! 🎉\n", end->name);
}

int main() {
    int choice;
    float lat, lon;
    char name[MAX_NAME_LENGTH];
    char start[MAX_NAME_LENGTH], end[MAX_NAME_LENGTH];

    printf("Welcome to the GPS Navigation Simulation! 🎉\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add location\n");
        printf("2. List locations\n");
        printf("3. Navigate\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter location name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove trailing newline
                printf("Enter latitude: ");
                scanf("%f", &lat);
                printf("Enter longitude: ");
                scanf("%f", &lon);
                addLocation(name, lat, lon);
                break;
            case 2:
                listLocations();
                break;
            case 3:
                printf("Enter start location: ");
                fgets(start, MAX_NAME_LENGTH, stdin);
                start[strcspn(start, "\n")] = 0; // remove trailing newline
                printf("Enter end location: ");
                fgets(end, MAX_NAME_LENGTH, stdin);
                end[strcspn(end, "\n")] = 0; // remove trailing newline
                navigate(start, end);
                break;
            case 4:
                printf("🌟 Thank you for using GPS Navigation Simulation! Safe travels! 🌟\n");
                exit(0);
            default:
                printf("🚫 Invalid option! Please try again.\n");
        }
    }
    return 0;
}