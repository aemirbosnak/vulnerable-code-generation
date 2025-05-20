//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define EARTH_RADIUS 6371.01
#define RADIANS_PER_DEGREE 0.017453292519943295

typedef struct {
    double latitude;
    double longitude;
} Coordinate;

Coordinate destination;

double distance(Coordinate c1, Coordinate c2) {
    double dLat = (c2.latitude - c1.latitude) * RADIANS_PER_DEGREE;
    double dLon = (c2.longitude - c1.longitude) * RADIANS_PER_DEGREE;

    double a = sin(dLat/2) * sin(dLat/2) + cos(c1.latitude * RADIANS_PER_DEGREE) * cos(c2.latitude * RADIANS_PER_DEGREE) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return EARTH_RADIUS * c;
}

int main() {
    printf("Holy smokes! Welcome to the world's most mind-boggling GPS Navigation Simulation!\n\n");

    printf("Buckle up, space cadet! Let's blast off with our coordinates:\n");
    printf("Latitude (in degrees): ");
    scanf("%lf", &destination.latitude);
    printf("Longitude (in degrees): ");
    scanf("%lf", &destination.longitude);

    printf("\nPrepare for warp speed, traveler! We're about to embark on an epic journey.\n");

    Coordinate current;
    current.latitude = 0.0;
    current.longitude = 0.0;

    double distanceToDestination;

    while (1) {
        distanceToDestination = distance(current, destination);

        if (distanceToDestination < 0.1) {
            printf("\nHoly guacamole! You've arrived at your destination!\n");
            break;
        }

        printf("\nCurrent location: (%.2f, %.2f)\n", current.latitude, current.longitude);
        printf("Distance to destination: %.2f kilometers\n", distanceToDestination);

        printf("\nPunch it, Scotty! Let's make some progress. Enter your next latitude and longitude (or 'q' to quit):\n");
        printf("Latitude: ");
        scanf("%lf", &current.latitude);
        if (current.latitude == 0.0) break;
        printf("Longitude: ");
        scanf("%lf", &current.longitude);
        if (current.longitude == 0.0) break;
    }

    printf("\nMission accomplished, Starfleet! You've navigated like a pro.\nMay your warp engines always hum with precision.\n");

    return 0;
}