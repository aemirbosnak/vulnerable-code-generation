//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 100

// Struct to hold task information
typedef struct {
    int id;
    void (*func)(void*);
    void* arg;
} task_t;

// Global array to hold tasks
task_t tasks[MAX_TASKS];
int task_count = 0;

// Mutex for task array
pthread_mutex_t task_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to execute tasks
void* task_executor(void* arg) {
    int i;

    // Lock mutex
    pthread_mutex_lock(&task_mutex);

    // Execute all tasks
    for (i = 0; i < task_count; i++) {
        tasks[i].func(tasks[i].arg);
    }

    // Unlock mutex
    pthread_mutex_unlock(&task_mutex);

    return NULL;
}

int main() {
    int i;

    // Initialize pthreads
    pthread_t threads[MAX_TASKS];

    // Spawn executor thread
    pthread_create(&threads[0], NULL, task_executor, NULL);

    // Accept tasks
    for (i = 0; i < MAX_TASKS; i++) {
        // Accept task information from user
        printf("Enter task ID: ");
        scanf("%d", &tasks[i].id);

        printf("Enter task function: ");
        scanf("%p", &tasks[i].func);

        printf("Enter task argument: ");
        scanf("%p", &tasks[i].arg);

        // Lock mutex
        pthread_mutex_lock(&task_mutex);

        // Add task to array
        tasks[task_count++] = tasks[i];

        // Unlock mutex
        pthread_mutex_unlock(&task_mutex);
    }

    // Join executor thread
    pthread_join(threads[0], NULL);

    return 0;
}