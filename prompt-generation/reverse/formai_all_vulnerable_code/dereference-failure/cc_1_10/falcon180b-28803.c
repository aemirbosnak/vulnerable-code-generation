//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a structure to hold data for each thread
typedef struct {
    int id;
    int sum;
} thread_data_t;

// Function to be executed by each thread
void *sum_thread(void *arg) {
    int i, n = *(int *) arg;
    thread_data_t *data = (thread_data_t *) arg;
    
    // Calculate the sum of numbers from 1 to n
    for(i = 1; i <= n; i++) {
        data->sum += i;
    }
    
    // Print the sum calculated by this thread
    printf("Thread %d calculated sum: %d\n", data->id, data->sum);
    
    return NULL;
}

int main(int argc, char *argv[]) {
    int num_threads, i, sum = 0;
    pthread_t threads[10];
    thread_data_t data[10];
    
    // Get the number of threads from command line argument
    if(argc!= 2) {
        fprintf(stderr, "Usage: %s num_threads\n", argv[0]);
        exit(1);
    }
    num_threads = atoi(argv[1]);
    
    // Initialize data for each thread
    for(i = 0; i < num_threads; i++) {
        data[i].id = i + 1;
        data[i].sum = 0;
    }
    
    // Create threads and pass data to them
    for(i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, sum_thread, &data[i]);
    }
    
    // Wait for threads to finish
    for(i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print the total sum calculated by all threads
    printf("Total sum: %d\n", sum);
    
    return 0;
}