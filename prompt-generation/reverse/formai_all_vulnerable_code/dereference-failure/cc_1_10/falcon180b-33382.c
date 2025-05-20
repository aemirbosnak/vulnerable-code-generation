//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>

#define NUM_THREADS 5
#define STACK_SIZE 1024

unsigned long long total_memory = 0;
unsigned long long free_memory = 0;

void *thread_func(void *arg) {
    int i;

    for(i = 0; i < 1000000; i++) {
        // Do some memory allocation and deallocation
        char *str = malloc(10);
        strcpy(str, "Hello");
        free(str);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    struct rusage usage;

    for(int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, NULL);
        if(rc) {
            printf("Error: Unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    getrusage(RUSAGE_SELF, &usage);
    total_memory = usage.ru_maxrss;
    free_memory = usage.ru_idrss;

    printf("Total memory usage: %llu bytes\n", total_memory);
    printf("Free memory available: %llu bytes\n", free_memory);

    return 0;
}