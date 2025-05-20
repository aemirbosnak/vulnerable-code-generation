#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    void (*func)(void*);
    void* arg;
} Job;

void work_function(void* arg) {
    printf("Doing some important work...\n");
    int* ptr = (int*) malloc(sizeof(int));
    *ptr = 42;
    free(ptr);
    printf("%d\n", *ptr); // Accessing freed memory
}

void scheduler(Job* jobs, int size) {
    pthread_t threads[size];

    for (int i = 0; i < size; ++i) {
        pthread_create(&threads[i], NULL, jobs[i].func, jobs[i].arg);
    }

    for (int i = 0; i < size; ++i) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    Job jobs[] = {
        { work_function, NULL },
        { work_function, NULL },
        { work_function, NULL }
    };

    scheduler(jobs, sizeof(jobs) / sizeof(Job));

    return 0;
}
