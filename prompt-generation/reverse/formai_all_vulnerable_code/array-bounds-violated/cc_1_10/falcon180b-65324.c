//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int thread_id[NUM_THREADS];
int thread_result[NUM_THREADS];

void *thread_func(void *arg) {
    int id = *(int *) arg;
    int sum = 0;
    for (int i = id * (sizeof(data) / sizeof(data[0])) / NUM_THREADS; 
         i < (id + 1) * (sizeof(data) / sizeof(data[0])) / NUM_THREADS; 
         i++) {
        sum += data[i];
    }
    thread_result[id] = sum;
    return NULL;
}

int main() {
    pthread_t thread_id[NUM_THREADS];
    int rc;

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_id[i] = i;
        rc = pthread_create(&thread_id[i], NULL, thread_func, &thread_id[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(thread_id[i], NULL);
        if (rc) {
            printf("Error: unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    int total_sum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        total_sum += thread_result[i];
    }

    int checksum = total_sum % 256;
    printf("Checksum: %d\n", checksum);

    return 0;
}