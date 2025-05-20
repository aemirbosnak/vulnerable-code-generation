//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Struct to hold task information
typedef struct task {
    char *name;
    int priority;
    void (*function)(void *);
    void *data;
} Task;

// Comparator function for sorting tasks by priority
int compare_tasks(const void *a, const void *b) {
    const Task *task_a = (const Task *)a;
    const Task *task_b = (const Task *)b;

    if (task_a->priority > task_b->priority) {
        return 1;
    } else if (task_a->priority < task_b->priority) {
        return -1;
    } else {
        return 0;
    }
}

// Function to run a task
void run_task(void *data) {
    Task *task = (Task *)data;
    task->function(task->data);
}

// Main function for the task scheduler
int main() {
    // Initialize pthread library
    pthread_t thread_id;
    int ret;

    // Create a list of tasks
    Task tasks[] = {
        {"Task 1", 1, run_task, NULL},
        {"Task 2", 2, run_task, NULL},
        {"Task 3", 3, run_task, NULL},
        {"Task 4", 4, run_task, NULL},
        {"Task 5", 5, run_task, NULL}
    };

    // Sort tasks by priority
    qsort(tasks, sizeof(tasks) / sizeof(Task), sizeof(Task), compare_tasks);

    // Run each task
    for (int i = 0; i < sizeof(tasks) / sizeof(Task); i++) {
        ret = pthread_create(&thread_id, NULL, tasks[i].function, tasks[i].data);
        if (ret!= 0) {
            printf("Error creating thread: %d\n", ret);
            exit(1);
        }
    }

    // Wait for all tasks to finish
    for (int i = 0; i < sizeof(tasks) / sizeof(Task); i++) {
        ret = pthread_join(thread_id, NULL);
        if (ret!= 0) {
            printf("Error joining thread: %d\n", ret);
            exit(1);
        }
    }

    return 0;
}