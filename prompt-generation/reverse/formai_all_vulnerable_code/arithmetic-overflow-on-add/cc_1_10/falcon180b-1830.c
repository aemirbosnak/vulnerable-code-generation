//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 10

// Define the structure for each task
typedef struct {
    int id;
    int priority;
    int duration;
    int start_time;
    int end_time;
} Task;

// Define the function prototypes
void *task_scheduler(void *arg);
int compare_tasks(const void *a, const void *b);

// Define the main function
int main() {
    int i, j;
    pthread_t threads[MAX_TASKS];
    Task tasks[MAX_TASKS];

    // Initialize the tasks
    for (i = 0; i < MAX_TASKS; i++) {
        tasks[i].id = i;
        tasks[i].priority = rand() % 100;
        tasks[i].duration = rand() % 50 + 1;
        tasks[i].start_time = 0;
        tasks[i].end_time = 0;
    }

    // Sort the tasks by priority
    qsort(tasks, MAX_TASKS, sizeof(Task), compare_tasks);

    // Schedule the tasks
    for (i = 0; i < MAX_TASKS; i++) {
        tasks[i].start_time = time(NULL) + tasks[i].duration;
        pthread_create(&threads[i], NULL, task_scheduler, &tasks[i]);
    }

    // Wait for the tasks to finish
    for (i = 0; i < MAX_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

// Define the task scheduler function
void *task_scheduler(void *arg) {
    Task *task = arg;

    // Sleep until the start time
    sleep(task->start_time - time(NULL));

    // Execute the task
    printf("Task %d started at %ld and ended at %ld\n", task->id, time(NULL), task->end_time);
    task->end_time = time(NULL);

    return NULL;
}

// Define the function to compare tasks by priority
int compare_tasks(const void *a, const void *b) {
    Task *task_a = a;
    Task *task_b = b;

    if (task_a->priority > task_b->priority) {
        return -1;
    } else if (task_a->priority < task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}