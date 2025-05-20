//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define HEIGHT 800
#define WIDTH 800
#define THREADS 4
#define MAX_ITERATIONS 500

int thread_data[THREADS][HEIGHT];
int thread_start_row[THREADS];
int thread_end_row[THREADS];
pthread_t thread_id[THREADS];

void *generate_fractal(void *param) {
    int start_row = *(int *)param;
    int end_row = start_row + HEIGHT / THREADS;

    for (int r = start_row; r < end_row; r++) {
        for (int c = 0; c < WIDTH; c++) {
            int zr = 0;
            int zi = 0;
            int iterations = 0;

            while (iterations < MAX_ITERATIONS && zr * zr + zi * zi < 4) {
                zr = 2 * zr * zr - 1 + c;
                zi = 2 * zr * zi + r;
                iterations++;
            }

            if (iterations == MAX_ITERATIONS) {
                thread_data[pthread_self()][r] = 0;
            } else {
                thread_data[pthread_self()][r] = iterations;
            }
        }
    }

    return NULL;
}

void generate_fractal_multi_threaded() {
    for (int t = 0; t < THREADS; t++) {
        thread_start_row[t] = t * HEIGHT / THREADS;
        thread_end_row[t] = (t + 1) * HEIGHT / THREADS;

        pthread_create(&thread_id[t], NULL, generate_fractal, &thread_start_row[t]);
    }

    for (int t = 0; t < THREADS; t++) {
        pthread_join(thread_id[t], NULL);
    }
}

void print_fractal() {
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            int color = thread_data[0][r] * 255 / MAX_ITERATIONS;

            if (color == 0) {
                printf("  ");
            } else {
                printf("%c", 219 - 3 * color);
            }
        }

        printf("\n");
    }
}

int main() {
    generate_fractal_multi_threaded();
    print_fractal();

    return 0;
}