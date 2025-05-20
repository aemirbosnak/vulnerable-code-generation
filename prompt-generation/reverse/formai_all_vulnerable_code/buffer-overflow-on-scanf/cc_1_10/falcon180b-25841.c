//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char city[20];
    int x;
    int y;
} Location;

int main() {
    int numLocations;
    Location locations[100];

    // Read in number of locations
    printf("Enter number of locations: ");
    scanf("%d", &numLocations);

    // Read in location information
    for (int i = 0; i < numLocations; i++) {
        printf("Enter location %d: ", i+1);
        scanf("%s %d %d", locations[i].city, &(locations[i].x), &(locations[i].y));
    }

    // Prompt user for starting location
    printf("Enter starting location: ");
    char startCity[20];
    scanf("%s", startCity);

    // Search for starting location
    Location* start = NULL;
    for (int i = 0; i < numLocations; i++) {
        if (strcmp(locations[i].city, startCity) == 0) {
            start = &(locations[i]);
            break;
        }
    }

    if (start == NULL) {
        printf("Starting location not found.\n");
        return 1;
    }

    // Prompt user for destination
    printf("Enter destination: ");
    char destCity[20];
    scanf("%s", destCity);

    // Search for destination
    Location* dest = NULL;
    for (int i = 0; i < numLocations; i++) {
        if (strcmp(locations[i].city, destCity) == 0) {
            dest = &(locations[i]);
            break;
        }
    }

    if (dest == NULL) {
        printf("Destination not found.\n");
        return 1;
    }

    // Calculate distance between starting and destination locations
    int distance = abs(start->x - dest->x) + abs(start->y - dest->y);

    // Calculate estimated travel time based on distance
    float travelTime = (float)distance / 50;

    // Display estimated travel time
    printf("Estimated travel time: %.2f hours\n", travelTime);

    return 0;
}