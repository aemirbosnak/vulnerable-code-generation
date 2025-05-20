//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 5
#define TASK_RUNTIME 2 // Each task will run for this many seconds

// Structure to hold parameters for each task
typedef struct {
    int task_id;
    double execution_time;
} task_params;

// Function for each task to run
void* perform_task(void* params) {
    task_params* p = (task_params*)params;
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    
    // Simulate doing some work
    sleep(TASK_RUNTIME); // Sleep to let the task "work"
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed_time = (end.tv_sec - start.tv_sec) + 
                          (end.tv_nsec - start.tv_nsec) / 1e9;

    p->execution_time = elapsed_time;
    printf("Task %d completed in %.2f seconds.\n", p->task_id, elapsed_time);

    return NULL;
}

int main() {
    pthread_t threads[NUM_TASKS];
    task_params params[NUM_TASKS];

    // Create and start threads to perform tasks
    for (int i = 0; i < NUM_TASKS; i++) {
        params[i].task_id = i + 1;
        if (pthread_create(&threads[i], NULL, perform_task, &params[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculate total execution time
    double total_time = 0.0;
    for (int i = 0; i < NUM_TASKS; i++) {
        total_time += params[i].execution_time;
    }

    printf("Total execution time for all tasks: %.2f seconds.\n", total_time);
    
    // Find the maximum execution time
    double max_time = params[0].execution_time;
    for (int i = 1; i < NUM_TASKS; i++) {
        if (params[i].execution_time > max_time) {
            max_time = params[i].execution_time;
        }
    }

    printf("Maximum execution time among tasks: %.2f seconds.\n", max_time);

    return 0;
}