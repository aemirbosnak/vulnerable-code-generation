//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 5
#define STACK_SIZE 1024

void *thread_func(void *param);

int main() {
    pthread_t threads[NUM_THREADS];
    int i, rc;
    void *status;

    srand(time(NULL));

    // Initialize the threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *) rand());
        if (rc) {
            printf("ERROR: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // Join the threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], &status);
        if (rc) {
            printf("ERROR: unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    printf("All threads have completed!\n");
    return 0;
}

void *thread_func(void *param) {
    int rand_num = *((int *) param);
    int i;

    for (i = 0; i < rand_num; i++) {
        printf("Thread %d is running...\n", rand());
        sleep(1);
    }

    pthread_exit(0);
}