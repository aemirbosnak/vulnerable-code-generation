//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 10

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} location_t;

location_t locations[MAX_LOCATIONS] = {
    {"New York City", 40.7127, -74.0059},
    {"Los Angeles", 34.0522, -118.2437},
    {"Chicago", 41.8781, -87.6298},
    {"Houston", 29.7604, -95.3698},
    {"Phoenix", 33.4484, -112.0740},
    {"San Antonio", 29.4241, -98.4936},
    {"San Diego", 32.7157, -117.1611},
    {"Dallas", 32.7767, -96.7970},
    {"San Jose", 37.3382, -121.8863},
    {"Austin", 30.2672, -97.7431}
};

int main() {
    char input[50];
    int i;
    double latitude, longitude;

    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("Enter a location: ");
    scanf("%s", input);

    for (i = 0; i < MAX_LOCATIONS; i++) {
        if (strcmp(input, locations[i].name) == 0) {
            latitude = locations[i].latitude;
            longitude = locations[i].longitude;
            break;
        }
    }

    if (i == MAX_LOCATIONS) {
        printf("Location not found.\n");
        return 1;
    }

    printf("Latitude: %.6f\n", latitude);
    printf("Longitude: %.6f\n", longitude);

    return 0;
}