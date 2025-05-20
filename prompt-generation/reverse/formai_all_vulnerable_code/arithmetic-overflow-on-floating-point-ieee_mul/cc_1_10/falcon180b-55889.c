//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_ITERATIONS 1000
#define PI 3.14159265358979323846

typedef struct {
    int x, y;
} Point;

void *generate_fractal(void *arg) {
    int thread_id = *(int *) arg;
    int start_x = thread_id * (800 / MAX_THREADS);
    int end_x = (thread_id + 1) * (800 / MAX_THREADS);

    for (int x = start_x; x < end_x; x++) {
        double real = x / 800.0 * 3.5 - 2.5;
        double imag = 0;

        int iterations = 0;
        while (iterations < MAX_ITERATIONS && pow(real, 2) + pow(imag, 2) < 4) {
            double new_real = pow(real, 2) - imag + (real = 0.8 * real + 0.156 * imag);
            imag = 2 * real * imag + 1.6;
            iterations++;
        }

        if (iterations == MAX_ITERATIONS) {
            printf("Thread %d: Point (%d, %d) is in the Mandelbrot set.\n", thread_id, x, iterations);
        } else {
            printf("Thread %d: Point (%d, %d) is not in the Mandelbrot set.\n", thread_id, x, iterations);
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS] = {0, 1, 2, 3};

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, generate_fractal, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}