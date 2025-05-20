//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define GPS coordinate structure
struct Coordinate {
    double lat;
    double lon;
};

// Define location structure
struct Location {
    char name[100];
    struct Coordinate coord;
};

// Define a function to calculate distance between two coordinates
double distance(struct Coordinate c1, struct Coordinate c2) {
    double a = (c1.lat - c2.lat) * (c1.lat - c2.lat);
    double b = (c1.lon - c2.lon) * (c1.lon - c2.lon);
    return sqrt(a + b);
}

int main() {
    // Define the case
    printf("Welcome to Sherlock Holmes GPS Navigation Simulation\n");
    printf("You are presented with a case of a missing person. The last known location of the person is recorded as 36.2405N, 115.2719W\n");
    printf("Your task is to identify the location of the person and navigate to it.\n");

    // Define the locations
    struct Location locations[3];
    strcpy(locations[0].name, "The Library");
    locations[0].coord.lat = 36.2409;
    locations[0].coord.lon = -115.2332;
    strcpy(locations[1].name, "The Park");
    locations[1].coord.lat = 36.2381;
    locations[1].coord.lon = -115.2656;
    strcpy(locations[2].name, "The Museum");
    locations[2].coord.lat = 36.1721;
    locations[2].coord.lon = -115.1437;

    // Define initial GPS coordinate
    struct Coordinate currentLoc = {36.1700, -115.1400};

    // Navigate to the location
    int i, locFound = 0;
    for (i = 0; i < 3; i++) {
        double dist = distance(currentLoc, locations[i].coord);
        printf("You are %lf kilometers away from %s. Do you want to navigate to this location? (y/n) ", dist, locations[i].name);
        char ans[10];
        scanf("%s", ans);
        if (strcmp(ans, "y") == 0) {
            locFound = 1;
            currentLoc = locations[i].coord;
            printf("Navigating to %s...\n", locations[i].name);
            break;
        }
    }

    // Check if the location was found
    if (locFound) {
        printf("Congratulations! You have successfully navigated to the location of the missing person.\n");
    } else {
        printf("Sorry, you were not able to identify the location of the missing person.\n");
    }

    return 0;
}