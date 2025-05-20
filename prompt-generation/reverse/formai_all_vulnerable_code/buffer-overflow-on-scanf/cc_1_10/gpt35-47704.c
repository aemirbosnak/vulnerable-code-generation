//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int disks;
int tower_a[100];
int tower_b[100];
int tower_c[100];
int a_top = -1, b_top = -1, c_top = -1;

// Function declarations
void* tower_of_hanoi(void* arg);
void move_disk(int from[], int* from_top, int to[], int* to_top);
void print_towers();

int main() {
    // Getting number of disks from user
    printf("Enter the number of disks: ");
    scanf("%d", &disks);

    // Initializing tower A
    for (int i = disks; i > 0; i--) {
        tower_a[++a_top] = i;
    }

    // Creating threads
    pthread_t thread_a, thread_b, thread_c;
    pthread_create(&thread_a, NULL, tower_of_hanoi, (void*) 'a');
    pthread_create(&thread_b, NULL, tower_of_hanoi, (void*) 'b');
    pthread_create(&thread_c, NULL, tower_of_hanoi, (void*) 'c');

    // Waiting for threads to complete
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);

    // Printing final state of the towers
    printf("\nFinal state of the towers:\n");
    print_towers();
    
    return 0;
}

// Thread function for solving Tower of Hanoi problem
void* tower_of_hanoi(void* arg) {
    char from_tower = *(char*) &arg;
    char to_tower = from_tower == 'a' ? 'b' : from_tower == 'b' ? 'c' : 'a';
    
    // Moving disks until all disks are on the final tower (C)
    while (c_top != disks - 1) {
        pthread_mutex_lock(&mutex);
        int* from, * from_top, * to, * to_top;
        
        if (from_tower == 'a') {
            from = &tower_a[0];
            from_top = &a_top;
        } else if (from_tower == 'b') {
            from = &tower_b[0];
            from_top = &b_top;
        } else {
            from = &tower_c[0];
            from_top = &c_top;
        }

        if (to_tower == 'a') {
            to = &tower_a[0];
            to_top = &a_top;
        } else if (to_tower == 'b') {
            to = &tower_b[0];
            to_top = &b_top;
        } else {
            to = &tower_c[0];
            to_top = &c_top;
        }

        // Moving disk from the from tower to the to tower
        if (*from_top != -1 && (*to_top == -1 || *from > *to)) {
            move_disk(from, from_top, to, to_top);
            printf("Thread %c: Disk %d moved from Tower %c to Tower %c\n", from_tower, *to, from_tower, to_tower);
        }

        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Function to move a disk from the given "from" tower to the given "to" tower
void move_disk(int from[], int* from_top, int to[], int* to_top) {
    to[++(*to_top)] = from[(*from_top)--];
}

// Function to print the current state of the towers
void print_towers() {
    printf("Tower A: ");
    for (int i = a_top; i >= 0; i--) {
        printf("%d ", tower_a[i]);
    }
    printf("\nTower B: ");
    for (int i = b_top; i >= 0; i--) {
        printf("%d ", tower_b[i]);
    }
    printf("\nTower C: ");
    for (int i = c_top; i >= 0; i--) {
        printf("%d ", tower_c[i]);
    }
    printf("\n");
}