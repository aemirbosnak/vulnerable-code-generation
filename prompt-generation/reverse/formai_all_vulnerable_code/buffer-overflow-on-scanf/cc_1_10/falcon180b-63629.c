//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371

struct point {
    double latitude;
    double longitude;
};

struct point get_current_location() {
    struct point current_location;
    current_location.latitude = rand() % 90 + 1; // randomly generate a latitude between 1 and 90 degrees
    current_location.longitude = rand() % 180 + 1; // randomly generate a longitude between 1 and 180 degrees
    return current_location;
}

double distance(struct point p1, struct point p2) {
    double d_lat = p2.latitude - p1.latitude;
    double d_lon = p2.longitude - p1.longitude;
    double a = sin(d_lat / 2) * sin(d_lat / 2) + cos(p1.latitude * PI / 180) * cos(p2.latitude * PI / 180) * sin(d_lon / 2) * sin(d_lon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

int main() {
    srand(time(NULL));
    struct point current_location = get_current_location();
    printf("Your current location: %f degrees latitude, %f degrees longitude\n", current_location.latitude, current_location.longitude);

    int choice;
    while (1) {
        printf("Enter your destination:\n");
        printf("1. North\n");
        printf("2. South\n");
        printf("3. East\n");
        printf("4. West\n");
        scanf("%d", &choice);

        struct point destination;
        switch (choice) {
            case 1:
                destination.latitude = current_location.latitude + 1;
                destination.longitude = current_location.longitude;
                break;
            case 2:
                destination.latitude = current_location.latitude - 1;
                destination.longitude = current_location.longitude;
                break;
            case 3:
                destination.latitude = current_location.latitude;
                destination.longitude = current_location.longitude + 1;
                break;
            case 4:
                destination.latitude = current_location.latitude;
                destination.longitude = current_location.longitude - 1;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        double distance_to_destination = distance(current_location, destination);
        printf("The distance to your destination is %.2f kilometers.\n", distance_to_destination);
    }

    return 0;
}