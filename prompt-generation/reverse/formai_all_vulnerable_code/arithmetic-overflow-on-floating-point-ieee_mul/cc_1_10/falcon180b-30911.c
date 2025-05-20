//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0
#define DEG_TO_RAD (PI/180.0)
#define RAD_TO_DEG (180.0/PI)

typedef struct {
    double lat;
    double lon;
} Coordinate;

Coordinate get_user_position() {
    Coordinate user_pos;
    printf("Enter your current latitude and longitude (in decimal degrees):\n");
    scanf("%lf %lf", &user_pos.lat, &user_pos.lon);
    return user_pos;
}

Coordinate get_destination() {
    Coordinate destination;
    printf("Enter your destination latitude and longitude (in decimal degrees):\n");
    scanf("%lf %lf", &destination.lat, &destination.lon);
    return destination;
}

double calculate_distance(Coordinate pos1, Coordinate pos2) {
    double dlat = pos2.lat - pos1.lat;
    double dlon = pos2.lon - pos1.lon;
    double a = sin(dlat/2) * sin(dlat/2) + cos(pos1.lat*DEG_TO_RAD) * cos(pos2.lat*DEG_TO_RAD) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_RADIUS * c;
}

void print_directions(Coordinate current_pos, Coordinate destination) {
    double distance = calculate_distance(current_pos, destination);
    double bearing = atan2(destination.lon - current_pos.lon, destination.lat - current_pos.lat);
    printf("You are currently at (%.4lf, %.4lf)\n", RAD_TO_DEG*current_pos.lat, RAD_TO_DEG*current_pos.lon);
    printf("Your destination is at (%.4lf, %.4lf)\n", RAD_TO_DEG*destination.lat, RAD_TO_DEG*destination.lon);
    printf("The distance between you and your destination is %.2lf km\n", distance);
    printf("To reach your destination, head %.2lf degrees north\n", RAD_TO_DEG*bearing);
}

int main() {
    srand(time(NULL));
    Coordinate current_pos = get_user_position();
    Coordinate destination = get_destination();
    print_directions(current_pos, destination);
    return 0;
}