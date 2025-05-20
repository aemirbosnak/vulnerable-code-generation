//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_POINTS 1000000
#define RADIUS 100
#define PI 3.14159265358979323846

typedef struct {
    int id;
    double x, y;
} Point;

Point *generate_points(int num_points) {
    Point *points = (Point *)malloc(num_points * sizeof(Point));
    srand(time(NULL));
    for (int i = 0; i < num_points; i++) {
        points[i].id = i;
        points[i].x = (double)rand() / RAND_MAX * 2 * RADIUS - RADIUS;
        points[i].y = (double)rand() / RAND_MAX * 2 * RADIUS - RADIUS;
    }
    return points;
}

void *count_points_in_circle(void *arg) {
    int thread_id = *(int *)arg;
    Point *points = generate_points(NUM_POINTS);
    int count = 0;

    for (int i = thread_id * NUM_POINTS / NUM_THREADS; i < (thread_id + 1) * NUM_POINTS / NUM_THREADS; i++) {
        if (sqrt(pow(points[i].x - RADIUS, 2) + pow(points[i].y - RADIUS, 2)) <= RADIUS) {
            count++;
        }
    }

    pthread_exit((void *)count);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1, 2, 3};
    int results[NUM_THREADS];

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, count_points_in_circle, (void *)&thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], (void *)&results[i]);
    }

    double pi_estimate = (double)NUM_POINTS / (4 * RADIUS * RADIUS) * results[0];

    printf("Estimated value of pi: %.6f\n", pi_estimate);

    return 0;
}