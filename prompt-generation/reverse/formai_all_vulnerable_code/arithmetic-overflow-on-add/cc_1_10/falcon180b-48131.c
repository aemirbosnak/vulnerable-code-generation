//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 1000
#define MAX_DISTANCE 10
#define PROBABILITY_OF_INVASION 0.1
#define EARTH_RADIUS 6371.0

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate the distance between two points on Earth's surface
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

// Function to simulate an alien invasion
int simulate_invasion(double lat1, double lon1, double lat2, double lon2) {
    int tries = 0;
    while (tries < MAX_TRIES) {
        double x = rand_int(lat1 - MAX_DISTANCE, lat1 + MAX_DISTANCE);
        double y = rand_int(lon1 - MAX_DISTANCE, lon1 + MAX_DISTANCE);
        if (distance(lat1, lon1, x, y) <= MAX_DISTANCE) {
            return 1;
        }
        tries++;
    }
    return 0;
}

int main() {
    srand(time(NULL));

    double lat1, lon1, lat2, lon2;
    printf("Enter the latitude and longitude of your kingdom: ");
    scanf("%lf %lf", &lat1, &lon1);
    printf("Enter the latitude and longitude of your enemy's kingdom: ");
    scanf("%lf %lf", &lat2, &lon2);

    int invasion_count = 0;
    for (int i = 0; i < 100; i++) {
        if (simulate_invasion(lat1, lon1, lat2, lon2)) {
            invasion_count++;
        }
    }

    double probability_of_invasion = (double)invasion_count / 100.0;
    printf("The probability of an alien invasion is %.2f%%\n", probability_of_invasion * 100.0);

    return 0;
}