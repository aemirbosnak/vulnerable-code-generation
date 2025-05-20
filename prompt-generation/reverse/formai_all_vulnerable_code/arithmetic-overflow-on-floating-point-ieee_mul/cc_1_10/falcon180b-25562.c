//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

typedef struct {
    double latitude;
    double longitude;
} Coordinate;

Coordinate get_current_position() {
    Coordinate current_pos;
    printf("Enter your current latitude: ");
    scanf("%lf", &current_pos.latitude);
    printf("Enter your current longitude: ");
    scanf("%lf", &current_pos.longitude);
    return current_pos;
}

Coordinate get_destination() {
    Coordinate destination;
    printf("Enter your destination latitude: ");
    scanf("%lf", &destination.latitude);
    printf("Enter your destination longitude: ");
    scanf("%lf", &destination.longitude);
    return destination;
}

double calculate_distance(Coordinate pos1, Coordinate pos2) {
    double dLat = pos2.latitude - pos1.latitude;
    double dLon = pos2.longitude - pos1.longitude;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(pos1.latitude) * cos(pos2.latitude) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void display_route(Coordinate current_pos, Coordinate destination) {
    double distance = calculate_distance(current_pos, destination);
    printf("The distance between your current position and your destination is %.2lf km.\n", distance);
    printf("Your route starts at (%.2lf, %.2lf) and ends at (%.2lf, %.2lf).\n", current_pos.latitude, current_pos.longitude, destination.latitude, destination.longitude);
}

int main() {
    srand(time(NULL));

    Coordinate current_pos = get_current_position();
    Coordinate destination = get_destination();

    display_route(current_pos, destination);

    return 0;
}