//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    double latitude;
    double longitude;
} Location;

Location* createLocation(char* name, double latitude, double longitude) {
    Location* loc = (Location*)malloc(sizeof(Location));
    loc->name = strdup(name);
    loc->latitude = latitude;
    loc->longitude = longitude;
    return loc;
}

void printLocation(Location* loc) {
    printf("Name: %s\n", loc->name);
    printf("Latitude: %lf\n", loc->latitude);
    printf("Longitude: %lf\n", loc->longitude);
}

int main() {
    Location* home = createLocation("Home", 37.7749, -122.4194);
    Location* work = createLocation("Work", 37.7749, -122.4194);
    Location* groceryStore = createLocation("Grocery Store", 37.7749, -122.4194);

    printf("Welcome to the GPS Navigation System!\n");
    printf("Please select your destination:\n");
    printf("1. Home\n");
    printf("2. Work\n");
    printf("3. Grocery Store\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Navigating to Home...\n");
            break;
        case 2:
            printf("Navigating to Work...\n");
            break;
        case 3:
            printf("Navigating to Grocery Store...\n");
            break;
        default:
            printf("Invalid destination.\n");
            return 1;
    }

    return 0;
}