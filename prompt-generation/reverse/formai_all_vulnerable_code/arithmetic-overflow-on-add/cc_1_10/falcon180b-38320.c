//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>

#define N 5
#define MAX_VALUE 10
#define SLEEP_TIME 2

int shared_data[N];

sem_t mutex;

void init_semaphore() {
    sem_init(&mutex, 0, 1);
}

void lock_semaphore(int index) {
    sem_wait(&mutex);
    printf("Player %d locked the semaphore.\n", index);
}

void unlock_semaphore(int index) {
    sem_post(&mutex);
    printf("Player %d unlocked the semaphore.\n", index);
}

void* player_thread(void* arg) {
    int index = *(int*)arg;
    int value = 0;

    srand(time(NULL) + index);

    for (int i = 0; i < MAX_VALUE; i++) {
        value += rand() % 2;
        sleep(SLEEP_TIME);
    }

    lock_semaphore(index);
    shared_data[index] = value;
    unlock_semaphore(index);

    return NULL;
}

int main() {
    init_semaphore();

    pthread_t threads[N];

    for (int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, player_thread, (void*)&i);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < N; i++) {
        printf("Player %d's score is %d.\n", i, shared_data[i]);
    }

    return 0;
}