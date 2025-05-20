//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_DISKS 4
#define NUM_RODS 3

int rods[NUM_RODS][NUM_DISKS];
pthread_mutex_t rods_mutex[NUM_RODS];

void move_disk(int from, int to) {
    int disk = rods[from][rods[from][0]--];
    rods[to][++rods[to][0]] = disk;
    printf("Move disk %d from rod %d to rod %d\n", disk, from, to);
}

void* solver(void* arg) {
    int n = *(int*) arg;
    if (n == 1) {
        move_disk(0, 2);
    }
    else {
        solver(&n-1);
        move_disk(0, 2);
        solver(&n-1);
    }
    return NULL;
}

void print_rods() {
    printf("\nRod 0: ");
    for (int i = NUM_DISKS; i > 0; i--) {
        printf("%d ", rods[0][i]);
    }
    printf("\nRod 1: ");
    for (int i = NUM_DISKS; i > 0; i--) {
        printf("%d ", rods[1][i]);
    }
    printf("\nRod 2: ");
    for (int i = NUM_DISKS; i > 0; i--) {
        printf("%d ", rods[2][i]);
    }
    printf("\n");
}

int main() {
    // Initialize rods
    for (int i = 0; i < NUM_DISKS; i++) {
        rods[0][i+1] = NUM_DISKS-i;
        rods[1][i+1] = 0;
        rods[2][i+1] = 0;
    }
    rods[0][0] = NUM_DISKS;
    rods[1][0] = 0;
    rods[2][0] = 0;
    // Initialize mutexes
    for (int i = 0; i < NUM_RODS; i++) {
        pthread_mutex_init(&rods_mutex[i], NULL);
    }
    // Print initial state
    print_rods();
    // Create thread
    pthread_t thread;
    int n = NUM_DISKS;
    pthread_create(&thread, NULL, solver, &n);
    // Wait for thread to finish
    pthread_join(thread, NULL);
    // Print final state
    print_rods();
    // Destroy mutexes
    for (int i = 0; i < NUM_RODS; i++) {
        pthread_mutex_destroy(&rods_mutex[i]);
    }
    return 0;
}