//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

struct coordinate {
    double latitude;
    double longitude;
};

struct coordinate get_current_location() {
    struct coordinate current_location;
    current_location.latitude = rand() % 90 + 1;
    current_location.longitude = rand() % 180 + 1;
    return current_location;
}

double distance(struct coordinate location1, struct coordinate location2) {
    double dlat = location2.latitude - location1.latitude;
    double dlon = location2.longitude - location1.longitude;
    double a = sin(dlat/2) * sin(dlat/2) + cos(location1.latitude*PI/180) * cos(location2.latitude*PI/180) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS * c;
    return distance;
}

int main() {
    struct coordinate current_location = get_current_location();
    printf("Your current location is: Latitude: %lf, Longitude: %lf\n", current_location.latitude, current_location.longitude);

    char destination[20];
    printf("Enter your destination: ");
    scanf("%s", destination);

    struct coordinate destination_location = {0, 0};
    if(strcmp(destination, "North") == 0) {
        destination_location.latitude = current_location.latitude + 1;
    } else if(strcmp(destination, "South") == 0) {
        destination_location.latitude = current_location.latitude - 1;
    } else if(strcmp(destination, "East") == 0) {
        destination_location.longitude = current_location.longitude + 1;
    } else if(strcmp(destination, "West") == 0) {
        destination_location.longitude = current_location.longitude - 1;
    } else {
        printf("Invalid destination!\n");
        return 0;
    }

    double distance_to_destination = distance(current_location, destination_location);
    printf("The distance to your destination is: %lf\n", distance_to_destination);

    return 0;
}