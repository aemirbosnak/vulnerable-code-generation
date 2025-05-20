//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01
#define MAX_THREADS 100
#define MAX_LOCATIONS 1000

typedef struct {
    double lat;
    double lon;
} Location;

typedef struct {
    int id;
    Location start;
    Location end;
} ThreadData;

void *thread_func(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    Location start = data->start;
    Location end = data->end;

    double dLat = end.lat - start.lat;
    double dLon = end.lon - start.lon;

    double a = sin(dLat / 2) * sin(dLat / 2) + cos(start.lat) * cos(end.lat) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = EARTH_RADIUS * c;

    printf("Thread %d calculated distance between (%lf, %lf) and (%lf, %lf) is %.2lf km.\n", data->id, start.lat, start.lon, end.lat, end.lon, distance);

    pthread_exit(0);
}

int main() {
    int num_threads;
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[MAX_THREADS];
    ThreadData data[MAX_THREADS];

    int num_locations;
    printf("Enter number of locations: ");
    scanf("%d", &num_locations);

    Location locations[MAX_LOCATIONS];

    for (int i = 0; i < num_locations; i++) {
        printf("Enter location %d (latitude longitude): ", i + 1);
        scanf("%lf %lf", &locations[i].lat, &locations[i].lon);
    }

    int num_pairs = num_locations - 1;
    for (int i = 0; i < num_pairs; i++) {
        data[i].id = i + 1;
        data[i].start = locations[i];
        data[i].end = locations[i + 1];

        pthread_create(&threads[i], NULL, thread_func, (void *) &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}