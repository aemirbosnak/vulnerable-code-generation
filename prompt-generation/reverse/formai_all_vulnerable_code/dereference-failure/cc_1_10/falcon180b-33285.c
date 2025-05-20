//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_DISKS 10

// Global variables to be accessed by all threads
int num_disks;
char from_rod[MAX_DISKS];
char to_rod[MAX_DISKS];
char aux_rod[MAX_DISKS];

// Function prototypes
void *move_disk(void *arg);
void print_solution(int n);

// Main function to initialize threads
int main(int argc, char **argv) {
    int i;

    if (argc!= 3) {
        printf("Usage: %s num_disks from_rod\n", argv[0]);
        return -1;
    }

    num_disks = atoi(argv[1]);
    strcpy(from_rod, argv[2]);

    pthread_t threads[num_disks];

    // Create threads for each disk
    for (i = num_disks - 1; i >= 0; i--) {
        pthread_create(&threads[i], NULL, move_disk, (void *)i);
    }

    // Join all threads
    for (i = 0; i < num_disks; i++) {
        pthread_join(threads[i], NULL);
    }

    print_solution(num_disks);

    return 0;
}

// Function to move a disk from one rod to another
void *move_disk(void *arg) {
    int disk = (int)arg;

    if (disk == 0) {
        printf("Move disk 1 from %s to %s\n", from_rod, to_rod);
        strcpy(to_rod, from_rod);
        strcpy(from_rod, aux_rod);
        strcpy(aux_rod, to_rod);
    } else {
        printf("Move disk %d from %s to %s\n", disk, from_rod, to_rod);
        strcpy(to_rod, from_rod);
        strcpy(from_rod, aux_rod);
        strcpy(aux_rod, to_rod);
    }

    pthread_exit(NULL);
}

// Function to print the solution
void print_solution(int n) {
    printf("\nSolution:\n");
    printf("Move disk 1 from %s to %s\n", from_rod, to_rod);
    for (int i = 2; i <= n; i++) {
        printf("Move disk %d from %s to %s\n", i, from_rod, to_rod);
    }
}