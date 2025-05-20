//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371

typedef struct {
    double lat;
    double lon;
} Coord;

Coord current_pos;
Coord destination;

void init() {
    printf("Enter your current position (latitude, longitude): ");
    scanf("%lf %lf", &current_pos.lat, &current_pos.lon);

    printf("Enter your destination (latitude, longitude): ");
    scanf("%lf %lf", &destination.lat, &destination.lon);
}

void calculate_distance() {
    double dlat = destination.lat - current_pos.lat;
    double dlon = destination.lon - current_pos.lon;

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(current_pos.lat) * cos(destination.lat) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = EARTH_RADIUS * c;

    printf("The distance between your current position and destination is %.2lf km.\n", distance);
}

void simulate_gps() {
    time_t start_time, end_time;
    double total_time;

    printf("GPS Simulation:\n");
    printf("Starting GPS simulation...\n");

    time(&start_time);
    sleep(2);

    while (1) {
        time(&end_time);
        total_time = difftime(end_time, start_time);

        if (total_time >= 60) {
            calculate_distance();
            break;
        }

        printf("Simulating GPS signal...\n");
        sleep(1);
    }
}

int main() {
    init();
    simulate_gps();

    return 0;
}