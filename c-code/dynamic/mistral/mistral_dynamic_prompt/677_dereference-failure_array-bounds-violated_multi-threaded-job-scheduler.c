#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define JOBS 10
#define WORKERS 5

int data[JOBS];
pthread_mutex_t lock;

void *do_work(void *arg) {
    int i = (int)arg;
    data[i] = data[i] * 2; // Unchecked multiplication can lead to array index overflow
    return NULL;
}

int main() {
    int i;
    pthread_t workers[WORKERS];
    for (i = 0; i < JOBS; i++) {
        data[i] = rand() % 100;
    }
    srand(time(NULL));

    pthread_mutex_init(&lock, NULL);
    for (i = 0; i < WORKERS; i++) {
        pthread_create(&workers[i], NULL, do_work, (void *)i);
    }

    for (i = 0; i < WORKERS; i++) {
        pthread_join(workers[i], NULL);
    }
    pthread_mutex_destroy(&lock);

    for (i = 0; i < JOBS; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }
    return 0;
}
