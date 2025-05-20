//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

struct v {
    int *array;
    int size;
    int thread_id;
};

void *runner(void *arg) {
    struct v *data = (struct v *) arg;
    int i;
    for (i = 0; i < data->size; i++) {
        data->array[i] += data->thread_id;
    }
    return NULL;
}

int main() {
    int i, j, size, num_threads;
    int *array;
    pthread_t threads[100];
    struct v v;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    array = (int *) malloc(size * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    v.array = array;
    v.size = size;
    v.thread_id = 0;

    clock_t start_time = clock();

    for (i = 0; i < num_threads; i++) {
        v.thread_id = i + 1;
        pthread_create(&threads[i], NULL, runner, (void *) &v);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_t end_time = clock();
    double elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    printf("Elapsed time: %lf seconds\n", elapsed_time);

    return 0;
}