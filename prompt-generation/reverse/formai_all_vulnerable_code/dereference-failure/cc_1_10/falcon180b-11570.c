//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define N 500
#define dt 0.01

typedef struct {
    double x, y;
} Particle;

Particle *particles;
double box_x, box_y, box_l;
int num_threads;

void init() {
    srand(time(NULL));
    box_x = 0;
    box_y = 0;
    box_l = 1;
    num_threads = 4;
    particles = malloc(N * sizeof(Particle));
    for (int i = 0; i < N; i++) {
        particles[i].x = rand() % 100 / 100.0 - 0.5;
        particles[i].y = rand() % 100 / 100.0 - 0.5;
    }
}

void *simulate(void *arg) {
    int start = *(int *) arg;
    int end = (start + N) / num_threads;

    for (int i = start; i < end; i++) {
        Particle *p = &particles[i];
        p->x += p->x * dt;
        p->y += p->y * dt;

        if (p->x > box_l) {
            p->x = 2 * box_l - p->x;
        } else if (p->x < -box_l) {
            p->x = -2 * box_l - p->x;
        }

        if (p->y > box_l) {
            p->y = 2 * box_l - p->y;
        } else if (p->y < -box_l) {
            p->y = -2 * box_l - p->y;
        }
    }
}

int main() {
    init();

    pthread_t threads[num_threads];
    int thread_args[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_args[i] = i * N / num_threads;
        pthread_create(&threads[i], NULL, simulate, &thread_args[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}