//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 10
#define MAX_ALIENS 100

typedef struct {
    int id;
    int count;
} thread_data_t;

void *count_aliens(void *arg) {
    int max = (int) arg;
    int count = 0;

    srand(time(NULL));
    while (count < max) {
        int alien_count = rand() % 101;
        if (alien_count > 50) {
            count++;
        }
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int max_aliens = MAX_ALIENS;
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_data_t *data = malloc(sizeof(thread_data_t));
        data->id = i + 1;
        data->count = 0;
        pthread_create(&threads[i], NULL, count_aliens, (void *)&max_aliens);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    int total_aliens = 0;
    for (i = 0; i < NUM_THREADS; i++) {
        thread_data_t *data = malloc(sizeof(thread_data_t));
        data->id = i + 1;
        data->count = 0;
        pthread_create(&threads[i], NULL, count_aliens, (void *)&max_aliens);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_aliens += ((thread_data_t *)threads[i])->count;
    }

    double probability = (double)total_aliens / (MAX_ALIENS * NUM_THREADS);

    printf("Alien Invasion Probability: %.2f%%\n", probability * 100);

    return 0;
}