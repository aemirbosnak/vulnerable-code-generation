//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_SIDES 10000

struct vertex {
    int x;
    int y;
};

struct thread_data {
    int thread_id;
    int num_sides;
    struct vertex *vertices;
};

void *draw_polygon(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int thread_id = data->thread_id;
    int num_sides = data->num_sides;
    struct vertex *vertices = data->vertices;

    for (int i = thread_id; i < num_sides; i += MAX_THREADS) {
        int x1 = vertices[i].x;
        int y1 = vertices[i].y;
        int x2 = vertices[(i + 1) % num_sides].x;
        int y2 = vertices[(i + 1) % num_sides].y;

        printf("Thread %d drawing line from (%d, %d) to (%d, %d)\n",
               thread_id, x1, y1, x2, y2);
    }

    return NULL;
}

int main() {
    int num_threads;
    int num_sides;

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the number of sides of the polygon: ");
    scanf("%d", &num_sides);

    if (num_threads > MAX_THREADS || num_sides > MAX_SIDES) {
        printf("Error: Invalid input\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    struct vertex vertices[MAX_SIDES];

    for (int i = 0; i < num_sides; i++) {
        vertices[i].x = i;
        vertices[i].y = i;
    }

    for (int i = 0; i < num_threads; i++) {
        struct thread_data data;
        data.thread_id = i;
        data.num_sides = num_sides;
        data.vertices = vertices;

        pthread_create(&threads[i], NULL, draw_polygon, &data);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}