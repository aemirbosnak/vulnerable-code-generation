//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
    int id;
    int x1, y1, x2, y2;
} ThreadData;

void *calculateArea(void *arg) {
    ThreadData *data = (ThreadData *) arg;

    int area = (data->x2 - data->x1) * (data->y2 - data->y1);

    printf("Thread %d calculated area: %d\n", data->id, area);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadData data[MAX_THREADS];

    int numThreads = 0;

    while (numThreads < MAX_THREADS) {
        int x1, y1, x2, y2;

        printf("Enter coordinates for rectangle %d:\n", numThreads + 1);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        data[numThreads].id = numThreads + 1;
        data[numThreads].x1 = x1;
        data[numThreads].y1 = y1;
        data[numThreads].x2 = x2;
        data[numThreads].y2 = y2;

        pthread_create(&threads[numThreads], NULL, calculateArea, (void *)&data[numThreads]);

        numThreads++;
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}