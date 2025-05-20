//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10

// function to print the tower
void print_tower(int n) {
    int i;
    for (i = 0; i <= n; i++) {
        printf(" ");
    }
}

// function to move the disk
void move_disk(int n, char from, char to, char aux) {
    printf("Move disk %d from %c to %c\n", n, from, to);
}

// recursive function to solve the tower of hanoi problem
void tower_of_hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        move_disk(1, from, to, aux);
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, aux);
    tower_of_hanoi(n - 1, aux, to, from);
}

// worker function for the thread to solve the tower of hanoi problem
void *worker(void *arg) {
    int n = *((int *) arg);
    tower_of_hanoi(n, 'A', 'C', 'B');
    pthread_exit(0);
}

// main function to start the threads
int main() {
    int i, n;
    pthread_t thread_id[N];

    // get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // print the initial tower
    printf("Initial state of the tower:\n");
    print_tower(n);

    // create the threads
    for (i = 0; i < n; i++) {
        pthread_create(&thread_id[i], NULL, worker, &i);
    }

    // join the threads
    for (i = 0; i < n; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}