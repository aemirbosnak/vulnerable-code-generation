//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 1000
#define MAX_YEAR 3000
#define RADIUS_EARTH 6371

// Function to calculate distance between two points on earth's surface
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return RADIUS_EARTH * c;
}

// Function to generate random coordinates within given range
void generate_coordinates(double min_lat, double max_lat, double min_lon, double max_lon, double *lat, double *lon) {
    *lat = min_lat + (max_lat - min_lat) * rand() / RAND_MAX;
    *lon = min_lon + (max_lon - min_lon) * rand() / RAND_MAX;
}

// Function to check if given coordinates are within given range
int is_within_range(double lat, double lon, double min_lat, double max_lat, double min_lon, double max_lon) {
    if (lat >= min_lat && lat <= max_lat && lon >= min_lon && lon <= max_lon) {
        return 1;
    }
    return 0;
}

// Function to simulate alien invasion and calculate probability
int simulate_invasion(double lat, double lon, int year, int max_tries) {
    srand(time(0));
    int tries = 0;
    while (tries < max_tries) {
        double alien_lat, alien_lon;
        generate_coordinates(-90, 90, -180, 180, &alien_lat, &alien_lon);
        if (is_within_range(alien_lat, alien_lon, lat - 5, lat + 5, lon - 5, lon + 5)) {
            printf("Alien invasion detected at (%f, %f) in the year %d!\n", alien_lat, alien_lon, year);
            return 1;
        }
        tries++;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    double lat, lon;
    printf("Enter your current location (latitude and longitude): ");
    scanf("%lf %lf", &lat, &lon);

    // Simulate alien invasion for next 100 years
    for (int i = 0; i < 100; i++) {
        int result = simulate_invasion(lat, lon, i + 1, MAX_TRIES);
        if (result == 1) {
            break;
        }
    }

    return 0;
}