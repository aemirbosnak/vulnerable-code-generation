//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_DISKS 10 // maximum number of disks allowed
#define MAX_THREADS 3 // maximum number of threads allowed
#define RODS 3 // number of rods

int delay = 500000; // delay between each step in microseconds

int num_disks; // number of disks in the tower
int cur_disk; // current disk position
int cur_rod; // current rod position
bool done; // flag to indicate if the tower has been solved

int towers[RODS][MAX_DISKS]; // main tower array

// function to initialize the tower
void init_tower() {
    int i, j;
    for (i = 0; i < RODS; i++) {
        for (j = 0; j < MAX_DISKS; j++) {
            towers[i][j] = -1;
        }
    }
    for (i = 0; i < num_disks; i++) {
        towers[0][i] = i;
    }
}

// function to print the tower status
void print_tower() {
    int i, j;
    for (i = 0; i < RODS; i++) {
        printf("Rod %d: ", i + 1);
        for (j = 0; j < MAX_DISKS; j++) {
            if (towers[i][j] >= 0) {
                printf("%d ", towers[i][j] + 1);
            }
        }
        printf("\n");
    }
}

// function to move the disk to another rod
void move_disk(int from_rod, int to_rod) {
    int i, j, top_from, top_to;
    top_from = -1;
    top_to = -1;
    for (i = 0; i < MAX_DISKS; i++) {
        if (towers[from_rod][i] >= 0) {
            top_from = i;
        }
        if (towers[to_rod][i] >= 0) {
            top_to = i;
        }
    }
    if (top_to < 0 || towers[from_rod][top_from] < towers[to_rod][top_to]) {
        towers[to_rod][top_to + 1] = towers[from_rod][top_from];
        towers[from_rod][top_from] = -1;
        cur_disk = towers[to_rod][top_to + 1];
        cur_rod = to_rod;
        usleep(delay);
        print_tower();
        if (top_from == 0 && cur_rod != 0) {
            done = true;
        }
    }
}

// function to solve the tower using recursive algorithm
void solve_tower(int from_rod, int to_rod, int aux_rod, int n) {
    if (done) return; // exit condition
    if (n == 1) {
        move_disk(from_rod, to_rod);
        return;
    }
    solve_tower(from_rod, aux_rod, to_rod, n - 1); // move n-1 disks from source to auxiliary
    move_disk(from_rod, to_rod); // move the last disk from source to destination
    solve_tower(aux_rod, to_rod, from_rod, n - 1); // move n-1 disks from auxiliary to destination
}

// thread function to solve the tower
void *solve_thread(void *arg) {
    while (!done) {
        if (cur_disk < 0) continue;
        int i;
        for (i = 0; i < RODS; i++) {
            if (i != cur_rod && !done) {
                move_disk(cur_rod, i);
                if (!done) solve_tower(0, 2, 1, num_disks);
            }
        }
    }
    return NULL;
}

// main function
int main() {
    printf("Enter number of disks (1 - %d): ", MAX_DISKS);
    scanf("%d", &num_disks);
    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    init_tower();
    print_tower();
    cur_disk = towers[0][0];
    cur_rod = 0;
    done = false;
    pthread_t threads[MAX_THREADS]; // array of threads
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, solve_thread, NULL);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}