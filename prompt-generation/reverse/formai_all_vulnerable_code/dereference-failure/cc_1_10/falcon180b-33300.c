//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_DISKS 4
#define DELAY 100000 // Microseconds

// Semaphore for synchronization
sem_t mutex;

// Function prototypes
void move_disk(int from_rod, int to_rod, int aux_rod, int n);
void* thread_move_disk(void* arg);

int main(int argc, char* argv[]) {
    pthread_t threads[NUM_DISKS];
    int rods[NUM_DISKS] = {1, 3, 2, 4};

    // Initialize semaphore
    sem_init(&mutex, 0, 1);

    // Create threads
    for (int i = 0; i < NUM_DISKS; i++) {
        pthread_create(&threads[i], NULL, thread_move_disk, (void*)rods[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_DISKS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void move_disk(int from_rod, int to_rod, int aux_rod, int n) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }

    move_disk(from_rod, aux_rod, to_rod, n - 1);
    printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);
    move_disk(aux_rod, to_rod, from_rod, n - 1);
}

void* thread_move_disk(void* arg) {
    int* rod = (int*)arg;
    sleep(rand() % DELAY); // Delay for random time

    sem_wait(&mutex);
    move_disk(*rod, *rod, 6 - *rod, NUM_DISKS);
    sem_post(&mutex);

    return NULL;
}