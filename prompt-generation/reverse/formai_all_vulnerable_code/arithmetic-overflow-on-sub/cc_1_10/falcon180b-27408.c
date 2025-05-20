//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SAMPLES 1000
#define MIN_SPEED 0
#define MAX_SPEED 100
#define MIN_FIX_TIME 1
#define MAX_FIX_TIME 10

typedef struct {
    double latitude;
    double longitude;
    double speed;
    time_t timestamp;
} gps_sample_t;

void generate_samples(gps_sample_t samples[], int num_samples) {
    srand(time(NULL));

    for (int i = 0; i < num_samples; i++) {
        double delta_lat = (rand() % 1000 - 500) / 1000.0;
        double delta_lon = (rand() % 1000 - 500) / 1000.0;
        double speed = MIN_SPEED + (MAX_SPEED - MIN_SPEED) * (double)rand() / RAND_MAX;
        time_t timestamp = time(NULL) - i * (MAX_FIX_TIME - MIN_FIX_TIME + 1) * 60;

        samples[i].latitude = 37.7749 + delta_lat;
        samples[i].longitude = -122.4194 + delta_lon;
        samples[i].speed = speed;
        samples[i].timestamp = timestamp;
    }
}

void print_samples(gps_sample_t samples[], int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        printf("Sample %d: %s\n", i, ctime(&samples[i].timestamp));
        printf("Latitude: %.6f, Longitude: %.6f, Speed: %.2f km/h\n",
               samples[i].latitude, samples[i].longitude, samples[i].speed * 3.6);
        printf("\n");
    }
}

int main() {
    gps_sample_t samples[NUM_SAMPLES];

    generate_samples(samples, NUM_SAMPLES);
    print_samples(samples, NUM_SAMPLES);

    return 0;
}