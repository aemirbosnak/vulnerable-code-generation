//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ELEMENTS 100000

typedef struct {
    int start;
    int end;
    int *array;
} thread_data;

void *bucket_sort(void *arg) {
    thread_data *data = arg;
    int i, j, k, n;
    int *bucket = malloc(MAX_ELEMENTS * sizeof(int));
    
    for (i = data->start; i <= data->end; i++) {
        bucket[i / MAX_ELEMENTS]++;
    }
    
    for (i = 0, n = 0; i < MAX_ELEMENTS; i++) {
        k = 0;
        while (k < bucket[i]) {
            data->array[n++] = i * MAX_ELEMENTS + k;
            k++;
        }
    }
    
    for (i = data->start; i <= data->end; i++) {
        data->array[i] = i * MAX_ELEMENTS + bucket[i / MAX_ELEMENTS] - 1;
    }
    
    free(bucket);
}

int main() {
    int i, n, *array;
    thread_data data;
    pthread_t threads[MAX_THREADS];
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    array = malloc(n * sizeof(int));
    
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    data.start = 0;
    data.end = n - 1;
    data.array = array;
    
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, bucket_sort, &data);
    }
    
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    
    free(array);
    return 0;
}