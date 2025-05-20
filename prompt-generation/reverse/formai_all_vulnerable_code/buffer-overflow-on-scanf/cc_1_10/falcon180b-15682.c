//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ELEMENTS 100

typedef struct {
    int value;
    int index;
} Element;

Element elements[MAX_ELEMENTS];
int num_elements = 0;

void* thread_func(void* arg) {
    int thread_num = *(int*) arg;
    printf("Thread %d started.\n", thread_num);

    for (int i = 0; i < num_elements; i++) {
        printf("Thread %d processed element %d with value %d.\n", thread_num, elements[i].index, elements[i].value);
    }

    printf("Thread %d finished.\n", thread_num);
    return NULL;
}

int main() {
    int num_threads = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    for (int i = 0; i < num_elements; i++) {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &elements[i].value);
        elements[i].index = i;
    }

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        int rc = pthread_create(&threads[i], NULL, thread_func, (void*) &i);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}