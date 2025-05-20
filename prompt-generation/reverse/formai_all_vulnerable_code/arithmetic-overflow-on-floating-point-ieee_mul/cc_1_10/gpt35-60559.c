//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double radius;
double* areas;
int num_threads;

void* calculate_area(void* arg) {
    int id = *((int*)arg);
    int start = id * (int)(radius / num_threads);
    int end = (id + 1) * (int)(radius / num_threads);
    if (id == num_threads - 1) {
        end = (int)radius;
    }

    for (int i = start; i < end; i++) {
        areas[i] = 3.14159 * i * i;
    }
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s radius num_threads\n", argv[0]);
        exit(1);
    }

    radius = atof(argv[1]);
    num_threads = atoi(argv[2]);

    areas = (double*)malloc(radius * sizeof(double));
    pthread_t* threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
    int* thread_ids = (int*)malloc(num_threads * sizeof(int));

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_area, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    double total_area = 0;
    for (int i = 0; i < radius; i++) {
        total_area += areas[i];
    }

    printf("The area of the circle with radius %lf is %lf\n", radius, total_area);

    free(areas);
    free(threads);
    free(thread_ids);
    return 0;
}