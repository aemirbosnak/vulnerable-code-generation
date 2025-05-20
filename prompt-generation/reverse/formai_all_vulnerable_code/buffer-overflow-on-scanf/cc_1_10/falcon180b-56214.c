//Falcon-180B DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_ELEMENTS 1000
#define NUM_THREADS 5

typedef struct {
    int *data;
    int start;
    int end;
} thread_data_t;

void *sort_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int *array = data->data;
    int start = data->start;
    int end = data->end;
    int i, j, temp;

    for (i = start; i < end; i++) {
        for (j = i; j > start && array[j] < array[j - 1]; j--) {
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
        }
    }

    return NULL;
}

int main() {
    int i, j, num_elements;
    int *array;
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    array = (int *) malloc(sizeof(int) * num_elements);

    printf("Enter the elements:\n");
    for (i = 0; i < num_elements; i++) {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        data[i].data = array;
        data[i].start = i * (num_elements / NUM_THREADS);
        data[i].end = (i == NUM_THREADS - 1)? num_elements - 1 : (i + 1) * (num_elements / NUM_THREADS) - 1;

        pthread_create(&threads[i], NULL, sort_thread, &data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sorted array: ");
    for (i = 0; i < num_elements; i++) {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}