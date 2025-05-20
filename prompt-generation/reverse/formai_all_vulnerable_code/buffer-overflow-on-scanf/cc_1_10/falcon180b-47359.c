//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#define BUFFER_SIZE 100
#define NUM_THREADS 5

char buffer[BUFFER_SIZE];
sem_t mutex;
sem_t empty;
sem_t full;

void *consumer(void *arg) {
    char *result = (char *) malloc(BUFFER_SIZE * sizeof(char));
    int i = 0;

    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);

        strcpy(result, buffer);

        sem_post(&mutex);
        sem_post(&empty);

        printf("%s\n", result);

        free(result);
        result = (char *) malloc(BUFFER_SIZE * sizeof(char));
    }

    return NULL;
}

void *producer(void *arg) {
    char input[BUFFER_SIZE];

    while (1) {
        sem_wait(&empty);
        sem_wait(&mutex);

        printf("Enter text to convert to Morse code: ");
        scanf("%s", input);

        strcpy(buffer, input);

        sem_post(&mutex);
        sem_post(&full);

        sleep(1);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, NUM_THREADS);
    sem_init(&full, 0, 0);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, producer, NULL);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}