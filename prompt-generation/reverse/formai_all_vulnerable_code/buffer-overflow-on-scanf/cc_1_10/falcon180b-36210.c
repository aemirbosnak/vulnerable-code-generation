//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100
#define NUM_THREADS 10

int arr[MAX]; // array to store the coins
int m[MAX]; // array to store the minimum number of coins required to make a sum
int n; // number of coins
int sum; // sum to be made
int num_threads; // number of threads
int thread_id; // thread ID

void *thread_func(void *arg) {
    int start = *(int *) arg;
    int end = start + (MAX / num_threads);

    int i;
    for (i = start; i < end; i++) {
        m[i] = i; // initialize m[i] to i
    }

    for (i = start - 1; i >= 0; i--) {
        if (m[i] > m[i + 1]) {
            m[i] = m[i + 1];
        }
    }

    for (i = end; i < MAX; i++) {
        if (m[i] < m[i - 1]) {
            m[i] = m[i - 1];
        }
    }

    for (i = start; i < end; i++) {
        if (m[i] == i) {
            m[i] = m[i - 1] + 1;
        } else if (m[i] > i && m[i] < m[i - 1]) {
            m[i] = m[i - 1];
        }
    }

    return NULL;
}

int main() {
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    printf("Enter the sum to be made: ");
    scanf("%d", &sum);

    num_threads = NUM_THREADS;
    pthread_t threads[num_threads];

    int chunk_size = MAX / num_threads;

    for (int i = 0; i < num_threads; i++) {
        int start = i * chunk_size;
        int end = (i == num_threads - 1)? MAX : (i + 1) * chunk_size;

        if (end > MAX) {
            end = MAX;
        }

        if (start < MAX) {
            pthread_create(&threads[i], NULL, thread_func, (void *)&start);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Minimum number of coins required: %d\n", m[sum]);

    return 0;
}