//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: rigorous
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Structure to pass data to the thread function
typedef struct {
    int* arr;
    int size;
    int start;
    int end;
    int* sum;
} ThreadData;

// Thread function to calculate the sum of a portion of the array
void* sum_array_portion(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int local_sum = 0;

    // Calculate the sum of the specified portion of the array
    for (int i = data->start; i < data->end; i++) {
        local_sum += data->arr[i];
    }

    // Update the global sum
    *data->sum += local_sum;

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Get the number of elements in the array
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));

    // Get the array elements from the user
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Allocate memory for the global sum
    int* sum = (int*)malloc(sizeof(int));
    *sum = 0;

    // Create the thread pool
    const int num_threads = 4;
    pthread_t threads[num_threads];

    // Divide the array into equal portions for each thread
    int portion_size = n / num_threads;
    ThreadData data[num_threads];
    for (int i = 0; i < num_threads; i++) {
        data[i].arr = arr;
        data[i].size = n;
        data[i].start = i * portion_size;
        data[i].end = (i + 1) * portion_size;
        data[i].sum = sum;
    }

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, sum_array_portion, &data[i]);
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the sum of the array
    printf("The sum of the array is: %d\n", *sum);

    // Free the allocated memory
    free(arr);
    free(sum);

    return 0;
}