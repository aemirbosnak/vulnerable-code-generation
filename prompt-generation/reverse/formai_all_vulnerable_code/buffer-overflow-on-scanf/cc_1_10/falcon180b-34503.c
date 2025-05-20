//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_DISKS 10

// Structure for passing data between threads
typedef struct {
    int from;
    int to;
    int count;
} thread_data;

// Function for moving disks
void move_disks(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from peg %d to peg %d\n", from, to);
    } else {
        move_disks(n-1, from, aux, to);
        printf("Move disk %d from peg %d to peg %d\n", n, from, to);
        move_disks(n-1, aux, to, from);
    }
}

// Function for each thread to execute
void* thread_func(void* arg) {
    thread_data* data = (thread_data*) arg;
    move_disks(data->count, data->from, data->to, (data->from+data->to)%3-data->from);
    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_DISKS];
    int count = 0;

    // Get user input for number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &count);

    // Check if input is valid
    if (count < 1 || count > MAX_DISKS) {
        printf("Invalid number of disks\n");
        exit(1);
    }

    // Initialize threads
    for (int i = 0; i < count; i++) {
        thread_data data;
        data.count = count;
        data.from = 0;
        data.to = 2;
        pthread_create(&threads[i], NULL, thread_func, &data);
    }

    // Join threads
    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}