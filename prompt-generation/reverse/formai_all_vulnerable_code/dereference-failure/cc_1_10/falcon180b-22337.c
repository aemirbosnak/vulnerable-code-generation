//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of tasks
#define NUM_TASKS 5

// Define the task function prototype
void *task_function(void *param);

// Define the task parameters
void *task_params[NUM_TASKS];

// Define the task IDs
pthread_t task_ids[NUM_TASKS];

// Define the task priorities
int task_priorities[NUM_TASKS];

int main() {
    // Initialize the task parameters
    for (int i = 0; i < NUM_TASKS; i++) {
        task_params[i] = malloc(sizeof(int));
        *(int *) task_params[i] = i;
    }

    // Set the task priorities
    for (int i = 0; i < NUM_TASKS; i++) {
        task_priorities[i] = i;
    }

    // Create the tasks
    for (int i = 0; i < NUM_TASKS; i++) {
        pthread_create(&task_ids[i], NULL, task_function, task_params[i]);
    }

    // Wait for the tasks to finish
    for (int i = 0; i < NUM_TASKS; i++) {
        pthread_join(task_ids[i], NULL);
    }

    return 0;
}

// Task function
void *task_function(void *param) {
    int task_id = *(int *) param;
    printf("Task %d started\n", task_id);
    sleep(task_id);
    printf("Task %d finished\n", task_id);
    return NULL;
}